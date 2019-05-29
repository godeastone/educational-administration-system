#pragma once
#ifndef _Menu_H
#define _Menu_H

#include <string>
#include <vector>
#include <iostream>
#include "ICommand.h"

class ICommand;

class Menu
{
private:
	std::string menuName;
	std::string select;
	std::vector<ICommand *> menuCommandList;

	std::vector<ICommand *>::iterator it;
public:
	Menu(std::string name)
	{
		this->menuName = name;
	};
	void addMenu(ICommand *command);
	void execute();
};

#endif