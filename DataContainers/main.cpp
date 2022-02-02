#include<iostream>
using namespace std;
#define tab "\t"
//#define DEBUG
class Element
{
	int Data;//�������� ��������
	Element* pNext;//����� ���������� ��������
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
class ForwardList//����������� ������
{
	Element* Head;//������ ��������� �� ��������� ������� ������
	unsigned int size;//������ ������
public:
	ForwardList()
	{
		Head = nullptr;//���� ������ ��������� �� 0 , �� ������ ����
		size = 0;
		cout << "LConstructor:\t" << this << endl;
	}
	
	~ForwardList()
	{
		while (Head)pop_front();//���� � ��� �� ���� ������� ��������� �������
		cout << "LDestrucror:\t" << this << endl;
	}

	//Adding elements
	void push_front(int Data)
	{
		Element* New = new Element(Data);//������� ����� �������
		New->pNext = Head;//����������� ����� ������� � ������ ������
		Head = New;
		size++;
	}
	void pop_front()
	{
		if (Head == nullptr)return;
		//1)���������� ����� ���������� ��������
		Element* Erased = Head;
		//2)��������� ����
		Head = Erased->pNext;
		delete Erased;
		size--;
	}
	void pop_back()
	{
		if (Head == nullptr)return;
		if (Head->pNext == nullptr)return pop_front();
		//1)����� �� �������������� ��������
		Element* Temp = Head;
		while (Temp->pNext->pNext)Temp = Temp->pNext;
		//2)������� ��������� �������
		delete Temp->pNext;
		//3)�������� ����� ���������� �������� �����
		Temp->pNext = nullptr;
		size--;

	}
	void print()const
	{
		Element* Temp = Head;//Temp-��� ��������
		while (Temp)//���� �������� �������� �� ������� �����
		{
			cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
			Temp = Temp->pNext;//������� �� ��������� �������
				
		}

		cout << "���������� ��������� ������:" << size << endl;
		cout << "����� ���������� ��������� :" << Head->count << endl;

	}
	void push_back(int Data)
	{
		//0)�������� �� ������ ������
		if (Head == nullptr)return push_front(Data);
		//1)������� ����� �������
		Element* New = new Element(Data);
		//2)������� �� ����� ������
		Element* Temp = Head;
		while (Temp->pNext)Temp = Temp->pNext;//���� ������ �� 0,��������� �� ���� ��
		//������ ��������� � ��������� ��
		//3)������������ ����� �� � ����������,�.�. ������
		Temp->pNext = New;
		size++;
	}
	void erase(int index)
	{
		if (index > size)return;
		if (index == 0)return pop_front();
		//1������� �� ������� ��
		Element* Temp = Head;
		for (int i = 0; i < index-1; i++)Temp = Temp->pNext;
		//2.���������� ����� ���������� ��������
		Element* Erased = Temp->pNext;
		//3 ��������� ������� �� ������
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
		//1/������� �� ������� ��������
		Element* Temp = Head;
		for (int i = 0; i < index - 1; i++)Temp = Temp->pNext;
		//�������� ����� ������� � ������
		New->pNext = Temp->pNext;
		Temp->pNext = New;
		size++;
	}

};
//#define BASE_CHECK
//#define DESRTUCTOR_CHECK
void main() 
{
	setlocale(LC_ALL, "");

#ifdef BASE_CHECK
	int n;
	cout << "������� ������ ������: "; cin >> n;
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
	cout << "������� ������ ������������ ��������: "; cin >> index;
	cout << "������� �������� ������������ ��������: "; cin >> value;
	
	list.insert(index, value);
	list.print();
	cout << "������� ������ ���������� ��������: "; cin >> index;
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
	cout << "������� ������ ������: "; cin >> n;
	ForwardList list;

	for (int i = 0; i < n; i++)
	{
		list.push_front(rand());
	}
	cout << "������ ��������:\t" << endl;
#endif // DESTRUC_CHECK

	int n;
	cout << "������� ������ ������:"; cin >> n;
	ForwardList list(n);

	for (int i = 0; i < n; i++)
	{
		list[i] = rand() % 100;
	}

	cout << endl;
}