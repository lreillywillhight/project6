/*
Louis Reilly-Willhight 
CS131 Spring 2026, Everett CC

Employee Data II

expands on project 5:
reads formatted data from a file
places data into arrays
formulates an integer total and appends to array
outputs in formatted table

reformatted using vectors

rewritten from start

*/


#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

//CONSTS

//const int LIST_MAX_SIZE = 50; //DEPRECTAED VECTORS
const int TOTAL_COL = 8; //LOCATION FOR TOTAL HOURS


//FUNCTIONS

//loadFile
//opens file in fstream, includes error handler and input code
void loadFile (ifstream& inFile) {
    cout << endl << "Weekly hours manager: " << endl;
    string fileName;
    cout << "Please enter file name: ";
    fileName = "empdata.txt";
    cout << fileName;
    //cin >> fileName;
    cout << endl;
    inFile.open(fileName);
    if (!inFile.is_open()) {
        cout << "Could not open file: " << fileName << endl;
        cout << "Please try again" << endl;
        cout << "\n\nEND\n\n";
        exit(1);
    }
}

//countEmployees to remove from stream 
//and set employee count for use in other funcs
int countEmployees(ifstream& inFile) {
    int empNum;
    inFile >> empNum;
    return empNum;
}


int main() 
{
    

    ifstream fin;

    loadFile(fin);

    const int NUM_EMPLOYEES = countEmployees(fin);

    struct Employee {
        string name;
        vector<int> hours;
        int totalHours;
    };

    //declare employeeData vector of type Employee, length NUM_EMPLOYEES
    vector<Employee*> employeeData(NUM_EMPLOYEES);

    //initialize employees
    for (int i = 0; i < NUM_EMPLOYEES; i++) {
        employeeData[i] = new Employee {"defaulto", {}, i};
        // employeeData[i]->name = "defaulto";
        employeeData[i]->hours.resize(7,0);
        // employeeData[i]->totalHours = ;
    }

    //populate employeeData vector with data from ifstream fin
    string tempName = "";
    int tempNum = 0;
    for (int i = 0; i < NUM_EMPLOYEES; i++) {
        for (int j = 0; j < 8 ; j++) {
            if (j == 0) {
                fin >> tempName;
                employeeData[i]->name = tempName;
                cout << "user " << i << " assigned name: " << employeeData[i]->name << endl;
            }
            else {
                fin >> tempNum;
                employeeData[i]->hours[j-1] = tempNum ;
                cout << "tempnum " << tempNum << endl;
                cout << "user " << i << "assigned hour: " << employeeData[i]->hours[j-1] << endl;
            }
        }
    }
    fin.close();

    //sum hours from employeeData.hours, assign to employeeData.totalHours
    for (int i =  0; i < NUM_EMPLOYEES; i++) {
        int tempSum = 0;
        for (int j = 0; j < 7; j++) {
            tempSum = tempSum + employeeData[i]->hours[j];
            // cout << "tempsum " << i << tempSum << endl;
        }
        employeeData[i]->totalHours = tempSum;
        cout << "total: " << i << " = " << employeeData[i]->totalHours << endl;
    }

    //TODO SORT VECTOR

    int nameL = 20; //placeholder
    int dayL = 5;

    //header()
    cout << setw(nameL + 2) << left << "Name:";
    cout << setw(dayL) << "Mon";
    cout << setw(dayL) << "Tue";
    cout << setw(dayL) << "Wed";
    cout << setw(dayL) << "Thu";
    cout << setw(dayL) << "Fri";
    cout << setw(dayL) << "Sat";
    cout << setw(dayL) << "Sun";
    cout << setw(dayL) << "Tot";
    cout << endl;

    // //print()
    // //refact with foreach
    // for (int i = 0; i < NUM_EMPLOYEES; i++) {
    // // for (Employee* emp : employeeData) {
    //     //name
    //     cout << left << setw(nameL) << setfill('_') << employeeData[i]->name << "__";
    //     //hours
    //     // cout << right;
    //     // resetiosflags;
    //     for (int j = 0; j < 7; j++) {
    //         cout << setw(dayL) << setfill(' ') << employeeData[i]->hours[j];
    //     }
    //     //total hours
    //     cout << setw(dayL) << setfill (' ') << employeeData[i]->totalHours;
    //     cout << endl;
    // }

    for (Employee* emp : employeeData) {
        cout << left << setw(nameL) << setfill ('_') << emp->name << "__";
        for (int hour : emp->hours) {
            cout << setw(dayL) << setfill (' ') << hour;
        }
        cout << setw(dayL) << setfill (' ') << emp->totalHours;
        cout << endl;
    }

    //sample for refactor
    // for (Employee* emp : workers) {
    //     cout << emp->name << ": ";
    //     for (int hr : emp->hours) {
    //         cout << hr << " ";
    //     }
    //     cout << endl;
    // }

    // for (Employee* emp : employeeData) {
    //     cout << emp->totalHours;
    // }





    
    cout << "\n\nEND\n\n";

    return 0;
}

/* ===== SAMPLE OUTPUT =========

*/

/* =====CODE GRAVEYARD=====


*/