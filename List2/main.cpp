#include"List.h"
#include"List.cpp"

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