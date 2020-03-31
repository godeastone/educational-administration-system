#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "MenuCommand_Stu.h"
#include "Student.h"
#include "Course.h"
#include "Professor.h"
#include "ICommand.h"
#include "Variables.h"


using namespace std;


MenuCommand_Stu::MenuCommand_Stu() :ICommand()
{
	setCommandName("student menu");
}
void MenuCommand_Stu::addMenu(ICommand *command)
{
	menuCommandList.push_back(command);
}
void MenuCommand_Stu::execute()
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
			cout << " " << i << ") " << (*it)->getCommandName() << endl;
			it++;
			i++;
		}
		cout << " " << i << ") exit" << endl;
		cout << " " << "a" << ") undo" << endl;
		cout << " " << "b" << ") redo" << endl;

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
				cout << "##can't undo!\n" << endl;
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
				cout << "##can't redo!\n" << endl;
			}
			else
			{
				ICommand *co2 = historyList2.top();
				co2->redo();
				historyList2.pop();
			}
		}

		else
			(menuCommandList.at(atoi(select.c_str()) - 1))->execute();
	}
}
