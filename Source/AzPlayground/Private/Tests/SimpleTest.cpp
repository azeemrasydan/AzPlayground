#include "Misc/AutomationTest.h"
#include "Tests/AutomationEditorCommon.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FPlaceholderTest, "TestGroup.TestSubgroup.Placeholder Test", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FPlaceholderTest::RunTest(const FString& Parameters)
{
    // Make the test pass by returning true, or fail by returning false.

    return true;
}