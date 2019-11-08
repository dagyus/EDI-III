/**
* Copyright (c) 2019 Gabriel Ferreira <gabrielinuz@gmail.com>. All rights reserved. 
* This file is part of CPPSET.
* Released under the GPL3 license
* https://opensource.org/licenses/GPL-3.0
**/

#include <iostream>
#include <cppset/Configuration.h>
#include <cppset/ApplicationInterface.h>
#include <cppset/ComponentFactory.h>

typedef std::shared_ptr<ApplicationInterface> IApplicationPtr;
typedef std::shared_ptr<ComponentFactory> ComponentFactoryPtr;

int main()
{
    ComponentFactoryPtr cF(new ComponentFactory());
    IApplicationPtr app = cF->create<ApplicationInterface>(APPLICATION_PATH);
    app->run();
}