
CXX?=clang++
#CXX?=g++
CXXFLAGS=-std=c++11 -O3

HEADERS = testfunction.h
OBJECTS = main.o testfunction.o
TARGET=main

all: $(TARGET)

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm $(TARGET) $(OBJECTS)
