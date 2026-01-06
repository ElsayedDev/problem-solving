#!/bin/bash

# Script to create a new test file for a problem

if [ $# -eq 0 ]; then
    echo "Usage: $0 <problem_name> [test_type]"
    echo "  problem_name: Name of the problem (e.g., 'two_sum', 'reverse_bits')"
    echo "  test_type: Type of test (sample, unit, integration) - defaults to 'sample'"
    echo ""
    echo "Examples:"
    echo "  $0 two_sum sample"
    echo "  $0 binary_search unit"
    exit 1
fi

PROBLEM_NAME=$1
TEST_TYPE=${2:-sample}
WORKSPACE_ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
TEST_DIR="$WORKSPACE_ROOT/tests/${TEST_TYPE}_tests"

# Create test directory if it doesn't exist
mkdir -p "$TEST_DIR"

TEST_FILE="$TEST_DIR/${PROBLEM_NAME}_test.cpp"

if [ -f "$TEST_FILE" ]; then
    echo "Test file already exists: $TEST_FILE"
    echo "Do you want to overwrite it? (y/N)"
    read -r response
    if [[ ! "$response" =~ ^[Yy]$ ]]; then
        echo "Aborted."
        exit 1
    fi
fi

# Create the test file template
cat > "$TEST_FILE" << EOF
#include "../test_framework.h"

// TODO: Include the source file for $PROBLEM_NAME
// #include "../../path/to/${PROBLEM_NAME}.cpp"

TEST_CASE("${PROBLEM_NAME^} - Basic Test", test_${PROBLEM_NAME}_basic) {
    // TODO: Implement basic test case for $PROBLEM_NAME
    
    // Example:
    // Solution solution;
    // int result = solution.someFunction(input);
    // ASSERT_EQ(expected, result);
    
    ASSERT_TRUE(true); // Placeholder - remove this line
}

TEST_CASE("${PROBLEM_NAME^} - Edge Case", test_${PROBLEM_NAME}_edge_case) {
    // TODO: Test edge cases for $PROBLEM_NAME
    
    // Examples of edge cases to consider:
    // - Empty input
    // - Single element
    // - Maximum/minimum values
    // - Invalid input
    
    ASSERT_TRUE(true); // Placeholder - remove this line
}

TEST_CASE("${PROBLEM_NAME^} - Performance Test", test_${PROBLEM_NAME}_performance) {
    // TODO: Test with larger inputs if applicable
    
    // Example:
    // auto start = std::chrono::high_resolution_clock::now();
    // // Run your function with large input
    // auto end = std::chrono::high_resolution_clock::now();
    // auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    // ASSERT_LT(duration.count(), 1000); // Should complete within 1 second
    
    ASSERT_TRUE(true); // Placeholder - remove this line
}

// If testing I/O based problem, use this template:
/*
TEST_CASE("${PROBLEM_NAME^} - IO Test", test_${PROBLEM_NAME}_io) {
    std::string input = "sample input here\\n";
    std::string expected_output = "expected output here\\n";
    
    TestUtils::InputSimulator input_sim(input);
    TestUtils::OutputCapture output_cap;
    
    // TODO: Call your main function or the function that processes stdin/stdout
    // main(); // If testing main function
    
    std::string actual_output = output_cap.getOutput();
    ASSERT_EQ(expected_output, actual_output);
}
*/
EOF

echo "Created test file: $TEST_FILE"
echo ""
echo "Next steps:"
echo "1. Edit $TEST_FILE to include the correct source file"
echo "2. Implement the test cases"
echo "3. Run tests with: make test"
echo "4. Run specific test with: make test-'$PROBLEM_NAME'"

# If this is for a LeetCode problem, provide additional guidance
if [ -f "$WORKSPACE_ROOT/leetcode/${PROBLEM_NAME}.cpp" ]; then
    echo ""
    echo "Detected LeetCode problem. Update the include line to:"
    echo "#include \"../../leetcode/${PROBLEM_NAME}.cpp\""
elif [ -f "$WORKSPACE_ROOT/codeforces/${PROBLEM_NAME}.cpp" ]; then
    echo ""
    echo "Detected Codeforces problem. Update the include line to:"
    echo "#include \"../../codeforces/${PROBLEM_NAME}.cpp\""
elif [ -f "$WORKSPACE_ROOT/codechef/${PROBLEM_NAME}.cpp" ]; then
    echo ""
    echo "Detected CodeChef problem. Update the include line to:"
    echo "#include \"../../codechef/${PROBLEM_NAME}.cpp\""
fi
