# Testing Setup Guide

This guide will help you understand and use the comprehensive testing framework set up for your competitive programming workspace.

## 🚀 Quick Start

### 1. Run All Tests
```bash
make test
```

### 2. Run Tests Through VS Code
- Press `Cmd+Shift+P` (macOS) or `Ctrl+Shift+P` (Windows/Linux)
- Type "Tasks: Run Task"
- Select "Run All Tests"

### 3. Create a New Test
```bash
./create_test.sh my_problem_name sample
```

## 📁 Project Structure

```
/Users/elsayeddev/Documents/GitHub/problem-solving/
├── tests/                          # Main testing directory
│   ├── test_framework.h           # Testing framework header
│   ├── test_runner.cpp            # Main test runner
│   ├── sample_tests/              # Sample problem tests
│   │   ├── come_back_test.cpp     # Example test for come_back.cpp
│   │   ├── example_test.cpp       # General testing examples
│   │   └── test_data_format.md    # Guide for test data format
│   └── unit_tests/                # Unit tests for common utilities
│       └── common_test.cpp        # Tests for common.h utilities
├── Makefile                       # Build and test automation
├── create_test.sh                 # Script to create new tests
└── .vscode/tasks.json             # VS Code tasks configuration
```

## 🧪 Testing Framework Features

### Assertion Macros
- `ASSERT_EQ(expected, actual)` - Assert equality
- `ASSERT_NE(expected, actual)` - Assert not equal
- `ASSERT_TRUE(condition)` - Assert condition is true
- `ASSERT_FALSE(condition)` - Assert condition is false
- `ASSERT_LT(a, b)` - Assert a < b
- `ASSERT_LE(a, b)` - Assert a <= b
- `ASSERT_GT(a, b)` - Assert a > b
- `ASSERT_GE(a, b)` - Assert a >= b
- `ASSERT_VEC_EQ(expected, actual)` - Assert vector equality

### Test Definition
```cpp
TEST_CASE("Test Name", test_function_name) {
    // Your test code here
    ASSERT_EQ(expected_value, actual_value);
}
```

### Input/Output Testing
```cpp
TEST_CASE("IO Test", test_io) {
    std::string input = "5\n1 2 3 4 5\n";
    std::string expected_output = "1 2 3 4 5\n";
    
    TestUtils::InputSimulator input_sim(input);
    TestUtils::OutputCapture output_cap;
    
    // Call your main function or solution
    main();
    
    std::string actual_output = output_cap.getOutput();
    ASSERT_EQ(expected_output, actual_output);
}
```

## 🛠 Available Make Commands

| Command | Description |
|---------|-------------|
| `make test` | Run all tests with verbose output |
| `make clean` | Clean all build files |
| `make setup` | Setup test environment |
| `make test-leetcode` | Run tests for LeetCode problems |
| `make test-codeforces` | Run tests for Codeforces problems |
| `make test-codechef` | Run tests for CodeChef problems |
| `make build-problem-NAME` | Build a specific problem executable |
| `make test-with-files-NAME` | Test with input.txt and output.txt |

## 📋 VS Code Tasks

Access these through `Cmd+Shift+P` > "Tasks: Run Task":

- **Run All Tests** - Execute all tests
- **Setup Test Environment** - Initialize testing directories
- **Clean Test Build** - Remove build files
- **Test LeetCode Problems** - Run LeetCode-specific tests
- **Test Codeforces Problems** - Run Codeforces-specific tests
- **Test CodeChef Problems** - Run CodeChef-specific tests

## 📝 Creating Tests

### Method 1: Using the Script
```bash
./create_test.sh problem_name [test_type]
```

Example:
```bash
./create_test.sh two_sum sample
./create_test.sh binary_search unit
```

### Method 2: Manual Creation
1. Create a new `.cpp` file in the appropriate test directory
2. Include the test framework: `#include "../test_framework.h"`
3. Include your solution file: `#include "../../path/to/solution.cpp"`
4. Write test cases using `TEST_CASE` macro

## 🎯 Testing Different Problem Types

### LeetCode Problems
```cpp
#include "../test_framework.h"
#include "../../leetcode/solution.cpp"

TEST_CASE("LeetCode Problem", test_leetcode_problem) {
    Solution solution;
    vector<int> input = {1, 2, 3};
    vector<int> expected = {3, 2, 1};
    vector<int> result = solution.reverse(input);
    ASSERT_VEC_EQ(expected, result);
}
```

### Competitive Programming Problems (stdin/stdout)
```cpp
TEST_CASE("CP Problem", test_cp_problem) {
    std::string input = "3\n1 2 3\n";
    std::string expected_output = "6\n";
    
    TestUtils::InputSimulator input_sim(input);
    TestUtils::OutputCapture output_cap;
    
    main(); // Your main function
    
    std::string actual_output = output_cap.getOutput();
    ASSERT_EQ(expected_output, actual_output);
}
```

### File-Based Testing
Create test data files with this format:
```
input_data
---
expected_output
```

Then use:
```cpp
TEST_CASE("File Test", test_file) {
    auto [input, output] = TestUtils::readTestCase("path/to/test_data.txt");
    // Use input and output for testing
}
```

## 🔧 Customization

### Adding New Test Categories
1. Create a new directory under `tests/`
2. Add corresponding Make targets in `Makefile`
3. Add VS Code tasks in `.vscode/tasks.json`

### Modifying Test Framework
Edit `tests/test_framework.h` to add new assertion macros or utilities.

### Performance Testing
```cpp
TEST_CASE("Performance Test", test_performance) {
    auto start = std::chrono::high_resolution_clock::now();
    
    // Your code to test
    heavy_computation();
    
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    
    ASSERT_LT(duration.count(), 1000); // Should complete within 1 second
}
```

## 🐛 Troubleshooting

### Common Issues

1. **Compilation Errors**
   - Check that all included files exist
   - Verify C++14 compatibility
   - Ensure proper header guards

2. **Test Failures**
   - Use verbose mode: `make test` (already verbose by default)
   - Check assertion messages for details
   - Verify expected vs actual output

3. **Missing Files**
   - Run `make setup` to create necessary directories
   - Check file paths in include statements

### Debug Mode
Run tests with additional debugging:
```bash
./build/test_runner -v
```

## 🎉 Examples

The framework includes several example tests:

1. **`tests/unit_tests/common_test.cpp`** - Tests for common data structures
2. **`tests/sample_tests/come_back_test.cpp`** - Tests for the come_back.cpp solution
3. **`tests/sample_tests/example_test.cpp`** - General testing examples

Study these files to understand best practices for testing different types of problems.

## 📚 Next Steps

1. **Run the existing tests** to make sure everything works
2. **Create tests for your existing solutions** using the provided script
3. **Adopt test-driven development** for new problems
4. **Extend the framework** as needed for your specific requirements

Happy testing! 🧪✨
