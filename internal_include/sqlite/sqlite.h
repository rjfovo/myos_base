#ifndef __SQLITE_H__
#define __SQLITE_H__

#include <string>
#include <sqlite3.h>

namespace MyOS {

class CSqlite {
public:
    CSqlite(void);
    ~CSqlite(void);

    int open(const std::string &db_path);
    int exec(const std::string &sql, std::string &err_msg);
    int close(void);

    static int callback(void *NotUsed, int argc, char **argv, char **azColName);
private:
    sqlite3 * db_ptr_;
};

}
#endif