#include "LoginServer.h"
#include "../base/ConfigReader.h"

int main(void)
{
    ConfigReader reader("../src/login_server/login.conf");
    char* ip = reader.getConfigByName("IP");
    char* str_port = reader.getConfigByName("Port");
    int port = atoi(str_port);
    LoginServer server(ip, port);
    server.start();

}