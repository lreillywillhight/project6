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

finished: all-in-all, not too much space saved, codewise

*/


#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

//STRUCS

struct Employee {
    string name;
    vector<int> hours;
    int totalHours;
};

//FUNCTIONS

//loadFile
//opens file in fstream, includes error handler and input code
void loadFile (ifstream& inFile) {
    cout << endl << "Weekly hours manager: " << endl;
    string fileName;
    cout << "Please enter file name: ";
    // fileName = "empdata4.txt";
    cout << fileName;
    cin >> fileName;
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

//initialize employees in vector list
void initList(vector<Employee*>& list, int employeeNum) {
    for (int i = 0; i < employeeNum; i++) {
        list[i] = new Employee {"defaulto", {}, 0};
        list[i]->hours.resize(7,0);
    }
}

//set employee values from ifstream
void loadEmployees(ifstream& inFile, vector<Employee*>& list, int numEmployees) {
    for (Employee* emp: list) {
        string tempName = "";
        inFile >> tempName;
        emp->name = tempName;
        for (int i = 0; i < 7; i++) {
            int tempNum = 0;
            inFile >> tempNum;
            emp->hours[i] = tempNum;
        }
        int tempSum = 0;
        for (int hr: emp->hours) {
            tempSum = tempSum + hr;
        }
        emp->totalHours = tempSum;
    }
    inFile.close();
}

//sort vector employees by total hours, most to least
void hoursSort(vector<Employee*>& list, int employeeNum) {
    for (int i = 0; i < employeeNum - 1; i++) {
        for (int j = 0; j < employeeNum - 1 - i; j++) {
            if (list[j]->totalHours < list[j+1]->totalHours) {
                swap(list[j], list [j+1]);
            }
        }
    }
}

//helper function for print output
int NameLength(vector<Employee*> list) {
    int tempLength = 0;
    for (Employee* emp: list) {
        if (emp->name.length() > tempLength) {
            tempLength = emp->name.length();
        }
    }
    return tempLength;
}

//generic header to look nice, print
void header(int NAME_LENGTH, int DAY_LENGTH) {
    cout << setw(NAME_LENGTH + 2) << left << "Name:";
    cout << setw(DAY_LENGTH) << "Mon";
    cout << setw(DAY_LENGTH) << "Tue";
    cout << setw(DAY_LENGTH) << "Wed";
    cout << setw(DAY_LENGTH) << "Thu";
    cout << setw(DAY_LENGTH) << "Fri";
    cout << setw(DAY_LENGTH) << "Sat";
    cout << setw(DAY_LENGTH) << "Sun";
    cout << setw(DAY_LENGTH) << "Tot";
    cout << endl;        
}

//print data from vector
void printTable (vector<Employee*> list, int nameL, int dayL) {
    for (Employee* emp : list) {
        cout << left << setw(nameL + 2) << setfill ('_') << emp->name;
        for (int hour : emp->hours) {
            cout << setw(dayL) << setfill (' ') << hour;
        }
        cout << setw(dayL) << setfill (' ') << emp->totalHours;
        cout << endl;
    }
}


int main() 
{
    //declare fstream input
    ifstream fin;
    
    //load file (formatted .txt,see instructions)
    loadFile(fin);
    
    //remove list size from stream, define for parameter
    const int NUM_EMPLOYEES = countEmployees(fin);
    
    //creates vector of pointer to type emplyee, size NUM_EMPLOYEES
    vector<Employee*> employeeData(NUM_EMPLOYEES);

    //initialize employees in vector with default values
    initList(employeeData, NUM_EMPLOYEES);
    
    //declare employee name, hours, totalhours values from stream
    //close file
    loadEmployees(fin, employeeData, NUM_EMPLOYEES);
    
    //sort for output
    hoursSort(employeeData, NUM_EMPLOYEES);
    
    //OUTPUT
    
    const int NAME_LENGTH = NameLength(employeeData);
    const int DAY_LENGTH = 5;
    
    //generic
    header(NAME_LENGTH, DAY_LENGTH);
    
    //from vector
    printTable (employeeData, NAME_LENGTH, DAY_LENGTH);

    cout << "\n\nEND\n\n";

    //delete data from vector
    for (Employee* emp : employeeData) {
        delete emp;
    }
    
    return 0;

}


/* ===== SAMPLE OUTPUT =========

Weekly hours manager: 
Please enter file name: demo.txt

Could not open file: demo.txt
Please try again


END

louis@jankensteinii:~/school_docs/cs131/JFC$ /home/louis/school_docs/cs131/JFC/P6_EMP_DATA_2_LWILLHIGHT

Weekly hours manager: 
Please enter file name: empdata3.txt

Name:           Mon  Tue  Wed  Thu  Fri  Sat  Sun  Tot  
Kirk,James______10   10   0    10   12   0    0    42   
Bosco,Sam_______7    3    8    7    2    5    7    39   
Rugg,James______7    3    8    7    2    5    7    39   
VanPelt,Grace___5    6    5    6    5    6    5    38   
Peters,Greg_____5    6    5    6    5    6    5    38   
Jane,Patrick____9    3    7    5    8    0    0    32   
Lisbon,Teresa___2    3    8    3    6    3    5    30   
Rigsby,Wayne____9    10   4    7    0    0    0    30   
Lilly,Jack______2    3    8    3    6    3    5    30   
Theiss,Bill_____9    10   4    7    0    0    0    30   
Cho,Kimball_____8    8    3    0    8    2    0    29   
Daniels,Carl____8    8    3    0    8    2    0    29   
Minelli,Virgil__2    5    3    0    4    9    4    27   
McCoy,Lenard____0    4    0    8    4    0    2    18   
Scott,Annis_____1    6    2    0    0    1    0    10   


END

louis@jankensteinii:~/school_docs/cs131/JFC$ /home/louis/school_docs/cs131/JFC/P6_EMP_DATA_2_LWILLHIGHT

Weekly hours manager: 
Please enter file name: empdata4.txt

Name:             Mon  Tue  Wed  Thu  Fri  Sat  Sun  Tot  
Kirk,James________10   10   0    10   12   0    0    42   
Ryan,Kevin________5    6    7    6    5    6    5    40   
Leslie,Eddie______5    6    5    6    7    6    5    40   
Uhura,Nyota_______10   10   0    8    12   0    0    40   
Bosco,Sam_________7    3    8    7    2    5    7    39   
Rugg,James________7    3    8    7    2    5    7    39   
Chekov,Pavel______7    3    8    7    2    5    7    39   
VanPelt,Grace_____5    6    5    6    5    6    5    38   
Peters,Greg_______5    6    5    6    5    6    5    38   
Parish,Lanie______7    3    8    6    2    5    7    38   
Esposito,Javier___2    5    3    9    4    9    4    36   
Beckett,Kate______2    8    8    3    6    3    5    35   
Galloway,David____9    10   4    8    0    0    2    33   
Jane,Patrick______9    3    7    5    8    0    0    32   
Castle,Richard____4    3    7    5    8    0    5    32   
Sulu,Hikaru_______2    3    8    5    6    3    5    32   
Lisbon,Teresa_____2    3    8    3    6    3    5    30   
Rigsby,Wayne______9    10   4    7    0    0    0    30   
Lilly,Jack________2    3    8    3    6    3    5    30   
Theiss,Bill_______9    10   4    7    0    0    0    30   
Montgo,Roy________9    2    4    7    0    0    8    30   
Cho,Kimball_______8    8    3    0    8    2    0    29   
Daniels,Carl______8    8    3    0    8    2    0    29   
Rodgers,Martha____8    7    3    0    8    2    0    28   
Minelli,Virgil____2    5    3    0    4    9    4    27   
Chapel,Christine__1    6    2    8    9    1    0    27   
Kyle,John_________8    8    3    0    2    2    0    23   
McCoy,Lenard______0    4    0    8    4    0    2    18   
Rand,Janice_______0    4    0    8    3    0    2    17   
Scott,Annis_______1    6    2    0    0    1    0    10   



*/

/* =====CODE GRAVEYARD=====

    //segmentation fault***
    // for (Employee* emp: employeeData) {
    //     emp = new Employee {"defaulto", {}, 0};
    //     emp->hours.resize(7,0);
    // }

            // for (int hr: emp->hours) {
        //     int tempNum = 0;
        //     inFile >> tempNum;
        //     hr = tempNum;
        // }
*/