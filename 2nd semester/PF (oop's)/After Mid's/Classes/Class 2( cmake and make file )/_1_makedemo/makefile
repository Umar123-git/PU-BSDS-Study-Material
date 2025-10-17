# Compile everything using g++
# Compatible with MSYS2, MinGW, Linux
Captain:
	cls && make clean && make run && make clean

all: demo.exe

demo.exe: demo.o sorting.o searching.o
	g++ demo.o sorting.o searching.o -o demo.exe

demo.o: demo.cpp welcome.h sorting.h searching.h
	g++ -c demo.cpp -o demo.o

sorting.o: sorting.cpp sorting.h
	g++ -c sorting.cpp -o sorting.o

searching.o: searching.cpp searching.h
	g++ -c searching.cpp -o searching.o

clean:
	del *.o demo.exe
	
run: demo.exe
	./demo.exe
