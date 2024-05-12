#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <string>
#define MAX 100
#include<stdio.h>
#include<stdlib.h>
#include"Connecter.h"

using namespace std;

struct UsersData UserData;

void MainApplication()
{
    App();
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

void LoginToAccount()
{
    string LoginPassword;
    string LoginUsername;
       
    cout << "LOGIN" << endl;

    cout << "Please Enter Your Username" << endl;
    cin >> LoginUsername;

    cout << "Please Enter Your Password" << endl;
    cin >> LoginPassword;
    
    vector<int> LoginCodedPassword = encrypt(LoginPassword);
    cout << LoginCodedPassword << endl;
    ifstream b2("BankUsersFiles.txt"); 

    string userDataUsername;
    string userDataCodedPasswordLine;
    while (getline(b2, userDataUsername) && getline(b2, userDataCodedPasswordLine)) {
        if (userDataUsername == LoginUsername) {
            vector<int> userDataCodedPassword;
            istringstream passwordStream(userDataCodedPasswordLine);
            int num;
            while (passwordStream >> num) {
                userDataCodedPassword.push_back(num);
            }

            // Check if the passwords match
            if (userDataCodedPassword == LoginCodedPassword) {
                MainApplication();
                return;
            } else {
                cout << "Incorrect Password" << endl;
                return; // Exit the function if the password is incorrect
            }
        }
    }

    // If the username is not found
    cout << "Username not found" << endl;
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

    cout << "Please Enter Your Current Adress (For spaces yous dashes): " << endl;
    cin >> UserData.Adress;

    cout << "Please Enter Your SSN: " << endl;
    cin >> UserData.SSN;

    UserData.codedSSN = encrypt(UserData.SSN);
    cout << UserData.codedSSN << endl;
    UserData.SSN = "";
    
    cout << "Please Enter Your Phone Number: " << endl;
    cin >> UserData.PhoneNum;
    
    cout << "Please Enter Your Income Per Year (dont use comma's): " << endl;
    cin >> UserData.IncomePerYear;
    
    if(UserData.IncomePerYear >= 350000)
    {
        UserData.IsMinority = true;
    }
    else
    {
        UserData.IsPriority = true;
    }
    
    cout << "Please Enter Age: " << endl;
    cin >> UserData.age;
    if (UserData.age < 18)
    {
        UserData.UA = true;
    }
    
    cout << "Do you want this account to be a savings accout? (0 for true or 1 for false): " << endl;
    cin >> UserData.SA;
    if(UserData.age < 18 && UserData.SA == true)
    {
        UserData.USA = true;
        UserData.UA = false;
    }
    
    cout << "Do you want this to be a Business Account (0 for true or 1 for false): " << endl;
    cin >> UserData.BA;
    
    cout << "Do you want this to be a Normal Bank Account (0 for true or 1 for false): " << endl;
    cin >> UserData.NBA;
    
    if(UserData.SA == true && UserData.IsMinority == true)
    {
        UserData.CIRFA = UserData.IRMSA;
    }
    else if(UserData.USA == true && UserData.IsMinority == true)
    {
        UserData.CIRFA = UserData.IRMSSA;
    }
    else if(UserData.SA == true && UserData.IsPriority == true)
    {
        UserData.CIRFA == UserData.IRPSA;
    }
    else if(UserData.USA == true && UserData.IsPriority == true)
    {
        UserData.CIRFA == UserData.IRPSSA;
    }
    
    ofstream b1("BankUsersFiles.txt", ios::app);
    b1 << UserData.Username << '\n'
   << UserData.codedPassword[0] << ' ' << UserData.codedPassword[1] << ' ' << UserData.codedPassword[2] << '\n'
   << "Home Address: " + UserData.Adress << '\n'
   << "Phone number: " << UserData.PhoneNum << '\n'
   << "Income Per Year: " << UserData.IncomePerYear << '\n'
   << "Age: " << UserData.age << '\n'
   << "Savings account: " << (UserData.SA ? "true" : "false") << '\n'
   << "Underaged Savings Account: " << (UserData.USA ? "true" : "false") << '\n'
   << "Business Account: " << (UserData.BA ? "true" : "false") << '\n'
   << "Normal Bank Account: " << (UserData.NBA ? "true" : "false") << '\n';
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
