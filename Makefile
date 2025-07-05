# Makefile for C++ E-commerce System
# Fawry Quantum Internship Challenge 3
# Author: Abdelhamid Khald

CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -Wpedantic -O2
TARGET = ecommerce
SOURCE = ecommerce_system.cpp
OBJECT = $(SOURCE:.cpp=.o)

# Default target
all: $(TARGET)

# Build the executable
$(TARGET): $(SOURCE)
	@echo "Compiling $(SOURCE)..."
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SOURCE)
	@echo "Build completed successfully!"
	@echo "Run with: make run"

# Compile object file (for future modular builds)
$(OBJECT): $(SOURCE)
	$(CXX) $(CXXFLAGS) -c $(SOURCE)

# Clean build artifacts
clean:
	@echo "Cleaning build artifacts..."
	rm -f $(TARGET) $(OBJECT)
	@echo "Clean completed!"

# Run the program
run: $(TARGET)
	@echo "Running E-commerce System..."
	@echo "=========================="
	./$(TARGET)

# Debug build
debug: CXXFLAGS += -g -DDEBUG
debug: $(TARGET)
	@echo "Debug build completed!"

# Release build
release: CXXFLAGS += -DNDEBUG
release: $(TARGET)
	@echo "Release build completed!"

# Check for memory leaks (requires valgrind)
memcheck: $(TARGET)
	valgrind --leak-check=full --show-leak-kinds=all ./$(TARGET)

# Display help
help:
	@echo "Available targets:"
	@echo "  all       - Build the executable (default)"
	@echo "  clean     - Remove build artifacts"
	@echo "  run       - Build and run the program"
	@echo "  debug     - Build with debug flags"
	@echo "  release   - Build optimized release version"
	@echo "  memcheck  - Run with valgrind memory checker"
	@echo "  help      - Show this help message"

.PHONY: all clean run debug release memcheck help