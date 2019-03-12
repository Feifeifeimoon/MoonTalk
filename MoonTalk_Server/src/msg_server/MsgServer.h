#ifndef _MOONTALK_SRC_MSGSERVER_H_
#define _MOONTALK_SRC_MSGSERVER_H_

class TcpServer;
class TcpConnection;
class SqlConnectionPool;
class User;

class MsgServer
{

public:
    MsgServer();
    ~MsgServer();
    void initialize();
    void start();
private:
    void newMessage(TcpConnection& conn, char* buf);
    void _getUserInfo(TcpConnection& conn, char* userName);
    void _getUserList(TcpConnection& conn, char* userName);
    TcpServer*         m_server;
    SqlConnectionPool* m_sqlConnPool;
};


#endif  //_MOONTALK_SRC_MSGSERVER_H_