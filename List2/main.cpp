#include<iostream>
using namespace std;
#define tab "\t"
class List
{
	class Element
	{
		int Data;//значение элемента
		Element* pNext;//адрес следующего элемента
		Element* pPrev;//предыдущего элемента
	public:
		Element(int Data, Element* pNext = nullptr, Element* pPrev = nullptr) :
			Data(Data), pNext(pNext), pPrev(pPrev)
		{
			cout << "EConstructor:\t" << this << endl;
		}
		~Element()
		{
			cout << "EDestructor:\t" << this << endl;
		}
		friend class List;
	}*Head,*Tail;
	size_t size;
public:
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
	Iterator begin()
	{
		return Head;
	}
	Iterator end()
	{
		return nullptr;
	}
	ReversIterator rbegin()
	{
		return Tail;
	}
	ReversIterator rend()
	{
		return nullptr;
	}
	List()
	{
		Head = Tail = nullptr;
		size = 0;
		cout << "LConstructor:\t" << this << endl;
	}
	List(const initializer_list<int>& il) :List()
	{
		cout << typeid(il.begin()).name() << endl;
		for (int const* it = il.begin(); it != il.end(); ++it)
		{
			push_back(*it);
		}
	}
	~List()
	{
		//while (Head)pop_front();
		while (Tail)pop_back();
		cout << "LDestructor:\t" << this << endl;
	}
	void push_front(int Data)
	{
		if (Head == nullptr && Tail == nullptr)
		{
			Head=Tail = new Element(Data);
			size++;
			return;
		}
/*
		Element* New = new Element(Data);
		New->pNext = Head;
		Head->pPrev = New;
		Head = New;
*/

		Head = Head->pPrev = new Element(Data, Head);
		size++;
	}
	void push_back(int Data)
	{
		if (Head == nullptr && Tail == nullptr)
		{
			Head = Tail = new Element(Data);
			size++;
			return;
		}
		/*Element* New = new Element(Data);
		New->pPrev = Tail;
		Tail->pNext = New;
		Tail = New;*/
		Tail = Tail->pNext = new Element(Data,nullptr, Tail);
		size++;
	}
	void pop_front()//удаление в начале
	{
		if (Head == nullptr && Tail == nullptr)return;
		if (Head == Tail)
		{
			delete Head;
			Head = Tail = nullptr;
			size--;
			return;
		}
		Head = Head->pNext;
		delete Head->pPrev;
		Head->pPrev = nullptr;
		size--;
	}
	void pop_back()
	{
		if (Head == Tail)return pop_front();
		Tail = Tail->pPrev;
		delete Tail->pNext;
		Tail->pNext = nullptr;
		size--;
	}
	void insert(int index, int Data)
	{
		if (index > size)return;
		if (index == 0)return push_front(Data);
		if (index >= size)return push_back(Data);
		
		Element* Temp;
		if (index < size / 2)
		{
			Temp = Head;
			for (int i = 0; i < index; i++)Temp = Temp->pNext;

		}
		else
		{
			Temp = Tail;
			for (int i = 0; i < size-1-index; i++)Temp = Temp->pPrev;
		}
		//Неважно с какой стороны добрались до нового элемента
		//процедура добавления нового элемента будет идентичной
		/*Element* New = new Element(Data);
		New->pNext = Temp;
		New->pPrev = Temp->pPrev;
		Temp->pPrev->pNext = New;
		Temp->pPrev = New;*/
		Temp->pPrev = Temp->pPrev->pNext = new Element(Data, Temp, Temp->pPrev);
		size++;
	}
	void print()const
	{
		for (Element* Temp = Head; Temp; Temp = Temp->pNext)
			cout << Temp->pPrev << tab<<Temp <<tab<< Temp->Data << tab << Temp->pNext << endl;
		cout << "Количество элементов списка:" << size << endl;
	}
	void revers_print()const
	{
		for (Element* Temp = Tail; Temp; Temp = Temp->pPrev)
			cout << Temp->pPrev << tab <<Temp<<tab<< Temp->Data << tab << Temp->pNext << endl;
		cout << "Количество элементов списка:" << size << endl;
	}
};

//#define BASE_CHECK

void main()
{
	setlocale(LC_ALL, "");
#ifdef BASE_CHECK
	int n;
	cout << "Введите размер списка: "; cin >> n;
	List list;
	for (int i = 0; i < n; i++)
	{
		list.push_front(rand() % 100);

	}
	list.print();
	list.revers_print();
	/*list.push_back(rand() % 100);
	list.print();
	list.pop_front();
	list.print();
	list.pop_back();
	list.print();*/

	int index;
	int value;
	cout << "Введите индекс добавляемого элемента:"; cin >> index;
	cout << "Введите значение добавляемого элемента:"; cin >> value;
	list.insert(index, value);
	list.print();
	list.revers_print();
#endif // BASE_CHECK
	List list = {3,5,8,13,21};
	//list.print();
	for (int i : list)
	{
		cout << i << tab;
	}
	cout << endl;
	for (List::ReversIterator it = list.rbegin(); it ; ++it)
	{
		cout << *it << tab;

	}
	cout << endl;
}