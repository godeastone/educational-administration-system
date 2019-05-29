#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "Menu.h"
#include "Student.h"
#include "Course.h"
#include "Professor.h"
#include "ICommand.h"
#include "Variables.h"

using namespace std;

class Course;
class Student;
class ICommand;

void Menu::addMenu(ICommand *command)
{
	menuCommandList.push_back(command);
}
void Menu::execute()
{
	while (1)
	{
		const char *aa;

		cout << menuName << endl;
		if (menuCommandList.empty() == true)
			break;
		it = menuCommandList.begin();
		int i = 1;
		while (it < menuCommandList.end())
		{
			cout << i << ". " << (*it)->getCommandName() << endl;
			it++;
			i++;
		}
		cout << i << ". 종 료" << endl;
		cout << "" << "a" << ". undo" << endl;
		cout << "" << "b" << ". redo" << endl;
		cout << "" << ">> ";
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
				cout << "##undo 를 할 수 없습니다!\n" << endl;
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
				cout << "##redo 를 할 수 없습니다!\n" << endl;
			}
			else
			{
				ICommand *co2 = historyList2.top();
				co2->redo();
				historyList2.pop();
			}
		}
		else
		{
			(menuCommandList.at(atoi(select.c_str()) - 1))->execute();

		}
	}
}
