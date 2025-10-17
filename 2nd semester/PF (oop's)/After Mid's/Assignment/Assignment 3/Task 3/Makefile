Captain:
	cls && (if not exist .OFiles mkdir .oFiles) && make exe && .\exe && make clean

exe: .oFiles/daily_wager.o .oFiles/employee.o  .oFiles/officer.o .oFiles/Payroll.o .oFiles/main.o 
	g++ .oFiles/daily_wager.o .oFiles/employee.o  .oFiles/officer.o .oFiles/Payroll.o .oFiles/main.o -o exe
	
.oFiles/daily_wager.o: daily_wager.cpp employee.h
	g++ -c daily_wager.cpp -o .oFiles/daily_wager.o

.oFiles/employee.o: employee.cpp daily_wager.h
	g++ -c employee.cpp -o .oFiles/employee.o

.oFiles/officer.o:employee.h daily_wager.h officer.cpp
	g++ -c officer.cpp -o .oFiles/officer.o

.oFiles/Payroll.o:employee.h daily_wager.h Payroll.cpp
	g++ -c Payroll.cpp -o .oFiles/Payroll.o

.oFiles/main.o:Payroll.h main.cpp
	g++ -c main.cpp -o .oFiles/main.o



clean:
	del .oFiles\daily_wager.o  .oFiles\employee.o  .oFiles\officer.o .oFiles\Payroll.o .oFiles\main.o  exe.exe
	rmdir .oFiles