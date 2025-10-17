Captain:
	cls && make all && exe && make clean

all: run.exe

exe: main.obj tmp.obj
	g++ main.obj tmp.obj -o run.exe

main.obj: main.cpp
	g++ -c main.cpp -o main.obj

tmp.obj: tmp.cpp
	g++ -c tmp.cpp -o tmp.obj

clean:
	del *.exe
	del *.obj