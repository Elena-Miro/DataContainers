#include<iostream>
using namespace std;
#define tab "\t"
class Element
{
	int Data;//значение элемента
	Element* pNext;//Адрес следующего элемента
public:
	Element(int Data, Element* pNext = nullptr) :Data(Data), pNext(pNext)
	{
		cout << "EConstructor:\t" << this << endl;
	}
	~Element()
	{
		cout << "EDestructor:\t" << this << endl;
	}
	friend class ForwardList;

};
class ForwardList//односвязный список
{
	Element* Head;//голова указывает на начальный элемент списка
public:
	ForwardList()
	{
		Head = nullptr;//если голова указывает на 0 , то список пуст
		cout << "LConstructor:\t" << this << endl;
	}
	~ForwardList()
	{
		cout << "LDestrucror:\t" << this << endl;
	}

	//Adding elements
	void push_front(int Data)
	{
		Element* New = new Element(Data);//Создаем новый элемент
		New->pNext = Head;//привязываем новый элемент к началу списка
		Head = New;
	}
	void print()const
	{
		Element* Temp = Head;//Temp-это итератор
		while (Temp)//пока итератор содержит не нулевой адрес
		{
			cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
			Temp = Temp->pNext;//переход на следующий элемент
				
		}

    }

};
void main() 
{
	setlocale(LC_ALL, "");
	int n;
	cout << "Введите размер списка: "; cin >> n;
	ForwardList list;
	for (int i = 0; i < n; i++)
	{
		list.push_front(rand() % 100);
	}
	list.print();
}