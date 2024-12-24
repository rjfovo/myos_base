#ifndef __APPIMAGE_H__
#define __APPIMAGE_H__

#include "app_define.h"

#include <string>

class CAppImage {
public:
    CAppImage();
    ~CAppImage();

    int install(const std::string &app_path);
    int uninstall(const std::string &app_path);
    
private:
};

#endif