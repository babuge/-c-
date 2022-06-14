CXX = clang++
SOURCE_CXX = main.cpp
SOURCE17_CXX = main17.cpp

TARGET = main

LDFLAGS_COMMON = -std=c++14

all:
	$(CXX) $(SOURCE_CXX) $(LDFLAGS_COMMON) -o $(TARGET)

other:
	$(CXX) $(SOURCE17_CXX) $(LDFLAGS_COMMON) -o $(TARGET)

clean:
	rm -rf *.o $(TARGET)
