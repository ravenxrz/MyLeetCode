#include <iostream>
using namespace std;

class MyStruct
{
	
public:

	MyStruct(int age, int score);

public:
	int age;
	int score;
};

MyStruct::MyStruct(int age, int score): age(age),
                                        score(score)
{
}


int main()
{
	MyStruct s(10, 20);
	cout << s.age << s.score << endl;
	
	return 0;
}
