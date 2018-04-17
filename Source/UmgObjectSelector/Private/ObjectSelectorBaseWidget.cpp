// Fill out your copyright notice in the Description page of Project Settings.

#include "ObjectSelectorBaseWidget.h"
#include "SelectableObjectBaseWidget.h"
#include "Runtime/UMG/Public/Components/PanelWidget.h"

void UObjectSelectorBaseWidget::AddSelectableObjectToWidget(USelectableObjectBaseWidget * Widget)
{
	BasePanel->AddChild(Widget);
	SelectableChildWidgets.Add(Widget);
	Widget->ObjectSelectorWidget = this;
}

void UObjectSelectorBaseWidget::OnSelectableObjectBaseWidgetSelected(USelectableObjectBaseWidget* SelectedWidget)
{
	if (!bAllowMultiselect)
	{
		for (auto Widget : SelectableChildWidgets)
		{
			if (Widget != SelectedWidget && Widget->bIsSelected)
			{
				Widget->TryDeselect();
			}
		}
	}
	if (OnObjectSelectionChanged.IsBound())
	{
		OnObjectSelectionChanged.Broadcast(SelectedWidget->ContainedObject);
	}
}
