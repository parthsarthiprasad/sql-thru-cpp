# sql-thru-cpp

-this repository aims to provide a step by step process to install lampp in a linux distribution 
- to know more about [LAMP](https://www.digitalocean.com/community/tags/lamp-stack?type=tutorials) and tutorials .
- to know more about [MYSQL] ( https://www.mysql.com) and its implementation.

this setup helps in using MYSQL as RDBMS ( relational database management environment ) and PHP as object oriented scripting language.

# SQL through C PLUS PLUS  
### this is a Guide on how to use the XAMPP setup with C++.
---
C++ contains libraries and header files that can be used in order to access the data present in mysql or MariaDB. Follow the steps listed below in order to create the full development environment:

> These instructions are for debian based linux only.

1. Download XAMPP for linux using the following command: `$ wget https://www.apachefriends.org/xampp-files/7.3.9/xampp-linux-x64-7.3.9-0-installer.run`
2. Run the installer, this will install lampp which contains mariaDB which we will be using as our database
3. To install development files for C++ in order to use the database, open terminal and type
    1. `$ sudo apt install libmysqlcppconn-dev`
    2. `$ sudo apt install libmysqlcppconn7v5`
    3. `$ sudo apt install default-libmysqlclient-dev`
4. To start up the database use `$ sudo /opt/lampp/lampp start`
5. Now to test compile sample/first.cpp using `$ g++ sample/first.cpp -lmysqlclient -o ./test/first` it should compile successfully.
6. Run the compiled version normally using `$ ./test/first`
7. To stop the database use `$ sudo /opt/lampp/lampp stop`
---
### Directory Structure
- **sample**: contains the source-code for sample programs.
- **bin**: contains the compiled version of the sample program with the same name.
- **test**: empty directory for you to compile the source yourself.
