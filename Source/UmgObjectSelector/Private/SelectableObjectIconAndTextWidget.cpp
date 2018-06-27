// Fill out your copyright notice in the Description page of Project Settings.

#include "SelectableObjectIconAndTextWidget.h"
#include "Runtime/UMG/Public/Components/Image.h"
#include "Runtime/UMG/Public/Blueprint/WidgetTree.h"
#include "Runtime/UMG/Public/Components/PanelWidget.h"
#include "Runtime/UMG/Public/Components/TextBlock.h"

//void USelectableObjectIconAndTextWidget::RebuildWidget()
//{
//	Super::RebuildWidget();
//	IconImage = WidgetTree->ConstructWidget<UImage>(UImage::StaticClass(), TEXT("IconImage"));
//	IconTextBlock = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("IconTextBlock"));
//	WidgetPanel->AddChild(IconImage);
//}

void USelectableObjectIconAndTextWidget::SetupSelectableObjectData(FSelectableObjectIconAndTextData SelectableObjectData)
{
	if (IconImage != nullptr)
	{
		IconImage->SetBrushFromTexture(SelectableObjectData.IconTexture);
	}
	else if (DefaultIconImage != nullptr)
	{
		IconImage->SetBrushFromTexture(DefaultIconImage);
	}
	IconTextBlock->SetText(SelectableObjectData.IconText);
	ContainedObject = SelectableObjectData.ContainedObject;
}
