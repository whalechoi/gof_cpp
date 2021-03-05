#include "UserDAO.h"

#ifndef __LoginForm_h__
#define __LoginForm_h__

class LoginForm
{
private:
    UserDAO dao;
    std::string UserName = "";
    std::string UserPassword = "";

public:
    void init();
    void display();
    void validate();
};

#endif