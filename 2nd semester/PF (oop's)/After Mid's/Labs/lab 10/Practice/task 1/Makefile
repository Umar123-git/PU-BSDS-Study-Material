Captain:
	cls && make run && run && make clean

run: main.o student.o student.h
	g++ main.o student.o -o run.exe



main.o: main.cpp student.h
	g++ -c main.cpp -o main.o

student.o: student.cpp
	g++ -c student.cpp -o student.o

clean:
	del *.o *.exe