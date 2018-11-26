/**
 * @file lab3_a.cpp
 * @author Shengcong Zhou * @Date 2018.May.29
 * @version 1.0
 * @brief
 * The program should display the patient's information, information about
 * all three of the procedures, and the total charges of all procedures.
 *
 */
// I declare that this assignment is my own work and that I have correctly
// acknowledged the work of others. I acknowledged that I have read and
// followed the Academic Honesty and
//Integrity related policies as outlined in the syllabus. //
// _____ Shengcong Zhou ____ _____2018.May.29______________ //
// ____ 301336141 ______ //

#include <iostream>
#include <string>

using namespace std;

/**
 * @brief This class defines information about a patient
 */
class Patient
{
public:
    // Constructor declaration
    Patient(string newFirstName, string newMiddleName, string newLastName,
            string newAddress, string newCity, string newState,
            string newZipCode, long int newPhoneNumber,
            string newEmergencyContact, long int newEmergencyNumber);

    // Accessor declarations
    string getFirstName();
    string getMiddleName();
    string getLastName();
    string getAddress();
    string getCity();
    string getState();
    string getZipCode();
    long int getPhoneNumber();
    string getEmergencyContact();
    long int getEmergencyNumber();

    // Mutator declarations
    void setFirstName(string newFirstName);
    void setMiddleName(string newMiddleName);
    void setLastName(string newLastName);
    void setAddress(string newAddress);
    void setCity(string newCity);
    void setState(string newState);
    void setZipCode(string newZipCode);
    void setPhoneNumber(long int newPhoneNumber);
    void setEmergencyContact(string newEmergencyContact);
    void setEmergencyNumber(long int newEmergencyNumber);

    friend void patientOutput(Patient thePatient);

private:
    string firstName;
    string middleName;
    string lastName;
    string address;
    string city;
    string state;
    string zipCode;
    long int phoneNumber;
    string emergencyContact;
    long int emergencyNumber;

};

/**
 * @brief This class defines information about a patient
 */
class Procedure
{
public:
    Procedure(string newProcedureName, string newProcedureDate,
              string newPractitioner, double newCharge);

    // Accessor declarations
    string getProcedureName();
    string getProcedureDate();
    string getPractitioner();
    double getCharge();

    // Mutator declarations
    void setProcedureName(string newProcedureName);
    void setProcedureDate(string newProcedureDate);
    void setPractitioner(string newPractitioner);
    void setCharge(double newCharge);

    friend void procedureOutput(Procedure theProcedure);

private:
    string procedureName;
    string procedureDate;
    string practitioner;
    double charge;
};


int main()
{
    double totalCharge = 0.0;

    Patient sfu("Simon", "Fraser", "University", "8888 University Drive", "Burnaby", "BC",
                "V5A 1S6", 7777777777, "Mr. Someone Whoever",
                1234567890);

    Procedure procedure1("Physical Exam", "2018 May 29", "Dr. Irvine", 250.00),
            procedure2("X-ray", "2018 May 29", "Dr. jamison", 500.00),
            procedure3("Blood test", "2018 May 29", "Dr. Smith", 200.00);

    patientOutput(sfu);
    for(int i = 0; i < 3; i++)
    {
        if(i == 0)
        {
            procedureOutput(procedure1);
            totalCharge = totalCharge + procedure1.getCharge();
        }
        else if(i == 1)
        {
            procedureOutput(procedure2);
            totalCharge = totalCharge + procedure2.getCharge();
        }
        else if(i == 2)
        {
            procedureOutput(procedure3);
            totalCharge = totalCharge + procedure3.getCharge();
        }
    }

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    cout << "Total charge: $" << totalCharge << endl << endl;

    return 0;
}

// Patient constructor definition
Patient::Patient(string newFirstName, string newMiddleName, string newLastName,
                 string newAddress, string newCity, string newState,
                 string newZipCode, long int newPhoneNumber,
                 string newEmergencyContact, long int newEmergencyNumber)
{
    firstName = newFirstName;
    middleName = newMiddleName;
    lastName = newLastName;
    address = newAddress;
    city = newCity;
    state = newState;
    zipCode = newZipCode;
    phoneNumber = newPhoneNumber;
    emergencyContact = newEmergencyContact;
    emergencyNumber = newEmergencyNumber;
}

// Procedure constructor definition
Procedure::Procedure(string newProcedureName, string newProcedureDate,
                     string newPractitioner, double newCharge)
{
    procedureName = newProcedureName;
    procedureDate = newProcedureDate;
    practitioner = newPractitioner;
    charge = newCharge;
}

/**
 * @brief Accessor functions return values stored in member variables
 *
 * @return member variable
 */
// Patient accessor definitions
string Patient::getFirstName()
{
    return firstName;
}
string Patient::getMiddleName()
{
    return middleName;
}
string Patient::getLastName()
{
    return lastName;
}
string Patient::getAddress()
{
    return address;
}
string Patient::getCity()
{
    return city;
}
string Patient::getState()
{
    return state;
}
string Patient::getZipCode()
{
    return zipCode;
}
long int Patient::getPhoneNumber()
{
    return phoneNumber;
}
string Patient::getEmergencyContact()
{
    return emergencyContact;
}
long int Patient::getEmergencyNumber()
{
    return emergencyNumber;
}

/**
 * @brief Accessor functions return values stored in member variables
 *
 * @return member variable
 */
// Procedure accessor definitions
string Procedure::getProcedureName()
{
    return procedureName;
}
string Procedure::getProcedureDate()
{
    return procedureDate;
}
string Procedure::getPractitioner()
{
    return practitioner;
}
double Procedure::getCharge()
{
    return charge;
}

// Patient mutator definitions
/**
 * @brief Mutator functions changes values stored in member variables
 *
 * @param newInput
 * @return void
 */
void Patient::setFirstName(string newFirstName)
{
    firstName = newFirstName;
}
void Patient::setMiddleName(string newMiddleName)
{
    middleName = newMiddleName;
}
void Patient::setLastName(string newLastName)
{
    lastName = newLastName;
}
void Patient::setAddress(string newAddress)
{
    address = newAddress;
}
void Patient::setCity(string newCity)
{
    city = newCity;
}
void Patient::setState(string newState)
{
    state = newState;
}
void Patient::setZipCode(string newZipCode)
{
    zipCode = newZipCode;
}
void Patient::setPhoneNumber(long int newPhoneNumber)
{
    phoneNumber = newPhoneNumber;
}
void Patient::setEmergencyContact(string newEmergencyContact)
{
    emergencyContact = newEmergencyContact;
}
void Patient::setEmergencyNumber(long int newEmergencyNumber)
{
    emergencyNumber = newEmergencyNumber;
}

// Procedure mutator definitions
/**
 * @brief mutator functions changes values stored in member variables
 *
 * @param newInput
 * @return void
 */
void Procedure::setProcedureName(string newProcedureName)
{
    procedureName = newProcedureName;
}
void Procedure::setProcedureDate(string newProcedureDate)
{
    procedureDate = newProcedureDate;
}
void Procedure::setPractitioner(string newPractitioner)
{
    practitioner = newPractitioner;
}
void Procedure::setCharge(double newCharge)
{
    charge = newCharge;
}

/**
 * @brief This friend function output patient information
 *
 * @param thePatient is an object name
 * @return void
 */
void patientOutput(Patient thePatient)
{
    cout << "Patient name:\n" << thePatient.firstName << " "
         << thePatient.middleName << " " << thePatient.lastName << endl;
    cout << "Address:\n" << thePatient.address << ", "
         << thePatient.city << ", " << thePatient.state << ", "
         << thePatient.zipCode << endl;
    cout << "Phone number:\n" << thePatient.phoneNumber << endl;
    cout << "Emergency contact:\n" << thePatient.emergencyContact
         << endl << thePatient.emergencyNumber << endl << endl;
}

/**
 * @brief This friend function output procedure information
 *
 * @param theProcedure is an object name
 * @return void
 */
void procedureOutput(Procedure theProcedure)
{
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    cout << "Procedure: " << theProcedure.procedureName << endl
         << "Date: " << theProcedure.procedureDate << endl
         << "Practitioner: " << theProcedure.practitioner << endl
         << "Charge: $" << theProcedure.charge << endl << endl;
}
