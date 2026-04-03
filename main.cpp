// COMSC-210 | Lab 23 | Christine Susic

#include <iostream>
#include <fstream>
#include <iomanip>
#include <list>
#include "Goat.h"
using namespace std;

const int SZ_NAMES = 200, SZ_COLORS = 25, MAX_AGE = 20;

int main_menu();
int select_goat(list<Goat> trip);
void add_goat(list<Goat> &trip, string [], string []);
void delete_goat(list<Goat> &trip);
void display_trip(list<Goat> trip);

int main() {
    srand(time(0));
    bool again;

    // read & populate arrays for names and colors
    ifstream fin("names.txt");
    string names[SZ_NAMES];
    int i = 0;
    while (fin >> names[i++]);
    fin.close();
    ifstream fin1("colors.txt");
    string colors[SZ_COLORS];
    i = 0;
    while (fin1 >> colors[i++]);
    fin1.close();
    
    //create a list of Goat objects
    list<Goat> trip;
    
    //create three Goat objects and put them into the list
    for (int i = 0; i < 3; i++) {
        //put random names, ages, and colors for each of them
        Goat tmp(names[rand() % SZ_NAMES], rand() % 20 + 1, colors[rand() % SZ_COLORS]);
        trip.push_back(tmp);
    }

    //main_menu();
    select_goat(trip);
    //add_goat(list<Goat> &trip, string [], string []);
    //delete_goat(list<Goat> &trip);
    //display_trip(trip);

    return 0;
}

int main_menu() {
    //output menu
    int choice1;
    for (int i = 0; i < 2; i++) {
        cout << "*** GOAT MANAGER 3001 ***" << endl;
        cout << "[1] Add a goat" << endl;
        cout << "[2] Delete a goat" << endl;
        cout << "[3] List goats" << endl;
        cout << "[4] Quit" << endl;
        cout << "Choice --> ";
        //input choice
        cin >> choice1;
        //input validation
        while (choice1 < 1 or choice1 > 4 or cin.fail()) {
            if (cin.fail()) {
                cin.clear(); //clears the cin.fail flag
                cin.ignore(1000, '\n'); //clears the buffer of the bad char+endl
            }
            cout << "ERROR. Please enter 1-4. ";
            cin >> choice1;
        }
    }
    return choice1;
}

int select_goat(list<Goat> trip) {
    int choice2;
    //output the goat names list
    for (auto val : trip) {
    cout << val.get_name();
    cout << " (" << val.get_age() << ", ";
    cout << val.get_color() << ")" << endl;
    }
    //select goat number
    cout << "Choice --> ";
    //input choice
    cin >> choice2;
    //input validation
    while (choice2 < 1 or choice2 > 8 or cin.fail()) {
        if (cin.fail()) {
            cin.clear(); //clears the cin.fail flag
            cin.ignore(1000, '\n'); //clears the buffer of the bad char+endl
        }
        cout << "ERROR. Please enter 1-8. ";
        cin >> choice2;
    }
    return choice2; 
};

void add_goat(list<Goat> &trip, string [], string []) {
    
};

void delete_goat(list<Goat> &trip) {
    
};

void display_trip(list<Goat> trip) {
    //output the goat names list
    for (auto val : trip) {
    cout << val.get_name();
    cout << " (" << val.get_age() << ", ";
    cout << val.get_color() << ")" << endl;
    }
};