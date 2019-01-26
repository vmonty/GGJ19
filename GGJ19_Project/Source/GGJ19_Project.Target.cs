// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class GGJ19_ProjectTarget : TargetRules
{
	public GGJ19_ProjectTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;

		ExtraModuleNames.AddRange( new string[] { "GGJ19_Project" } );
	}
}
