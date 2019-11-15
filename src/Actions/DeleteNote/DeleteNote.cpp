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

class DeleteNote : public ActionInterface
{
    public:
        DeleteNote(){std::cout << "Se construye DeleteNote " << std::endl;}
        virtual ~DeleteNote(){std::cout << "Se destruye DeleteNote " << std::endl;}
        void execute()
        {
            std::cout << "¡Delete the note!" << std::endl;
        }
};

extern "C" IActionPtr create(std::string);

IActionPtr create(std::string typeinfo)
{
	return ( typeid(ActionInterface).name() == typeinfo )? std::make_shared<DeleteNote>() : nullptr;
}
