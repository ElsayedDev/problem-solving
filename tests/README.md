# Testing Framework for Competitive Programming

This directory contains the testing framework for the problem-solving workspace.

## Structure

- `test_runner.cpp` - Main test runner that can execute tests for different problems
- `test_framework.h` - Header file with testing utilities and macros
- `sample_tests/` - Directory containing sample test cases for problems
- `unit_tests/` - Directory for unit tests of utility functions
- `integration_tests/` - Directory for integration tests

## Usage

### Running Tests

```bash
# Compile and run all tests
make test

# Run tests for a specific problem
./test_runner <problem_name>

# Run with verbose output
./test_runner <problem_name> -v
```

### Adding New Tests

1. Create a test file in the appropriate directory
2. Use the provided testing macros
3. Register the test in the test runner

### Testing Macros

- `ASSERT_EQ(expected, actual)` - Assert equality
- `ASSERT_TRUE(condition)` - Assert condition is true
- `ASSERT_FALSE(condition)` - Assert condition is false
- `TEST_CASE(name, function)` - Define a test case
- `RUN_TESTS()` - Execute all registered tests

## Examples

See the sample tests for examples of how to test competitive programming solutions.
