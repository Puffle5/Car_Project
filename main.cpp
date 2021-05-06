#include <iostream>
#include <vector>
#include <regex>
#include <bits/stdc++.h>
using namespace std;

struct Car
{
    string brand;
    int year; /*integer data type*/
    double price; /*real data type*/
    string VIN;
    double fuel_cost;
    char color[10]; /*composite data type*/
};

/*Sum all car prices*/
double sumAllPrices(vector<Car> cars)
{
    double priceSum = 0;
    for (int i = 0; i < cars.size(); i++)
        {
            priceSum += cars[i].price;
        }
        return priceSum;

}

/*Calculate average price*/
double calculateAveragePrice(vector<Car> cars)
{
    return sumAllPrices(cars)/cars.size();
}

/*Display a single car*/
void displayCar(Car car)
{
    cout << "Brand: " + car.brand << endl
         << "Year: " + to_string(car.year) << endl
         << "Price: " << fixed << setprecision(2) << car.price << endl
         << "VIN: " + car.VIN << endl
         << "Fuel Cost: " << fixed << setprecision(2) << car.fuel_cost << endl
         << "Color: " +  string(car.color) << endl;
}

/*Display a list of cars*/
void displayCarList(vector<Car> cars)
{
    for (int i = 0; i < cars.size(); i++)
        {
            cout << "---------------" << endl;
            cout << "Car " + to_string(i + 1) + ":" << endl;
            displayCar(cars[i]);
            cout << "---------------" << endl;
        }
}

/*Search cars by year*/
vector<Car> searchCarsByYear(int year, vector<Car> cars)
{
    vector<Car> foundCars;
    for (int i = 0; i < cars.size(); i++)
        {
            if (cars[i].year == year){
                foundCars.push_back(cars[i]);
            }
        }
        return foundCars;
}

/*Search cars whose years is bigger || equal to the specified one*/
vector<Car> searchCarsByBiggerYear(int year, vector<Car> cars)
{
    vector<Car> foundCars;
    for (int i = 0; i < cars.size(); i++)
        {
            if (cars[i].year >= year){
                foundCars.push_back(cars[i]);
            }
        }
        return foundCars;
}

/*This function returns a single car because the VIN is a unique field*/
Car searchCarByVIN(string VIN, vector<Car> cars)
{
    Car foundCar;
    for (int i = 0; i < cars.size(); i++)
        {
            if (!VIN.compare(cars[i].VIN))
                {
                    foundCar = cars[i];
                }
        }
        return foundCar;
}

/*Search cars by brand*/
vector<Car> searchCarsByBrand(string brand, vector<Car> cars)
{
    vector<Car> foundCars;
    for (int i = 0; i < cars.size(); i++)
        {
            if (!brand.compare(cars[i].brand))
                {
                    foundCars.push_back(cars[i]);
                }
        }
        return foundCars;
}

/*Create a Car structure*/
Car createCar()
{
    Car car;
    cout << "Enter Brand: "; cin >> car.brand;
    cout << "Enter Year: "; cin >> car.year;
    cout << "Enter Price: "; cin >> car.price;
    cout << "Enter VIN: "; cin >> car.VIN;
    cout << "Enter Fuel Cost: "; cin >> car.fuel_cost;
    cout << "Enter Color: "; cin >> car.color;

    return car;
}

/*Helper function - compares brands*/
bool compareBrands(const Car &firstCar, const Car &secondCar) {return firstCar.brand < secondCar.brand;}

/*Sort cars by brand alphabetically*/
vector<Car> sortCarsByBrand(vector<Car> cars)
{
    sort(cars.begin(), cars.end(), compareBrands);
    return cars;
}

/*Helper function - compares fuel costs*/
bool compareFuelCosts(const Car &firstCar, const Car &secondCar) {return firstCar.fuel_cost < secondCar.fuel_cost;}

/*Sort cars by fuel cost in ascending order*/
vector<Car> sortCarsByFuelCost(vector<Car> cars)
{
    sort(cars.begin(), cars.end(), compareFuelCosts);
    return cars;
}

/*Find cars which do not have this color*/
vector<Car> findCarsByAbsentColour(char colour[], vector<Car> &cars)
{
    vector<Car> foundCars;
    for (int i = 0; i < cars.size(); i++)
        {
            if(strcmp(colour, cars[i].color) != 0)
                {
                    foundCars.push_back(cars[i]);
                }
        }
        return foundCars;
}

/*Delete a car by VIN*/
void deleteCarByVIN(vector<Car> &cars, string VIN) {
    cars.erase(
        remove_if(cars.begin(), cars.end(), [&](Car const &car)
                  {
                    return car.VIN == VIN;
        }),
        cars.end());
}

/*Change a car's price by VIN*/
void changeCarPriceByVIN(string VIN, double price, vector<Car> &cars)
{
    for (int i = 0; i < cars.size(); i++)
        {
            if (!VIN.compare(cars[i].VIN))
                {
                    cars[i].price = price;
                }
        }
}

/*Add cars to a list*/
vector<Car> createCarList(int count, vector<Car> &cars)
{
    for (int i = 0; i < count; i++)
        {
            cout << "---------------" << endl;
            cars.insert(cars.end(), createCar());
        }
    return cars;
}

int getInput()
{
    int option;
    cin >> option;
    return option;
}

void displayMainMenu()
{
    cout << "Please select an option:" << endl
         << "0: Exit the program." << endl
         << "1: Input." << endl
         << "2: Output." << endl
         << "---------------" << endl
         << "Chosen option: ";
}

void displayInputMenu()
{
    cout << "Welcome to Vicky's Car Service!" << endl
         << "Please select an option:" << endl
         << "0: Add (a) new car/s." << endl
         << "1: Delete a car by VIN." << endl
         << "2: Change car price." << endl
         << "---------------" << endl
         << "Chosen option: ";
}

void displayOutputMenu()
{
    cout << "Welcome to Vicky's Car Service!" << endl
         << "Please select an option:" << endl
         << "0: Display all cars." << endl
         << "1: Search cars by year." << endl
         << "2: Search car by VIN (Vehicle Identification Number)." << endl
         << "3: Search cars by brand." << endl
         << "4: Display all cars with a >= year." << endl
         << "5: Sum all car prices." << endl
         << "6: Sort cars alphabetically by brand." << endl
         << "7: Sort cars by fuel cost in ascending order." << endl
         << "8: Display average price." << endl
         << "9: Display all cars which are not a certain color." << endl
         << "---------------" << endl
         << "Chosen option: ";
}

void inputMenu(int option, vector<Car> cars)
{
    int count;
    string VIN;
    double price;
    switch(option)
    {
        case 0: system("cls");
                cout << "How many cars do you wish to add? " << endl;
                cout << "Answer: "; cin >> count;
                createCarList(count, cars);
                if (count != 0)
                {
                  cout << "Car/s added!" << endl;
                } else {
                    cout << "No cars added. Here's the list instead:" << endl;
                       }
                 cout << "---------------" << endl;
            displayCarList(cars);
            break;
        case 1: system("cls");
                displayCarList(cars);
                cout << "Enter VIN: "; cin >> VIN;
                deleteCarByVIN(cars, VIN);
                cout << "Car deleted!" << endl;
                cout << "---------------" << endl;
            displayCarList(cars);
            break;
        case 2: system("cls");
                displayCarList(cars);
                cout << "Enter VIN: "; cin >> VIN;
                cout << "Enter new price: "; cin >> price;
                changeCarPriceByVIN(VIN, price, cars);
                cout << "Price changed!" << endl;
                cout << "---------------" << endl;
                displayCar(searchCarByVIN(VIN, cars));
                break;
        default: cout << "Invalid option!" << endl; break;
    }
}

void outputMenu(int option, vector<Car> cars)
{
    string VIN;
    string brand;
    int year;
    char color[10];
    switch(option)
    {
        case 0: system("cls");
                displayCarList(cars); break;
        case 1: system("cls");
                cout << "Enter Year: "; cin >> year;
                displayCarList(searchCarsByYear(year, cars)); break;
        case 2: system("cls");
                cout << "Enter VIN: "; cin >> VIN;
                displayCar(searchCarByVIN(VIN, cars)); break;
        case 3: system("cls");
                cout << "Enter brand: "; cin >> brand;
                displayCarList(searchCarsByBrand(brand, cars)); break;
        case 4: system("cls");
                cout << "Enter year: "; cin >> year;
                displayCarList(searchCarsByBiggerYear(year, cars)); break;
        case 5: system("cls");
                cout << "Price Sum: " << fixed << setprecision(2) << sumAllPrices(cars); break;
        case 6: system("cls");
                displayCarList(sortCarsByBrand(cars)); break;
        case 7: system("cls");
                displayCarList(sortCarsByFuelCost(cars)); break;
        case 8: system("cls");
                cout << "Average Price: " << fixed << setprecision(2) << calculateAveragePrice(cars); break;
        case 9: system("cls");
                cout << "Enter color: "; cin >> color;
                displayCarList(findCarsByAbsentColour(color, cars)); break;
        default: cout << "Invalid option!" << endl; break;
    }
}

int main()
{
    /*Three default cars*/
    Car firstCar =
    {
        "Toyota",
        1998,
        3000,
        "5TENX22N66Z295894",
        100.00,
        "Gray"
    };
    Car secondCar =
    {
        "Toyota",
        1966,
        1000,
        "1N4AL11D26C238237",
        50.00,
        "Black"
    };
    Car thirdCar =
    {
        "Ferrari",
        2015,
        100000,
        "2CNDL23F166142776",
        140.00,
        "Red"
    };

   /*Empty car list*/
   vector<Car> cars;

   /*Add the three cars to the list*/
   cars.push_back(firstCar);
   cars.push_back(secondCar);
   cars.push_back(thirdCar);

   displayMainMenu();
   int mainOption = getInput();
   int inputOption;
   int outputOption;

   switch (mainOption)
     {
        case 0: return 0;
        case 1: system("cls");
                displayInputMenu();
                cin >> inputOption;
                inputMenu(inputOption, cars);
                break;
        case 2: system("cls");
                displayOutputMenu();
                cin >> outputOption;
                outputMenu(outputOption, cars);
                break;
       default: cout << "Invalid option!" << endl; return 0;
     }
    return 0;
}
