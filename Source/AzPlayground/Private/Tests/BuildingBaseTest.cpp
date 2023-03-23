#include "Buildings/BuildingBase.h"
#include "Misc/AutomationTest.h"
#include "Tests/AutomationCommon.h"

#if WITH_DEV_AUTOMATION_TESTS

BEGIN_DEFINE_SPEC(FBuildingBaseTest, "BuildingBase", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)
END_DEFINE_SPEC(FBuildingBaseTest)

DEFINE_LATENT_AUTOMATION_COMMAND_TWO_PARAMETER(FDebugSetBuildingHealth, ABuildingBase*, BuildingBase, float, Health);
bool FDebugSetBuildingHealth::Update()
{
	BuildingBase->Debug_SetHealth(Health);
	return true;
}

DEFINE_LATENT_AUTOMATION_COMMAND_TWO_PARAMETER(FTestBuildHealthEqual50f, FAutomationTestBase*, Test, ABuildingBase*, BuildingBase);
bool FTestBuildHealthEqual50f::Update()
{
	UE_LOG(LogTemp, Log, TEXT("Hey you wahtsapp man"));
	Test->TestEqual("Health is equal", BuildingBase->GetHealth(), 50.f);
	return true;
}


void FBuildingBaseTest::Define() {
	It("Loading BuildingBase must have Health 100f", [this]()
		{
			ABuildingBase* buildingBase = NewObject<ABuildingBase>();
		
			float health = buildingBase->GetHealth();
			ADD_LATENT_AUTOMATION_COMMAND(FEngineWaitLatentCommand(1.0f));
			TestEqual("Health is equal", health, 100.f);
		}
	);

	It("BuildingBase Debug_SetHealth must set to specified value", [this]()
		{
			ABuildingBase* buildingBase = NewObject<ABuildingBase>();
		
			ADD_LATENT_AUTOMATION_COMMAND(FDebugSetBuildingHealth(buildingBase, 50.f))
			ADD_LATENT_AUTOMATION_COMMAND(FEngineWaitLatentCommand(1.0f));
			ADD_LATENT_AUTOMATION_COMMAND(FTestBuildHealthEqual50f(this, buildingBase));

		}
	);

}

#endif