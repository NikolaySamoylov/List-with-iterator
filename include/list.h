#pragma once

#include <iostream>

template <class T>
class List
{
private:
	// звено списка
	template <class T>
	struct Node
	{
		Node* pNext;
		T data;
		// конструктор с параметром
		Node(T value = T(), Node* pN = NULL)
		{
			data = value;
			pNext = pN;
		}
	};
	size_t size; // размер списка
	Node<T>* first; // указатель на первый элемент списка
public:
	// конструктор без параметров 
	List()
	{
		size = 0;
		first = NULL;
	}
	// конструктор копирования
	List(const List<T>& l)
	{
		first = NULL;
		size = l.size;
		Node<T>* copier = l.first;
		while (copier != NULL)
		{
			push_back(copier->data);
			copier = copier->pNext;
		}
	}
	// деструктор
	~List()
	{
		while (size)
			pop_front();
	}
	// получить количество элементов в списке
	size_t get_size()
	{
		return size;
	}
	// получить указатель на первый элемент списка
	Node<T>* get_first()
	{
		return first;
	}
	// проверка списка на пустоту
	bool empty()
	{
		return first == NULL;
	}
	// положить элемент в конец списка
	void push_back(const T& Elem)
	{
		if (empty())
		{
			first = new Node<T>(Elem);
		}
		else
		{
			Node<T>* cur = this->first;
				while (cur->pNext != NULL)
					cur = cur->pNext;
			cur->pNext = new Node<T>(Elem);
		}
		size++;
	}
	// удалить элемент из конца списка
	void pop_back()
	{
		if (!empty())
		{
			Node<T>* last = first;
			while (last->pNext != NULL)
				last = last->pNext;
			last = NULL;
			size--;
		}
		else throw "List is empty!";
	}
	// положить элемент в начало списка
	void push_front(const T& Elem)
	{
		first = new Node<T>(Elem, first);
		size++;
	}
	// удалить первый элемент в списке
	void pop_front()
	{
		if (!empty())
		{
			Node<T>* del = first;
			first = first->pNext;
			delete del;
			size--;
		}
		else throw "List is empty!";
	}
	// положить элемент в произвольное место списка
	void insert(Node<T>* pos, const T& Elem)
	{
		if (pos == NULL)
			push_front(Elem);
		else
		{
			Node<T>* tmp = new Node<T>(Elem, pos->pNext);
			pos->pNext = tmp;
			size++;
		}
	}
	// удалить произвольный элемент в списке
	void erase(Node<T>* pos)
	{
		if (pos == NULL)
			pop_front();
		else
		{
			Node<T>* del = pos->pNext;
			pos->pNext = del;
			delete del;
			size--;
		}
	}
	// итератор
	class Iterator
	{
	private:
		Node<T>* current;
	public:
		// конструктор без параметров
		Iterator() { current = first; }
		//конструктор с параметром
		Iterator(Node<T>* node) { current = node; }
		//конструктор копирования
		Iterator(const Iterator& i) { current = i.current; }
		// разыменование 
		Node<T>*& operator*() { return current; }
		// обращение
		Node<T>* operator->() { return current; }
		// префиксный инкремент
		Iterator operator++() { current = current->pNext; return current; }
		// постфиксный инкремент
		Iterator operator++(int) { Iterator i(*this); ++(*this); return i; }
		// проверка на равенство
		bool operator==(Iterator i) { return current == i.current; }
		// проверка на неравенство
		bool operator!=(Iterator i) { return current != i.current; }
	};
	// начало итератора
	Iterator begin() const { Iterator i(first); return i; }
	// конец итератора
	Iterator end() const { Iterator i(NULL); return i; }
};
