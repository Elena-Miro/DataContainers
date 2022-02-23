#pragma once
#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;
#define tab "\t"

//ќбъ€вление
template<typename T>
class List
{
	class Element
	{
		T Data;//значение элемента
		Element* pNext;//адрес следующего элемента
		Element* pPrev;//предыдущего элемента
	public:
		Element(T Data, Element* pNext = nullptr, Element* pPrev = nullptr);
		~Element();
		friend class List<T>;
	}*Head, * Tail;
	size_t size;
public:

#ifdef DEBUG
	class Iterator
	{
		Element* Temp;
	public:
		Iterator(Element* Temp = nullptr) :Temp(Temp)
		{
			cout << "ItConstructor:\t" << this << endl;
		}
		~Iterator()
		{
			cout << "ItDestructor:\t" << this << endl;
		}
		Iterator& operator ++()
		{
			Temp = Temp->pNext;
			return *this;
		}
		Iterator operator++(int)
		{
			Iterator old = *this;
			Temp = Temp->pNext;
			return old;
		}
		Iterator& operator--()
		{
			Temp = Temp->pPrev;
			return *this;
		}
		Iterator operator--(int)
		{
			Iterator old = *this;
			Temp = Temp->pPrev;
			return old;
		}
		bool operator ==(const Iterator& other)const
		{
			return this->Temp == other.Temp;
		}
		bool operator !=(const Iterator& other)const
		{
			return this->Temp != other.Temp;
		}
		const int& operator*()const
		{
			return Temp->Data;
		}
		int& operator*()
		{
			return Temp->Data;
		}

	};
	class ReversIterator
	{
		Element* Temp;
	public:
		ReversIterator(Element* Temp = nullptr) :Temp(Temp)
		{
			cout << "RItConstructor:\t" << this << endl;
		}
		~ReversIterator()
		{
			cout << "RItDestructor:\t" << this << endl;
		}
		ReversIterator& operator++()
		{
			Temp = Temp->pPrev;
			return *this;
		}
		ReversIterator operator++(int)
		{
			ReversIterator old = *this;
			Temp = Temp->pPrev;
			return old;
		}
		ReversIterator& operator--()
		{
			Temp = Temp->pNext;
			return *this;
		}
		ReversIterator operator--(int)
		{
			ReversIterator old = *this;
			Temp = Temp->pNext;
			return old;
		}
		bool operator==(const ReversIterator& other)const
		{
			return this->Temp == other.Temp;
		}
		bool operator!=(const ReversIterator& other)const
		{
			return this->Temp != other.Temp;
		}
		const int& operator*()const
		{
			return Temp->Data;
		}
		int& operator*()
		{
			return Temp->Data;
		}
		operator bool()const
		{
			return Temp;
		}
	};
#endif // DEBUG
	class BaseIterator
	{
	protected:
		Element* Temp;
	public:
		BaseIterator(Element* Temp = nullptr);
		~BaseIterator();
		virtual BaseIterator& operator++() = 0;
		//virtual BaseIterator operator++(int) = 0;
		virtual BaseIterator& operator--() = 0;

		bool operator ==(const BaseIterator& other)const;
		bool operator !=(const BaseIterator& other)const;
		const T& operator*()const;
		operator bool()const;
	};
	class ConstIterator :public BaseIterator
	{
	public:
		ConstIterator(Element* Temp = nullptr);
		~ConstIterator();
		ConstIterator& operator ++();
		ConstIterator operator++(int);
		ConstIterator& operator--();
		ConstIterator operator--(int);

	};
	class ConstReversIterator :public BaseIterator
	{
	public:
		ConstReversIterator(Element* Temp = nullptr);
		~ConstReversIterator();

		ConstReversIterator& operator++();
		ConstReversIterator operator++(int);
		ConstReversIterator& operator--();
		ConstReversIterator operator--(int);

	};
	class Iterator :public ConstIterator
	{
	public:
		Iterator(Element* Temp = nullptr);
		~Iterator();
		T& operator*();
	};
	class ReversIterator :public ConstReversIterator
	{
	public:
		ReversIterator(Element* Temp = nullptr);
		~ReversIterator();
		T& operator*();
	};

	ConstIterator cbegin()const;
	ConstIterator cend()const;
	ConstReversIterator crbegin()const;
	ConstReversIterator crend()const;

	Iterator begin();;
	Iterator end();
	ReversIterator rbegin();
	ReversIterator rend();

	List();
	List(const initializer_list<T>& il);
	~List();

	void push_front(T Data);
	void push_back(T Data);
	void pop_front();
	void pop_back();
	void insert(int index, T Data);
	void print()const;
	void revers_print()const;
};
