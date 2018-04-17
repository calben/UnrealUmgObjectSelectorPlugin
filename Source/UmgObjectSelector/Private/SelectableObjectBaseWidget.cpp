// Fill out your copyright notice in the Description page of Project Settings.

#include "SelectableObjectBaseWidget.h"
#include "Runtime/UMG/Public/Components/Button.h"
#include "Runtime/UMG/Public/Components/PanelWidget.h"
#include "Runtime/UMG/Public/Blueprint/WidgetTree.h"
#include "ObjectSelectorBaseWidget.h"

//TSharedRef<SWidget> USelectableObjectBaseWidget::RebuildWidget()
//{
//	Super::RebuildWidget();
//	auto RootWidget = Cast<UPanelWidget>(GetRootWidget());
//	WidgetPanel = WidgetTree->ConstructWidget<UPanelWidget>(UPanelWidget::StaticClass(), TEXT("WidgetPanel"));
//	if (RootWidget == nullptr)
//	{
//		WidgetTree->RootWidget = WidgetPanel;
//	}
//	return Super::RebuildWidget();
//}

void USelectableObjectBaseWidget::NativeConstruct()
{
	Super::Construct();
	SelectableObjectButton->OnReleased.AddDynamic(this, &USelectableObjectBaseWidget::TrySelect);
}

void USelectableObjectBaseWidget::TrySelect()
{
	if (bAllowSelect)
	{
		if (!bIsSelected || bAllowReselect)
		{
			bIsSelected = true;
			if (ObjectSelectorWidget != nullptr)
			{
				ObjectSelectorWidget->OnSelectableObjectBaseWidgetSelected(this);
			}
			if (OnSelected.IsBound())
			{
				OnSelected.Broadcast();
			}
		}
	}
}

void USelectableObjectBaseWidget::TryDeselect()
{
	if (bAllowDeselect)
	{
		bIsSelected = false;
		if (OnDeselected.IsBound())
		{
			OnDeselected.Broadcast();
		}
	}
}

