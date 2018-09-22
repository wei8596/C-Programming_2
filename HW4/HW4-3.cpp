#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <ctime>
#include <vector> 
 
using namespace std;

class BoxOfProduce
{
	public:
		BoxOfProduce(){	items.clear(); }
		void setItem(string );
		int getSize() const;
		vector<string> getItem() const;
		void output();
		void change(int , string );
		friend BoxOfProduce operator + (const BoxOfProduce& box1, const BoxOfProduce& box2);
	private:
		vector<string> items;
};

int main()
{
	fstream file;
	BoxOfProduce box1, box2, box3;
	string str1[5], str2[5];
	int i;
	srand(time(NULL));
	
	file.open("items.txt", ios::in);	
	if(!file)
	{
		cout << "FILE ERROR!\n";
		exit(1);
	}
	
	i = 0;
	while(!file.eof())
	{
		file >> str1[i];
		i++;
	}
	file.close();
	
	for(int i = 0; i < 2; i++)
	{
		str2[i] = str1[rand()%5];
		box1.setItem(str2[i]);
	}
	for(int i = 0; i < 4; i++)
	{
		str2[i] = str1[rand()%5];
		box2.setItem(str2[i]);
	}
	
	box1.output();
	cout << endl; 
	box2.output();
	cout << endl;
	
	box3 = box1 + box2;
	box3.output();
	cout << endl;
	
	return 0;
}

void BoxOfProduce::setItem(string str)
{
	items.push_back(str);
}

int BoxOfProduce::getSize() const
{
	return items.size();
}

vector<string> BoxOfProduce::getItem() const
{
	return items;
}

void BoxOfProduce::output()
{
	unsigned int i = 0;
	
	cout << "The box contains:  ";
	while(i < items.size())
	{
		cout << "("<<i+1<<")"<<items[i]<<" ";
		i++;
	}
}

BoxOfProduce operator + (const BoxOfProduce& box1, const BoxOfProduce& box2)
{	
	BoxOfProduce temp;
	unsigned int i = 0;
	vector<string> items1, items2;
	
	items1 = box1.getItem();
	items2 = box2.getItem();
	while(i < items1.size())
	{
		temp.items.push_back(items1[i]);
		i++;
	}
	i = 0;
	while(i < items2.size())
	{
		temp.items.push_back(items2[i]);
		i++;
	}
	
	return temp;
}
