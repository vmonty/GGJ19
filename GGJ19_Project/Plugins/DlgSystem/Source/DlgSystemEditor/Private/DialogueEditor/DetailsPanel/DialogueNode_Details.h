// Copyright 2017-2018 Csaba Molnar, Daniel Butum
#pragma once

#include "CoreMinimal.h"
#include "IDetailCustomization.h"

/**
 * How the details customization panel looks for the UDlgNode (and derived types)
 * See FDlgSystemEditorModule::StartupModule for usage.
 */
class FDialogueNode_Details : public IDetailCustomization
{
	typedef FDialogueNode_Details Self;

public:
	// Makes a new instance of this detail layout class for a specific detail view requesting it
	static TSharedRef<IDetailCustomization> MakeInstance() { return MakeShareable(new Self); }

	// IDetailCustomization interface
	/** Called when details should be customized */
	void CustomizeDetails(IDetailLayoutBuilder& DetailBuilder) override;
};
