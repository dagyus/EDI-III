/**
* Copyright (c) 2019 Gabriel Ferreira <gabrielinuz@gmail.com>. All rights reserved. 
* This file is part of CPPSET.
* Released under the GPL3 license
* https://opensource.org/licenses/GPL-3.0
**/

#include <iostream>
#include <memory>
#include <cppset/ActionInterface.h>
#include <cppset/RequestHandlerInterface.h>
#include <cppset/ResponseHandlerInterface.h>

typedef std::shared_ptr<ActionInterface> IActionPtr;

class ReadNotes : public ActionInterface
{
    public:
        ReadNotes(){std::cout << "Se construye ReadNotes " << std::endl;}
        virtual ~ReadNotes(){std::cout << "Se destruye ReadNotes " << std::endl;}
        void execute()
        {
            std::cout << "¡Read the notes!" << std::endl;
        }
};

extern "C" IActionPtr create(std::string);

IActionPtr create(std::string typeinfo)
{
	return ( typeid(ActionInterface).name() == typeinfo )? std::make_shared<ReadNotes>() : nullptr;
}
