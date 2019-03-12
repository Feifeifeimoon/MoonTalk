#ifndef _MOONTALK_SRC_BASE_SQLCONN_
#define _MOONTALK_SRC_BASE_SQLCONN_

#include "SqlConnection.h"

class SqlConn
{
public:
    SqlConn(SqlConnection* conn) : m_sqlConn(conn)
    { m_sqlConn->lock();}
    ~SqlConn() {m_sqlConn->unlock();};
    SqlConnection* get() { return m_sqlConn; }
private:
    SqlConnection* m_sqlConn;

};




#endif //_MOONTALK_SRC_BASE_SQLCONN_