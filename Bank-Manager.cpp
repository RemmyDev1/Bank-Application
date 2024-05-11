#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <string>
#define MAX 100
#include<stdio.h>
#include<stdlib.h>


using namespace std;

void MainApplication()
{
    cout << "Your Are In!" << endl;
}

set<int> prime;
int public_key;
int private_key;
int n;

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

// Function to generate a random prime number
int generatePrime(int min, int max) {
    int prime;
    do {
        prime = rand() % (max - min + 1) + min;
    } while (!isPrime(prime));
    return prime;
}

// Function to calculate the modular exponentiation (x^y mod n)
int powerMod(int x, int y, int n) {
    int result = 1;
    x = x % n;
    while (y > 0) {
        if (y % 2 == 1) {
            result = (result * x) % n;
        }
        y = y / 2;
        x = (x * x) % n;
    }
    return result;
}

void saveKeys() {
    ofstream file("keys.txt");
    if (file.is_open()) {
        file << public_key << " " << private_key << " " << n;
        file.close();
    } else {
        cout << "Unable to save keys to file." << endl;
    }
}

// Function to generate public and private keys
void generateKeys() {
    
    if (public_key == 0 && private_key == 0 && n == 0) {
        // Generate two random prime numbers
        int p = generatePrime(100, 1000);
        int q = generatePrime(100, 1000);

        // Calculate n
        n = p * q;

        // Calculate Euler's totient function
        int phi = (p - 1) * (q - 1);

        // Choose an integer e such that 1 < e < phi and gcd(e, phi) = 1
        public_key = generatePrime(2, phi - 1);

        // Calculate d, the modular multiplicative inverse of e mod phi
        private_key = powerMod(public_key, -1, phi);
    }
}

void loadKeys() {
    ifstream file("keys.txt");
    if (file.is_open()) {
        file >> public_key >> private_key >> n;
        file.close();
    } else {
        cout << "Keys file not found. Generating new keys." << endl;
        generateKeys();
        saveKeys();
    }
}




// Function to encrypt a message using the public key
vector<int> encrypt(const string& message) {
    vector<int> encryptedMessage;
    for (char c : message) {
        int encryptedChar = powerMod(c, public_key, n);
        encryptedMessage.push_back(encryptedChar);
    }
    return encryptedMessage;
}

ostream& operator<<(ostream &out, const vector<int> &vec) {
    for (const auto &element : vec) {
        out << element << " ";
    }
    return out;
}

istream& operator>>(istream &in, vector<int> &vec) {
    int value;
    vec.clear(); // Clear existing elements before reading new ones
    while (in >> value) {
        vec.push_back(value);
    }
    return in;
}

istream& skipLine(istream &in) {
    return in.ignore(numeric_limits<streamsize>::max(), '\n');
}


struct UsersData
{

    float IRMSA = 0.16f;
    float IRMSSA = 0.08f;
    float IRPSA = 0.05f;
    float IRPSSA = 0.02f;
    string Username = "";
    string Password = "";
    vector<int> codedPassword;
    string Fname = "";
    string Lname = "";
    string SSN = "0";
    vector<int> codedSSN;

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
    string Adress = "";
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

}UserData;


void LoginToAccount() {
    string LoginPassword;
    string LoginUsername;
       
    cout << "LOGIN" << endl;

    cout << "Please Enter Your Username" << endl;
    cin >> LoginUsername;

    cout << "Please Enter Your Password" << endl;
    cin >> LoginPassword;

    // Encode the input password
    vector<int> LoginCodedPassword = encrypt(LoginPassword);
    cout << "Encoded Password: " << LoginCodedPassword << endl;

    ifstream b2("BankUsersFiles.txt"); 

    bool loginSuccessful = false;
    while (getline(b2, UserData.Username)) {
        vector<int> codedPassword;
        if (!(b2 >> codedPassword)) {
            // Error reading password
            break;
        }

        cout << "File Username: " << UserData.Username << endl;
        cout << "File Password: " << codedPassword << endl;

        if (LoginUsername == UserData.Username && codedPassword == LoginCodedPassword) {
            // Username and password match
            loginSuccessful = true;
            break;
        }

        // Skip the rest of the line
        skipLine(b2);
    }

    if (loginSuccessful) {
        MainApplication();
    } else {
        cout << "Incorrect login Information!" << endl;
    }
}

void CreateUserAccount()
{
    string VerifyPassTemp;
    
    cout << "Please Enter Your Username: " << endl;
    cin >> UserData.Username;

    cout << "Please Enter Your Password: " << endl;
    cin >> UserData.Password;

    cout << "Please verify your Password: " << endl;
    cin >> VerifyPassTemp;

    if (VerifyPassTemp != UserData.Password)
    {
        cout << "Passwords do not match" << endl;
        return;
    }

    UserData.codedPassword = encrypt(UserData.Password);
    UserData.Password = "";

    cout << "Please Enter Your Current Adress: " << endl;
    cin >> UserData.Adress;

    cout << "Please Enter Your SSN" << endl;
    cin >> UserData.SSN;

    UserData.codedSSN = encrypt(UserData.SSN);
    cout << UserData.codedSSN << endl;
    UserData.SSN = "";
                
    ofstream b1("BankUsersFiles.txt", ios::app);
    b1 << UserData.Username << '\n'
       << UserData.codedPassword << '\n'
       << UserData.Adress << '\n'
       << UserData.codedSSN << '\n';
    b1.close();
    system("clear");
}

void Menu()
{
    cout << "1. Create New Account" << endl;
    cout << "2. Switch to Login" << endl;
    cout << "3. Exit Program" << endl;
    
    int choice = 0;
    cin >> choice;

    switch (choice)
    {
        case 1:
        {
            system("clear");
            CreateUserAccount();
            LoginToAccount();
            break;
        }

        case 2:
        {
            system("clear");
            LoginToAccount();
            break;
        }
    }  
}

int main()
{
    srand(time(0)); // Seed the random number generator

    loadKeys();
    Menu();
}



