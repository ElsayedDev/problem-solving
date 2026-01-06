# Compiler settings
CXX = g++
CXXFLAGS = -std=c++14 -Wall -Wextra -O2 -g
INCLUDES = -I./tests -I./leetcode

# Directories
TEST_DIR = tests
BUILD_DIR = build
SRC_DIRS = leetcode acpc_preperation codechef codeforces interviews_perperation learning

# Find all test files
TEST_SOURCES = $(shell find $(TEST_DIR) -name "*_test.cpp")

# Main test runner
TEST_RUNNER = $(BUILD_DIR)/test_runner
TEST_RUNNER_SRC = $(TEST_DIR)/test_runner.cpp
ALL_TESTS_FILE = $(BUILD_DIR)/all_tests.cpp

# Default target
.PHONY: all clean test help setup

all: test

# Create build directory structure
$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)
	@mkdir -p $(BUILD_DIR)/$(TEST_DIR)/unit_tests
	@mkdir -p $(BUILD_DIR)/$(TEST_DIR)/sample_tests

# Generate a single file that includes all test files
$(ALL_TESTS_FILE): $(TEST_SOURCES) | $(BUILD_DIR)
	@echo "// Auto-generated file that includes all tests" > $@
	@echo "#include \"test_framework.h\"" >> $@
	@for test_file in $(TEST_SOURCES); do \
		echo "#include \"../$$test_file\"" >> $@; \
	done

# Build test runner
$(TEST_RUNNER): $(TEST_RUNNER_SRC) $(ALL_TESTS_FILE) | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(TEST_RUNNER_SRC) $(ALL_TESTS_FILE) -o $@

# Run all tests
test: $(TEST_RUNNER)
	@echo "Running all tests..."
	./$(TEST_RUNNER) -v

# Run specific test
test-%: $(TEST_RUNNER)
	@echo "Running test: $*"
	./$(TEST_RUNNER) -v "$*"

# Clean build files
clean:
	rm -rf $(BUILD_DIR)

# Setup test environment
setup:
	@echo "Setting up test environment..."
	@mkdir -p $(TEST_DIR)/sample_tests
	@mkdir -p $(TEST_DIR)/unit_tests
	@mkdir -p $(TEST_DIR)/integration_tests
	@echo "Test environment setup complete!"

# Help target
help:
	@echo "Available targets:"
	@echo "  all       - Build and run all tests (default)"
	@echo "  test      - Run all tests"
	@echo "  test-NAME - Run specific test by name"
	@echo "  clean     - Clean build files"
	@echo "  setup     - Setup test environment"
	@echo "  help      - Show this help message"
	@echo ""
	@echo "Examples:"
	@echo "  make test                    # Run all tests"
	@echo "  make test-'TreeNode Creation' # Run specific test"
	@echo "  make clean                   # Clean build files"

# Individual problem testing (examples)
.PHONY: test-leetcode test-codeforces test-codechef

# Test specific categories
test-leetcode: $(TEST_RUNNER)
	@echo "Running LeetCode tests..."
	./$(TEST_RUNNER) -v | grep -i leetcode || true

test-codeforces: $(TEST_RUNNER)
	@echo "Running Codeforces tests..."
	./$(TEST_RUNNER) -v | grep -i codeforces || true

test-codechef: $(TEST_RUNNER)
	@echo "Running CodeChef tests..."
	./$(TEST_RUNNER) -v | grep -i codechef || true

# Build individual executables for testing
LEETCODE_SOURCES = $(wildcard leetcode/*.cpp)
CODEFORCES_SOURCES = $(wildcard codeforces/*.cpp)

# Example: build a specific problem for testing
build-problem-%:
	@if [ -f "leetcode/$*.cpp" ]; then \
		echo "Building LeetCode problem: $*"; \
		$(CXX) $(CXXFLAGS) $(INCLUDES) leetcode/$*.cpp -o $(BUILD_DIR)/$*; \
	elif [ -f "codeforces/$*.cpp" ]; then \
		echo "Building Codeforces problem: $*"; \
		$(CXX) $(CXXFLAGS) $(INCLUDES) codeforces/$*.cpp -o $(BUILD_DIR)/$*; \
	elif [ -f "codechef/$*.cpp" ]; then \
		echo "Building CodeChef problem: $*"; \
		$(CXX) $(CXXFLAGS) $(INCLUDES) codechef/$*.cpp -o $(BUILD_DIR)/$*; \
	else \
		echo "Problem $* not found in any directory"; \
		exit 1; \
	fi

# Test with sample input/output files
test-with-files-%:
	@if [ -f "$(BUILD_DIR)/$*" ] && [ -f "input.txt" ] && [ -f "output.txt" ]; then \
		echo "Testing $* with input.txt and output.txt"; \
		./$(BUILD_DIR)/$* < input.txt > $(BUILD_DIR)/$*_actual_output.txt; \
		if diff -q output.txt $(BUILD_DIR)/$*_actual_output.txt > /dev/null; then \
			echo "✓ Test passed for $*"; \
		else \
			echo "✗ Test failed for $*"; \
			echo "Expected output:"; \
			cat output.txt; \
			echo "Actual output:"; \
			cat $(BUILD_DIR)/$*_actual_output.txt; \
		fi; \
	else \
		echo "Missing files for testing $*. Need: $(BUILD_DIR)/$*, input.txt, output.txt"; \
	fi
