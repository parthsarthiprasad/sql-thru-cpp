#include <bits/stdc++.h>
#include <windows.h>
#include <mysql.h>
using namespace std;

int main()
{
    MYSQL *conn;
    MYSQL_ROW row;
    MYSQL_RES *res;
    conn = mysql_init(0);
    int qstate;
    if (conn)
        cout << "Connection object OK" << conn << endl;
    else
        cout << "Connection object Problem!" << mysql_error(conn) << endl;
    conn = mysql_real_connect(conn, "localhost", "root", "", "organisation", 0, NULL, 0);

    if (conn)
    {
        cout << "Connection to Database done !!!" << conn << endl;
        char c='y';
        while(c=='y'){
            cout<<"1: Number of employees who joined in March 2015"<<endl;
            cout<<"2: Nth Highest Salary"<<endl;
            cout<<"3: Budget of each Department"<<endl;
            cout<<"4: Department with Maximum Budget"<<endl;
            int a;
            cin>>a;
            if(a==1){
                string s="SELECT * from employee where hire_date between 20150301 and 20150331";
                qstate=mysql_query(conn,s.c_str());
                if(!qstate){
                    res=mysql_store_result(conn);
                    cout<<setw(15)<<"Employee id";
                    cout<<setw(15)<<"Name";
                    cout<<setw(15)<<"DOB";
                    cout<<setw(15)<<"Salary";
                    cout<<setw(15)<<"Join Date";
                    cout<<setw(15)<<"Department Id"<<endl;
                    while(row=mysql_fetch_row(res)){
                        cout<<setw(15)<<row[0];
                        cout<<setw(15)<<row[1];
                        cout<<setw(15)<<row[2];
                        cout<<setw(15)<<row[5];
                        cout<<setw(15)<<row[6];
                        cout<<setw(15)<<row[7]<<endl;
                    }
                }
            }
            if(a==2){
                string n;
                cin>>n;
                string s="select min(salary) as Required_Salary from(select salary from employee order by salary desc limit "+n+") as Required";
                qstate=mysql_query(conn,s.c_str());
                if(!qstate){
                    res=mysql_store_result(conn);
                    cout<<setw(15)<<"Required Salary"<<endl;
                    while(row=mysql_fetch_row(res)){
                        cout<<setw(15)<<row[0]<<endl;
                    }
                }
            }
            if(a==3){
                string s="select department.name,sum(salary) as budget from employee,department where department.department_id=employee.department_id group by employee.department_id";
                qstate=mysql_query(conn,s.c_str());
                if(!qstate){
                    res=mysql_store_result(conn);
                    cout<<setw(25)<<"Department Name";
                    cout<<setw(25)<<"Budget"<<endl;
                    while(row=mysql_fetch_row(res)){
                        cout<<setw(25)<<row[0];
                        cout<<setw(25)<<row[1]<<endl;
                    }
                }
            }
            if(a==4){
                string s="select department.name,sum(salary) as budget from employee,department where department.department_id=employee.department_id group by employee.department_id order by budget desc limit 1";
                qstate=mysql_query(conn,s.c_str());
                if(!qstate){
                    res=mysql_store_result(conn);
                    cout<<setw(25)<<"Department Name";
                    cout<<setw(25)<<"Budget"<<endl;
                    while(row=mysql_fetch_row(res)){
                        cout<<setw(25)<<row[0];
                        cout<<setw(25)<<row[1]<<endl;
                    }
                }
            }
            cin>>c;
        }
    }

    else
    {
        cout << "Connection object Problem!" << mysql_error(conn) << endl;
    }

    return 0;
}


