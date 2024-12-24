#include "sqlite.h"

#include <sqlite3.h>

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
    int ret = sqlite3_exec(db_ptr_ , sql.c_str() ,0 ,0, &msg); 
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