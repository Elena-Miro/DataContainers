#include<iostream>
using namespace std;
#define tab "\t"
//#define DEBUG
class Element
{
	int Data;//значение элемента
	Element* pNext;//Адрес следующего элемента
	static int count;
public:
	Element(int Data, Element* pNext = nullptr) :Data(Data), pNext(pNext)
	{
		count++;

#ifdef DEBUG
		cout << "EConstructor:\t" << this << endl;
#endif // DEBUG



	}
	~Element()
	{
		count--;
#ifdef DEBUG
		cout << "EDestructor:\t" << this << endl;
#endif // DEBUG

	}
	friend class ForwardList;

};
int Element::count = 0;
class ForwardList//односвязный список
{
	Element* Head;//голова указывает на начальный элемент списка
	unsigned int size;//размер списка
public:
	ForwardList()
	{
		Head = nullptr;//если голова указывает на 0 , то список пуст
		size = 0;
		cout << "LConstructor:\t" << this << endl;
	}
	ForwardList(unsigned int size):ForwardList()
	{
		this->Head = nullptr;
		this-> size=0;
		for (int i = 0; i < size; i++)
		{
			push_front(0);
		}
		
	}
	ForwardList(const initializer_list<int>& il) :ForwardList()
	{
	cout << typeid(il.begin()).name() << endl;
	//cont int* -константный указатель(не изменяется адрес
	//int const* указатель на константу(не изменяется значение по адресу
	for (int const* it = il.begin(); it != il.end(); it++)
	{
		//it-iterator
		push_back(*it);
	}
	/*for(int const* it=il.end()-1;it!=il.begin()-1;it--)
	{
	push_front(*it);
	}
	*/
	}
	~ForwardList()
	{
		while (Head)pop_front();//если в хэд не ноль удаляем начальный элемент
		cout << "LDestrucror:\t" << this << endl;
	}
	//Operators:
	const int& operator[](int index)const
	{
		Element* Temp = Head;
		for (int i = 0; i < index; i++)Temp = Temp->pNext;
		return Temp->Data;
    }
	int& operator[](int index)//оператор[]  возвращает значение по индексу
	{
		Element* Temp = Head;
		for (int i = 0; i < index; i++)Temp = Temp->pNext;
		return Temp->Data;
	}

	//Adding elements
	void push_front(int Data)
	{
		Element* New = new Element(Data);//Создаем новый элемент
		New->pNext = Head;//привязываем новый элемент к началу списка
		Head = New;
		size++;
	}
	void pop_front()
	{
		if (Head == nullptr)return;
		//1)запоминаем адрес удаляемого элемента
		Element* Erased = Head;
		//2)исключаем удал
		Head = Erased->pNext;
		delete Erased;
		size--;
	}
	void pop_back()
	{
		if (Head == nullptr)return;
		if (Head->pNext == nullptr)return pop_front();
		//1)Дойти до предпоследнего элемента
		Element* Temp = Head;
		while (Temp->pNext->pNext)Temp = Temp->pNext;
		//2)удалить последний элемент
		delete Temp->pNext;
		//3)Затираем адрес удаленного элемента нулем
		Temp->pNext = nullptr;
		size--;

	}
	void print()const
	{
		Element* Temp = Head;//Temp-это итератор
		while (Temp)//пока итератор содержит не нулевой адрес
		{
			cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
			Temp = Temp->pNext;//переход на следующий элемент
				
		}

		cout << "Количество элементов списка:" << size << endl;
		cout << "Общее количество элементов :" << Head->count << endl;

	}
	void push_back(int Data)
	{
		//0)является ли список пустым
		if (Head == nullptr)return push_front(Data);
		//1)сщздаем новый элемент
		Element* New = new Element(Data);
		//2)доходим до конца списка
		Element* Temp = Head;
		while (Temp->pNext)Temp = Temp->pNext;//пока пнекст не 0,переходим на след эл
		//теперь находимся в последнем эл
		//3)присоединяем новый эл к последнему,т.е. пнекст
		Temp->pNext = New;
		size++;
	}
	void erase(int index)
	{
		if (index > size)return;
		if (index == 0)return pop_front();
		//1доходим до нужного эл
		Element* Temp = Head;
		for (int i = 0; i < index-1; i++)Temp = Temp->pNext;
		//2.запоминаем адрес удаляемого элемента
		Element* Erased = Temp->pNext;
		//3 исключаем элемент из списка
		Temp->pNext = Erased->pNext;
		//Temp->pNext=Temp->pNext->pNext;
		delete Erased;
		size--;

	}
	void insert(int index, int Data)
	{
		if (Head == nullptr||Head==nullptr)return push_front(Data);
		if (index == 0)return push_front(Data);
		if (index > size)return;
		Element* New = new Element(Data);
		//1/доходим до нужного элемента
		Element* Temp = Head;
		for (int i = 0; i < index - 1; i++)Temp = Temp->pNext;
		//включаем новый элемент в список
		New->pNext = Temp->pNext;
		Temp->pNext = New;
		size++;
	}

};
//#define BASE_CHECK
//#define DESRTUCTOR_CHECK
//#define HOME_WORK_1
#define HOME_WORK_2

void main() 
{
	setlocale(LC_ALL, "");

#ifdef BASE_CHECK
	int n;
	cout << "Введите размер списка: "; cin >> n;
	ForwardList list;
	list.pop_front();
	for (int i = 0; i < n; i++)
	{
		//list.push_front(rand() % 100);
		list.push_back(rand() % 100);
	}
	list.print();
	/*list.push_back(123);
	list.print();*/
	//list.pop_front();
	//list.pop_back();
	int index;
	int value;
	cout << "Введите индекс добавляемого элемента: "; cin >> index;
	cout << "Введите значение добавляемого элемента: "; cin >> value;
	
	list.insert(index, value);
	list.print();
	cout << "Введите индекс удаляемого элемента: "; cin >> index;
	list.erase(index);
	list.print();

#endif // BASE_CHECK
	/*ForwardList list1;
	list1.push_back(3);
	list1.push_back(5);
	list1.push_back(8);
	list1.push_back(13);
	list1.push_back(21);
	list1.print();

	ForwardList list2;
	list2.push_back(34);
	list2.push_back(55);
	list2.push_back(89);
	list2.print();*/
#ifdef DESRTUCTOR_CHECK
	int n;
	cout << "Введите размер списка: "; cin >> n;
	ForwardList list;

	for (int i = 0; i < n; i++)
	{
		list.push_front(rand());
	}
	cout << "Список заполнен:\t" << endl;
#endif // DESTRUC_CHECK

#ifdef DESTRUCTOR_CHECK
	int n;
	cout << "Введите размер списка: "; cin >> n;
	ForwardList list;
	for (int i = 0; i < n; i++)
	{
		list.push_front(rand());
	}
	//cout << "Список заполнен" << endl;
	list.print();
#endif // DESTRUCTOR_CHECK

#ifdef HOME_WORK_1
	int n;
	cout << "Введите размер списка: "; cin >> n;
	ForwardList list(n);
	for (int i = 0; i < n; i++)
	{
		list[i] = rand() % 100;
	}
	for (int i = 0; i < n; i++)
	{
		cout << list[i] << tab;
	}
	cout << endl;
#endif // HOME_WORK_1

#ifdef HOME_WORK_2
	//l-value        =   r-value
	ForwardList list = { 3,5,8,13,21 };
	//(ForwardList)     (initializer_list)
	list.print();
#endif // HOME_WORK_2
}