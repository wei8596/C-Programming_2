#include<iostream>
#include<cstdlib>
#define N 100
using namespace std;

class CharPair
{
	public:
		CharPair();
		CharPair(int sz);
		CharPair(int sz, char ch[]);
		int getSize();
		void output();
		char& operator [] (int index);
	private:
		char arr[N];
		int size;
};

int main()
{
	CharPair a;
	cout << "a.\n"
		 << a.getSize() << endl;
	a.output();
	
	cout << "\n\nb.\nEnter two letters (no space):\n";
	cin >> a[1] >> a[2];
	cout << "You entered:\n"
		 << a[1] << a[2] << endl;
	
	CharPair c(3);
	cout << "\nc.\n"
		 << c.getSize() << endl;
	c.output();
	
	char arr[5];
	for(int i = 0; i < 5; i++)
		arr[i] = '*';
	CharPair d(5, arr);
	cout << "\n\nd.\n"
		 << d.getSize() << endl;
	d.output();
	
	return 0;
}

CharPair::CharPair()
{
	int i;
	
	size = 10;
	for(i = 0; i < size; i++)
		arr[i] = '#';
	arr[i] = '\0';
}

CharPair::CharPair(int sz)
{
	int i;
	
	size = sz;
	for(i = 0; i < size; i++)
		arr[i] = '#';
	arr[i] = '\0';
}

CharPair::CharPair(int sz, char ch[])
{
	int i;
	
	size = sz;
	for(i = 0; i < size; i++)
		arr[i] = ch[i];
	arr[i] = '\0';
}

int CharPair::getSize()
{
	return size;
}

void CharPair::output()
{
	int index = 0;
	
	while(arr[index] != '\0')
	{
		cout << arr[index];
		index++;
	}
}

//Uses iostream and cstdlib
char& CharPair::operator [](int index)
{
	if (index>=0 && index < N)
	{
		return arr[index];
	}
	else
	{
		cout << "Illegal index value.\n";
		exit(1);
	}
}
