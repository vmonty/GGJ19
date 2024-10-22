// Copyright 2017-2018 Csaba Molnar, Daniel Butum
#pragma once

#include "IPropertyTypeCustomization.h"
#include "Layout/Visibility.h"
#include "DialogueDetailsPanelUtils.h"

class UDlgDialogue;
class FMultiLineEditableTextBox_CustomRowHelper;
class FTextPropertyPickList_CustomRowHelper;

/**
 * How the details customization panel looks for the FDlgEdge
 * See FDlgSystemEditorModule::StartupModule for usage.
 */
class FDialogueEdge_Details : public IPropertyTypeCustomization
{
	typedef FDialogueEdge_Details Self;

public:
	static TSharedRef<IPropertyTypeCustomization> MakeInstance() { return MakeShareable(new Self); }

	/** IPropertyTypeCustomization interface */
	/**
	 * Called when the header of the property (the row in the details panel where the property is shown)
	 * If nothing is added to the row, the header is not displayed
	 *
	 * @param StructPropertyHandle		Handle to the property being customized
	 * @param HeaderRow					A row that widgets can be added to
	 * @param StructCustomizationUtils	Utilities for customization
	 */
	void CustomizeHeader(TSharedRef<IPropertyHandle> StructPropertyHandle,
		FDetailWidgetRow& HeaderRow,
		IPropertyTypeCustomizationUtils& StructCustomizationUtils) override;

	/**
	 * Called when the children of the property should be customized or extra rows added
	 *
	 * @param StructPropertyHandle		Handle to the property being customized
	 * @param StructBuilder				A builder for adding children
	 * @param StructCustomizationUtils	Utilities for customization
	 */
	void CustomizeChildren(TSharedRef<IPropertyHandle> StructPropertyHandle,
		IDetailChildrenBuilder& StructBuilder,
		IPropertyTypeCustomizationUtils& StructCustomizationUtils) override;



	/** Gets the Speaker States from all Dialogues. */
	TArray<FName> GetAllDialoguesSpeakerStates() const
	{
		TArray<FName> OutArray;
		UDlgManager::GetAllDialoguesSpeakerStates(OutArray);
		return OutArray;
	}

	/** Handler for when the speaker state is changed */
	void HandleSpeakerStateCommitted(const FText& InSearchText, ETextCommit::Type CommitInfo);

	/** Handler for when the text is changed */
	void HandleTextCommitted(const FText& InText, ETextCommit::Type CommitInfo);

private:
	// Getters for the visibility of some properties
	EVisibility GetTextVisibility() const { return bShowTextProperty ? EVisibility::Visible : EVisibility::Hidden; }

	EVisibility GetSpeakerStateVisibility() const
	{
		const UDlgSystemSettings* Settings = GetDefault<UDlgSystemSettings>();

		return bShowTextProperty &&
			  (Settings->DialogueSpeakerStateVisibility == EDlgSpeakerStateVisibility::DlgShowOnEdge ||
			   Settings->DialogueSpeakerStateVisibility == EDlgSpeakerStateVisibility::DlgShowOnNodeAndEdge)
			   ? EVisibility::Visible : EVisibility::Hidden;
	}

private:
	/** The property handle of the entire struct. */
	TSharedPtr<IPropertyHandle> StructPropertyHandle;

	/** Bool flag indicating to show or not the Text Property of the Edge */
	bool bShowTextProperty = true;

	/** Cache some properties */
	TSharedPtr<IPropertyHandle> TextPropertyHandle;
	TSharedPtr<FMultiLineEditableTextBox_CustomRowHelper> TextPropertyRow;
	TSharedPtr<FTextPropertyPickList_CustomRowHelper> SpeakerStatePropertyRow;

	/** Hold a reference to dialogue we are displaying. */
	UDlgDialogue* Dialogue = nullptr;
};
