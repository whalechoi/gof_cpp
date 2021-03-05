#include <string>
#include "mysql.h"
#ifndef __DBUtil_h__
#define __DBUtil_h__

class DBUtil
{
public:
    bool open();
    void close();
    MYSQL_RES *exesql(std::string sql);
    ~DBUtil();

private:
    MYSQL mysql, *real = nullptr;
    const char *host = "localhost";
    const char *user = "whale";
    const char *password = "123456";
    const char *database = "keshe";
    const int port = 3306;
};

#endif