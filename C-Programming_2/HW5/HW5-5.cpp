#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
	string fileName;
	fstream file;
	double num, ave = 0;
	int count = 0;
	
	cout << "Enter a file name. 12 characters or less, please.\n";
	cin >> fileName;
	file.open(fileName.c_str(), ios::in);
	if(!file)
	{
		cout << "ERROR!\n";
		exit(1);
	}
	
	while(!file.eof() && count < 10)
	{
		file >> num;
		ave += num;
		count++;
	}
	ave /= count;
	file.close();
	
	file.open(fileName.c_str(), ios::in);
	if(!file)
	{
		cout << "ERROR!\n";
		exit(1);
	}
	
	count = 0;
	double total = 0, sd = 0;
	while(!file.eof() && count < 10)
	{
		file >> num;
		total += pow(num-ave, 2);
		count++;
	}
	file.close();
	sd = sqrt(total / count);
	
	cout << "Average of " << count << " numbers is " << fixed << setprecision(6) << ave << endl
		 << "Standard Deviation of " << count << " numbers is " << sd << endl; 
	
	return 0;
}
