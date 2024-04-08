using UnrealBuildTool; 

public class FortniteUI: ModuleRules 

{ 
        public FortniteUI(ReadOnlyTargetRules Target) : base(Target) 

        {
                PrivateDependencyModuleNames.AddRange(new string[] {"Core", "CoreUObject", "Engine", "FortniteGame", "FortniteEditor" });

                // Slate UI
                PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore", "UMG" });
    } 
}