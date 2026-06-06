#pragma once

#include <drogon/HttpController.h>

using namespace drogon;

class route : public HttpController<route>
{
public:
    METHOD_LIST_BEGIN
    ADD_METHOD_TO(route::home, "/", Get);
    ADD_METHOD_TO(route::AddUser, "/adduser", Post);
    ADD_METHOD_TO(route::finduser, "/find/{id}", Get);
    METHOD_LIST_END

    void home(
        const HttpRequestPtr &req,
        std::function<void(const HttpResponsePtr &)> &&callback);

    void AddUser(
        const HttpRequestPtr &req,
        std::function<void(const HttpResponsePtr &)> &&callback);

    void finduser(
        const HttpRequestPtr &req,
        std::function<void(const HttpResponsePtr &)> &&callback,
        int id);
};
