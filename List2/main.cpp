#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;
#define tab "\t"
template<typename T>
class List
{
	class Element
	{
		T Data;//значение элемента
		Element* pNext;//адрес следующего элемента
		Element* pPrev;//предыдущего элемента
	public:
		Element(T Data, Element* pNext = nullptr, Element* pPrev = nullptr) :
			Data(Data), pNext(pNext), pPrev(pPrev)
		{
#ifdef DEBUG
			cout << "EConstructor:\t" << this << endl;
#endif // DEBUG

		}
		~Element()
		{
#ifdef DEBUG
			cout << "EDestructor:\t" << this << endl;
#endif // DEBUG

		}
		friend class List<T>;
	}*Head,*Tail;
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
		BaseIterator(Element* Temp=nullptr) :Temp(Temp)
		{
#ifdef DEBUG
			cout << "BItConstructor:\t" << this << endl;
#endif // DEBUG

		}
		~BaseIterator()
		{
#ifdef DEBUG
			cout << "BItDestructor:\t" << this << endl;
#endif // DEBUG

		}
		virtual BaseIterator& operator++() = 0;
		//virtual BaseIterator operator++(int) = 0;
		virtual BaseIterator& operator--() = 0;

		bool operator ==(const BaseIterator& other)const
		{
			return this->Temp == other.Temp;
		}
		bool operator !=(const BaseIterator& other)const
		{
			return this->Temp != other.Temp;
		}
		const T& operator*()const
		{
			return Temp->Data;
		}
		operator bool()const
		{
			return Temp;
		}
	};
	class ConstIterator :public BaseIterator
	{
	public:
		ConstIterator(Element* Temp=nullptr) :BaseIterator(Temp)
		{
#ifdef DEBUG
			cout << "CItConstructor:\t" << this << endl;
#endif // DEBUG

		}
		~ConstIterator()
		{
#ifdef DEBUG
			cout << "CItDestructor:\t" << this << endl;
#endif // DEBUG

		}
		ConstIterator& operator ++()
		{
			BaseIterator::Temp = BaseIterator::Temp->pNext;
			return *this;
		}
		ConstIterator operator++(int)
		{
			ConstIterator old = *this;
			BaseIterator::Temp = BaseIterator::Temp->pNext;
			return old;
		}
		ConstIterator& operator--()
		{
			BaseIterator::Temp = BaseIterator::Temp->pPrev;
			return *this;
		}
		ConstIterator operator--(int)
		{
			ConstIterator old = *this;
			BaseIterator::Temp = BaseIterator::Temp->pPrev;
			return old;
		}

	};
	class ConstReversIterator :public BaseIterator
	{
	public:
		ConstReversIterator(Element* Temp = nullptr) :BaseIterator(Temp)
		{
#ifdef DEBUG
			cout << "CRItConstructor:\t" << this << endl;
#endif // DEBUG

		}
		~ConstReversIterator()
		{
#ifdef DEBUG
			cout << "CRItDestructor:\t" << this << endl;
#endif // DEBUG

		}
		ConstReversIterator& operator++()
		{
			BaseIterator::Temp = BaseIterator::Temp->pPrev;
			return *this;
		}
		ConstReversIterator operator++(int)
		{
			ConstReversIterator old = *this;
			BaseIterator::Temp = BaseIterator::Temp->pPrev;
			return old;
		}
		ConstReversIterator& operator--()
		{
			BaseIterator::Temp = BaseIterator::Temp->pNext;
			return *this;
		}
		ConstReversIterator operator--(int)
		{
			ConstReversIterator old = *this;
			BaseIterator::Temp = BaseIterator::Temp->pNext;
			return old;
		}
		
	};
	class Iterator :public ConstIterator
	{
	public:
		Iterator(Element* Temp=nullptr) :ConstIterator(Temp)
		{
#ifdef DEBUG
			cout << "ItConstructor:\t" << this << endl;
#endif // DEBUG

		}
		~Iterator()
		{
#ifdef DEBUG
			cout << "ItDestructor:\t" << this << endl;
#endif // DEBUG

		}
		T& operator*()
		{
			return BaseIterator::Temp->Data;
		}
	};
	class ReversIterator :public ConstReversIterator
	{
	public:
		ReversIterator(Element* Temp = nullptr) :ConstReversIterator(Temp)
		{
#ifdef DEBUG
			cout << "RItConstructor:\t" << this << endl;
#endif // DEBUG

		}
		~ReversIterator()
		{
#ifdef DEBUG
			cout << "RItDestructor:\t" << this << endl;
#endif // DEBUG

		}
		T& operator*()
		{
			return BaseIterator::Temp->Data;
		}
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
template<typename T>
typename List<T>::ConstIterator List<T>::cbegin()const//const begin
{
	return Head;
}
template<typename T>
typename List<T>::ConstIterator List<T>::cend()const//
{
	return nullptr;
}
template<typename T>
typename List<T>::ConstReversIterator List<T>::crbegin()const//const revers begin
{
	return Tail;
}
template<typename T>
typename List<T>::ConstReversIterator List<T>:: crend()const
{
	return nullptr;
}
template<typename T>
typename List<T>::Iterator List<T>::begin()//const begin
{
	return Head;
}
template<typename T>
typename List<T>::Iterator List<T>::end()//
{
	return nullptr;
}
template<typename T>
typename List<T>::ReversIterator List<T>::rbegin()
{
	return Tail;
}
template<typename T>
typename List<T>::ReversIterator List<T>::rend()
{
	return nullptr;
}
template<typename T>
List<T>::List()
{
	Head = Tail = nullptr;
	size = 0;
	cout << "LConstructor:\t" << this << endl;
}
template<typename T>
List<T>::List(const initializer_list<T>& il) :List()
{
	cout << typeid(il.begin()).name() << endl;
	for (T const* it = il.begin(); it != il.end(); ++it)
	{
		push_back(*it);
	}
}
template<typename T>
List<T>::~List()
{
	//while (Head)pop_front();
	while (Tail)pop_back();
	cout << "LDestructor:\t" << this << endl;
}
template<typename T>

void List<T>::push_front(T Data)
{
	if (Head == nullptr && Tail == nullptr)
	{
		Head = Tail = new Element(Data);
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
template<typename T>
void List<T>::push_back(T Data)
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
	Tail = Tail->pNext = new Element(Data, nullptr, Tail);
	size++;
}
template<typename T>
void List<T>::pop_front()//удаление в начале
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
template<typename T>
void List<T>::pop_back()
{
	if (Head == Tail)return pop_front();
	Tail = Tail->pPrev;
	delete Tail->pNext;
	Tail->pNext = nullptr;
	size--;
}
template<typename T>
void List<T>::insert(int index, T Data)
{
	if (index > size)return;
	if (index == 0)return push_front(Data);
	if (index = size)return push_back(Data);

	Element* Temp;
	if (index < size / 2)
	{
		Temp = Head;
		for (int i = 0; i < index; i++)Temp = Temp->pNext;

	}
	else
	{
		Temp = Tail;
		for (int i = 0; i < size - 1 - index; i++)Temp = Temp->pPrev;
	}
	//Неважно с какой стороны добрались до нового элемента
	//процедура добавления нового элемента будет идентичной
	Element* New = new Element(Data);
	New->pNext = Temp;
	New->pPrev = Temp->pPrev;
	Temp->pPrev->pNext = New;
	Temp->pPrev = New;
	size++;
}
template<typename T>
void List<T>::print()const
{
	for (Element* Temp = Head; Temp; Temp = Temp->pNext)
		cout << Temp->pPrev << tab << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
	cout << "Количество элементов списка:" << size << endl;
}
template<typename T>
void List<T>::revers_print()const
{
	for (Element* Temp = Tail; Temp; Temp = Temp->pPrev)
		cout << Temp->pPrev << tab << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
	cout << "Количество элементов списка:" << size << endl;
}

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
	list.push_back(rand() % 100);
	list.print();
	list.pop_front();
	list.print();
	list.pop_back();
	list.print();

	int index;
	int value;
	cout << "Введите индекс добавляемого элемента:"; cin >> index;
	cout << "Введите значение добавляемого элемента:"; cin >> value;
	list.insert(index, value);
	list.print();
	list.revers_print();
#endif // BASE_CHECK
	List<int> list = {3,5,8,13,21};
	list.print();
	for (int i : list)
	{
		cout << i << tab;
	}
	cout << endl;
	for (List<int>::ReversIterator it = list.rbegin(); it ; ++it)
	{
		cout << *it << tab;

	}
	cout << endl;
	List <double> d_list = { 2.5,3.14,5.2,8.3 };
	for (double i : d_list)cout << i << tab; cout << endl;
	for (List<double>::ReversIterator it = d_list.rbegin(); it; ++it)
	{
		cout << *it << tab;
	}
	cout << endl;
	List<std::string>s_list = { "Have","a","nice","day" };
	for (std::string i : s_list)cout << i << tab; cout << endl;
for(List<std::string>::ReversIterator it=s_list.rbegin();it!=s_list.rend();++it)
cout << *it << tab; cout << endl;
}