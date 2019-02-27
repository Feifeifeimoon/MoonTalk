#ifndef _MOONTALK_BASE_SQLCONNECTION_H_
#define _MOONTALK_BASE_SQLCONNECTION_H_

#include <vector>
#include <string>
#include <mysql/mysql.h>

#define FREE 1
#define BUSY 0

class SqlConnection
{
public:
    SqlConnection();
    ~SqlConnection();
    bool connect(const char* host, 
                 const char* user,
                 const char* passwd,
                 const char* db,
                 const unsigned int port);
    bool isExist(const char* table,
                 const char* field,
                 const char* value);
    bool test(const char* comm);
    void exec(const char* comm);
    void getUserInfoByName(std::vector<std::string>& info,char* userName);
    bool isFree() { return state;};
    int  state;
private:
    MYSQL m_mysql;
};


#endif