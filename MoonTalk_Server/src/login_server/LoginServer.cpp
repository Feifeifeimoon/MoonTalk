#include "LoginServer.h"
#include <string>
#include "../base/SqlConnectionPool.h"
#include "../base/SqlConnection.h"
#include "../net/TcpServer.h"
#include "../protobuf/login.pb.h"
/*
        ._
      ._(.)<  (GAGAGA)
       \___)  
~~~~~~~~~~~~~~~~~~~~~~~*/

LoginServer::LoginServer(const char *ip, int port)
    :m_server(new TcpServer(ip, port)),
     m_sqlConnPool(new SqlConnectionPool(5))
{
    m_server->setMessageCallback(
        std::bind(&LoginServer::newMessage, this, std::placeholders::_1, std::placeholders::_2));
    m_sqlConnPool->init("119.29.130.228", "root", "8888888866", "moontalk", 3306);
}



LoginServer::~LoginServer()
{

}


void LoginServer::start()
{
    m_server->run();
}

void LoginServer::newMessage(TcpConnection& conn, char* buf)
{
    DataHeader dh = {};
    memcpy(&dh, buf, sizeof(dh));
    switch(dh.type)
    {
    case MSG_TYPE_LOGIN:
    {
        LogIn login = {};
        LogInRet ret = {};
        memcpy(&login,buf, sizeof(login));
        User user;
        user.ParseFromArray(login.buf, login.length);
        std::cout << user.account() << "|" << user.password() <<  "|" << inet_ntoa(conn.addr().sin_addr) << std::endl;
        if(_confirm(user))
        {
            std::cout << "Login Successful \n";
            ret.ret = 1;
        }
        else
        {
            std::cout << "Login Failed Wrong Accont Or PassWord \n";
            ret.ret = 0;
        }
        conn.send((char*)&ret, sizeof(ret));
    }
    }
}

bool LoginServer::_confirm(const User& user)
{
    SqlConnection* sqlConnection = m_sqlConnPool->getNext();
    std::string cmd = "SELECT COUNT(*) FROM user WHERE userName = '" + user.account() + "' AND passWord = '" + user.password() + "'";
    return sqlConnection->test(cmd.c_str());
}
