CXX = g++
CXXFLAGS = -Wall
IODIR =../../proj5_IO

proj5: proj5.cpp Bar.o LL.cpp
        $(CXX) $(CXXFLAGS) proj5.cpp Bar.o LL.cpp -o proj5

Bar.o: Bar.h Bar.cpp LL.cpp
        $(CXX) $(CXXFLAGS) -c Bar.cpp

LL_test: LL.cpp LL_test.cpp
        $(CXX) $(CXXFLAGS) LL.cpp LL_test.cpp -o LL_test

valLL:
        valgrind ./LL_test

clean:
        rm *.o
        rm *~

run1:
        ./proj5 proj5_test1.txt

run2:
        ./proj5 proj5_test2.txt

val1:
        valgrind ./proj5 proj5_test1.txt

val2:
        valgrind ./proj5 proj5_test2.txt
