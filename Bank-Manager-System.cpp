#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void EncryptData()
{

  
}

struct MinorityUsers
{

    float IRMSA = 0.16f;
    float IRMSSA = 0.08f;
    string LoginUsername = "";
    string LoginPassword = "";
    string Fname = "";
    string Lname = "";
    int SSN = 0;

    //SA = Savigs account!
    bool SA = false;
    // AU = Underadged account!
    bool UA = false;
    //Savings And Underadged account
    bool SUA = false;
    // Business account?
    bool BA = false;

    int PhoneNum = 0;
    int Money = 0;
    string adress = "";
    int IncomePerYear = 0;


    int LWP = 0;
    int LMP = 0;
    int LYP = 0;
    int ATP = 0;
    int ASLW = 0;
    int ASLM = 0;
    int ASLY = 0;

    bool IsMinority = false;
    bool IsPriority = false;


    // Has a credit card?
    bool HCC = false;
    // Always starts a 650
    int CCS = 650;
    // This is always the starter (CCL) Credit Card Limit after income is determined 
    // And calculated if payment history exists (CCL) Credt Card Limit will change
    int CCL = 500;
    int ACCLS = 0;
    // Has Cash Back Card
    bool HCBC = false;
    float NCBCA = 0.03f;
    // Has Debit card?
    bool HDC = false;
    // Money In Debit Card
    int MIDC = 0;

    int debt = 0;
    // Monthly statment txt file should be sent via email or postal code.
    // Loan history and Payment history will be created when I get a pc currently working on a chrome book.
    //I cannot make  that hass to access files like txt.
    // Previous Amount of Loans given to Client 
    int PAL = 0;
    // Has Money due
    bool HMD = false;
    // Due Date to pay money;
    int DDTPM = 0;

};

struct PriorityUsers
{
    float IRPSA = 0.05f;
    float IRPSSA = 0.02f;
    string LoginUsername = "";
    string LoginPassword = "";
    string Fname = "";
    string Lname = "";
    int SSN = 0;

    //SA = Savigs account!
    bool SA = false;
    // AU = Underadged account!
    bool UA = false;
    //Savings And Underadged account
    bool SUA = false;
    // Business account?
    bool BA = false;

    int PhoneNum = 0;
    int Money = 0;
    string adress = "";
    int IncomePerYear = 0;


    int LWP = 0;
    int LMP = 0;
    int LYP = 0;
    int ATP = 0;
    int ASLW = 0;
    int ASLM = 0;
    int ASLY = 0;


    // Has a credit card?
    bool HCC = false;
    // Always starts a 650
    int CCS = 650;
    // This is always the starter (CCL) Credit Card Limit after income is determined 
    // And calculated if payment history exists (CCL) Credt Card Limit will change
    int CCL = 500;
    int ACCLS = 0;
    // Has Cash Back Card
    bool HCBC = false;
    float NCBCA = 0.03f;
    // Has Debit card?
    bool HDC = false;
    // Money In Debit Card
    int MIDC = 0;

    int debt = 0;
    // Monthly statment txt file should be sent via email or postal code.
    // Loan history and Payment history will be created when I get a pc currently working on a chrome book.
    //I cannot make  that hass to access files like txt.
    // Previous Amount of Loans given to Client 
    int PAL = 0;
    // Has Money due
    bool HMD = false;
    // Due Date to pay money;
    int DDTPM = 0;

};

void CreateUserAccount()
{
    int choice = 0;
    
    cout << "1. Create New Account" << endl;
    cout << "2. Switch to Login" << endl;
    cout << "3. Exit Program"
    
    switch(choice)
    {
        case '1':
        {
            
        }
    }
  
}

int main()
{
    CreateUserAccount();
}



