//Due Date: 7/22/2024
//Author Name: Devin Latham
//Course-Sec: CSCI 2170
//Program Description: A program to read coin values from a file and calculate 
//how many of each coin is in each value.

#include <iostream>
#include <fstream>
#include <cassert>
using namespace std;


void ComputeCoins(int coinValue, int& number, int& amountLeft);//Function prototype

int main(){
    ifstream inputFile("coins.dat");//open coins.dat file
    assert(inputFile);//check for error


    int changeValue; // var to hold change value
    while(inputFile >> changeValue){ // loop through each value in file
        //var to hold each coin type
        int quarters;
        int dimes;
        int pennies;
        int amountLeft = changeValue; // init amount left with change value

        ComputeCoins(25, quarters, amountLeft); //calc num of quarters

        ComputeCoins(10, dimes, amountLeft); // calc num of dimes

        //output results
        cout << changeValue << " cents can be changed using: " << endl;
        cout << quarters << " quarter(s)" << endl;
        cout << dimes << " dime(s)" << endl;
        cout << amountLeft << " cent(s)." << endl;
        cout << endl;
    }

    inputFile.close();//close file
    return 0;
}

//function to calc num of coins og given coinValue in main function
void ComputeCoins(int coinValue, int& number, int& amountLeft){
    number = amountLeft / coinValue;// calc number of coins
    amountLeft %= coinValue; // calc remaining amount after using coins
}