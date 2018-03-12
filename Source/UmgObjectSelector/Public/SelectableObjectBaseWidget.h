// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SelectableObjectBaseWidget.generated.h"

USTRUCT(BlueprintType)
struct FSelectableObjectData
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UObject* ContainedObject;
};

/**
 *
 */
UCLASS()
class UMGOBJECTSELECTOR_API USelectableObjectBaseWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UObject* ContainedObject;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UObjectSelectorBaseWidget* ObjectSelectorWidget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UButton* WidgetButton;

	UFUNCTION(BlueprintCallable)
		void OnSelectThisObject();

	void NativeConstruct() override;

	//virtual TSharedRef<SWidget> RebuildWidget() override;
};
