#include "Persons/Person.h"
#include "Misc/AutomationTest.h"
#include "Tests/AutomationCommon.h"
#include "Tests/AutomationEditorCommon.h"

APerson* GetAbuAliPerson() {
	APerson* person = NewObject<APerson>();
	person->Init("Abu", "Ali", FDateTime(1995, 7, 22), FAIR_SKIN);
	return person;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(PersonTestInstantiateFirstAndLastName, "APerson.Instantiating.Must have first and last name", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool PersonTestInstantiateFirstAndLastName::RunTest(const FString& Parameters)
{
	APerson* person = GetAbuAliPerson();
	FString firstName = person->GetFirstName();
	FString lastName = person->GetLastName();

	ADD_LATENT_AUTOMATION_COMMAND(FEngineWaitLatentCommand(1.04));

	TestEqual("First name is equal", firstName, "Abu");
	TestEqual("Last name is equal", lastName, "Ali");

	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(PersonTestInstantiateDateOfBirth, "APerson.Instantiating.Must have date of birth", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool PersonTestInstantiateDateOfBirth::RunTest(const FString& Parameters)
{
	APerson* person = GetAbuAliPerson();

	FString firstName = person->GetFirstName();
	FString lastName = person->GetLastName();

	ADD_LATENT_AUTOMATION_COMMAND(FEngineWaitLatentCommand(1.04));

	TestEqual("First name is equal", firstName, "Abu");
	TestEqual("Last name is equal", lastName, "Ali");

	return true;
}


IMPLEMENT_SIMPLE_AUTOMATION_TEST(PersonTestSkin, "APerson.Skin color needs to be equal", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool PersonTestSkin::RunTest(const FString& Parameters)
{
	APerson* person = GetAbuAliPerson();
	ESkinColor skinColor = person->GetSkinColor();

	TestEqual("Skin color must equal", skinColor, ESkinColor::FAIR_SKIN);

	return true;
}
