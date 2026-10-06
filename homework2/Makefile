# References: https://www.geeksforgeeks.org/cpp/makefile-in-c-and-its-applications/

# Compilers and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2

# Outputs
TARGETS = async-min-max.out vec-sum.out vec-mult.out

# Default is to build everything
all: $(TARGETS)

# Rule to compile .cpp files into any .out 
%.out: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

# Clean rule to remove generated files
clean:
	rm -f $(TARGET)

.PHONY: all clean
