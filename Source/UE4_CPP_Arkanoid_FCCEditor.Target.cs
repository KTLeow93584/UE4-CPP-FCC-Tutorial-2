// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class UE4_CPP_Arkanoid_FCCEditorTarget : TargetRules
{
	public UE4_CPP_Arkanoid_FCCEditorTarget( TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		ExtraModuleNames.AddRange( new string[] { "UE4_CPP_Arkanoid_FCC" } );
	}
}
