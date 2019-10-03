#include "account.h"
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cstdio>
using namespace std;

// checks if the account is negative or not
bool Account::is_negative(){
  if(balance < 0){
    return true;
  }

  return false;
}

// make a withdraw
void Account::withdraw(float amount){
  balance -= amount;
  if(balance < 0){
    cout<<"Your account is below $0.00: "<<endl;
  }
}

void Account::deposit(float amount){
  balance += amount;
  cout<<fixed<<setprecision(2)<<"Approved! balance: "<<balance<<endl;
  if(balance < 0){
    cout<<"Your account is negative. "<<endl;
  }
}

void Account::check_balance(){
  cout<<fixed<<setprecision(2)<<"Current balance: "<<balance<<endl;
}

void Account::change_pin(int newpin){
    pin = newpin;

}

void Account::change_password(string pw){
  password = pw;
}

int Account::current_pin(){
    return pin;
}

//acts as a constructor to create an account
void Account::createAccount(string usrnme, string pswrd, float amount, int pn){
  // sets the data members to the input values
  username = usrnme;
  password = pswrd;
  balance = amount;
  pin = pn;

  //creates the file name
  string hold = username;
  hold.append(".txt");
  ofstream client(hold);

  //saves the info to the file
  client<<username<<endl<<password<<endl<<balance<<endl<<pin;
  client.close();

}

bool Account::login(string un, string pw){

    bool access = false;
    string hold = un;
    hold.append(".txt");

    // opens the file and reads it
    ifstream client;
    client.open(hold);
    client>>username>>password>>balance>>pin;
    client.close();

    // checks if the password on-file matches with what the user put in
    if(pw==password){
      access = true;
    }
    else{
      access = false;
    }
    return access;

}

//updates the file when the user changes some info
void Account::update(){
  string hold = username;
  hold.append(".txt");
  ofstream client;
  client.open(hold);
  client<<username<<endl<<password<<endl<<balance<<endl<<pin;
  client.close();
}

//acts as a deconstuctor when an account is deleted
void Account::erase(){
    string hold = username;
    hold.append(".txt");

    if(remove(hold.c_str()) != 0){
      cout<<"There was a problem deleting your account."<<endl;
    }
    else{
      cout<<hold<<" Has been removed!"<<endl;
      cout<<"Your account has been successfully deleted."<<endl;
    }
    username = "";
    password = "";
    balance = 0;
    pin = 0;

}
