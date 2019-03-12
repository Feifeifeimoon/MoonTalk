#ifndef _MOONTALK_SERVER_LOGINSERVER_H_
#define _MOONTALK_SERVER_LOGINSERVER_H_

enum MSG_TYPE{
    MSG_TYPE_LOGIN = 1,
    MSG_TYPE_LOGIN_RET
};

struct DataHeader
{
    MSG_TYPE type;
    int length;
};

struct LogIn : public DataHeader
{
    char buf[64];
};

struct LogInRet : public DataHeader
{
    int ret;
    LogInRet()
    {
        type = MSG_TYPE_LOGIN_RET;
        length = 4;
    }

};

class TcpServer;
class TcpConnection;
class SqlConnectionPool;
class User;
class LoginServer
{
public:
    LoginServer(const char *ip, int port);
    ~LoginServer();
    void start();
private:
    void newMessage(TcpConnection& conn, char* buf);
    bool _confirm(const User& user);

    TcpServer*         m_server;
    SqlConnectionPool* m_sqlConnPool;
};

#endif