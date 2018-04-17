// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SelectableObjectBaseWidget.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnSelected);

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDeselected);

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
		bool bAllowSelect = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bAllowDeselect = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bAllowReselect = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UObject* ContainedObject;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UObjectSelectorBaseWidget* ObjectSelectorWidget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UButton* SelectableObjectButton;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bIsSelected;

	UPROPERTY(BlueprintAssignable, Category = "Widget Event")
		FOnSelected OnSelected;

	UPROPERTY(BlueprintAssignable, Category = "Widget Event")
		FOnDeselected OnDeselected;

	UFUNCTION()
		void TrySelect();

	UFUNCTION()
		void TryDeselect();

	void NativeConstruct() override;

	//virtual TSharedRef<SWidget> RebuildWidget() override;
};
