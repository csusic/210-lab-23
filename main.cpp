// COMSC-210 | Lab 23 | Christine Susic

#include <iostream>
#include <fstream>
#include <iomanip>
#include <list>
#include <cstdlib>
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
        Goat tmp(names[rand() % SZ_NAMES], rand() % MAX_AGE + 0, colors[rand() % SZ_COLORS]);
        trip.push_back(tmp);
    }

    //output main menu and get choice from main menu
    int choice = main_menu();
    //if choice equals 1(add a goat)
    if (choice == 1) {
        //add a Goat object
        add_goat(trip, names, colors);
        //display Goat object
        display_trip(trip);
    }
    //if choice1 equals 2(delete a goat)
    if (choice == 2) {
        //delete a Goat object
        delete_goat(trip);
        //display updated Goat object
        display_trip(trip);
    }
    //if choice1 equals 3(list goats)
    if (choice == 3) {
        //display Goat object
        display_trip(trip);
    }
    //if choice1 equals 4(quit)
    if (choice == 4) {
        //the Goat Manager quits
        exit(0);
    }

    return 0;
}

int main_menu() {
    //output menu
    int choice1;
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
    return choice1;
}

int select_goat(list<Goat> trip) {
    //output the goat names list
    cout << endl;
    for (auto val : trip) {
    cout << val.get_name();
    cout << " (" << val.get_age() << ", ";
    cout << val.get_color() << ")" << endl;
    }
    //select goat number
    cout << "Select which goat --> ";
    //input choice
    int choice2;
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

//add a Goat object to the trip
void add_goat(list<Goat> &trip, string [], string []) {
    //read & populate arrays for names and colors
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
    //put random names, ages, and colors for each of them
    trip.emplace_back(names[rand() % SZ_NAMES], rand() % MAX_AGE + 0, colors[rand() % SZ_COLORS]);
};

//delete a Goat object from the trip
void delete_goat(list<Goat> &trip) {
    int goat_choice = select_goat(trip);
    auto it = trip.begin();
    advance(it, goat_choice);
    trip.erase(it);
};

//output the updated goat names list
void display_trip(list<Goat> trip) {
    cout << endl;
    cout << "Goat List: " << endl;
    for (auto val : trip) {
    cout << val.get_name();
    cout << " (" << val.get_age() << ", ";
    cout << val.get_color() << ")" << endl;
    }
};