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
    fileName = "empdata4.txt";
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

struct Employee {
    string name;
    vector<int> hours;
    int totalHours;
};

int main() 
{
    

    ifstream fin;

    loadFile(fin);

    const int NUM_EMPLOYEES = countEmployees(fin);

    //declare employeeData vector of type Employee, length NUM_EMPLOYEES
    vector<Employee*> employeeData(NUM_EMPLOYEES);

    //initialize employees
    for (int i = 0; i < NUM_EMPLOYEES; i++) {
        employeeData[i] = new Employee {"defaulto", {}, 0};
        // employeeData[i]->name = "defaulto";
        employeeData[i]->hours.resize(7,0);
        // employeeData[i]->totalHours = ;
    }
    
    for (Employee* emp : employeeData) {
        string tempName = "";
        int tempNum = 0;
        fin >> tempName;
        emp-> name = tempName;
        for (int i = 0; i < 7; i++) {
            fin >> tempNum;
            emp->hours[i] = tempNum;
        }
    }
    fin.close();

    for (Employee* emp: employeeData) {
        int tempSum = 0;
        for (int hrs : emp->hours) {
            tempSum = tempSum + hrs;
        }
        emp->totalHours = tempSum;
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


    for (Employee* emp : employeeData) {
        cout << left << setw(nameL) << setfill ('_') << emp->name << "__";
        for (int hour : emp->hours) {
            cout << setw(dayL) << setfill (' ') << hour;
        }
        cout << setw(dayL) << setfill (' ') << emp->totalHours;
        cout << endl;
    }

    




    
    cout << "\n\nEND\n\n";

    return 0;
}

/* ===== SAMPLE OUTPUT =========

*/

/* =====CODE GRAVEYARD=====


*/