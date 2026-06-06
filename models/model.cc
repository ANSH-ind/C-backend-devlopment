#include "model.h"
#include <vector>

std::vector<user_validator> Users;

void adduser(const user_validator &user)
{
    Users.push_back(user);
}

Json::Value Finduser(int id)
{
    for (auto &user : Users)
    {
        if (user.id == id)
        {
            Json::Value result;
            result["id"] = user.id;
            result["name"] = user.name;
            result["email"] = user.email;

            return result;
        }
    }

    return Json::Value();
}
