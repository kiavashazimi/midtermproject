CXX = g++
CXXFLAGS = -std=c++17 -Wall -c
LXXFLAGS = -std=c++17
OBJECTS = main.o  maze.o

TARGET = main
$(TARGET): $(OBJECTS)
	$(CXX) $(LXXFLAGS) $(OBJECTS) -o $(TARGET)

main.o : main.cpp  maze.h 
	$(CXX) $(CXXFLAGS) main.cpp

maze.o : maze.cpp
	$(CXX) $(CXXFLAGS) maze.cpp


clean:
	rm -fv $(TARGET) $(OBJECTS)
