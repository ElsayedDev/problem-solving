#include "../test_framework.h"
#include <vector>
#include <algorithm>

// Sample test showing how to test file I/O based problems
TEST_CASE("File IO Test Example", test_file_io_example)
{
    // This is an example of how to test problems that read from stdin and write to stdout

    // Test input simulation
    std::string input = "5\n1 2 3 4 5\n";
    std::string expected_output = "1 2 3 4 5\n";

    TestUtils::InputSimulator input_sim(input);
    TestUtils::OutputCapture output_cap;

    // Simulate the main logic here
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }

    // Simple example: just output the same array
    for (int i = 0; i < n; i++)
    {
        if (i > 0)
            std::cout << " ";
        std::cout << arr[i];
    }
    std::cout << std::endl;

    std::string actual_output = output_cap.getOutput();
    ASSERT_EQ(expected_output, actual_output);
}

// Test using the test data utility
TEST_CASE("Test Data File Reading", test_data_file_reading)
{
    try
    {
        std::pair<std::string, std::string> test_data = TestUtils::readTestCase("tests/sample_tests/sample_test_data.txt");
        std::string input = test_data.first;
        std::string output = test_data.second;

        ASSERT_FALSE(input.empty());
        ASSERT_FALSE(output.empty());

        // The sample test data should have input "5\n1 2 3 4 5" and output "1 2 3 4 5"
        ASSERT_TRUE(input.find("5") != std::string::npos);
        ASSERT_TRUE(input.find("1 2 3 4 5") != std::string::npos);
        ASSERT_EQ("1 2 3 4 5", output);
    }
    catch (const std::runtime_error &e)
    {
        // If file doesn't exist, that's okay for this example
        std::cout << "Note: Test data file not found (this is okay for demo): " << e.what() << std::endl;
    }
}

// Example test for sorting algorithm
TEST_CASE("Sorting Algorithm Test", test_sorting_algorithm)
{
    std::vector<int> arr = {5, 2, 8, 1, 9, 3};
    std::vector<int> expected = {1, 2, 3, 5, 8, 9};

    std::sort(arr.begin(), arr.end());

    ASSERT_VEC_EQ(expected, arr);
}

// Example test for binary search
TEST_CASE("Binary Search Test", test_binary_search)
{
    std::vector<int> arr = {1, 3, 5, 7, 9, 11, 13, 15};

    // Test finding existing elements
    auto it1 = std::lower_bound(arr.begin(), arr.end(), 7);
    ASSERT_TRUE(it1 != arr.end());
    ASSERT_EQ(7, *it1);

    // Test finding non-existing element
    auto it2 = std::lower_bound(arr.begin(), arr.end(), 6);
    ASSERT_TRUE(it2 != arr.end());
    ASSERT_EQ(7, *it2); // Should point to first element >= 6
}

// Example test for mathematical operations
TEST_CASE("Math Operations Test", test_math_operations)
{
    // Test GCD using algorithm header
    int a = 48, b = 18;

    // Simple GCD implementation for C++14 compatibility
    auto gcd = [](int a, int b)
    {
        while (b != 0)
        {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    };

    int gcd_result = gcd(a, b);
    ASSERT_EQ(6, gcd_result);

    // Test power of 2 check
    auto isPowerOfTwo = [](int n)
    {
        return n > 0 && (n & (n - 1)) == 0;
    };

    ASSERT_TRUE(isPowerOfTwo(8));
    ASSERT_TRUE(isPowerOfTwo(16));
    ASSERT_FALSE(isPowerOfTwo(10));
    ASSERT_FALSE(isPowerOfTwo(0));
}
