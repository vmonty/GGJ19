// Copyright 2017-2018 Csaba Molnar, Daniel Butum
#pragma once

#include "EdGraph/EdGraphSchema.h"
#include "Templates/SubclassOf.h"

#include "NewComment_DialogueGraphSchemaAction.generated.h"

class UEdGraph;

/** Action to create new comment */
USTRUCT()
struct FNewComment_DialogueGraphSchemaAction : public FEdGraphSchemaAction
{
	GENERATED_USTRUCT_BODY();

	FNewComment_DialogueGraphSchemaAction() : FEdGraphSchemaAction() {}
	FNewComment_DialogueGraphSchemaAction(const FText& InNodeCategory, const FText& InMenuDesc, const FText& InToolTip, const int32 InGrouping)
		: FEdGraphSchemaAction(InNodeCategory, InMenuDesc, InToolTip, InGrouping) {}

	//~ Begin FEdGraphSchemaAction Interface
	UEdGraphNode* PerformAction(UEdGraph* ParentGraph, UEdGraphPin* FromPin, const FVector2D Location, bool bSelectNewNode = true) override;
	//~ End FEdGraphSchemaAction Interface
};

