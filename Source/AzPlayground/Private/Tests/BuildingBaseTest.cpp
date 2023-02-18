#include "Buildings/BuildingBase.h"

BEGIN_DEFINE_SPEC(FBuildingBaseTest, "BuildingBase", EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)
int UsefulInteger = 0;
void UtilityMethodForTest();
END_DEFINE_SPEC(FBuildingBaseTest)

void FBuildingBaseTest::UtilityMethodForTest() {
	// do stg 
}

void FBuildingBaseTest::Define() {
	It("Loading BuildingBase must have Health 100f", [this]()
		{
			ABuildingBase* buildingBase = NewObject<ABuildingBase>();

			buildingBase->Debug_SetHealth(100.f);
			float health = buildingBase->GetHealth();

			TestEqual("Health is equal", health, 100.f);

		});

}