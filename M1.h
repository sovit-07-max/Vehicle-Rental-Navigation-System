#ifndef M1_H
#define M1_H
#include <iostream>
#include <string>
using namespace std;
class User{
protected:
    int userID;
    string name;
    string phone;
    string username;
    string password;

public:
    User(){
        userID = 0;
        name = "";
        phone = "";
        username = "";
        password = "";
    }
    void registerUser(){
        cout << "\n===== USER REGISTRATION =====\n";
        cout << "Enter User ID: ";
        cin >> userID;
        cin.ignore();
        cout << "Enter Name: ";
        getline(cin, name);
        cout << "Enter Phone Number: ";
        getline(cin, phone);
        cout << "Create Username: ";
        getline(cin, username);
        cout << "Create Password: ";
        getline(cin, password);
        cout << "\nRegistration Successful!\n";
    }
    bool login(){
        string enteredUsername;
        string enteredPassword;
        cout << "\n===== USER LOGIN =====\n";
        cout << "Enter Username: ";
        cin >> enteredUsername;
        cin.ignore();
        cout << "Enter Password: ";
        cin >> enteredPassword;
        cin.ignore();
        if (enteredUsername == username &&
            enteredPassword == password){
            cout << "\nLogin Successful!\n";
            return true;
        }
        cout << "\nInvalid Username or Password!\n";
        return false;
    }
    void displayUser() const{
        cout << "\n===== USER DETAILS =====\n";
        cout << "User ID  : " << userID << endl;
        cout << "Name     : " << name << endl;
        cout << "Phone    : " << phone << endl;
        cout << "Username : " << username << endl;
    }
    bool operator==(const User &u) const{
        return username == u.username;
    }
};
class Customer : public User{
public:
    void displayRole() const{
        cout << "Role: Customer\n";
    }
};
class Admin : public User{
public:
    void displayRole() const{
        cout << "Role: Admin\n";
    }
};
#endif