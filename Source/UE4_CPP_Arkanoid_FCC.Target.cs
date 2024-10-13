// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class UE4_CPP_Arkanoid_FCCTarget : TargetRules
{
	public UE4_CPP_Arkanoid_FCCTarget( TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		ExtraModuleNames.AddRange( new string[] { "UE4_CPP_Arkanoid_FCC" } );
	}
}
