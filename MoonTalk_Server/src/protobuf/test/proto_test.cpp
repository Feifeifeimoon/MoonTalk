#include <iostream>
#include <fstream>
#include <string>
#include "../login.pb.h"

using namespace std;
int main(int argc, char const *argv[])
{
    GOOGLE_PROTOBUF_VERIFY_VERSION;
    User user;
    user.set_account("account");
    user.set_password("password");
    char buf[128];
    user.SerializePartialToArray(buf, 128);
    printf("%d \n", (int)strlen(buf));
    /*for(int i = 0; i < strlen(buf); ++i)
    {
        printf("%x ", buf[i]);
    }*/
    User t;
    t.ParseFromArray(buf, strlen(buf));
    cout << t.account() << "|" << t.password() << endl;

    /*fstream output("./log", ios::out | ios::trunc | ios::binary); 
    if(!user.SerializeToOstream(&output))
    {
        
    }*/
    return 0;
}
