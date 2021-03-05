#include <WinSock.h>
#include <iostream>
#include "mysql.h"
#include "DBUtil.h"

bool DBUtil::open()
{
    mysql_init(&mysql);
    real = mysql_real_connect(&mysql, host, user, password, database, port, NULL, 0);
    if (real == nullptr)
    {
        std::cout<<"Open Mysql connection failed!"<<std::endl;
        return false;
    }
    return true;
}

void DBUtil::close()
{
    if (real == nullptr)
    {
        return;
    }
    mysql_close(real);
    real = nullptr;
    return;
}

MYSQL_RES *DBUtil::exesql(std::string sql)
{
    MYSQL_RES *result;
    if (this->real == nullptr)
    {
        return nullptr;
    }
    if (mysql_query(&mysql, sql.c_str()) != 0)
    {
        return nullptr;
    }
    if ((result = mysql_store_result(&mysql)) == nullptr)
    {
        return nullptr;
    }
    return result;
}

DBUtil::~DBUtil(){
    close();
}
