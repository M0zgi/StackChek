#include "Stack.h"
#include"List.h"

int main()
{

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::cout.setf(std::ios_base::boolalpha);

	locale loc(cout.getloc(), new ::numpunct);
	cout.imbue(loc);

	int count = 0, countchar = 0;

	string str;

	cout << "Введите строку: ";
	getline(cin, str);

	DynamicStack<char, 100> dst;

	List<char> lst;

	if (str[0] == ')' || str[0] == '}' || str[0] == ']')
	{
		cout << "Введенная строка содержит ошибоку в первом символе: " << str[0];
		
	}		

	else
	{
		for (size_t i = 0; i < str.length(); i++)
		{

			if (str[i] == '(' || str[i] == '{' || str[i] == '[')
			{
				dst.push(str[i]);
				count++;
			}

			else if (str[i] == ')')
			{
				count++;

				if (dst.peek() == '(')
					dst.pop();
				else
				{
					countchar++;
					break;
				}
			}

			else if (str[i] == '}')
			{
				count++;

				if (dst.peek() == '{')
					dst.pop();
				else
				{
					countchar++;
					break;
				}
			}

			else if (str[i] == ']')
			{
				count++;

				if (dst.peek() == '[')
					dst.pop();
				else
				{
					countchar++;
					break;
				}
			}

			countchar++;
		}

		if (!count)
			cout << "Введенная строка не содержит скобок";

		else if (dst.isEmpty())
			cout << "Введенная строка не содержит ошибок";

		else
		{
			cout << "Введенная строка содержит ошибки: ";

			for (size_t i = 0; i < countchar; i++)
			{
				lst.push_back(str[i]);
			}
			cout << lst;
		}
	}
	

	cout << endl;
	system("pause");
}