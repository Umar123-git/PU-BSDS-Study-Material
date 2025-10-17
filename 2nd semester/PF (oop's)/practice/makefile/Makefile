
Captain:
	cls && (if not exist .OFiles mkdir .OFiles) && make exe && .\exe && make clean

#exe: *.o
#	g++ date.o CashMemo.o SaleLine.o main.o -o exe

#%.o: %.cpp
#	g++ -c $^

exe: .OFiles/date.o .OFiles/CashMemo.o .OFiles/SaleLine.o .OFiles/main.o
	g++ .OFiles/date.o .OFiles/CashMemo.o .OFiles/SaleLine.o .OFiles/main.o -o exe

.OFiles/date.o: date.cpp date.h
	g++ -c date.cpp -o .OFiles/date.o

.OFiles/CashMemo.o: CashMemo.cpp cashmemo.h SaleLine.h date.h
	g++ -c CashMemo.cpp -o .OFiles/CashMemo.o

.OFiles/SaleLine.o: SaleLine.cpp SaleLine.h
	g++ -c SaleLine.cpp -o .OFiles/SaleLine.o

.OFiles/main.o: main.cpp cashmemo.h
	g++ -c main.cpp -o .OFiles/main.o

	
clean:
	del .OFiles\date.o .OFiles\CashMemo.o .OFiles\SaleLine.o .OFiles\main.o exe.exe
	rmdir .OFiles