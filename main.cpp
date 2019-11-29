/**
* Copyright (c) 2019 Gabriel Ferreira <gabrielinuz@gmail.com>. All rights reserved. 
* This file is part of CPPSET.
* Released under the GPL3 license
* https://opensource.org/licenses/GPL-3.0
**/

#include <iostream>
#include <cppset/ApplicationInterface.h>
#include <cppset/ComponentFactory.h>

typedef std::shared_ptr<ApplicationInterface> IApplicationPtr;
typedef std::shared_ptr<ComponentFactory> ComponentFactoryPtr;
typedef std::shared_ptr<IniReader> IniReaderPtr;

int main()
{
	IniReaderPtr iniReader( new IniReader() );
	iniReader->open("configuration.ini");
	std::string APPLICATION_NAME = iniReader->selectSection("GENERAL")->getValue("applicationName");
    
    ComponentFactoryPtr cF(new ComponentFactory());
    IApplicationPtr app = cF->create<ApplicationInterface>(APPLICATION_NAME);
    app->run();
}