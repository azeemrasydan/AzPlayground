BEGIN_DEFINE_SPEC(FClassName, "TestGroup", EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)
int UsefulInteger = 0;
void UtilityMethodForTest();
END_DEFINE_SPEC(FClassName)

void FClassName::UtilityMethodForTest() {
	// do stg 
}

void FClassName::Define() {
	It("Test description", [this]() {
		const auto a = true;
	TestTrue("value of a", a);
		});
}