#include <iostream>
#include <mysql/mysql.h>
#include <string>
#include <iomanip>

using namespace std;
/*
  for this one add a database called school in phpmyadmin and then run the binary.
*/
int addEntry(MYSQL *conn)
{
    string sid;
    string name;
    string rollno;
    int qstate;
    char reply;

    cin.ignore();
    cout << "Please enter the student ID.\n";
    cin >> sid;
    cin.ignore();
    cout << "Please enter the student's name.\n";
    getline(cin, name, '\n');
    //cin.ignore();
    cout << "Please enter the student's roll number.\n";
    getline(cin, rollno, '\n');

    string query = "INSERT INTO student (studentID, name, rollNo) VALUES ('" + sid + "', '" + name + "', '" + rollno + "');";

    qstate = mysql_query(conn, query.c_str());

    if (!qstate)
    {
        cout << "Entry added successfully, continue adding more?(y/N)\n";
        cin >> reply;

        if (reply == 'Y' || reply == 'y')
        {
            return 0;
        }

        else
        {
            return 1;
        }
    }

    else
    {
        cout << "Query failed to execute! " << mysql_error(conn) << "\n";
        return 1;
    }
}

void displayTable(MYSQL *conn)
{
    MYSQL_ROW row;
    MYSQL_RES *res;
    int qstate;
    string query = "SELECT * FROM student";

    qstate = mysql_query(conn, query.c_str());

    if (!qstate)
    {
        res = mysql_store_result(conn);
        cout << "=======================================================================\n";
        while (row = mysql_fetch_row(res))
        {
            cout << "Student id: " << setw(3) << internal << row[0] << " "
                 << "| Name: " << setw(31) << left << row[1] << " "
                 << "| Roll No: " << setw(3) << internal << row[2] << "|\n";
            cout << "=======================================================================\n";
        }
    }

    else
    {
        cout << "Query failed to execute! " << mysql_error(conn) << "\n";
    }
}

int main()
{
    MYSQL *conn = mysql_init(0);
    const char *hostname = "127.0.0.1";
    const char *user = "root";
    const char *password = "";
    const char *database = "School";
    int option;
    int failed = 0;

    if (conn)
    {
        cout << "Initialisation successful!\n";
    }

    else
    {
        cout << "Initialisation failed! " << mysql_error(conn) << "exiting.\n";
        return 1;
    }

    conn = mysql_real_connect(conn, hostname, user, password, database, 0, 0, 0);

    if (conn)
    {
        cout << "Connection to database successful!\n"
             << "----------------------------------------------------------------\n";
    options:
        cout << "\nPlease select an option:\n"
             << "1. Add Entry to table.\n"
             << "2. Display Table. \n"
             << "3. Exit program.\n";

        cin >> option;
        switch (option)
        {
        case 1:
            //adds entries
            {
                while (!failed)
                {
                    failed = addEntry(conn);
                }

                failed = 0;
                goto options;
            }
            break;

        case 2:
            //displays entries
            {
                displayTable(conn);
                goto options;
            }
            break;

        case 3:
            return 0;
            break;

        default:
            cout << "Invalid option, please try again.\n";
            goto options;
            break;
        }
    }

    else
    {
        cout << "Connection to database failed! " << mysql_error(conn) << " exiting.\n";
        return 1;
    }
}

