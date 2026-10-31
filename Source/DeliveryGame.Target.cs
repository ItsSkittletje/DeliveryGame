using UnrealBuildTool;

public class DeliveryGameTarget : TargetRules
{
	public DeliveryGameTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.Latest;
		IncludeOrderVersion = EngineIncludeOrderVersion.Latest;
		ExtraModuleNames.Add("DeliveryGame");
	}
}
