#ifndef _MOONTALK_BASE_SQLCONNECTIONPOOL_H_
#define _MOONTALK_BASE_SQLCONNECTIONPOOL_H_

#include <vector>

class SqlConnection;

class SqlConnectionPool
{
public:
    SqlConnectionPool(int nums);
    ~SqlConnectionPool();
    void init(const char* host, 
              const char* user,
              const char* passwd,
              const char* db,
              const unsigned int port);
    SqlConnection* getNext();
private:
    int m_sqlconnection_nums;
    int m_next;
    std::vector<SqlConnection*> m_sqlconns;
};


#endif