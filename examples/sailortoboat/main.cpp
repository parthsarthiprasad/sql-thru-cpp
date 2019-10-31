#include <iostream>
#include <windows.h>
#include <mysql.h>
using namespace std;

int main()
{
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* res;
    conn = mysql_init(0);
    int qstate;
    if (conn)
        cout<< "Connection object OK" <<conn<< endl;
    else
        cout<< "Connection object Problem!" << mysql_error(conn) << endl;
    conn = mysql_real_connect(conn, "localhost","root","", "nsit", 0, NULL, 0);

    cout<<"select from menu "<<endl;
    cout<<" 1. for name and age of sailor" <<endl;
     cout<<" 2. for info of sailors who have reserved boat number 101" <<endl;
      cout<<" 3. for name of sailors who have reserved a red  boat  , and list in the order of age"  <<endl;
       cout<<" 4. for name of sailors who have received atleast one boat" <<endl;
        cout<<" 5. for ids and name of sailor who have reserved two different boats on the same day" <<endl;
        int x;
        cin>>x;
        switch(x){
        case 1 : { qstate = mysql_query(conn, "select s_name,age FROM sailor2");
        if (!qstate)
        {
            res = mysql_store_result(conn);
            while (row=mysql_fetch_row(res))
            {
                cout<< row[0] << " "
                    << row[1]<<" "
                    << row[2]<<endl;
            }
        }
    else
    {
       cout<< "Query Execution Problem!" << mysql_error(conn) << endl;
    }
        }
        case 2 : {

         qstate = mysql_query(conn, "select S.*  FROM sailor2 S , reserve R  WHERE S.s_id = R.s_id AND R.b_id = 101");
        if (!qstate)
        {
            res = mysql_store_result(conn);
            while (row=mysql_fetch_row(res))
            {
                cout<< row[0] << " "
                    << row[1]<<" "
                    << row[2]<<endl;
            }
        }
    else
    {
       cout<< "Query Execution Problem!" << mysql_error(conn) << endl;
    }


        }
        case 3: {
         qstate = mysql_query(conn, "select S.s_name , S.age   FROM sailor2 S, reserve R , boat B  WHERE S.s_id = R.s_id AND R.b_id = B.b_id AND B.color = 'red'  ORDER BY S.age");
        if (!qstate)
        {
            res = mysql_store_result(conn);
            while (row=mysql_fetch_row(res))
            {
                cout<< row[0] << " "
                    << row[1]<<" "
                    << row[2]<<endl;
            }
        }
    else
    {
       cout<< "Query Execution Problem!" << mysql_error(conn) << endl;
    }

    }

    case 4: { qstate = mysql_query(conn, "select s_name  FROM sailor2 S , reserve R  WHERE S.s_id = R.s_id");
        if (!qstate)
        {
            res = mysql_store_result(conn);
            while (row=mysql_fetch_row(res))
            {
                cout<< row[0] << " "
                    << row[1]<<" "
                    << row[2]<<endl;
            }
        }
    else
    {
       cout<< "Query Execution Problem!" << mysql_error(conn) << endl;
    }
    }

      case 5 : {   qstate = mysql_query(conn, "select DISTINCT S.s_id , S.s_name  FROM sailor2 S , reserve R1 , reserve R2   WHERE  S.s_id =  R1.s_id AND S.s_id = R2.s_id  AND R1.day = R2.day AND R1.b_id <> R2.b_id");
        if (!qstate)
        {
            res = mysql_store_result(conn);
            while (row=mysql_fetch_row(res))
            {
                cout<< row[0] << " "
                    << row[1]<<" "
                    << row[2]<<endl;
            }
        }
    else
    {
       cout<< "Query Execution Problem!" << mysql_error(conn) << endl;
    }
      }




        }
    if (conn)
        {
        cout<< "Connection to Database done !!!" << conn <<endl;
        qstate = mysql_query(conn, "select s_name,age FROM sailor2");
        if (!qstate)
        {
            res = mysql_store_result(conn);
            while (row=mysql_fetch_row(res))
            {
                cout<< row[0] << " "
                    << row[1]<<" "
                    << row[2]<<endl;
            }
        }
    else
    {
       cout<< "Query Execution Problem!" << mysql_error(conn) << endl;
    }
        }

    else
    {
     cout<< "Connection object Problem!" << mysql_error(conn) << endl;
    }



        return 0;
}

