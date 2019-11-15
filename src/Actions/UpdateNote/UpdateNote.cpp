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

class UpdateNote : public ActionInterface
{
    public:
        UpdateNote(){std::cout << "Se construye UpdateNote " << std::endl;}
        virtual ~UpdateNote(){std::cout << "Se destruye UpdateNote " << std::endl;}
        void execute()
        {
            std::cout << "¡Update the note!" << std::endl;
        }
};

extern "C" IActionPtr create(std::string);

IActionPtr create(std::string typeinfo)
{
	return ( typeid(ActionInterface).name() == typeinfo )? std::make_shared<UpdateNote>() : nullptr;
}
