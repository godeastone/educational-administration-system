#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "About_regist.h"
#include "ICommand.h"
#include "Student.h"
#include "Course.h"
#include "Professor.h"
#include "Variables.h"


using namespace std;


About_regist::About_regist() :ICommand()
{
	setCommandName("About regist subject");
}
void About_regist::addMenu(ICommand *command)
{
	menuCommandList.push_back(command);
}
void About_regist::execute()
{
	while (1)
	{

		const char *aa;

		if (menuCommandList.empty() == true)
			break;
		it = menuCommandList.begin();
		int i = 1;
		while (it < menuCommandList.end())
		{
			cout << " [" << i << "] " << (*it)->getCommandName() << endl;
			it++;
			i++;
		}
		cout << " [" << i << "] exit" << endl;
		cout << " " << "[a" << "] undo" << endl;
		cout << " " << "[b" << "] redo" << endl;

		cout << " " << ">> ";
		cin >> select;
		cout << endl;

		aa = (select.c_str());

		if (atoi(aa) >= i)
		{
			break;
		}
		else if (aa[0] == 'a')
		{
			if (historyList.empty())
			{
				cout << "##Can't undo!\n" << endl;
			}
			else
			{
				ICommand *co = historyList.top();
				co->undo();
				historyList2.push(historyList.top());
				//undo를 위한 스택을 redo를 위한 스택으로 넘김.
				historyList.pop();
			}
		}

		else if (aa[0] == 'b')
		{
			if (historyList2.empty())
			{
				cout << "##Can't redo!\n" << endl;
			}
			else
			{
				ICommand *co2 = historyList2.top();
				cout << "1" << endl;

				co2->redo();
				historyList2.pop();

			}
		}
		else
		{
			historyList.push(menuCommandList.at(atoi(select.c_str()) - 1));

			(menuCommandList.at(atoi(select.c_str()) - 1))->execute();
		}
	}
}
