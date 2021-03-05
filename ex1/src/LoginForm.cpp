#include <iostream>
#include "LoginForm.h"


void LoginForm::init()
{
    std::cout << "Welcome to GoF(CPP version) ex1!" << std::endl;
    this->display();
}

void LoginForm::display()
{
    std::cout << "Please login!" << std::endl;
    std::cout << "User Name:";
    std::cin >> UserName;
    std::cout << "User Password:";
    std::cin >> UserPassword;
    this->validate();
}

void LoginForm::validate()
{
    if (dao.FindUser(UserName, UserPassword))
    {
        std::cout << "Login success!" << std::endl;
    }
    else
    {
        std::cout << "Login failed!" << std::endl;
    }
    std::cout << "Bye!" << std::endl;
}