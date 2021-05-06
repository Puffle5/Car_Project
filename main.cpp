#include <iostream>
#include <cstring>

using namespace std;

struct Car {
    char brand[10];
    int year;
    double price;
    char VIN[17];
    double fuel_cost;
    char color[10];
};

void input(Car* cars, int n){
    for(int i = 0; i < n; i++)
        {
        cout << "Brand: "; cin >> cars[i].brand;
        cout << "Year: "; cin >> cars[i].year;
        cout << "Price: "; cin >> cars[i].price;
        cout <<"VIN (Vehicle Identification Number): "; cin >> cars[i].VIN;
        cout << "Fuel Cost: "; cin >> cars[i].fuel_cost;
        cout << "Color: "; cin >> cars[i].color;
    }
}

void outputCar(Car car)
{
        cout << endl;
        cout << "Brand: "; cout << car.brand << endl;
        cout << "Year: "; cout << car.year << endl;
        cout << "Price: "; cout << car.price << endl;
        cout << "VIN: "; cout << car.VIN << endl;
        cout << "Fuel Cost: "; cout << car.fuel_cost << endl;
        cout << "Color: "; cout << car.color << endl;
}

void output(Car* cars, int n)
{
    for(int i = 0; i < n; i++)
        {
            outputCar(cars[i]);
        }
}

void findCarsByYear(Car* cars, int n)
{
    int year;
    cout << "Enter year: "; cin >> year;
    for (int i = 0 ; i < n; i++){
        if(cars[i].year == year){
            outputCar(cars[i]);
        }
    }
}

void equalPrices(Car* cars, int n)
{
    for (int i = 0; i < n - 1; i++)
        {
            for (int j = i+1; j < n; j++)
            {
                if (cars[i].price == cars[j].price)
                {cout << i << " & " << j << "cars have equal prices." << endl;}
        }
    }

}

void equalFuelCosts(Car* cars, int n){

    for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (cars[i].fuel_cost == cars[j].fuel_cost)
                {cout << "Cars " << i << " & " << j << " have equal fuel costs." << endl;}
        }
    }

}

void equalField(Car* cars, int n)
{
    char field;
    cout << "Choose field - P (price) || C (fuel cost): "; cin >> field;
    if (field == 'P'){equalPrices(cars, n);}
    else if (field == 'C'){equalFuelCosts(cars, n);}
}

void findCarsByVIN(Car* cars, int n)
{
    char VIN[17];
    cin.ignore();
    cout << "Enter VIN: "; cin.getline(VIN, 17);
    for (int i = 0; i < n; i++)
        {
            if(!strcmp(VIN, cars[i].VIN))
            {
                outputCar(cars[i]);
            }
    }
}

void withBiggerYear(Car* cars, int n)
{
    int count = 0;
    int year;
    cout << "Enter year: "; cin >> year;
    for (int i = 0; i < n; i++)
        {
        if (cars[i].year > year) {count++;}
    }
    cout << "There are " << count << " cars with more recent years than " << year << "." << endl;
}

void sumPrices(Car* cars, int n)
{
    double sum = 0;
    for (int i = 0; i < n; i++)
        {
        sum += cars[i].price;
    }
    cout << "Price sum: " << sum << endl;
}

void sortCarsByBrand(Car* cars, int n)
{
    for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (strcmp(cars[i].brand, cars[j].brand) > 0)
                {
                Car temporary = cars[i];
                cars[i] = cars[j];
                cars[j] = temporary;
            }
        }
    }
}

void sortCarsByFuelCost(Car* cars, int n)
{
    for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if(cars[i].fuel_cost > cars[j].fuel_cost)
                {
                Car temporary = cars[i];
                cars[i] = cars[j];
                cars[j] = temporary;
            }
        }
    }
}

Car* addCar(Car* cars, int n)
{
    Car* temporary = new Car[n + 1];
    for (int i = 0; i < n; i++) {temporary[i] = cars[i];}
    cout << "Brand: "; cin >> temporary[n].brand;
    cout << "Year: "; cin >> temporary[n].year;
    cout << "Price: "; cin >> temporary[n].price;
    cout << "VIN: "; cin >> temporary[n].VIN;
    cout << "Fuel Cost: "; cin >> temporary[n].fuel_cost;
    cout << "Color: "; cin >> temporary[n].color;
    return temporary;
}

Car* deleteCar(Car* cars, int n)
{
    int number;
    cout << "Enter number of car: "; cin >> number;
    Car* temporary = new Car[n - 1];
    bool found = false;
    for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (j == number) {found = true;}
            if (!found)
            {
                if (i == j) {temporary[i]=cars[j];}
            } else {
                if (i + 1 == j) {temporary[i]=cars[j];}
            }
        }
    }
    return temporary;
}

void findHighestPrice(Car* cars, int n)
{
    double price = cars[0].price;
    for (int i = 0; i < n; i++)
        {
            if (price < cars[i].price){price = cars[i].price;}
    }
    cout << "Highest price: " << price << endl;
}

void changeColor(Car* cars)
{
    int number;
    cout << "Enter car number: "; cin >> number;
    cout << "New color: "; cin >> cars[number - 1].color;
}

int main ()
{
    Car* cars;
    int option, n;
    cout << "Choose an option (0/1): "; cin >> option;
    while (option != 0 && option != 1)
        {
        cout <<"Choose 0 || 1!" << endl;
        cout << "Choose an option: "; cin >> option;
    }

    if (option == 0) {return 0;}
    cout << "Car count: "; cin >> n;
    cars = new Car[n];
    input(cars, n);
    while (true)
        {
        cout << "Choose an option: "; cin >> option;
        switch(option)
        {
            case 0: return 0; break;
            case 1: input(cars, n); break;
            case 2: output(cars, n); break;
            case 3: findHighestPrice(cars, n); break;
            case 4: findCarsByYear(cars, n); break;
            case 5: equalField(cars, n); break;
            case 6: findCarsByVIN(cars, n); break;
            case 7: withBiggerYear(cars, n); break;
            case 8: sumPrices(cars, n); break;
            case 9: sortCarsByBrand(cars, n); break;
            case 10: sortCarsByFuelCost(cars, n); break;
            case 11: cars = addCar(cars, n);
                     n++;
                     break;
            case 12: cars = deleteCar(cars, n);
                     n--;
                     break;
            case 13: changeColor(cars); break;
            default: cout << "Invalid option!" << endl; break;
        }
    }
    return 0;
}
