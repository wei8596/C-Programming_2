#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>

using namespace std;

bool isAlpha(char ch);
bool isNumber(char ch);
void a(vector<char>& v);
void b(vector<char>& v);
void c(vector<char>& v);
void d(vector<char>& v);
void e(vector<char>& v);
void f(vector<char>& v);
void g(vector<char>& v);
void h(vector<char>& v);

int main(int argc, char* argv[])
{
	fstream file;
	char ch;
	vector<char> v;
	
	file.open(argv[1], ios::in);
	if(!file)
	{
		cout<<"ERROR!\n";
		exit(1);
	}
	else
	{
		while(!file.eof())
		{
			file.get(ch);
			v.push_back(ch);
		}
	}
	cout << "orginal:\n";
	for(unsigned int i = 0; i < v.size(); i++)
		cout << v[i];
	
	cout << "after:\n";
	c(v);
	e(v);
	d(v);
	f(v);
	g(v);
	h(v);
	a(v);
	b(v);
	for(unsigned int i = 0; i < v.size(); i++)
		cout << v[i];
	
	return 0;
}

bool isAlpha(char ch)
{
	ch = tolower(ch);
	
	return ('a'<=ch && ch<='z');
}

bool isNumber(char ch)
{
	return ('1'<=ch && ch<='9');
}

void a(vector<char>& v)
{
	for(unsigned int i = 0; i < v.size(); )
	{
		if(('1'<=v[i-2]&&v[i-2]<='9') && (v[i-1]=='.'&&v[i]==' '))
		{
			v.erase(v.begin()+i-2);  //erase 會返回「被移除元素之下一個元素」
			i--;
			v.erase(v.begin()+i-1);
			i--;
			v.erase(v.begin()+i);
		}
		else
			i++;
	}
}
void b(vector<char>& v)
{
	bool spaceFlag = true;
	
	for(unsigned int i = 0; i < v.size(); )
	{
		if(v[i]==' ' && spaceFlag)
		{
			spaceFlag = false;
			i++;
		}
		else if(v[i]==' ' && !spaceFlag)
		{
			if(v[i+1] != ' ')
				spaceFlag = true;
			v.erase(v.begin()+i);
		}
		else
		{
			spaceFlag = true;
			i++;
		}
	}
}
void c(vector<char>& v)
{
	for(unsigned int i = 0; i < v.size(); i++)
	{
		if(isAlpha(v[i-1]) && v[i]=='-')
			v[i] = ' ';
	}
}

void d(vector<char>& v)
{
	int count = 0;
	
	for(unsigned int i = 0; i < v.size(); i++)
	{
		if(v[i]=='\n' && count<6)
		{
			v.insert(v.begin()+i, ' ');
			v.insert(v.begin()+i+1, '-');
			v.insert(v.begin()+i+2, ' ');
			i += 3;
			count++;
		}
	}
}

void e(vector<char>& v)
{
	int c;
	
	for(unsigned int i = 0; i < v.size(); i++)
	{
		if(v[i]=='A' && v[i+1]=='n' && v[i+2]==' ')
		{
			c = i;
			while(v[c] != '-')
				c++;
			while(!isAlpha(v[c]))
				c--;
			c++;
			v.insert(v.begin()+c, ' ');
			v.insert(v.begin()+c+1, 'A');
			v.insert(v.begin()+c+2, 'n');
			v.erase(v.begin()+i);
			v.erase(v.begin()+i);
			v.erase(v.begin()+i);
		}
		else if(v[i]=='A' && v[i+1]==' ')
		{
			c = i;
			while(v[c] != '-')
				c++;
			while(!isAlpha(v[c]))
				c--;
			c++;
			v.insert(v.begin()+c, ' ');
			v.insert(v.begin()+c+1, 'A');
			v.erase(v.begin()+i);
			v.erase(v.begin()+i);
		}
		else if(v[i]=='T' && v[i+1]=='h' && v[i+2]=='e')
		{
			c = i;
			while(v[c] != '-')
				c++;
			while(!isAlpha(v[c]))
				c--;
			c++;
			v.insert(v.begin()+c, 'T');
			v.insert(v.begin()+c+1, 'h');
			v.insert(v.begin()+c+2, 'e');
			v.erase(v.begin()+i);
			v.erase(v.begin()+i);
			v.erase(v.begin()+i);
		}
	}
}
void f(vector<char>& v)
{
	int c = 0, first = 0, count = 0;
	
	for(unsigned int i = 0; i<v.size() && count<6; i++)
	{
		while(v[i] != '\n')
			i++;
		while(!isNumber(v[c]))
			c--;
		c += 3;
		first = c;
		while(v[c] != '-')
		{
			v.insert(v.begin()+i, v[c]);
			v.erase(v.begin()+first);
		}
		v.erase(v.begin()+c);
		v.erase(v.begin()+c);
		c = i + 1;
		count++;
	}
}
void g(vector<char>& v)
{
	int c = 0;
	bool second = false;
	
	for(unsigned int i = 0; i < v.size(); i++)
	{
		if(v[i] == '6')
			break;
		else if(isNumber(v[i]))
		{
			if(v[i] == '2')
				second = true;
			
			c = i;
			c += 3;
			while(v[i+1]!='-')
				i++;
			
			v.insert(v.begin()+c, ' ');
			while(v[i] != ' ')
			{
				v.insert(v.begin()+c, v[i]);
				v.erase(v.begin()+i+1);
			}
			
			if(second)
			{
				while(v[i]!='a')
					i--;
				v.erase(v.begin()+i);
				v.erase(v.begin()+i);
				v.erase(v.begin()+i);
				v.erase(v.begin()+i);
				second = false;
				while(v[i] != '.')
					i--;
				i += 2;
				v.insert(v.begin()+i, 'a');
				v.insert(v.begin()+i+1, 'n');
				v.insert(v.begin()+i+2, 'd');
				v.insert(v.begin()+i+3, ' ');
			}
		}
	}
}

void h(vector<char>& v)
{
	char ch[5][2], chTemp;
	int intTemp, c = 0;
	
	for(int i = 0; c < 5; i++)
	{
		while(!isNumber(v[i]))
			i++;
		i += 3;
		ch[c][0] = c+1;
		ch[c][1] = v[i];
		c++;
	}
	for(int i = 0; i < 4; i++)
	{
		for(int j = i+1; j < 5; j++)
		{
			if(ch[i][1] > ch[j][1])
			{
				chTemp = ch[i][1];
				intTemp = ch[i][0];
				ch[i][1] = ch[j][1];
				ch[i][0] = ch[j][0];
				ch[j][1] = chTemp;
				ch[j][0] = intTemp;
			}
		}
	}
	
	int p, i = 0;
	while(v[i] != '3')
		i++;
	p = i;
	while(v[i] != '5')
		i++;
	while(v[i] != '\n')
		i++;
	i++;
	while(v[p] != '\n')
	{
		v.insert(v.begin()+i, v[p]);
		v.erase(v.begin()+p);
	}
	v.insert(v.begin()+i, v[p]);
	v.erase(v.begin()+p);
}
