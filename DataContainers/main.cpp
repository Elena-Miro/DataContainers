#include<iostream>
using namespace std;
#define tab "\t"
class Element
{
	int Data;//�������� ��������
	Element* pNext;//����� ���������� ��������
	static int count;
public:
	Element(int Data, Element* pNext = nullptr) :Data(Data), pNext(pNext)
	{
		count++;
		cout << "EConstructor:\t" << this << endl;
	}
	~Element()
	{
		count--;
		cout << "EDestructor:\t" << this << endl;
	}
	friend class ForwardList;

};
int Element::count = 0;
class ForwardList//����������� ������
{
	Element* Head;//������ ��������� �� ��������� ������� ������
public:
	ForwardList()
	{
		Head = nullptr;//���� ������ ��������� �� 0 , �� ������ ����
		cout << "LConstructor:\t" << this << endl;
	}
	~ForwardList()
	{
		cout << "LDestrucror:\t" << this << endl;
	}

	//Adding elements
	void push_front(int Data)
	{
		Element* New = new Element(Data);//������� ����� �������
		New->pNext = Head;//����������� ����� ������� � ������ ������
		Head = New;
	}
	void pop_front()
	{
		if (Head == nullptr)return;
		//1)���������� ����� ���������� ��������
		Element* Erased = Head;
		//2)��������� ����
		Head = Erased->pNext;
		delete Erased;
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

	}
	void print()const
	{
		Element* Temp = Head;//Temp-��� ��������
		while (Temp)//���� �������� �������� �� ������� �����
		{
			cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
			Temp = Temp->pNext;//������� �� ��������� �������
				
		}

		cout << "���������� ��������� ������:" << Head->count << endl;
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
	}
	void insert(int index, int Data)
	{
		if (Head == nullptr||Head==nullptr)return push_front(Data);
		if (index == 0)return push_front(Data);
		if (index > Head->count)return;
		Element* New = new Element(Data);
		//1/������� �� ������� ��������
		Element* Temp = Head;
		for (int i = 0; i < index - 1; i++)Temp = Temp->pNext;
		//�������� ����� ������� � ������
		New->pNext = Temp->pNext;
		Temp->pNext = New;
	}

};
void main() 
{
	setlocale(LC_ALL, "");
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
}