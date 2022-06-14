C = gcc
CXX = clang++
SOURCE_C = 
OBJECTS_C = 
	
SOURCE_CXX = main.cpp
	
TARGET = main
	
LDFLAGS_COMMON = -std=c++14  #c++2a ubuntu支持14
	
all:
	# $(C) -c $(SOURCE_C)
	$(CXX) $(SOURCE_CXX) $(LDFLAGS_COMMON)  -o $(TARGET)
		
clean:
	rm -rf *.o $(TARGET)
