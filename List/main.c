#include<stdio.h>
#include<stdlib.h>
#include "Employee.h"

int main(){
List empList;

initList(&empList);
displayEmployeeList(empList);
printf("\n\n");

addEmployee(&empList, newEmployee(1001, "Maria Dela Cruz", "female", 40.0f));
addEmployee(&empList, newEmployee(1020, "Nouffa Ali", "female", 40.0f));
addEmployee(&empList, newEmployee(1045, "Jolo Tangpuz", "male", 40.0f));

displayEmployeeList(empList);
printf("\n\n");
List femaleEmployees = getFemaleEmployees(empList);
  displayEmployeeList(femaleEmployees);





return 0;
}
