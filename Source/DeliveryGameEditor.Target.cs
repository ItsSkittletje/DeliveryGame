using UnrealBuildTool;

public class DeliveryGameEditorTarget : TargetRules
{
	public DeliveryGameEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.Latest;
		IncludeOrderVersion = EngineIncludeOrderVersion.Latest;
		ExtraModuleNames.Add("DeliveryGame");
	}
}
