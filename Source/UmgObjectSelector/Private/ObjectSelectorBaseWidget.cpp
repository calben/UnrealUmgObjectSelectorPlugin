// Fill out your copyright notice in the Description page of Project Settings.

#include "ObjectSelectorBaseWidget.h"
#include "SelectableObjectBaseWidget.h"
#include "Runtime/UMG/Public/Components/PanelWidget.h"

void UObjectSelectorBaseWidget::AddSelectableObjectToWidget(USelectableObjectBaseWidget * Widget)
{
	BasePanel->AddChild(Widget);
	Widget->ObjectSelectorWidget = this;
}
