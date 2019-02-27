#include "../SqlConnectionPool.h"
#include "../SqlConnection.h"
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>


int main(int argc, char const *argv[])
{
    SqlConnectionPool pool(5);
    pool.init("119.29.130.228", "root", "8888888866", "moontalk", 3306);
    SqlConnection* conn = pool.getNext();


    std::vector<std::string> in;
    conn->getUserInfoByName(in, "11");

    for(auto i : in)
    {
        std::cout << i << " ";
    }
    return 0;
}
