//route.cc
#include "route.h"
#include "model.h"

#include <drogon/drogon.h>

using namespace drogon;

void route::home(
    const HttpRequestPtr &req,
    std::function<void(const HttpResponsePtr &)> &&callback)
{
    Json::Value response;

    response["running"] = true;
    response["port"] = 8000;
    response["language"] = "c++";

    auto resp = HttpResponse::newHttpJsonResponse(response);

    callback(resp);
}

void route::AddUser(
    const HttpRequestPtr &req,
    std::function<void(const HttpResponsePtr &)> &&callback)
{
    auto user_data = req->getJsonObject();

    if (!user_data)
    {
        Json::Value invalid;
        invalid["reason"] = "json body required";

        auto resp = HttpResponse::newHttpJsonResponse(invalid);
        resp->setStatusCode(k400BadRequest);

        callback(resp);
        return;
    }

    user_validator user;

    user.id = (*user_data)["id"].asInt();
    user.name = (*user_data)["name"].asString();
    user.email = (*user_data)["email"].asString();

    adduser(user);

    Json::Value result;
    result["status"] = "user added";
    result["id"] = user.id;
    result["name"] = user.name;

    auto resp = HttpResponse::newHttpJsonResponse(result);

    callback(resp);
}

void route::finduser(
    const HttpRequestPtr &req,
    std::function<void(const HttpResponsePtr &)> &&callback,
    int id)
{
    Json::Value user = Finduser(id);

    if (user.isNull())
    {
        Json::Value not_found;
        not_found["status"] = "not found";
        not_found["id"] = id;

        auto resp = HttpResponse::newHttpJsonResponse(not_found);
        resp->setStatusCode(k404NotFound);

        callback(resp);
        return;
    }

    auto resp = HttpResponse::newHttpJsonResponse(user);

    callback(resp);
}
