#include <iostream>

using namespace std;

struct CarSpecs {
    string engine;
    string color;
    int ownersCount;
};

struct Car {
    string brand;
    string model;
    int year;
    double price;
    bool canBargain;
    CarSpecs specs;
};

void printTable(Car cars[], int size);

int main() {
    const int SIZE = 2;
    Car market[SIZE] = {
        {"Toyota", "Camry", 2020, 25000, true, {"2.5L", "Black", 1}},
        {"Ford", "Focus", 2015, 9500, false, {"1.6L", "White", 3}}
    };

    printTable(market, SIZE);

    return 0;
}

void printTable(Car cars[], int size) {
    cout << "Brand\tModel\tYear\tPrice\tTorg\tEngine\tColor\tOwners" << endl;
    cout << "----------------------------------------------------------------" << endl;

    for (int i = 0; i < size; i++) {
        cout << cars[i].brand << "\t"
            << cars[i].model << "\t"
            << cars[i].year << "\t"
            << cars[i].price << "\t"
            << (cars[i].canBargain ? "Yes" : "No") << "\t"
            << cars[i].specs.engine << "\t"
            << cars[i].specs.color << "\t"
            << cars[i].specs.ownersCount << endl;
    }
}