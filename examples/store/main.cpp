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
    conn = mysql_real_connect(conn, "localhost", "root", "", "store", 0, NULL, 0);

    if (conn)
    {
        cout << "Connection to Database done !!!" << conn << endl;
        char c='y';
        while(c=='y'){
            cout<<"1: Show Customers Table"<<endl;
            cout<<"2: Show Product Table"<<endl;
            cout<<"3: Customers who purchased more than 3 units of a product on a day"<<endl;
            cout<<"4: Number of Products Sold on Each date"<<endl;
            cout<<"5: Insert into Invoice Table"<<endl;
            cout<<"6: Show Invoice Table"<<endl;
            int a;
            cin>>a;
            if(a==1){
                string s="select * from customers";
                qstate=mysql_query(conn,s.c_str());
                if(!qstate){
                    res=mysql_store_result(conn);
                    //cout<<setw(15)<<"ID";
                    cout<<setw(15)<<"First Name";
                    cout<<setw(15)<<"Last Name";
                    cout<<setw(15)<<"Balance"<<endl;
                    while(row=mysql_fetch_row(res)){
                        //cout<<setw(15)<<row[0];
                        cout<<setw(15)<<row[1];
                        cout<<setw(15)<<row[2];
                        cout<<setw(15)<<row[3]<<endl;
                    }

                }
            }
            if(a==2){
                string s="select * from products";
                qstate=mysql_query(conn,s.c_str());
                if(!qstate){
                        res=mysql_store_result(conn);
                    cout<<setw(15)<<"Product Name";
                    cout<<setw(15)<<"Price"<<endl;
                    while(row=mysql_fetch_row(res)){
                        cout<<setw(15)<<row[1];
                        cout<<setw(15)<<row[2]<<endl;
                    }
                }
            }
            if(a==3){
                string s="select cust_fname from customers,invoice where customers.cust_num=invoice.cust_num and unit_sold>3";
                qstate=mysql_query(conn,s.c_str());
                if(!qstate){
                    res=mysql_store_result(conn);
                    cout<<setw(15)<<"Customer Name"<<endl;
                    while(row=mysql_fetch_row(res)){
                        cout<<setw(15)<<row[0]<<endl;
                    }
                }
            }
            if(a==4){
                string s="select count(distinct prod_num) as count from invoice group by inv_date";
                qstate=mysql_query(conn,s.c_str());
                if(!qstate){
                    res=mysql_store_result(conn);
                    cout<<"Count"<<endl;
                    while(row=mysql_fetch_row(res)){
                        cout<<setw(2)<<row[0];
                        //cout<<setw(15)<<row[1]<<endl;
                    }
                }
            }
            if(a==5){
                string prod_num,cust_num,inv_date,unit_sold,inv_amount;
                cin>>prod_num>>cust_num>>inv_date>>unit_sold>>inv_amount;
                string s="INSERT INTO invoice (inv_num, prod_num, cust_num, inv_date, unit_sold, inv_amount) VALUES (NULL, '"+prod_num+"', '"+cust_num+"', '"+inv_date+"', '"+unit_sold+"', '"+inv_amount+"');";
                qstate=mysql_query(conn,s.c_str());
                cout<<"Inserted Successfully"<<endl;
            }
            if(a==6){
                string s="select * from invoice";
                qstate=mysql_query(conn,s.c_str());
                if(!qstate){
                    res=mysql_store_result(conn);
                    cout<<setw(15)<<"Invoice id";
                    cout<<setw(15)<<"Product id";
                    cout<<setw(15)<<"Customer id";
                    cout<<setw(15)<<"Invoice Date";
                    cout<<setw(15)<<"Unit Sold";
                    cout<<setw(15)<<"Invoice Amount"<<endl;
                    while(row=mysql_fetch_row(res)){
                        cout<<setw(15)<<row[0];
                        cout<<setw(15)<<row[1];
                        cout<<setw(15)<<row[2];
                        cout<<setw(15)<<row[3];
                        cout<<setw(15)<<row[4];
                        cout<<setw(15)<<row[5]<<endl;
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
