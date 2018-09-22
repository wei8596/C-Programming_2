/*inputs a date and outputs the day of the
week that corresponds to that date.*/
#include<iostream>
using namespace std;

bool isLeapYear(int );  //leap year
int getCenturyValue(int );
int getYearValue(int );
int getMonthValue(int , int );


int main(){
	int month, day, year, num;
	
	cout<<"Enter month (1-12)\n";
	cin>>month;
	cout<<"Enter day (1-31)\n";
	cin>>day;
	cout<<"Enter year (0000-9999)\n";
	cin>>year;
	num = day + getMonthValue(month, year) + getYearValue(year) + getCenturyValue(year);
	switch(num % 7){
		case 0:
			cout<<"Sunday\n";
			break;
		case 1:
			cout<<"Monday\n";
			break;
		case 2:
			cout<<"Tuesday\n";
			break;
		case 3:
			cout<<"Wednesday\n";
			break;
		case 4:
			cout<<"Thursday\n";
			break;
		case 5:
			cout<<"Friday\n";
			break;
		case 6:
			cout<<"Saturday\n";
			break;
	}
	
	return 0;
}

bool isLeapYear(int year){  //leap year
	if((year%400==0) || (year%4==0 && year%100!=0))
		return true;
	else
		return false;
}

int getCenturyValue(int year){
	int century, remainder;
	
	century = year / 100;
	remainder = century % 4;
	
	return (3-remainder)*2;
}

int getYearValue(int year){
	int num;
	
	num = year % 100;
	
	return (num/4)+num;
}

int getMonthValue(int month, int year){
	switch(month){
		case 1:
			if(isLeapYear(year))  //leap year
				return 6;
			else
				return 0;
		case 2:
			if(isLeapYear(year))  //leap year
				return 2;
			else
				return 3;
		case 3:
			return 3;
		case 4:
			return 6;
		case 5:
			return 1;
		case 6:
			return 4;
		case 7:
			return 6;
		case 8:
			return 2;
		case 9:
			return 5;
		case 10:
			return 0;
		case 11:
			return 3;
		case 12:
			return 5;
	}
}
