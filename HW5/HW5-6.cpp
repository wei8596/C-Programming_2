#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
using namespace std;

void chang(ifstream& inStream, ofstream& outStream, string firstName, string lastName);

int main()
{
	string fileName1, fileName2, firstName, lastName;
	cout << "Enter the name of a file containing the letter body.\n"
		 << " -- 20 characters max\n";
	cin >> fileName1;
	cout << "Enter the name of a file for the finished letter.\n"
		 << " -- 20 characters max\n";
	cin >> fileName2;
	cout << "Please enter a first name and a last name\n";
	cin >> firstName >> lastName;
	
	ifstream inStream;
	ofstream outStream;
	
	inStream.open(fileName1.c_str());
	if(inStream.fail())
	{
		cout << "Input file opening fialed.\n";
		exit(1);
	}
	
	outStream.open(fileName2.c_str());
	if(inStream.fail())
	{
		cout << "Output file opening fialed.\n";
		exit(1);
	}
	chang(inStream, outStream, firstName, lastName);
	
	inStream.close();
	outStream.close();
	
	return 0;
}

void chang(ifstream& inStream, ofstream& outStream, string firstName, string lastName)
{
	char next;
	bool check = true;
	
	inStream.get(next);
	while(!inStream.eof())
	{
		if(next == '#' && check)
		{
			outStream << firstName << " " << lastName;
			check = false;
			inStream.get(next);
			inStream.get(next);
		}
		else if(next == '#')
		{
			outStream << firstName;
			inStream.get(next);
			inStream.get(next);
		}
		else
			outStream << next;			
		inStream.get(next);
	}
}
