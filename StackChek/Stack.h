#pragma once

#include<iostream>
#include <Windows.h>
#include<string>
#include"MyData.h"

using namespace std;


struct numpunct
	: std::numpunct<char>
{
	std::string do_truename() const { return "Строка правильная"; }
	std::string do_falsename() const { return "Строка непраивльная"; }
};

template<class T, int size>
class DynamicStack
{
	MyData<T>* data = nullptr; // элементы хранения
	int top = 0; //вершина стека

public:
	~DynamicStack();
	void push(T val); // положить в стек
	T pop(); // извлечение из стека
	T peek(); // просмотр последнего элемента
	int getSize(); // получить размер стека
	bool isEmpty(); // проверка пустой ли стек
	bool isFull(); // проверка полный ли стек
	void clear(); // очстка стека
	void print() const;
};

template<class T, int size>
inline DynamicStack<T, size>::~DynamicStack()
{
	clear();
}

template<class T, int size>
inline void DynamicStack<T, size>::push(T val)
{
	if (top < size)
	{
		if (top == 0)
		{
			data = new MyData<T>;
			data->value = val;
		}

		else
		{
			MyData<T>* temp = new MyData<T>;
			temp->value = val;
			temp->next = data;
			data = temp;
		}
		top++;
	}

	else
	{
		cout << "Стек переполнен";
		system("pause");
		cout << endl;
	}
}

template<class T, int size>
inline T DynamicStack<T, size>::pop()
{
	T val = data->value;

	MyData<T>* temp = data;
	data = data->next;
	delete temp;
	top--;
	return val;
}

template<class T, int size>
inline T DynamicStack<T, size>::peek()
{
	if (top > 0)
		return data->value;
	else
	{
		cout << "Введенная строка содержит ошибки!\n";
		cout << "Число закрвающихся скобок превышает кол-во открывающихся\n ";
		exit(1);
	}
}

template<class T, int size>
inline int DynamicStack<T, size>::getSize()
{
	return top;
}

template<class T, int size>
inline bool DynamicStack<T, size>::isEmpty()
{
	return top == 0;
}

template<class T, int size>
inline bool DynamicStack<T, size>::isFull()
{
	return top == size;
}

template<class T, int size>
inline void DynamicStack<T, size>::clear()
{
	MyData<T>* temp = data;
	while (data)
	{
		data = data->next;
		delete temp;
		temp = data;
		top--;
	}
}


template<class T, int size>
inline void DynamicStack<T, size>::print() const
{
	
	if (top == 0)
		cout << "Стек пустой!";
	
	else
	{
		MyData<T>* temp = data;

		while (temp)
		{
			cout << temp->value;
			temp = temp->next;
		}
		cout << endl;
	}
	
	
}
