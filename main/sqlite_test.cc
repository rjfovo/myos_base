#include "sqlite.h"

#include <gtest/gtest.h>

class Sqlite_Test : public ::testing::Test {
protected:
    void SetUp() override {
        // Code here will be called immediately after the constructor (right
        // before each test).
    }

    void TearDown() override {
        // Code here will be called immediately after each test (right
        // before the destructor).
    }
};

TEST_F(Sqlite_Test, CreateTable)
{
    MyOS::CSqlite sql_conn;
    sql_conn.open("./test.db");
    /* Create SQL statement */
    std::string sql = "CREATE TABLE COMPANY("  \
         "ID INT PRIMARY KEY     NOT NULL," \
         "NAME           TEXT    NOT NULL," \
         "AGE            INT     NOT NULL," \
         "ADDRESS        CHAR(50)," \
         "SALARY         REAL );";

    std::string err_msg;
    sql_conn.exec(sql, err_msg);
    fprintf(stdout, "ret_msg: %s\n", err_msg.c_str());
}

TEST_F(Sqlite_Test, InsertData)
{
    MyOS::CSqlite sql_conn;
    sql_conn.open("./test.db");
    
    /* Create SQL statement */
    std::string sql = "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY) "  \
         "VALUES (1, 'Paul', 32, 'California', 20000.00 ); " \
         "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY) "  \
         "VALUES (2, 'Allen', 25, 'Texas', 15000.00 ); "     \
         "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY)" \
         "VALUES (3, 'Teddy', 23, 'Norway', 20000.00 );" \
         "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY)" \
         "VALUES (4, 'Mark', 25, 'Rich-Mond ', 65000.00 );";

    /* Execute SQL statement */
    std::string err_msg;
    sql_conn.exec(sql, err_msg);
    fprintf(stdout, "ret_msg: %s\n", err_msg.c_str());
}

TEST_F(Sqlite_Test, SelectData)
{
    MyOS::CSqlite sql_conn;
    sql_conn.open("./test.db");
    
    /* Create SQL statement */
   std::string sql = "SELECT * from COMPANY";

    /* Execute SQL statement */
    std::string err_msg;
    sql_conn.exec(sql, err_msg);
    fprintf(stdout, "ret_msg: %s\n", err_msg.c_str());
}

TEST_F(Sqlite_Test, UpdateData)
{
    MyOS::CSqlite sql_conn;
    sql_conn.open("./test.db");
    
    /* Create merged SQL statement */
    std::string sql = "UPDATE COMPANY set SALARY = 25000.00 where ID=1; " \
         "SELECT * from COMPANY";

    /* Execute SQL statement */
    std::string err_msg;
    sql_conn.exec(sql, err_msg);
    fprintf(stdout, "ret_msg: %s\n", err_msg.c_str());
}

TEST_F(Sqlite_Test, DeleteData)
{
    MyOS::CSqlite sql_conn;
    sql_conn.open("./test.db");
    
    /* Create merged SQL statement */
    std::string sql = "DELETE from COMPANY where ID=2; " \
         "SELECT * from COMPANY";

    /* Execute SQL statement */
    std::string err_msg;
    sql_conn.exec(sql, err_msg);
    fprintf(stdout, "ret_msg: %s\n", err_msg.c_str());
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}