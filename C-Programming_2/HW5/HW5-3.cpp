#include <iostream>
using namespace std;
void swap(char& v1, char& v2);
char* reverse(char* s);
//Returns a copy of s but with characters in reverse order.
bool isPal(char* s);
//Return true if s is a palindrome; false otherwise.
const int Size = 50;

int main()
{
	char* str = new char[Size];
	for(int i = 0; i < Size; i++)
		str[i] = '\0';
	
	cout << "Enter a string less than 50 characters long.\n";
	cin.get(str, Size);
		
	if(isPal(str))
		cout << endl << str << " Is a Palindrome\n";
	else
		cout << endl << str << " Is not a Palindrome\n";
	delete [] str;
	
	return 0;
}

void swap(char& v1, char& v2)
{
	char temp = v1;
	v1 = v2;
	v2 = temp;
}

char* reverse(char* s)
{
	int count = 0;
	while(s[count] != '\0')
		count++;
	int start = 0;
	int end = count - 1;
	char *head = &s[start];
	char *tail = &s[end];
	char* temp = new char[Size];
	for(int j = 0; s[j] != '\0'; j++)
		temp[j] = s[j];
	
	while((head!=tail) && (start+1!=end))
	{
		swap(temp[start], temp[end]);
		start++;
		end--;
		head = &s[start];
		tail = &s[end];
	}
	
	return temp;
}

bool isPal(char* s)
{
	bool check = true;
	char* temp = reverse(s);
	
	for(int i = 0; s[i] != '\0'; i++)
	{
		if(s[i] != temp[i])
		{
			check = false;
			break;
		}
	}
	
	return check;
}
