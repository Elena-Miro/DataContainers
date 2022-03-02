#include<iostream>
using namespace std;

class Tree
{
protected:
	class Element
	{
	
		int Data;
		Element* pLeft;
		Element* pRight;
	public:
		Element(int Data, Element* pLeft=nullptr, Element* pRight=nullptr) :Data(Data), pLeft(pLeft), pRight(pRight)
		{
			cout << "EConstructor:\t" << this << endl;
		}
		~Element()
		{
			cout << "EDestructor" << this << endl;
		}
		friend class Tree;
		friend class UniqueTree;
	}*Root;
public:
	Element* get_Root()const
	{
		return Root;
	}
	Tree()
	{
		this->Root = nullptr;
		cout << "TConstructor:\t" << this << endl;
	}
	Tree(const std::initializer_list<int>& il) :Tree()
	{
		for (int const* it = il.begin(); it != il.end(); it++)
		{
			insert(*it, Root);
		}
	}
	Tree(const Tree& other):Tree()
	{
		copy(other.Root);
		cout << "CopyConstructor:\t" << this << endl;
	}
	~Tree()
	{
		clear();
		cout << "TDeconstructor:\t" << this << endl;
	}
	void insert(int Data,Element* Root)
	{
		if (this->Root == nullptr)
		{
			this->Root = new Element(Data);
			return;
		}
		if (Root == nullptr)return;
		if (Data < Root->Data)
		{
			if (Root->pLeft == nullptr)Root->pLeft = new Element(Data);
			else insert(Data, Root->pLeft);
		}
		else
		{
			if (Root->pRight == nullptr)Root->pRight = new Element(Data);
			else insert(Data, Root->pRight);
			
		}
	}
	void insert(int Data)
	{
		insert(Data, Root);
	}
	int minValue()const
	{
		return minValue(Root);
	}
	int maxValue()const
	{
		return maxValue(Root);
	}
	void print()const
	{
		print(Root);
	}
	int size()const
	{
		return size(Root);
	}
	int sum()const
	{
		return sum(Root);
	}
	double avg()const
	{
		return (double)sum(Root) / size(Root);
	}
	void clear()
	{
		clear(Root);
		Root = nullptr;
	}
private:
	void clear(Element* Root)
	{
		if (Root == nullptr)return;
		clear(Root->pLeft);
		clear(Root->pRight);
		delete Root;
	}

	void copy(Element* Root)
	{
		if (Root == nullptr)return;
		insert(Root->Data, this->Root);
		copy(Root->pLeft);
		copy(Root->pRight);
	}
	int minValue(Element* Root)const
	{
		if (Root == nullptr)return 0;
		/*if (Root->pLeft == nullptr)return Root->Data;
		else return minValue(Root->pLeft);*/
		//return Root->pLeft == nullptr ? Root->Data : minValue(Root->pLeft);
		return Root->pLeft ? minValue(Root->pLeft) : Root->Data;
	}
	int maxValue(Element* Root)const
	{
		if (Root == nullptr)return 0;
		return Root->pRight ? maxValue(Root->pRight) : Root->Data;
	}
	int size(Element* Root)const
	{
		return Root == nullptr ? 0 : size(Root->pLeft) + size(Root->pRight) + 1;
	}
	int sum(Element* Root)const
	{
		return !Root ? 0 : sum(Root->pLeft) + sum(Root->pRight) + Root->Data;
	}
	void print(Element* Root)const
	{
		if (Root == nullptr)return;
		print(Root->pLeft);
		cout << Root->Data << "\t";
		print(Root->pRight);
	}
};
class UniqueTree :public Tree
{

	void insert(int Data, Element* Root)
	{
		if (this->Root == nullptr)
		{
			this->Root = new Element(Data);
			return;
		}
		if (Root == nullptr)return;
		if (Data < Root->Data)
		{
			if (Root->pLeft == nullptr)Root->pLeft = new Element(Data);
			else insert(Data, Root->pLeft);
		}
		else if(Data>Root->Data)
		{
			if (Root->pRight == nullptr)Root->pRight = new Element(Data);
			else insert(Data, Root->pRight);

		}
	}
public:
	void insert(int Data)
	{
		insert(Data, this->Root);
	}
};
//#define BASE_CHECK
void main()
{

	setlocale(LC_ALL, "");
#ifdef BASE_CHECK
	int n;
	cout << "Введите размер дерева:"; cin >> n;
	UniqueTree tree;
	for (int i = 0; i < n; i++)
	{
		tree.insert(rand() % 100);
	}
	//tree.clear();
	tree.print();
	cout << endl;
	cout << "Минимальное значение в дереве: " << tree.minValue();
	cout << endl;
	cout << "Максимальное значение в дереве: " << tree.maxValue();
	cout << endl;
	cout << "Количество элементов в дереве: " << tree.size();
	cout << endl;
	cout << "Сумма элементов дерева: " << tree.sum();
	cout << endl;
	cout << "Среденее арифметическое дерева: " << tree.avg();
	cout << endl;
#endif // BASE_CHECK
	Tree tree = { 50,25,75,16,32,64,80 };
	tree.print();
	Tree tree2 = tree;
	tree2.print();
}