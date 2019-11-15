/**
* Copyright (c) 2016 Gabriel Ferreira <gabrielinuz@gmail.com>. All rights reserved. 
* This file is part of CPPSET.
* Released under the GPL3 license
* https://opensource.org/licenses/GPL-3.0
**/
#ifndef RESPONSE_HANDLER_INTERFACE_H
#define RESPONSE_HANDLER_INTERFACE_H

#include <iostream>
#include <vendors/nlohmann/json.hpp>
using json = nlohmann::json;

class ResponseHandlerInterface
{
    public:
    	virtual void setResponse(json response) = 0;
};

#endif // RESPONSE_HANDLER_INTERFACE_H