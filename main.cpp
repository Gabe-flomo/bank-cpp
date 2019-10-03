#include <iostream>
#include "account.cpp"
using namespace std;

int main(){
  Account myaccount;
  float amount;
  int pin,sel;
  bool loop, signout = true, login = false, logout = true;
  string name, ans, pw, un;
do{
  signout = true, login = false, logout = true;
  cout<<"Login or create account"
      <<"(1 to login, 2 to create account)"<<endl;
    cin >> sel;


    if(sel == 1){
      do{
      system("CLS");
      cout<<"Enter your username: ";
      cin>>un;
      cout<<"Enter your password: ";
      cin>>pw;
      login = myaccount.login(un,pw);
      if(login == false){
        cout<<"incorrect password."<<endl;
        system("PAUSE");
      }
    }while(!login);
  }
    else{
      system("CLS");
          cout<<"Create your username: ";
          cin>>un;
          cout<<"Create your password: ";
          cin>>pw;
          cout<<"Create your pin#: ";
          cin>>pin;
          cout<<"How much would you like to deposit? ";
          cin>>amount;
          myaccount.createAccount(un,pw,amount,pin);
          cout<<"Your account has been created. Would you like to login? [Y/N] ";
          cin>>ans;
          if(ans == "Y"||ans == "y"||ans == "yes"||ans == "Yes"){
            login = myaccount.login(un,pw);
          }


    }

//banks user functions
if(login){
  do{
    system("CLS");
  cout<<"select an option from the menu. "<<endl;
  cout<<"1) Deposit."<<endl;
  cout<<"2) Withdraw."<<endl;
  cout<<"3) Check balance."<<endl;
  cout<<"4) User Profile."<<endl;  //change info (password or pin )
  cout<<"5) Delete account."<<endl;
  cout<<"6) Logout."<<endl;
  cout<<"7) signout."<<endl;
  cin>>sel;

  // menu selections
  switch (sel) {

    case 1: //Deposit
    system("CLS");
        cout<<"How much would you like to deposit? ";
        cin>>amount;
        myaccount.deposit(amount);
        myaccount.update();
        break;

    case 2:// Withdraw
    system("CLS");
        cout<<"How much would you like to withdraw? "<<endl;
        cin>>amount;
        myaccount.withdraw(amount);
        myaccount.update();
        break;

    case 3: // check balance
    system("CLS");
        myaccount.check_balance();
        break;

    case 4://user profile
    system("CLS");
        cout<<"1) change Pin."<<endl;
        cout<<"2) change password."<<endl;
        cin>>sel;
        if(sel==1){
          cout<<"Enter your new pin number: "<<endl;
          cin>>pin;
          myaccount.change_pin(pin);
          myaccount.update();
          cout<<"Pin changed to: "<<pin<<endl;
        }
        else{
          cout<<"Enter your new password: "<<endl;
          cin>>pw;
          myaccount.change_password(pw);
          myaccount.update();
          cout<<"Password changed to: "<<pw<<endl;
        }
        break;

    case 5: // delete account
    system("CLS");
      cout<<"Are your sure you want to delete?"<<endl;
      cin>>ans;
      if(ans == "Y"||ans == "y"||ans == "yes"||ans == "Yes")
      {
        myaccount.erase();
        cout<<"Your account has been deleted and you are now being logged out."<<endl;
        system("PAUSE");
        system("CLS");
        logout = false;
        loop = false;
      }
      else{
        cout<<"Redirecting you to the Main Menu."<<endl;
        logout = false;
        loop = true;
        system("PAUSE");
      }
        break;

    case 6: // logout
    system("CLS");
        logout = false;
        loop = false;
        break;

    case 7: //signout
        signout = true;
        logout = false;
        loop = false;
        cout<<"You have been signed out."<<endl;
        system("PAUSE");
        system("CLS");
        break;

    default:
        cout<<"Invalid option."<<endl;
  }

  /* this part only runs if the user doesnt
  logout or signout */
  if(logout){  // must be false in order to logout
  cout<<"back to main menu? [Y/N]"<<endl;
  cin>>ans;
  if(ans == "Y"||ans == "y"||ans == "yes"||ans == "Yes")
  {
    loop = true;
  }
  else{
    loop = false;
    system("CLS");
  }
}

}while(loop); //must be true in order to loop

}

}while(signout); //must be true in order to loop

  system("CLS");
  cout<<"Have a good day!"<<endl;
  return 0;

}
