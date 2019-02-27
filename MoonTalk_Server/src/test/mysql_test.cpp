#include <mysql/mysql.h>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int main(void)
{
    MYSQL mysql;
    mysql_init(&mysql);
    mysql_real_connect(
        &mysql, "119.29.130.228", "root", "8888888866", "test", 3306, NULL, 0);

    string sql = "show tables;";//查询数据库
    mysql_query( &mysql, sql.c_str() );
    MYSQL_RES *result = NULL;
    result = mysql_store_result( &mysql );

    //得到查询出来所有数据记录的数量
    vector<string> allTable;
    MYSQL_ROW row = mysql_fetch_row( result );
    while( NULL != row )
    {
        allTable.push_back( row[0] );
        row = mysql_fetch_row( result );
    }
    for(vector<string>::const_iterator cit = allTable.begin(); cit != allTable.end(); ++cit )
    {
        cout << *cit << "\t"; //每次查到打印名字
    }
    cout << endl;
    mysql_free_result( result );
    mysql_close( &mysql );
    return 0;
}
