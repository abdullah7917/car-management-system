//Abdullah Ali Khan, khanab@pdx.edu, 5/8/2025
//Purpose of the code in this file
//it will have the main fuctions
#include "cars.h"

using namespace std;

int main ()
{

	int choice = 0;
	car all_cars[15];
	
	int count = 0;
//	display(my_car);

	
	while(choice < 5)
	{
		choice = options();

		if (choice == 1)
		{
			read_car(all_cars, count);

		}
		else if(choice == 2)
		{
			display_all(all_cars, count);


		}
		else if (choice == 3)
		{
			display_fuel(all_cars, count);
		}
		else if (choice == 4)
		{
			display_year(all_cars, count);
		}
		else
		{
			cout <<"bye"<<endl;
		}

	}

	for (int i = 0; i < count; ++i)
    	{
        	save_car(all_cars[i]);
   	}	

	return 0;
}

void read_car(car all_cars[], int & count)
{
	cout<<" Enter car company: "<<endl;
	cin.get(all_cars[count].company,SIZE,'\n');
	cin.ignore(100,'\n');

	cout<<" Enter car model: "<<endl;
        cin.get(all_cars[count].model,SIZE,'\n');
        cin.ignore(100,'\n');

	cout<<" Enter Year: "<<endl;
        cin>>all_cars[count].year;
        cin.ignore(100,'\n');

	cout<<" Enter fuel type (gas or EV): "<<endl;
        cin.get(all_cars[count].fuel,SIZE,'\n');
        cin.ignore(100,'\n');

	cout<<" Enter price: "<<endl;
        cin>>all_cars[count].price;
        cin.ignore(100,'\n');

	cout<<" Enter lease Amount: "<<endl;
        cin>>all_cars[count].lease;
        cin.ignore(100,'\n');

	cout<<" Enter Down Payment Amount: "<<endl;
        cin>>all_cars[count].down;
        cin.ignore(100,'\n');

	cout<<" Enter car color: "<<endl;
        cin.get(all_cars[count].color,SIZE,'\n');
        cin.ignore(100,'\n');
	
	++count;
}

void display(car & new_car)
{
    cout << "Company: " << new_car.company
         << " | Model: " << new_car.model
         << " | Year: " << new_car.year
         << " | Fuel Type: " << new_car.fuel
         << " | Price: " << new_car.price
         << " | Lease: " << new_car.lease
         << " | Down: " << new_car.down
         << " | Warranty: " << new_car.warranty
         << " | Color: " << new_car.color << endl;
}

void display_all(car all_cars[], int count)
{
    for (int i = 0; i < count; ++i)
    {
        display(all_cars[i]); 
    }
}


void display_fuel(car all_cars[], int count)
{
	int response;

	cout << "\nWhich fuel type are you looking for:"
	     << "\n1. EV"
     	     << "\n2. Gas" << endl;
	cin>>response;
	cin.ignore(100,'\n');

	for (int i = 0; i < count; ++i)
	{
		if ( response == 1 && strcmp(all_cars[i].fuel,"EV")==0)
			{
				display(all_cars[i]);
			}
		else if ( response == 2 && strcmp(all_cars[i].fuel,"gas")==0)
			{
				display(all_cars[i]);
			}
		else 
			{
			cout <<"No car of the fuel type"<<endl;
			}
	}


}

void display_year(car all_cars[], int count)
{
	int year;
	bool found = false;

	cout << "\nWhich year are you looking for: "<<endl;
	cin>>year;

	for (int i = 0; i < count; ++i)
	{
		if (year == all_cars[i].year)
		{
			display(all_cars[i]);
			found = true;
		}
	if (found == false)
		{	
			 cout << "No cars found from year " << year << "." << endl;
		}		
	}	
}

int options()
{
	int choice ;
	cout << "\n1. Read in a new car"
             << "\n2. Display all cars"
             << "\n3. Display cars by fuel type"
             << "\n4. Search by year"
             << "\n5. Quit" << endl;
	
	cin >> choice;
	cin.ignore(100, '\n');

	return choice; 
}
void save_car(car & new_car)
{
    ofstream file_out("cars.txt", ios::app);
    if (file_out)
    {
        file_out << new_car.company << "|"
                 << new_car.model << "|"
                 << new_car.year << "|"
                 << new_car.fuel << "|"
                 << new_car.price << "|"
                 << new_car.lease << "|"
                 << new_car.down << "|"
		 << new_car.warranty << "|"
                 << new_car.color << endl;
        file_out.close();
    }
}
