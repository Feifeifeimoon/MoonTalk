#include "MsgServer.h"


int main()
{
    MsgServer* t = new MsgServer();
    t->initialize();
    t->start();
}