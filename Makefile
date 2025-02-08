CXX = g++
CXXFLAGS = -std=c++20 -march=native -O3 -flto -ffinite-math-only -fassociative-math -ffast-math -funroll-loops -ftree-vectorize
LDFLAGS = -flto

SRC = main.cpp trig_tester.cpp
OBJ = $(SRC:.cpp=.o)
EXEC = main

# Include dependencies for header files
DEP = $(SRC:.cpp=.d)

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(LDFLAGS) -o $@ $^

# Define how to build .o files from .cpp files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@ -MMD -MP

# Include the dependencies
-include $(DEP)

clean:
	rm -f $(OBJ) $(EXEC) $(DEP)
