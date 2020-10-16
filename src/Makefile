CXX      := g++
WARNINGS = -pedantic -Wall -Wfatal-errors -Wextra
CXXFLAGS := -std=c++14 -O0 $(WARNINGS) -g -c

TARGET   := followMe
OBJ      := main.o ClipList.o Clip.o
DEPS     := Clip.h ClipList.h 

$(TARGET) : $(OBJ)
	$(CXX) $(CXXFLAG) -o $(TARGET) $(OBJ)

%.o : %.cpp $(DEPS)
	$(CXX) $(CXXFLAG) -c -o $@ $< 

.PHONY: clean

ifeq ($(OS),Windows_NT)
clean :
	del $(TARGET).exe $(OBJ)
else
clean :
	rm $(TARGET) $(OBJ)
	
endif
