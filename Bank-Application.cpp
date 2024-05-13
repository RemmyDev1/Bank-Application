#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <string>
#define MAX 100
#include<stdio.h>
#include<stdlib.h>
#include"Connecter.h"

using namespace std;


struct UsersData UserDatas;

void CardStatus()
{
    
}

void LoanDep()
{
    
}

void UserInfo(string Username)
{
    ifstream b2("BankUsersFiles.txt");
    cout << "Your Information" << endl;
    
    while(getline(b2, UserDatas.Username))
    {
        if(UserDatas.Username == Username)
        {
            getline(b2, UserDatas.Money);
        }
        
    }
}


void App(string Username)
{
    int choice = 0;
    
    cout << "\t\tBank Application" << endl;
    cout << "1.View your Information" << endl;
    cout << "2.Card Status" << endl;
    cout << "3.Take Out Loan" << endl;
    cout << "4.deposit Money Into Savings Account From Debt Card" << endl;
    
    cin >> choice; 
    
    switch(choice)
    {
        case 1:
        {
            UserInfo(Username);
        }
        case 2:
        {
            CardStatus();
        }
        case 3:
        {
            LoanDep();
        }
    }
}
