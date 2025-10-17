
#include "Payroll.h"
#include<iostream>
#include<string>

int main() {

	Payroll p;
	p.loadEmployees();
	p.printSalaries();

    return 0;
}