#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <iostream>
#include <string>
using namespace std;

class Account
{
private:
  string password, username;
  int pin;
  float balance;

public:
  bool is_negative();
  void withdraw(float amount);
  void deposit(float amount);
  void check_balance();
  inline void change_pin(int newpin);
  inline int current_pin();
  void createAccount(string usrnme, string pswrd, float amount, int pn);
  bool login(string un, string pw);
  void update();
  void erase();
  void change_password(string pw);

};

#endif //ACCOUNT_H
