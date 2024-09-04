#include <iostream>
#include <string>
#include<iomanip>
#include<cstdlib>
#include<windows.h>

using namespace std;

// Structure to represent a patient
struct Patient
{
    string name;
    int age;
    char gender;
    string condition;
};

const int MAX_PATIENTS = 100; // Maximum number of patients

// Function prototypes
void addPatient(Patient[], int&);
void displayPatients(const Patient[], int);
void searchPatient(const Patient[], int);
void setAppointment(const Patient patients[], int numPatients);
void bill(void);
void inventory(void);

int main() 
{
    cout << "               ___                                    ___      \n";
    cout << "|  |ELCOME      |O     |__|OSPITAL    |\\/|ANAGMENT   |___ YSTEM \n";
    cout << "|/\\|            |      |  |           |  |            ___|      \n";
    Patient patients[MAX_PATIENTS]; // Array to store patients
    int numPatients = 0; // Current number of patients

    int choice;
    do 
    {
        // Display menu
        cout << "\n\nHospital Management System\n";
        cout << "1. Add Patient\n";
        cout << "2. Display Patients\n";
        cout << "3. Search Patient\n";
        cout << "4. Set Apointment\n";
        cout << "5. Bill\n";
        cout << "6. Inventory Managment\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) 
        {
        case 1:
            addPatient(patients, numPatients);
            break;
        case 2:
            displayPatients(patients, numPatients);
            break;
        case 3:
            searchPatient(patients, numPatients);
            break;
        case 4:
            setAppointment(patients, numPatients);
            break;
        case 5:
            bill();
            break;
        case 6:
            inventory();
            break;
        case 7:
            cout << " __            \n";
            cout << "|__XIT ...*_* *_* *_*  \n";
            cout << "|__            \n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 7);

    return 0;
}

// Function to add a new patient to the array
void addPatient(Patient patients[], int& numPatients)
{
    if (numPatients < MAX_PATIENTS) 
    {
        cout << "\nEnter patient details:\n";
        cout << "Name: ";
        cin.ignore();
        getline(cin, patients[numPatients].name);
        cout << "Age: ";
        cin >> patients[numPatients].age;
        cout << "Gender f/m : ";
        cin >> patients[numPatients].gender;
        patients[numPatients].gender = tolower(patients[numPatients].gender);
        while (patients[numPatients].gender != 'f' && patients[numPatients].gender != 'm')
        {
            cout << "Invalid choice. Please re-enter:";  cin >> patients[numPatients].gender;
        }
        cout << "Condition: ";
        cin.ignore();
        getline(cin, patients[numPatients].condition);

        numPatients++;
        cout << "Patient added successfully.\n";
    }
    else 
    {
        cout << "Maximum number of patients reached.\n";
    }
}

// Function to display all patients
void displayPatients(const Patient patients[], int numPatients)
{
    cout << "\nList of Patients:\n";
    for (int i = 0; i < numPatients; ++i) 
    {
        cout << "Patient " << i + 1 << ":\n";
        cout << "Name: " << patients[i].name << endl;
        cout << "Age: " << patients[i].age << endl;
        cout << "Gender: " << patients[i].gender << endl;
        cout << "Condition: " << patients[i].condition << endl << endl;
    }
}

// Function to search for a patient by name
void searchPatient(const Patient patients[], int numPatients) 
{
    string searchName;
    cout << "\nEnter the name of the patient to search: ";
    cin.ignore();
    getline(cin, searchName);

    bool found = false;
    for (int i = 0; i < numPatients; ++i) 
    {
        if (patients[i].name == searchName) 
        {
            cout << "Patient found:\n";
            cout << "Name: " << patients[i].name << endl;
            cout << "Age: " << patients[i].age << endl;
            cout << "Gender: " << patients[i].gender << endl;
            cout << "Condition: " << patients[i].condition << endl;
            found = true;
            break;
        }
    }

    if (!found) 
    {
        cout << "Patient not found.\n";
    }
}

void setAppointment(const Patient patients[], int numPatients)
{
    int chose, d,time;
    bool a;
    string doc;

    string searchName;
    bool found = false;
    while (found==false) 
    {
        cout << "\nEnter the name of the patient. ";
        cin.ignore();
        getline(cin, searchName);


        for (int i = 0; i < numPatients; ++i)
        {
            if (patients[i].name == searchName)
            {
                cout << "Patient found:\n";
                found = true;
                break;
            }
        }

        if (!found)
        {
            cout << "Patient not found.\n";
        }
    }

    int n = rand() % 2;
    do {
        cout << "Make an appointment with\n 1.General Physician\n 2.General Duty Medical Officer\n 3.Cardiologist\n 4.Doctor of Physiotherapy\n";
        cout << "Enter Your choice: "; cin >> chose;
        while (chose < 1 || chose >4)
        {
            cout << "Invalid choice. Please re-enter:"; cin >> chose;
        }
        cout << "Enter Date: ";
        cin >> setw(2) >> d; cout << endl;
        switch (chose)
        {
        case 1:
            doc = "General Physician ";
            break;
        case 2:
            doc = "General duty Medical Officer ";
            break;
        case 3:
            doc = "Cardiologist ";
            break;
        case 4:
            doc = "Doctor of Physiotherapy ";
            break;
        }

        if (n == 1)
        {
            cout <<searchName<< " have booked appointment with " << doc << "on " << d << " Feb, between 0800 to 1200.\n";
            cout << "Thank You for making an Appointment";
        }
        else
        {
            cout << "Sorry no slot is available on this date. Please try again.\n";
            for (int j = 0; j <= 4; j++) 
            {
                cout << setw(10) << ".....\n";
                Sleep(1000);
            }
        }
    } while (n == 0);
}

void bill(void)
{
    double discount, medicene, fee, wardCharges, otherCharges, tax, total;
    cout << "Doctor fee: Rs"; cin >> fee;
    cout << "Medicene Charges: Rs"; cin >> medicene;
    cout << "Admit fee and Ward Charges: Rs"; cin >> wardCharges;
    cout << "Other Charges: Rs"; cin >> otherCharges;
    cout << "Tax: Rs"; cin >> tax;
    cout << "Discount(%): "; cin >> discount;

    total = fee + medicene + wardCharges + otherCharges + tax;
    total = (discount / 100) * total;

    cout << "\n\n Your total hospital bill is Rs" << total;
}

void inventory(void)
{
    string equipments[8] = { "Beds","Injections","First aid box","Oxygen Cylinders","Wheel Chair","Medicene","Painkillers","IVs" };
    int amount;
    cout << "Equipments" << setw(20) << "Amount" << setw(20) << endl << endl;

    for (int i = 0; i < 8; i++)
    {
        cout << left;
        cout <<setw(25)<< equipments[i]; 
        cin >>amount;
    }
}