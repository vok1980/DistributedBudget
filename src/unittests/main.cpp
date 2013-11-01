
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>

#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>

#include <cppunit/XmlOutputter.h>



int main()
{
    CppUnit::TextUi::TestRunner runner;
    CppUnit::TestResultCollector collectedresults;
    runner.eventManager().addListener(&collectedresults);
    
    CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry();
    runner.addTest( registry.makeTest() );
    
    runner.run( "", false );

    std::ofstream xmlFileOut("UnittestResults.xml");
    CppUnit::XmlOutputter xmlOut(&collectedresults, xmlFileOut);
    xmlOut.write();
    
    return collectedresults.wasSuccessful() ? 0 : 1;
}

