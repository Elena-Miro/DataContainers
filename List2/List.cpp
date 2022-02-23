#include"List.h"

//Определение класса
template<typename T>
List<T>::Element::Element(T Data, Element* pNext, Element* pPrev) :
	Data(Data), pNext(pNext), pPrev(pPrev)
{
#ifdef DEBUG
	cout << "EConstructor:\t" << this << endl;
#endif // DEBUG

}
template<typename T>
List<T>::Element::~Element()
{
#ifdef DEBUG
	cout << "EDestructor:\t" << this << endl;
#endif // DEBUG

}
template<typename T>
List<T>::BaseIterator::BaseIterator(Element* Temp) :Temp(Temp)
{
#ifdef DEBUG
	cout << "BItConstructor:\t" << this << endl;
#endif // DEBUG

}
template<typename T>
List<T>::BaseIterator::~BaseIterator()
{
#ifdef DEBUG
	cout << "BItDestructor:\t" << this << endl;
#endif // DEBUG

}

template<typename T>
bool List<T>::BaseIterator:: operator ==(const List<T>::BaseIterator& other)const
{
	return this->Temp == other.Temp;
}
template<typename T>
bool List<T>::BaseIterator:: operator !=(const BaseIterator& other)const
{
	return this->Temp != other.Temp;
}
template<typename T>
const T& List<T>::BaseIterator:: operator*()const
{
	return Temp->Data;
}
template<typename T>
List<T>::BaseIterator::operator bool()const
{
	return Temp;
}
template<typename T>
List<T>::ConstIterator::ConstIterator(Element* Temp) :BaseIterator(Temp)
{
#ifdef DEBUG
	cout << "CItConstructor:\t" << this << endl;
#endif // DEBUG

}
template<typename T>
List<T>::ConstIterator::~ConstIterator()
{
#ifdef DEBUG
	cout << "CItDestructor:\t" << this << endl;
#endif // DEBUG

}template<typename T>
typename List<T>::ConstIterator& List<T>::ConstIterator:: operator ++()
{
	BaseIterator::Temp = BaseIterator::Temp->pNext;
	return *this;
}
template<typename T>
typename List<T>::ConstIterator List<T>::ConstIterator::operator++(int)
{
	ConstIterator old = *this;
	BaseIterator::Temp = BaseIterator::Temp->pNext;
	return old;
}
template<typename T>
typename List<T>::ConstIterator& List<T>::ConstIterator::operator--()
{
	BaseIterator::Temp = BaseIterator::Temp->pPrev;
	return *this;
}
template<typename T>
typename List<T>::ConstIterator List<T>::ConstIterator::operator--(int)
{
	ConstIterator old = *this;
	BaseIterator::Temp = BaseIterator::Temp->pPrev;
	return old;
}
template<typename T>
List<T>::ConstReversIterator::ConstReversIterator(Element* Temp) :BaseIterator(Temp)
{
#ifdef DEBUG
	cout << "CRItConstructor:\t" << this << endl;
#endif // DEBUG

}
template<typename T>
List<T>::ConstReversIterator::~ConstReversIterator()
{
#ifdef DEBUG
	cout << "CRItDestructor:\t" << this << endl;
#endif // DEBUG

}
template<typename T>
typename List<T>::ConstReversIterator& List<T>::ConstReversIterator:: operator++()
{
	BaseIterator::Temp = BaseIterator::Temp->pPrev;
	return *this;
}
template<typename T>
typename List<T>::ConstReversIterator List<T>::ConstReversIterator::operator++(int)
{
	ConstReversIterator old = *this;
	BaseIterator::Temp = BaseIterator::Temp->pPrev;
	return old;
}
template<typename T>
typename List<T>::ConstReversIterator& List<T>::ConstReversIterator::operator--()
{
	BaseIterator::Temp = BaseIterator::Temp->pNext;
	return *this;
}
template<typename T>
typename List<T>::ConstReversIterator List<T>::ConstReversIterator:: operator--(int)
{
	ConstReversIterator old = *this;
	BaseIterator::Temp = BaseIterator::Temp->pNext;
	return old;
}

template<typename T>
List<T>::Iterator::Iterator(Element* Temp) :ConstIterator(Temp)
{
#ifdef DEBUG
	cout << "ItConstructor:\t" << this << endl;
#endif // DEBUG

}
template<typename T>
List<T>::Iterator::~Iterator()
{
#ifdef DEBUG
	cout << "ItDestructor:\t" << this << endl;
#endif // DEBUG

}
template<typename T>

T& List<T>::Iterator::operator*()
{
	return BaseIterator::Temp->Data;
}

template<typename T>
List<T>::ReversIterator::ReversIterator(Element* Temp) :ConstReversIterator(Temp)
{
#ifdef DEBUG
	cout << "RItConstructor:\t" << this << endl;
#endif // DEBUG

}
template<typename T>
List<T>::ReversIterator::~ReversIterator()
{
#ifdef DEBUG
	cout << "RItDestructor:\t" << this << endl;
#endif // DEBUG

}
template<typename T>
T& List<T>::ReversIterator:: operator*()
{
	return BaseIterator::Temp->Data;
}

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
typename List<T>::ConstReversIterator List<T>::crend()const
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