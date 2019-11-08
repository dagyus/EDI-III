/**
* Copyright (c) 2019 Gabriel Ferreira <gabrielinuz@gmail.com>. All rights reserved. 
* This file is part of CPPSET.
* Released under the GPL3 license
* https://opensource.org/licenses/GPL-3.0
**/

#include <iostream>
#include <memory>
#include <cppset/ApplicationInterface.h>
#include <cppset/ComponentFactory.h>
#include <cppset/IniReader.h>

typedef std::shared_ptr<ApplicationInterface> IApplicationPtr;
typedef std::shared_ptr<ActionInterface> IActionPtr;
typedef std::shared_ptr<ComponentFactory> ComponentFactoryPtr;
typedef std::shared_ptr<IniReader> IniReaderPtr;

class Application : public ApplicationInterface
{
    public:
        Application()
        {
            // std::cout << "Se construye Application " << std::endl;
        }
        virtual ~Application()
        {
            // std::cout << "Se destruye Application " << std::endl;
        }
        void run()
        {
            IniReaderPtr iniReader(new IniReader());
            iniReader->open("configuration.ini");
            std::string actionPath = iniReader->selectSection("GENERAL")->getValue("actionPath");

            ComponentFactoryPtr cF(new ComponentFactory());
            IActionPtr action = cF->create<ActionInterface>(actionPath + requestParameters["action"]);
            action->execute();
            // std::cout << "¡Se ejecutó Application()!" << std::endl;
        }
};

extern "C" IApplicationPtr create(std::string);

IApplicationPtr create(std::string typeinfo)
{
    return ( typeid(ApplicationInterface).name() == typeinfo )? 
        std::make_shared<Application>() 
            : nullptr;
}
