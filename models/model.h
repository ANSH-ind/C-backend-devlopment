#pragma once

#include <string>
#include <json/json.h>

struct user_validator
{
    std::string name;
    std::string email;
    int id;
};

void adduser(const user_validator &user);

Json::Value Finduser(int id);
