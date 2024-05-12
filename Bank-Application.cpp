#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <string>
#define MAX 100
#include<stdio.h>
#include<stdlib.h>
#include"Connecter.h"

using namespace std;

void UserInfo()
{
    cout << "Your Information"
}


void App()
{
    int choice = 0;
    
    cout << "\t\tBank Application" << endl;
    cout << "1.View your Information" << endl;
    cout << "2.Card Status" << endl;
    cout << "3.Take Out Loan" << endl;
    cout << "4.deposit Money Into Savings Account From Debt Card"
    
    cin >> choice; 
    
    switch(choice)
    {
        case 1:
        {
            UserInfo();
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
