// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SelectableObjectBaseWidget.h"
#include "SelectableObjectTextWidget.generated.h"

USTRUCT(BlueprintType)
struct FSelectableObjectTextData : public FSelectableObjectData
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FText ItemText;
};

/**
 *
 */
UCLASS()
class UMGOBJECTSELECTOR_API USelectableObjectTextWidget : public USelectableObjectBaseWidget
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UTextBlock* IconTextBlock;

	UFUNCTION(BlueprintCallable)
		void SetupSelectableObjectData(FSelectableObjectTextData SelectableObjectData);

};
