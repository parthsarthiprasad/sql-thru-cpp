#include <iostream>
#include <mysql/mysql.h>
#include <string.h>
using namespace std;

/*
Although the code might compile, the actual binary might through an error.
Before actually running the binary goto 127.0.0.1/phpmyadmin and create a database 
called "mydatabase", add a table with 3 attributes to it and add some entries manually
later samples shows how to add entries via C++ as well.
*/


int main()
{
    MYSQL *conn;  //pointer to MYSQL object
    MYSQL_ROW row; //MYSQL_ROW object (to manipulate rows)
    MYSQL_RES *res; //pointer to MYSQL_RES object( to get result data)
    conn = mysql_init(0);
    int qstate; //query state (success if 0)

    const char* hostname = "127.0.0.1";
    const char* user = "root";
    const char* password = "";
    const char* database = "mydatabase"; //could be any database that you create using phpmyadmin

    if (conn)
    {
        cout << "Initialisation successful!\n";
    }

    else
    {
        cout << "Initialisation failed! " << mysql_error(conn) << "\n";
    }

    conn = mysql_real_connect(conn, hostname, user, password, database, 0, 0, 0);

    if (conn)
    {
        cout << "Connection to database successful!\n\n"
             << "----------------------------------------------------------------------------------\n";
        
        qstate = mysql_query(conn, "select * from table"); //general SQL query (could be anything)
        if (!qstate) //if query runs successfully
        {
            res = mysql_store_result(conn);
            while (row = mysql_fetch_row(res))
            {
                cout << "Attribute 1: " << row[0] << " "
                     << "Attribute 2: " << row[1] << " "
                     << "Attribute 3: " << row[2] << "\n"
                     << "----------------------------------------------------------------------------------";
            }
        }

        else
        {
            cout << "query failed to execute!" << mysql_error(conn) << "\n";
        }
    }

    else
    {
        cout << "connection to database couldn't be made!" << mysql_error(conn) << conn << "\n";
    }

    return 0;
}
