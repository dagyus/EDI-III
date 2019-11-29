/**
* Copyright (c) 2019 Gabriel Ferreira <gabrielinuz@gmail.com>. All rights reserved. 
* This file is part of CPPSET.
* Released under the GPL3 license
* https://opensource.org/licenses/GPL-3.0
**/
#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include <iostream>
#include <memory>
#include <cppset/IniReader.h>

// ToDo VERIFICAR EL MODO DE QUE SOLO SE CREE LO SOLICITADO A ESTA CONFIGURACIÓN

typedef std::shared_ptr<IniReader> IniReaderPtr;

IniReaderPtr iniReader( new IniReader() );
iniReader->open("configuration.ini");
std::string APPLICATION_NAME = iniReader->selectSection("GENERAL")->getValue("applicationName");
std::string COMPONENTS_PATH = iniReader->selectSection("GENERAL")->getValue("componentsPath");
std::string ACTIONS_PATH = iniReader->selectSection("GENERAL")->getValue("actionsPath");

#endif // CONFIGURATION_H