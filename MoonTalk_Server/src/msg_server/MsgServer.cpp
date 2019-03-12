#include "MsgServer.h"

#include "../base/ConfigReader.h"
#include "../net/TcpServer.h"
#include "../base/SqlConnectionPool.h"
#include "../base/SqlConnection.h"
#include "../base/SqlConn.h"
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
    case MSG_TYPE_GETUSERLIST:
    {
        UserListGet request = {};
        memcpy(&request, buf, sizeof(request));
        printf("userID:%s\n", request.buf);
        _getUserList(conn, request.buf);
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
    std::vector<std::string> info;
    SqlConn sqlConn(m_sqlConnPool->getNext());
    sqlConn.get()->getUserInfoByName(info, userName);
    for(auto i : info)
        std::cout << i << " ";
    std::cout << std::endl;
    UserInfoRet ret = {};
    char buf[128] = {};
    UserInfo userInfo;
    userInfo.set_userid(info[0]);
    userInfo.set_imageurl("/man.png");
    userInfo.set_nickname(info[3]);
    userInfo.set_sex(atoi(info[4].c_str()));
    userInfo.set_sign(info[5]);
    userInfo.SerializePartialToArray(buf, 128);
    // DEBUG
    // std::cout << userInfo.DebugString() << std::endl;
    int len = strlen(buf);
    ret.length = len;
    strncpy(ret.buf, buf, len + 1);
    conn.send((char*)&ret, sizeof(ret));
}


void MsgServer::_getUserList(TcpConnection& conn, char* userID)
{

    std::vector<std::vector<std::string> > info;
    SqlConn sqlConn(m_sqlConnPool->getNext());
    sqlConn.get()->getUserList(info, userID);
    for(int i = 0; i < info.size(); ++i)
    {
        for(auto it : info[i])
        {
            std::cout << it << " ";
        }
        std::cout << std::endl;
    }
    UserList userList;
    UserInfo* tmp;
    for(int i = 0; i < info.size(); ++i)
    {
        tmp = userList.add_userinfo();
        tmp->set_userid(info[i][0]);
        tmp->set_imageurl("/man.png");
        tmp->set_nickname(info[i][3]);
        tmp->set_sex(atoi(info[i][4].c_str()));
        tmp->set_sign(info[i][5]);
        //std::cout << tmp->DebugString() << std::endl;
    }
    //std::cout << userList.userinfo_size() << std::endl;
    UserListRet rep = {};
    char buf[1024] = {};
    userList.SerializePartialToArray(buf, 1024);
    int len = strlen(buf);
    rep.length = len;
    strncpy(rep.buf, buf, len + 1);
    conn.send((char*)&rep, sizeof(UserListRet));
    
}

