all: testcolor
testcolor: main.o functions.o
	g++ main.o functions.o -o testcolor
main.o: main.cpp
	g++ -c main.cpp
functions.o: functions.cpp
	g++ -c functions.cpp
clean:
	rm -rf *.o testcolor
