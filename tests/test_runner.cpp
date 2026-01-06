#include "test_framework.h"
#include <cstring>

int main(int argc, char *argv[])
{
    bool verbose = false;
    std::string specific_test = "";

    // Parse command line arguments
    for (int i = 1; i < argc; i++)
    {
        if (strcmp(argv[i], "-v") == 0 || strcmp(argv[i], "--verbose") == 0)
        {
            verbose = true;
        }
        else if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0)
        {
            std::cout << "Usage: " << argv[0] << " [options] [test_name]" << std::endl;
            std::cout << "Options:" << std::endl;
            std::cout << "  -v, --verbose    Enable verbose output" << std::endl;
            std::cout << "  -h, --help       Show this help message" << std::endl;
            std::cout << "  test_name        Run only the specified test" << std::endl;
            return 0;
        }
        else
        {
            specific_test = argv[i];
        }
    }

    auto &runner = TestRunner::getInstance();
    runner.setVerbose(verbose);

    if (!specific_test.empty())
    {
        std::cout << "Running specific test: " << specific_test << std::endl;
        // Note: For specific test filtering, you would need to modify TestRunner
        // to support filtering by test name
    }

    try
    {
        runner.runTests();
        std::cout << GREEN << "All tests passed!" << RESET << std::endl;
        return 0;
    }
    catch (const std::exception &e)
    {
        std::cout << RED << "Test execution failed: " << e.what() << RESET << std::endl;
        return 1;
    }
}
