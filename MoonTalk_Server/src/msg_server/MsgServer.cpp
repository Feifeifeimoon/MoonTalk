#include "MsgServer.h"

#include "../base/ConfigReader.h"
#include "../net/TcpServer.h"
#include "../base/SqlConnectionPool.h"
#include "../base/SqlConnection.h"
#include "./message.h"
#include "../protobuf/userInfo.pb.h"

MsgServer::MsgServer()
    : m_server(nullptr),
      m_sqlConnPool(new SqlConnectionPool(5))
{}

MsgServer::~MsgServer()
{}

void MsgServer::initialize()
{
    ConfigReader reader("../src/msg_server/msg.conf");
    char* ip = reader.getConfigByName("IP");
    char* str_port = reader.getConfigByName("Port");
    int port = atoi(str_port);
    m_server = new TcpServer(ip, port);
    m_server->setMessageCallback(
        std::bind(&MsgServer::newMessage, this, std::placeholders::_1, std::placeholders::_2)
    );
    char* SqlIP = reader.getConfigByName("SqlIP");
    char* str_port1 = reader.getConfigByName("SqlPort");
    int port1 = atoi(str_port1);
    char* user = reader.getConfigByName("User");
    char* pass = reader.getConfigByName("PassWrd");
    char* DB = reader.getConfigByName("DB");
    m_sqlConnPool->init(SqlIP, user, pass, DB, port1);

}

void MsgServer::start()
{
    m_server->run();
}


void MsgServer::newMessage(TcpConnection& conn, char* buf)
{
    printf("rec new Message\n");
    DataHeader dh = {};
    memcpy(&dh, buf, sizeof(dh));
    switch(dh.type)
    {
    case MSG_TYPE_GETUSERINFO:
    {
        UserInfoGet userInfo = {};
        memcpy(&userInfo, buf, sizeof(userInfo));
        printf("userName:%s\n", userInfo.username);
        _getUserInfo(conn, userInfo.username);
    }
    break;
    default:
        break;
    }
}
//DEBUG
#include <iostream>
void MsgServer::_getUserInfo(TcpConnection& conn, char* userName)
{
    SqlConnection* sqlConn = m_sqlConnPool->getNext();
    std::vector<std::string> info;
    sqlConn->getUserInfoByName(info, userName);
    for(auto i : info)
        std::cout << i << std::endl;
}

