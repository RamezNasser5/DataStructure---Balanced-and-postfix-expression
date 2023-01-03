#include<iostream>
#include<stack>
#include<string>
using namespace std;
//this function is check if it's Parentheses is balanced or not
bool ispair(char open, char close)
{
	if (open == '(' && close == ')')
	{
		return true;
	}
	else if (open == '{' && close == '}')
	{
		return true;
	}
	else if (open == '[' && close == ']')
	{
		return true;
	}
	else
	{
		return false;
	}
}
//this function is check if expression is balanced or not
bool is_Balanced(string exeprition)
{
	stack<char> test;
	for (int i = 0; i < exeprition.size(); i++)
	{
		if (exeprition[i] == '(' || exeprition[i] == '[' || exeprition[i] == '{')
		{
			test.push(exeprition[i]);
		}
		else
		{
			if (test.empty())
			{
				return true;
			}
			else if (ispair(test.top(), exeprition[i]))
			{
				test.pop();
			}
		}
	}
	if (test.empty())
	{
		return true;
	}
	else
		return false;
}
//this function is return the priority of operation
int priority(char operation)
{
	if (operation == '+' || operation == '-')
	{
		return 1;
	}
	else if (operation == '*' || operation == '/')
	{
		return 2;
	}
	else if (operation == '^')
	{
		return 3;
	}
	else
	{
		return 0;
	}
}
//this function is return an postfix of expression
string infix_to_postfix(string exeprition)
{
	stack<char>test;
	string exedigit = "";
	for (int i = 0; i < exeprition.size(); i++)
	{
		if (exeprition[i] == ' ')
		{
			continue;
		}
		else if (isdigit(exeprition[i]) || isalpha(exeprition[i]))
		{
			exedigit += exeprition[i];
		}
		else if (exeprition[i] == '(' || exeprition[i] == '{' || exeprition[i] == '[' || exeprition[i] == '+' || exeprition[i] == '*' || exeprition[i] == '/' || exeprition[i] == '-')
		{
			test.push(exeprition[i]);
		}
		else if (exeprition[i] == ')')
		{
			while (test.top() != '(')
			{
				exedigit += test.top();
				test.pop();
			}
			test.pop();
		}
		else if (exeprition[i] == '}')
		{
			while (test.top() != '{')
			{
				exedigit += test.top();
				test.pop();
			}
			test.pop();
		}
		else if (exeprition[i] == ']')
		{
			while (test.top() != '[')
			{
				exedigit += test.top();
				test.pop();
			}
			test.pop();
		}
		else
		{
			while (!test.empty() && priority(exeprition[i]) <= priority(exeprition[test.size() - 1]))
			{
				exedigit += test.top();
				test.pop();
			}
			test.push(exeprition[i]);
		}
	}
	while (!test.empty())
	{
		exedigit += test.top();
		test.pop();
	}
	return exedigit;
}
int main()
{
	string exeprition;
	getline(cin, exeprition);
	if (!is_Balanced(exeprition))
	{
		cout << "the exeprition is not Balanced";
	}
	else
	{
		cout << "the expression is Balanced\n";
		cout << infix_to_postfix(exeprition) << "\n";
	}
	system("pause");
	return 0;
}
