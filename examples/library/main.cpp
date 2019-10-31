#include <iostream>
#include <windows.h>
#include <mysql.h>
using namespace std;

void insertissue(){
MYSQL* conn;
                MYSQL_ROW row;
                MYSQL_RES* res;
                conn = mysql_init(0);
                int qstate;
                //  if (conn)
                //    cout<< "Connection object OK" <<conn<< endl;
                //else
                //  cout<< "Connection object Problem!" << mysql_error(conn) << endl;
                conn = mysql_real_connect(conn, "localhost","root","", "nsit", 0, NULL, 0);

string sid,bid,date,date2;
                cout<<"enter sid"<<endl;
                cin>>sid;
                cout<<"enter bid"<<endl;
                cin>>bid;
                cout<<"enter date"<<endl;
                cin>>date;
                 cout<<"enter return date"<<endl;
                cin>>date2;
                string que = "insert into borrows (s_id,b_id,issue_date,return_date) values('"+sid+"','" +bid+ "','" +date+ "','" +date2+ "')";
                const char * q = que.c_str();
                //cout<<"query is : " <<q << endl;
                qstate = mysql_query(conn, q);

}
void insertbooks(){

MYSQL* conn;
                MYSQL_ROW row;
                MYSQL_RES* res;
                conn = mysql_init(0);
                int qstate;
                //  if (conn)
                //    cout<< "Connection object OK" <<conn<< endl;
                //else
                //  cout<< "Connection object Problem!" << mysql_error(conn) << endl;
                conn = mysql_real_connect(conn, "localhost","root","", "nsit", 0, NULL, 0);
                string id,name,course;

                cout<<"enter book id"<<endl;
                cin>>id;
                cout<<"enter book title"<<endl;
                cin>>name;
                cout<<"enter course"<<endl;
                cin>>course;
                string que = "insert into books (b_id,title,course) values('"+id+"','" +name+ "','" +course+ "')";
                const char * q = que.c_str();
                //cout<<"query is : " <<q << endl;
                qstate = mysql_query(conn, q);
}
void insertinstudent(){
MYSQL* conn;
                MYSQL_ROW row;
                MYSQL_RES* res;
                conn = mysql_init(0);
                int qstate;
                //  if (conn)
                //    cout<< "Connection object OK" <<conn<< endl;
                //else
                //  cout<< "Connection object Problem!" << mysql_error(conn) << endl;
                conn = mysql_real_connect(conn, "localhost","root","", "nsit", 0, NULL, 0);

                string name,id,phone;
                cout<<"enter name"<<endl;
                cin>>name;
                cout<<"enter id"<<endl;
                cin>>id;
                cout<<"enter phone"<<endl;
                cin>>phone;
                string que = "insert into students (s_id,s_name,phone) values('"+id+"','" +name+ "','" +phone+ "')";
                const char * q = que.c_str();
                //cout<<"query is : " <<q << endl;
                qstate = mysql_query(conn, q);

}

void printissuerecord(){
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

    if (conn)
        {
        cout<< "Connection to Database done !!!" << conn <<endl;
        qstate = mysql_query(conn, "select * from borrows");
        if (!qstate)
        {
            res = mysql_store_result(conn);
            while (row=mysql_fetch_row(res))
            {
                cout<< "Student id  :"<< row[0] << " "
                    << "book id :"<< row[1]<<" "
                    << "issue date : "<<row[2]<<"  "
                    << "return date :  "<<row[3]<<endl;
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


}

void printbooks(){
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

    if (conn)
        {
        cout<< "Connection to Database done !!!" << conn <<endl;
        qstate = mysql_query(conn, "select * from books");
        if (!qstate)
        {
            res = mysql_store_result(conn);
            while (row=mysql_fetch_row(res))
            {
                cout<< "book id  :"<< row[0] << " "
                    << "title:"<< row[1]<<" "
                    << "course : "<<row[2]<<endl;
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


}
void printstudents()
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

    if (conn)
        {
        cout<< "Connection to Database done !!!" << conn <<endl;
        qstate = mysql_query(conn, "select * from students");
        if (!qstate)
        {
            res = mysql_store_result(conn);
            while (row=mysql_fetch_row(res))
            {
                cout<< "Student id  :"<< row[0] << " "
                    << "Name :"<< row[1]<<" "
                    << "phone No : "<<row[2]<<endl;
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




}
int main (){

   printstudents();
  printbooks();
   printissuerecord();
   insertinstudent();
   insertbooks();
  insertissue();
   printstudents();
   printbooks();
   printissuerecord();






return 0;
}
