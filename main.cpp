#include "document.h"
#include "writer.h"
#include "stringbuffer.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace rapidjson;
int main() {
    std::ifstream t("D:\\work\\study\\examination\\C\\demo\\medium4\\medium4\\test.json");
    std::stringstream stringbuffer;
    stringbuffer << t.rdbuf();
    std::string contents(stringbuffer.str());

    char *json;
    json = new char[contents.length()];
    memcpy(json, contents.c_str(), contents.length());
    //去除文件结尾
    size_t find = contents.rfind("}");
    if(find != std::string::npos)
    {
        json[find+1] = 0;
    }
    std::cout<<"buffer:\n %s" <<json<<std::endl;

    Document document;
    document.Parse(json);

    assert(document.HasMember("app_id"));
    assert(document["app_id"].IsString());
    std::cout<<"app_id:" << document["app_id"].GetString()<<std::endl;


    Value::MemberIterator app_secret = document.FindMember("app_secret");
    assert(app_secret != document.MemberEnd());
    assert(app_secret->value.IsString());
    std::cout<<"app_secret:" << app_secret->value.GetString()<<std::endl;

    Value& infoArray = document["data"];
    if (infoArray.IsArray()) {
        for (int i = 0; i < infoArray.Size(); i++) {
            const Value& object = infoArray[i];
            std::string deviceID = object["device"].GetString();
            std::cout<<"data["<<i<<"]."<<"device:"<<deviceID<<std::endl;

            const Value& userIds = object["userIds"];
            if (userIds.IsArray()) {
                for (int j = 0; j < userIds.Size(); j++) {
                    std::string userID = userIds[j].GetString();
                    std::cout<<"data["<<i<<"]."<<"userIds["<<j<<"]:"<<deviceID<<std::endl;
                }
            }
        }
    }
    delete []json;
    return 0;
}
