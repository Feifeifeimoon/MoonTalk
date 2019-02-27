#include "SqlConnectionPool.h"

#include "SqlConnection.h"

SqlConnectionPool::SqlConnectionPool(int nums)
    : m_sqlconnection_nums(nums)
{

}

SqlConnectionPool::~SqlConnectionPool()
{}

void SqlConnectionPool::init(const char* host, 
                             const char* user,
                             const char* passwd,
                             const char* db,
                             const unsigned int port)
{
    for(int i = 0; i < m_sqlconnection_nums; ++i)
    {
        SqlConnection* t = new SqlConnection();
        t->connect(host, user, passwd, db, port);
        t->state = FREE;
        m_sqlconns.push_back(t);
    }
}

SqlConnection* SqlConnectionPool::getNext()
{
    for(int i = 0; i < m_sqlconns.size(); ++i)
    {
        if(m_sqlconns[i]->isFree())
        {
            return m_sqlconns[i];
        }
    }

    
}