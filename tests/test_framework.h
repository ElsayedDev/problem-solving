#ifndef TEST_FRAMEWORK_H
#define TEST_FRAMEWORK_H

#include <iostream>
#include <vector>
#include <functional>
#include <string>
#include <chrono>
#include <fstream>
#include <sstream>

// Colors for output
#define GREEN "\033[32m"
#define RED "\033[31m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

// Test result structure
struct TestResult
{
    std::string name;
    bool passed;
    std::string message;
    double duration_ms;
};

// Test case structure
struct TestCase
{
    std::string name;
    std::function<void()> test_function;
};

// Global test registry
class TestRunner
{
private:
    std::vector<TestCase> test_cases;
    std::vector<TestResult> results;
    bool verbose = false;

public:
    static TestRunner &getInstance()
    {
        static TestRunner instance;
        return instance;
    }

    void addTest(const std::string &name, std::function<void()> test_func)
    {
        test_cases.push_back({name, test_func});
    }

    void setVerbose(bool v) { verbose = v; }

    void runTests()
    {
        std::cout << BLUE << "Running " << test_cases.size() << " tests..." << RESET << std::endl;
        std::cout << "================================" << std::endl;

        int passed = 0;
        for (const auto &test : test_cases)
        {
            auto start = std::chrono::high_resolution_clock::now();

            try
            {
                test.test_function();
                auto end = std::chrono::high_resolution_clock::now();
                auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

                TestResult result{test.name, true, "PASSED", duration.count() / 1000.0};
                results.push_back(result);
                passed++;

                if (verbose)
                {
                    std::cout << GREEN << "✓ " << test.name << " (" << result.duration_ms << "ms)" << RESET << std::endl;
                }
            }
            catch (const std::exception &e)
            {
                auto end = std::chrono::high_resolution_clock::now();
                auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

                TestResult result{test.name, false, e.what(), duration.count() / 1000.0};
                results.push_back(result);

                std::cout << RED << "✗ " << test.name << " - " << e.what() << RESET << std::endl;
            }
        }

        std::cout << "================================" << std::endl;
        std::cout << "Tests: " << GREEN << passed << " passed" << RESET;
        if (passed != (int)test_cases.size())
        {
            std::cout << ", " << RED << ((int)test_cases.size() - passed) << " failed" << RESET;
        }
        std::cout << std::endl;

        if (passed != (int)test_cases.size())
        {
            exit(1);
        }
    }

    const std::vector<TestResult> &getResults() const { return results; }
};

// Custom exception for test failures
class TestFailure : public std::exception
{
private:
    std::string message;

public:
    TestFailure(const std::string &msg) : message(msg) {}
    const char *what() const noexcept override { return message.c_str(); }
};

// Assertion macros
#define ASSERT_EQ(expected, actual)                                       \
    do                                                                    \
    {                                                                     \
        if ((expected) != (actual))                                       \
        {                                                                 \
            std::ostringstream oss;                                       \
            oss << "Expected: " << (expected) << ", Actual: " << (actual) \
                << " at " << __FILE__ << ":" << __LINE__;                 \
            throw TestFailure(oss.str());                                 \
        }                                                                 \
    } while (0)

#define ASSERT_NE(expected, actual)                                                 \
    do                                                                              \
    {                                                                               \
        if ((expected) == (actual))                                                 \
        {                                                                           \
            std::ostringstream oss;                                                 \
            oss << "Expected not equal: " << (expected) << ", Actual: " << (actual) \
                << " at " << __FILE__ << ":" << __LINE__;                           \
            throw TestFailure(oss.str());                                           \
        }                                                                           \
    } while (0)

#define ASSERT_TRUE(condition)                                    \
    do                                                            \
    {                                                             \
        if (!(condition))                                         \
        {                                                         \
            std::ostringstream oss;                               \
            oss << "Expected true, got false for: " << #condition \
                << " at " << __FILE__ << ":" << __LINE__;         \
            throw TestFailure(oss.str());                         \
        }                                                         \
    } while (0)

#define ASSERT_FALSE(condition)                                   \
    do                                                            \
    {                                                             \
        if (condition)                                            \
        {                                                         \
            std::ostringstream oss;                               \
            oss << "Expected false, got true for: " << #condition \
                << " at " << __FILE__ << ":" << __LINE__;         \
            throw TestFailure(oss.str());                         \
        }                                                         \
    } while (0)

#define ASSERT_LT(a, b)                                   \
    do                                                    \
    {                                                     \
        if (!((a) < (b)))                                 \
        {                                                 \
            std::ostringstream oss;                       \
            oss << "Expected " << (a) << " < " << (b)     \
                << " at " << __FILE__ << ":" << __LINE__; \
            throw TestFailure(oss.str());                 \
        }                                                 \
    } while (0)

#define ASSERT_LE(a, b)                                   \
    do                                                    \
    {                                                     \
        if (!((a) <= (b)))                                \
        {                                                 \
            std::ostringstream oss;                       \
            oss << "Expected " << (a) << " <= " << (b)    \
                << " at " << __FILE__ << ":" << __LINE__; \
            throw TestFailure(oss.str());                 \
        }                                                 \
    } while (0)

#define ASSERT_GT(a, b)                                   \
    do                                                    \
    {                                                     \
        if (!((a) > (b)))                                 \
        {                                                 \
            std::ostringstream oss;                       \
            oss << "Expected " << (a) << " > " << (b)     \
                << " at " << __FILE__ << ":" << __LINE__; \
            throw TestFailure(oss.str());                 \
        }                                                 \
    } while (0)

#define ASSERT_GE(a, b)                                   \
    do                                                    \
    {                                                     \
        if (!((a) >= (b)))                                \
        {                                                 \
            std::ostringstream oss;                       \
            oss << "Expected " << (a) << " >= " << (b)    \
                << " at " << __FILE__ << ":" << __LINE__; \
            throw TestFailure(oss.str());                 \
        }                                                 \
    } while (0)

// Vector comparison
#define ASSERT_VEC_EQ(expected, actual)                                               \
    do                                                                                \
    {                                                                                 \
        if ((expected).size() != (actual).size())                                     \
        {                                                                             \
            std::ostringstream oss;                                                   \
            oss << "Vector sizes differ. Expected: " << (expected).size()             \
                << ", Actual: " << (actual).size()                                    \
                << " at " << __FILE__ << ":" << __LINE__;                             \
            throw TestFailure(oss.str());                                             \
        }                                                                             \
        for (size_t i = 0; i < (expected).size(); ++i)                                \
        {                                                                             \
            if ((expected)[i] != (actual)[i])                                         \
            {                                                                         \
                std::ostringstream oss;                                               \
                oss << "Vector elements differ at index " << i                        \
                    << ". Expected: " << (expected)[i] << ", Actual: " << (actual)[i] \
                    << " at " << __FILE__ << ":" << __LINE__;                         \
                throw TestFailure(oss.str());                                         \
            }                                                                         \
        }                                                                             \
    } while (0)

// Test case registration macro
#define TEST_CASE(name, func)                                  \
    void func();                                               \
    namespace                                                  \
    {                                                          \
        struct TestRegistrar_##func                            \
        {                                                      \
            TestRegistrar_##func()                             \
            {                                                  \
                TestRunner::getInstance().addTest(name, func); \
            }                                                  \
        };                                                     \
        static TestRegistrar_##func test_registrar_##func;     \
    }                                                          \
    void func()

// Utility functions for competitive programming
namespace TestUtils
{
    // Read test data from file
    std::pair<std::string, std::string> readTestCase(const std::string &filename)
    {
        std::ifstream file(filename);
        if (!file.is_open())
        {
            throw std::runtime_error("Cannot open test file: " + filename);
        }

        std::string input, output, line;
        bool reading_output = false;

        while (std::getline(file, line))
        {
            if (line == "---")
            {
                reading_output = true;
                continue;
            }

            if (reading_output)
            {
                if (!output.empty())
                    output += "\n";
                output += line;
            }
            else
            {
                if (!input.empty())
                    input += "\n";
                input += line;
            }
        }

        return {input, output};
    }

    // Capture stdout for testing
    class OutputCapture
    {
    private:
        std::ostringstream buffer;
        std::streambuf *old_cout;

    public:
        OutputCapture()
        {
            old_cout = std::cout.rdbuf();
            std::cout.rdbuf(buffer.rdbuf());
        }

        ~OutputCapture()
        {
            std::cout.rdbuf(old_cout);
        }

        std::string getOutput()
        {
            return buffer.str();
        }
    };

    // Input simulation
    class InputSimulator
    {
    private:
        std::istringstream input_stream;
        std::streambuf *old_cin;

    public:
        InputSimulator(const std::string &input) : input_stream(input)
        {
            old_cin = std::cin.rdbuf();
            std::cin.rdbuf(input_stream.rdbuf());
        }

        ~InputSimulator()
        {
            std::cin.rdbuf(old_cin);
        }
    };
}

// Macro to run main function with input/output capture
#define TEST_MAIN_WITH_IO(test_name, input_str, expected_output) \
    TEST_CASE(test_name, test_##test_name)                       \
    {                                                            \
        TestUtils::InputSimulator input_sim(input_str);          \
        TestUtils::OutputCapture output_cap;                     \
                                                                 \
        int result = main();                                     \
                                                                 \
        std::string actual_output = output_cap.getOutput();      \
        ASSERT_EQ(expected_output, actual_output);               \
    }

#endif // TEST_FRAMEWORK_H
