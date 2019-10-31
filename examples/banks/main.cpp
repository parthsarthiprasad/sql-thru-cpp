#include <iostream>
#include <windows.h>
#include <mysql.h>
using namespace std;

void insertdata(){
 MYSQL* conn;

    MYSQL_ROW row;
    MYSQL_RES* res;
    conn = mysql_init(0);
    int qstate;
   // if (conn)
      //  cout<< "Connection object OK" <<conn<< endl;
    //else
       // cout<< "Connection object Problem!" << mysql_error(conn) << endl;
    conn = mysql_real_connect(conn, "localhost","root","", "nsit", 0, NULL, 0);
   string custid , custname , ifsc , num_of_fd;
   string savings , employee;
   cout<<"enter the customer id "<<endl;
   cin>>custid;
   cout<<"enter the customer name "<<endl;
   cin>>custname;
   cout<<"enter the ifsc code"<<endl;
   cin>>ifsc;
    cout<<"is an employee (1 for yes ,  0 for no) "<<endl;
   cin>>employee;
    cout<<"is savings account(1 for yes ,  0 for no) ? "<<endl;
   cin>>savings;
   cout<<"enter the number of fd"<<endl;
   cin>>num_of_fd;


   string que = "insert into customer(cust_id,cust_name,ifsc,savings,no_of_fd,employee) values ('"+custid+"','"+custname+"','"+ifsc+"','"+employee+"','"+savings+"','"+num_of_fd+"')";
const char * q = que.c_str();
qstate = mysql_query(conn,q);
if(!qstate)
cout<<endl<<"inserted";
else
cout<<endl<<"error";


}



void display()
{
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* res;
    conn = mysql_init(0);
    int qstate;
   // if (conn)
      //  cout<< "Connection object OK" <<conn<< endl;
    //else
       // cout<< "Connection object Problem!" << mysql_error(conn) << endl;
    conn = mysql_real_connect(conn, "localhost","root","", "nsit", 0, NULL, 0);

    if (conn)
        {
        cout<< "Connection to Database done !!!" << conn <<endl;
        qstate = mysql_query(conn, "select * from customer");
        if (!qstate)
        {
            res = mysql_store_result(conn);
            while (row=mysql_fetch_row(res))
            {
                cout<< "customer id :"<< row[0] <<endl
                    << " customer Name :"<< row[1]<<endl
                    << "ifsc code "<<row[2]<<endl
                    << "savings account"<<row[3]<<endl
                    << " no. of fd "<<row[4]<<endl
                    << "is an employee"<<row[5]<<endl;
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

int main(){

int ans ;
cout<<"/n enter "<<endl;
cout<<"1. insert    2. display  3.  quit"<<endl;
cin>>ans;
switch(ans){

case 1: {insertdata();
}break;

case 2: {display();}
break;

default : break;



}

return 0;



}

