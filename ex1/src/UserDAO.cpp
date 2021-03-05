#include <WinSock.h>
#include "mysql.h"
#include "UserDAO.h"
#include <string>

bool UserDAO::IsValid(std::string Parameter)
{
    std::string key[14] = {"and", "*", "=", " ", "%0a", "%", "/", "union", "|", "&", "^", "#", "/*", "*/"};
    for (int i = 0; i < 14; i++)
    {
        if (Parameter.find(key[i]) != std::string::npos)
        {
            return false;
        }
    }
    return true;
}

bool UserDAO::FindUser(std::string UserName, std::string UserPassword)
{
    if (!this->IsValid(UserName))
    {
        return false;
    }
    if (!this->IsValid(UserPassword))
    {
        return false;
    }
    MYSQL_RES *result = nullptr;
    MYSQL_ROW row;
    std::string sql = "select * from tb_reader where rdID = '" + UserName + "' and rdPwd = '" + UserPassword + "'";
    if (!db.open())
    {
        return false;
    }
    if ((result = db.exesql(sql)) == nullptr)
    {
        return false;
    }
    if ((row = mysql_fetch_row(result)) == nullptr)
    {
        return false;
    }
    return true;
}
