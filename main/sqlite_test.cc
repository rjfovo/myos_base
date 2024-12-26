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

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}