CXX=g++
EXEC=main
OBJECTS=main.o utility_functions.o
SRC=main.cpp utility_functions.cpp
HEADERS=Parameters.hpp utility_functions.hpp

# Link the executable
$(EXEC) : $(OBJECTS)
	$(CXX) $^ -o $@

# Compile the source files into object files
main.o: main.cpp $(HEADERS)
	$(CXX) -c $< -o $@

utility_functions.o: utility_functions.cpp $(HEADERS)
	$(CXX) -c $< -o $@

# Clean rule to remove object files and the executable
clean:
	rm -f *.o $(EXEC)