#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "MenuCommand_Pro.h"
#include "Student.h"
#include "Course.h"
#include "Professor.h"
#include "ICommand.h"
#include "Variables.h"


using namespace std;


MenuCommand_Pro::MenuCommand_Pro() : ICommand()
{
	setCommandName("���� �޴�");
}
void MenuCommand_Pro::addMenu(ICommand *command)
{
	menuCommandList.push_back(command);
}
void MenuCommand_Pro::execute()
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
		cout << " " << i << ") �� ��" << endl;
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
				cout << "##undo �� �� �� �����ϴ�!\n" << endl;
			}
			else
			{
				ICommand *co = historyList.top();
				co->undo();
				historyList2.push(historyList.top());
				//undo�� ���� ������ redo�� ���� �������� �ѱ�.
				historyList.pop();
			}
		}

		else if (aa[0] == 'b')
		{
			if (historyList2.empty())
			{
				cout << "##redo �� �� �� �����ϴ�!\n" << endl;
			}
			else
			{
				ICommand *co2 = historyList2.top();
				co2->redo();
				historyList2.pop();
			}
		}

		else if (atoi(select.c_str()) == 2)
		{
			historyList.push(menuCommandList.at(atoi(select.c_str()) - 1));
			(menuCommandList.at(atoi(select.c_str()) - 1))->execute();
		}
		else
		{
			(menuCommandList.at(atoi(select.c_str()) - 1))->execute();
		}
	}
}
