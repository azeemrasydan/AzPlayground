#include "Persons/Person.h"
#include "Misc/AutomationTest.h"
#include "Tests/AutomationCommon.h"


BEGIN_DEFINE_SPEC(FPersonTest, "Person", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)
END_DEFINE_SPEC(FPersonTest)

void FPersonTest::Define() {

	It("Loading Person must have first name and last name", [this]()
		{
			APerson* person = NewObject<APerson>();
			person->Init("Abu", "Ali", FDateTime(1995, 7, 22));

			FString firstName = person->GetFirstName();
			FString lastName = person->GetLastName();

			ADD_LATENT_AUTOMATION_COMMAND(FEngineWaitLatentCommand(1.04));

			TestEqual("First name is equal", firstName, "Abu");
			TestEqual("Last name is equal", lastName, "Ali");
		}
	);

	It("Loading Person must have date of birth", [this]()
		{
			APerson* person = NewObject<APerson>();
			person->Init("Abu", "Ali", FDateTime(1995, 7, 22));
			FDateTime dateTimeOfBirth = person->GetDateTimeOfBirth();

			ADD_LATENT_AUTOMATION_COMMAND(FEngineWaitLatentCommand(1.04));

			TestEqual("Date time of birth is equal", dateTimeOfBirth.ToString(), "1995.07.22-00.00.00");

		}
	);

	It("Loading Person must have skin color set", [this]()
		{
			APerson* person = NewObject<APerson>();
			person->Init("Abu", "Ali", FDateTime(1995, 7, 22), FAIR_SKIN);
			ESkinColor skinColor = person->GetSkinColor();

			TestEqual("Skin color must equal", skinColor, ESkinColor::FAIR_SKIN);
		}
	);

}
