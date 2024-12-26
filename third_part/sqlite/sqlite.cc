#include "sqlite.h"

namespace MyOS {
CSqlite::CSqlite(void)
:db_ptr_(nullptr)
{

}

CSqlite::~CSqlite(void)
{
    this->close();
}

int 
CSqlite::open(const std::string &db_path)
{
    return sqlite3_open(db_path.c_str(), &db_ptr_);
}

int 
CSqlite::exec(const std::string &sql, std::string &err_msg)
{
    if (db_ptr_ == nullptr) {
        return -1;
    }

    char *msg = nullptr;
    int ret = sqlite3_exec(db_ptr_ , sql.c_str() ,callback ,nullptr, &msg); 
    err_msg = msg;

    return ret;
}

int 
CSqlite::close(void)
{
    if (db_ptr_ == nullptr) {
        return 0;
    }
    return sqlite3_close(db_ptr_);
}

int 
CSqlite::callback(void *NotUsed, int argc, char **argv, char **azColName)
{
    for(int i = 0; i < argc; ++i){
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

}