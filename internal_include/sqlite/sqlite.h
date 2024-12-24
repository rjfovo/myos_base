#ifndef __SQLITE_H__
#define __SQLITE_H__

#include <string>

class CSqlite {
public:
    CSqlite(void);
    ~CSqlite(void);

    int open(const std::string &db_path);
    int exec(const std::string &sql, std::string &err_msg);
    int close();

private:
    sqlite3 * db_ptr_;
};

#endif