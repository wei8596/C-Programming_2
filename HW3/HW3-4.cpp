#include <cctype>  // for tolower()
#include <iostream>
using namespace std;

class Day{
public:
    Day(char c1, char c2, char c3);
    // constructor to set day based on first 
    // 3 chars of the day name

    Day(int dayNumber);
    // a constructor to set day base on day number,
    // 1 = Monday etc.

    Day();
    // a default constructor (do nothing)

    void getDayByNumber(istream&);
    // an input function to set the day based on the 
    // day number

    void getDayByName(istream&);
    // input function to set the day based on a three
    // character input

    void outputDayNumber(ostream&);
    // an output function that outputs the day as an integer,

    void outputDayName(ostream&);
    // an output function that outputs the day as the letters.

    Day nextDay();
    // a function that returns the next day as a day object
private:
    int dy;
};

int main(){
	char ch1, ch2, ch3;
	int intday;
	
    cout << "testing constructor Day(char, char, char)" << endl;
    Day d;
    cin>>ch1>>ch2>>ch3;
    d = Day(ch1, ch2, ch3);
    d.outputDayName(cout); cout << " ";
    d.outputDayNumber(cout); cout << endl;
    
    
    cout << endl << "Testing Day(int) constructor" << endl;
    cin>>intday;
    Day dd(intday);
    dd.outputDayNumber(cout); cout << " ";
    dd.outputDayName(cout); cout << endl;
    
    
    cout << endl << "Testing the getDayByName and outputDay*" << endl;
    d.getDayByName(cin);
    d.outputDayNumber(cout); cout << " ";
    d.outputDayName(cout); cout << endl;
    
    
    cout << endl << "Testing the getDayByNumber and outputDay*" << endl;
    dd.getDayByNumber(cin);
    dd.outputDayNumber(cout); cout << " ";
    dd.outputDayName(cout); cout << endl;
    
    
    cout << endl << "Testing nextDay member" << endl;
    cout << "current Day ";
    dd.outputDayNumber(cout); cout << endl;
    dd.outputDayName(cout); cout << endl;
    cout << "nextDay ";
    dd.nextDay().outputDayNumber(cout); cout << " ";
    dd.nextDay().outputDayName(cout); cout << endl;
    return 0;
}

Day Day::nextDay()
{
    int nextDay = dy + 1;
    if(nextDay == 13)
        nextDay = 1;
    return Day(nextDay);
}

Day::Day(int dayNumber)
{
    dy = dayNumber;
}

void Day::outputDayNumber(ostream& in)
{
    cout << dy;
}

void Day::outputDayName(ostream& out)
{
    if(1 == dy) out << "mon";
    else if(2 == dy) out << "tue";
    else if(3 == dy) out << "wed";
    else if(4 == dy) out << "thu";
    else if(5 == dy) out << "fri";
    else if(6 == dy) out << "sat";
    else if(7 == dy) out << "sun";
}

void Day::getDayByNumber(istream& in)
{
    in >> dy; // int Day::dy;
}

void Day::getDayByName(istream& in)
{
    char c1, c2, c3;
    in >> c1 >> c2 >> c3;
    c1 = tolower(c1); //force to lower case so any case
    c2 = tolower(c2); //the user enters is acceptable
    c3 = tolower(c3);
    if(c1=='m'&&c2=='o'&&c3=='n')
    	dy = 1;
    else if(c1=='t'&&c2=='u'&&c3=='e')
    	dy = 2;
    else if(c1=='w'&&c2=='e'&&c3=='d')
    	dy = 3;
    else if(c1=='t'&&c2=='h'&&c3=='u')
    	dy = 4;
    else if(c1=='f'&&c2=='r'&&c3=='i')
    	dy = 5;
    else if(c1=='s'&&c2=='a'&&c3=='t')
    	dy = 6;
    else if(c1=='s'&&c2=='u'&&c3=='n')
    	dy = 7;
}

Day::Day(char c1, char c2, char c3){
	c1 = tolower(c1);
    c2 = tolower(c2);
    c3 = tolower(c3);
	if(c1=='m'&&c2=='o'&&c3=='n')
    	dy = 1;
    else if(c1=='t'&&c2=='u'&&c3=='e')
    	dy = 2;
    else if(c1=='w'&&c2=='e'&&c3=='d')
    	dy = 3;
    else if(c1=='t'&&c2=='h'&&c3=='u')
    	dy = 4;
    else if(c1=='f'&&c2=='r'&&c3=='i')
    	dy = 5;
    else if(c1=='s'&&c2=='a'&&c3=='t')
    	dy = 6;
    else if(c1=='s'&&c2=='u'&&c3=='n')
    	dy = 7;
}

Day::Day()
{
    // body deliberately empty
}
