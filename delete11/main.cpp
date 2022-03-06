#include<iostream>
#include<string>
using namespace std;
class Apple;
class Human
{
public:
	void TakeApple(Apple& apple);

	void EatApple(Apple& apple)
	{
		
	}
};

class Apple
{
	friend Human;
public:
	Apple(int weight,string color)
	{
		this->color = color;
		this->weight = weight;
		count++;
		id = count;
	}
	int get_id()
	{
		
		return id;
	}

	static int get_count()
	{
		return count;
	}
	static void change_color(Apple& apple, string color)
	{
		apple.color = color;
	}
private:
	int weight;
	string color;
	int id;
	static int count;
};

int Apple::count = 0;



int main()
{
	setlocale(LC_ALL, "");
	Apple apple(150, "Red");
	apple.change_color(apple, "green");
	//Apple apple2(100, "Green");
	//cout << apple.get_id() << endl;
	//cout<< apple2.get_id() << endl;
	//cout << Apple::get_count() << endl;
	//cout << apple.get_count() << endl;
	Human human;
	human.TakeApple(apple);
	return 0;
}

void Human::TakeApple(Apple& apple)
{
	cout << apple.weight << endl << apple.color;
	
}
