CXX = g++
CXXFLAGS = -std=c++11
calculator: main.cpp
	$(CXX) $(CXXFLAGS) -o calculator main.cpp
.PHONY: clean
clean:
	rm -f calculator
