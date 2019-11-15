/**
* Copyright (c) 2019 Gabriel Ferreira <gabrielinuz@gmail.com>. All rights reserved. 
* This file is part of CPPSET.
* Released under the GPL3 license
* https://opensource.org/licenses/GPL-3.0
**/

#include <iostream>
#include <memory>
#include <cppset/ApplicationInterface.h>
#include <cppset/ActionInterface.h>
#include <cppset/ComponentFactory.h>
#include <cppset/IniReader.h>
#include <cppset/RequestHandlerInterface.h>


typedef std::shared_ptr<ApplicationInterface> IApplicationPtr;
typedef std::shared_ptr<ActionInterface> IActionPtr;
typedef std::shared_ptr<ComponentFactory> ComponentFactoryPtr;
typedef std::shared_ptr<IniReader> IniReaderPtr;
typedef std::shared_ptr<RequestHandlerInterface> IRequestHandlerPtr;

class Application : public ApplicationInterface
{
    public:
        Application()
        {
            IniReaderPtr iniReader( new IniReader() );
            iniReader->open("configuration.ini");
            this->actionsPath = iniReader->selectSection("GENERAL")->getValue("actionsPath");
        }
        
        virtual ~Application(){}

        void run()
        {
            ComponentFactoryPtr cF(new ComponentFactory());
            //IRequestHandlerPtr rH = cF->create<RequestHandlerInterface>("RequestHandler");
            //json request = rH->getRequest();

            // IActionPtr action = cF->create<ActionInterface>(this->actionsPath + request["action"]);
            IActionPtr action = cF->create<ActionInterface>(this->actionsPath + "CreateNote");
            action->execute();
        }
    private:
        std::string actionsPath;
};

extern "C" IApplicationPtr create(std::string);

IApplicationPtr create(std::string typeinfo)
{
    return ( typeid(ApplicationInterface).name() == typeinfo )? 
        std::make_shared<Application>() 
            : nullptr;
}
