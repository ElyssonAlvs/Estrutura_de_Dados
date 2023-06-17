/*
Fazer um programa que leia o número de um funcionário, seu número de horas trabalhadas, o valor que recebe por
hora e calcula o salário desse funcionário. A seguir, mostre o número e o salário do funcionário, com duas casas
decimais.

Write a program that reads the number of an employee, the number of hours worked, the amount he receives for
hour and calculates the salary of that employee. Next, show the employee's number and salary, with two spaces
decimals.
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main(){

    cout << fixed << setprecision(2);

    int number_of_employee, time_of_working, money_for_work, salary;
    cout << "Write number of the employee :";
    cin >> number_of_employee;
    cout << "Time at work : ";
    cin >> time_of_working;
    cout << "Money for working hour : ";
    cin >> money_for_work;

    salary = money_for_work * time_of_working;

    cout << "Number : " << number_of_employee << endl;
    cout << "Salary : R$ " << salary;
}