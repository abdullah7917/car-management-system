//Abdullah Ali Khan, khanab@pdx.edu, 5/8/2025, cs162-001
//Purpose of the code in this file
//Outline the specification for car using structs

#include <iostream>
#include <cctype>
#include <cstring>
#include <fstream>
using namespace std;

const int SIZE {21};

struct car
{
	char company [SIZE];
	char model [SIZE];
	int year;
	char fuel [SIZE];
	int price;
	int lease;
	int down;
	int warranty;
	char color [SIZE];
};

void read_car(car all_cars[], int & count);
void display(car & new_car);
void display_all(car all_cars[], int count);
void display_fuel(car all_cars[], int count);
void display_year(car all_cars[], int count);
int options();
void save_car(car & save_car);
