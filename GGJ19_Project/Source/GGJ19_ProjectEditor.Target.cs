// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class GGJ19_ProjectEditorTarget : TargetRules
{
	public GGJ19_ProjectEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;

		ExtraModuleNames.AddRange( new string[] { "GGJ19_Project" } );
	}
}
