// Fill out your copyright notice in the Description page of Project Settings.
using System.IO;
using UnrealBuildTool;

public class CGMergedProject : ModuleRules
{
	private string ModulePath
	{
		get { return ModuleDirectory; }
	}
 
	private string ThirdPartyPath
	{
		get { return Path.GetFullPath( Path.Combine( ModulePath, "../../ThirdParty/" ) ); }
	}
	

	public CGMergedProject(TargetInfo Target)
	{
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "Json", "JsonUtilities"  });

		PrivateDependencyModuleNames.AddRange(new string[] {  });

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });
		
		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
		
		LoadLibSVM(Target);	
	}

	public bool LoadLibSVM(TargetInfo Target) {
		bool isLibrarySupported = false;
		string LibrariesPath = Path.Combine(ThirdPartyPath, "libsvm", "libraries");
		string libName = "";
		if ((Target.Platform == UnrealTargetPlatform.Win64) || (Target.Platform == UnrealTargetPlatform.Win32)) {
			isLibrarySupported = true;
			libName = "libsvm.lib";
			//PublicDelayLoadDLLs.Add(Path.Combine(LibrariesPath, "libsvm.dll")); 
			PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "libsvm.lib"));
		} else if(Target.Platform == UnrealTargetPlatform.Linux) {
			isLibrarySupported = true;
			libName = "libsvm.a";
			//PublicDelayLoadDLLs.Add(Path.Combine(LibrariesPath, "libsvm.so.2"));
			PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "libsvm.a"));
		}

		if (isLibrarySupported) {
			PublicIncludePaths.Add(Path.Combine(ThirdPartyPath, "libsvm", "includes"));
			//PublicLibraryPaths.Add(LibrariesPath);
			//PublicAdditionalLibraries.Add(libName);
		}

		Definitions.Add(string.Format( "WITH_LIBSVM_BINDING={0}", isLibrarySupported ? 1 : 0 ) );

		return isLibrarySupported;
	}

}
