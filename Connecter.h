#ifndef CONNECTOR_H
#define CONNECTOR_H

using namespace std;

void App(string Username);

struct UsersData
{

    float IRMSA = 0.16f;
    float IRMSSA = 0.08f;
    float IRPSA = 0.05f;
    float IRPSSA = 0.02f;
    float CIRFA = 0.00f;
    string Username = "";
    string Password = "";
    vector<int> codedPassword;
    string Fname = "";
    string Lname = "";
    string SSN = "0";
    vector<int> codedSSN;
    string IntialDep = "";

    //SA = Savigs account!
    bool SA = false;
    // AU = Underadged account!
    bool UA = false;
    //Savings And Underadged account
    bool USA = false;
    // Business account?
    bool BA = false;
    // Normal Bank Accont?
    bool NBA = false;
    string PhoneNum = "";
    string Money = "0";
    string Adress = "";
    int IncomePerYear = 0;
    int age = 0;

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
    // Has Money due;
    bool HMD = false;
    // Due Date to pay money;
    int DDTPM = 0;
    // Money In Savings Account;
    int MISA = 0;

};

#endif
