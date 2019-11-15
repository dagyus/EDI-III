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

class CreateNote : public ActionInterface
{
    public:
        CreateNote(){std::cout << "Se construye CreateNote " << std::endl;}
        virtual ~CreateNote(){std::cout << "Se destruye CreateNote " << std::endl;}
        void execute()
        {
            std::cout << "¡Create the note!" << std::endl;
        }
};

extern "C" IActionPtr create(std::string);

IActionPtr create(std::string typeinfo)
{
	return ( typeid(ActionInterface).name() == typeinfo )? std::make_shared<CreateNote>() : nullptr;
}
