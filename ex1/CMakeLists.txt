cmake_minimum_required(VERSION 3.15)
project(ex1)

set(CMAKE_CXX_STANDARD 11)

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/include")

FIND_LIBRARY(MYSQL_LIB libmysql "${CMAKE_CURRENT_SOURCE_DIR}/lib/libmysql.lib" NO_DEFAULT_PATH)

FIND_LIBRARY(MYSQL_CLIENT_LIB mysqlclient "${CMAKE_CURRENT_SOURCE_DIR}/lib/mysqlclient.lib" NO_DEFAULT_PATH)

link_libraries(${MYSQL_LIB} ${MYSQL_CLIENT_LIB})

add_executable(ex1
        src/main.cpp
        src/LoginForm.h
        src/LoginForm.cpp
        src/UserDao.h
        src/UserDao.cpp
        src/DBUtil.h
        src/DBUtil.cpp
)
