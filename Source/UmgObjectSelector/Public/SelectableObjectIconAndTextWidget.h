// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SelectableObjectBaseWidget.h"
#include "SelectableObjectIconAndTextWidget.generated.h"

USTRUCT(BlueprintType)
struct FSelectableObjectIconAndTextData : public FSelectableObjectData
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UTexture2D* IconTexture;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FText IconText;
};

/**
 *
 */
UCLASS()
class UMGOBJECTSELECTOR_API USelectableObjectIconAndTextWidget : public USelectableObjectBaseWidget
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UImage* IconImage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UTextBlock* IconTextBlock;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UTexture2D* DefaultIconImage;

	UFUNCTION(BlueprintCallable)
		void SetupSelectableObjectData(FSelectableObjectIconAndTextData SelectableObjectData);

	//virtual void RebuildWidget() override;

};
