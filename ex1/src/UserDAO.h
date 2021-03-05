#include "DBUtil.h"

#ifndef __UserDAO_h__
#define __UserDAO_h__

class UserDAO
{
private:
    DBUtil db;
    bool IsValid(std::string Parameter);

public:
    bool FindUser(std::string UserName, std::string UserPassword);
};

#endif