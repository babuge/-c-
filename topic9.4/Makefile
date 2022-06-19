C = gcc
CXX = clang++ 
SOURCE_C = 
OBJECTS_C = 
        
SOURCE_CXX = main.cpp
        
TARGET = main
        
LDFLAGS_COMMON = -std=c++2a -lpthread -latomic
        
all:    
	$(CXX) $(SOURCE_CXX) $(LDFLAGS_COMMON)  -o $(TARGET)

.PHONY:clean
clean:
	-rm -vrf *.o $(TARGET)
