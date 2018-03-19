// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SelectableObjectBaseWidget.h"
#include "ObjectSelectorBaseWidget.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnObjectSelectionChangedEvent, const UObject*, SelectedObject);

/**
 *
 */
UCLASS()
class UMGOBJECTSELECTOR_API UObjectSelectorBaseWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UObject* CurrentSelectedObject;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UPanelWidget* BasePanel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TSubclassOf<USelectableObjectBaseWidget> SelectableObjectBaseWidgetClass;

	UPROPERTY(BlueprintAssignable, Category = "Widget Event")
		FOnObjectSelectionChangedEvent OnObjectSelectionChanged;

	UFUNCTION(BlueprintCallable)
		void AddSelectableObjectToWidget(class USelectableObjectBaseWidget* Widget);

};
