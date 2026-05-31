# Compiler and flags
CXX      = g++
CXXFLAGS = -O2 $(shell wx-config --cxxflags)
LIBS     = $(shell wx-config --libs) -llgpio

# Target and source
TARGET   = wxBaseTemplateRev3
SRC      = wxBaseTemplateRev3.cpp

# Default target - build and run
all: $(TARGET)
	./$(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) $(LIBS) -o $(TARGET)

# Run the program
run: $(TARGET)
	./$(TARGET)

# Clean build artifacts
clean:
	rm -f $(TARGET)

.PHONY: all clean run