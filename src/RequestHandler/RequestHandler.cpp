/**
* Copyright (c) 2019 Gabriel Ferreira <gabrielinuz@gmail.com>. All rights reserved. 
* This file is part of CPPSET.
* Released under the GPL3 license
* https://opensource.org/licenses/GPL-3.0
**/

#include <iostream>
#include <memory>
#include <cppset/RequestHandlerInterface.h>
#include <vendors/nlohmann/json.hpp>
using json = nlohmann::json;

typedef std::shared_ptr<RequestHandlerInterface> IRequestHandlerPtr;

class RequestHandler : public RequestHandlerInterface
{
    public:
        RequestHandler(){}
        virtual ~RequestHandler(){}
        json getRequest()
        {
            //deserialize from standard input
            // nlohmann::json request;
            json request;
            std::cin >> request;
            return request;
        }
};

extern "C" IRequestHandlerPtr create(std::string);

IRequestHandlerPtr create(std::string typeinfo)
{
    return ( typeid(RequestHandlerInterface).name() == typeinfo )? std::make_shared<RequestHandler>() : nullptr;
}
