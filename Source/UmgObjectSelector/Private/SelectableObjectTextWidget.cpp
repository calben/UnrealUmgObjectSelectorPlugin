// Fill out your copyright notice in the Description page of Project Settings.

#include "SelectableObjectTextWidget.h"
#include "Runtime/UMG/Public/Components/TextBlock.h"

void USelectableObjectTextWidget::SetupSelectableObjectData(FSelectableObjectTextData SelectableObjectData)
{
	IconTextBlock->SetText(SelectableObjectData.ItemText);
	ContainedObject = SelectableObjectData.ContainedObject;
}
