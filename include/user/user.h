#ifndef __USER_H__
#define __USER_H__

#include <string>
#include <map>

namespace MyOS {

struct SUserInfo {
    std::string name;
    std::string user_path;
    std::string system_user_path;
};

class CUser {
public:
    CUser(void);
    ~CUser(void);

    int load_user_info(void);
    int check_user(void);

    std::string get_user_name(void);
    SUserInfo get_user_info(void);

    int modify_username(const std::string &new_name);
    int modify_passwd(const std::string &old_name, const std::string &new_name);

    int remove_user_info(void);

private:
    SUserInfo user_info_;
};

class CUserManager {
public:
    CUserManager(void);
    ~CUserManager(void);

    int create_user(const std::string &user_name);
    int remove_user(const std::string &username);
    CUser* get_user(const std::string &user_name);

private:
    int load_user_data(void);
    int check_user(void);

private:
    std::map<std::string, CUser*> mp_user_;
};

}
#endif