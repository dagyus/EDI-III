/**
* Copyright (c) 2016 Gabriel Ferreira <gabrielinuz@gmail.com>. All rights reserved. 
* This file is part of CPPSET.
* Released under the GPL3 license
* https://opensource.org/licenses/GPL-3.0
**/

#ifndef REQUEST_HANDLER_INTERFACE_H
#define REQUEST_HANDLER_INTERFACE_H

#include <iostream>
#include <vendors/nlohmann/json.hpp>
using json = nlohmann::json;

class RequestHandlerInterface
{
    public:
    	virtual json getRequest() = 0;
};

#endif // REQUEST_HANDLER_INTERFACE_H