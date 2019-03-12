#include "SqlConnection.h"
#include <stdio.h>
#include <string.h>

//DEBUG
#include <iostream>
SqlConnection::SqlConnection()
{
    mysql_init(&m_mysql);
}


SqlConnection::~SqlConnection()
{

}

bool SqlConnection::connect(const char* host, 
                            const char* user,
                            const char* passwd,
                            const char* db,
                            const unsigned int port)
{      
    if(!mysql_real_connect(&m_mysql, host, user, passwd, db, port, NULL, 0))
    {
        return false;
    }
    mysql_query(&m_mysql, "SET NAMES UTF8");        //否则无法读取中文
    return true;
}
bool SqlConnection::isExist(const char* table,
                            const char* field,
                            const char* value)
{
    char comm[128];
    int len = strlen(table) + strlen(field) + strlen(value) + 34;
    snprintf(comm, len,"SELECT COUNT(*) FROM %s WHERE %s = '%s'", table, field, value);
    mysql_query( &m_mysql, comm);
    MYSQL_RES *result = NULL;
    result = mysql_store_result( &m_mysql );

    MYSQL_ROW row;
    row = mysql_fetch_row(result);
    if( !strcmp(row[0], "0") )
    {
        return false;
    }
    return true;
}

bool SqlConnection::test(const char* comm)
{
    mysql_query( &m_mysql, comm);
    MYSQL_RES *result = NULL;
    result = mysql_store_result( &m_mysql );
    MYSQL_ROW row;
    row = mysql_fetch_row(result);
    if( !strcmp(row[0], "0") )
    {
        return false;
    }
    return true;
}


void SqlConnection::exec(const char* comm)
{
    mysql_query( &m_mysql, comm);
    if(0 != mysql_query(&m_mysql, comm))
    {
        printf("%s", mysql_error(&m_mysql));
    }
}


void SqlConnection::getUserInfoByName(std::vector<std::string>& info,char* userName)
{
    std::string cmd = "SELECT * FROM user WHERE userName = '"; 
    cmd += userName;
    cmd += "'";
    if(0 != mysql_query(&m_mysql, cmd.c_str()))
    {
        printf("mysql error\n");
        return ;
    }
    MYSQL_RES* Result = NULL;
    Result = mysql_store_result(&m_mysql);
    //int row = mysql_num_rows(Result);
	int field = mysql_num_fields(Result);
    MYSQL_ROW line = NULL;
    line = mysql_fetch_row(Result);
    if(line == NULL)
        return ;
    std::string current;
    for(int i = 0; i < field; ++i)
    {
        if(line[i])
        {
            current = line[i];
        }
        else
        {
            current = "";
        }
        info.push_back(current);
    }

}


void SqlConnection::getUserList(std::vector<std::vector<std::string> >& info ,char* userID)
{
    std::string cmd = "SELECT * FROM user WHERE userID in (SELECT friendID FROM relationship WHERE userID = '"; 
    cmd += userID;
    cmd += "')";
   // std::cout << cmd << std::endl;
    if(0 != mysql_query(&m_mysql, cmd.c_str()))
    {
        printf("mysql error\n");
        return ;
    }
    MYSQL_RES* Result = NULL;
    Result = mysql_store_result(&m_mysql);
    int row = mysql_num_rows(Result);
	int field = mysql_num_fields(Result);
    MYSQL_ROW line = mysql_fetch_row(Result);
    while(line != NULL)
    {
        std::vector<std::string> tmp;
        if(line == NULL)
            return ;
        std::string current;
        for(int i = 0; i < field; ++i)
        {
            if(line[i])
            {
                current = line[i];
            }
            else
            {
                current = "";
            }
            tmp.push_back(current);
        }
        info.push_back(tmp);
        line = mysql_fetch_row(Result);
    }
}