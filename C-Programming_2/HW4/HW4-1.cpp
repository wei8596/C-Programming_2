#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

//Class for amounts of money in U.S. currency
class Money
{
	public:
		Money();
		Money(double amount);
		Money(int theDollars, int theCents);
		Money(int theDollars);
		double getAmount() const;
		int getDollars() const;
		int getCents() const;
		friend const Money operator + (const Money& amount1, const Money& amount2);
		friend const Money operator - (const Money& amount1, const Money& amount2);
		friend bool operator == (const Money& amount1, const Money& amount2);
		friend bool operator < (const Money& amount1, const Money& amount2);
		friend bool operator <= (const Money& amount1, const Money& amount2);
		friend bool operator > (const Money& amount1, const Money& amount2);
		friend bool operator >= (const Money& amount1, const Money& amount2);
		friend const Money operator - (const Money& amount);
		friend ostream& operator << (ostream& outputStream, const Money& amount);
		friend istream& operator >> (istream& inputStream, Money& amount);
		const Money percent (int percentFigure) const;
		//Returns percentFigure percent of Money.
		//example: If percentFigure is 10, a Money object is returned that
		//represents 0.1 of the amount of money of the calling object
		//If purse is a Money object representing $100.20, purse.percent(10)
		//is a Money object representing $10.02.
	private:
		//A negative amount is represented as negative dollars
		//and negative cents. Negative $4.50 is represented as
		//-4 and -50.
		int dollars, cents;
		
		int dollarsPart(double amount) const;
		int centsPart(double amount) const;
		int round(double number) const;
};

int main()
{
	double percent;
	Money yourAmount, myAmount(10, 9);
	cout << "Enter an amount of money: ";
	cin >> yourAmount;
	cout << "Enter a percent you wish to take of your amount\n";
	cin >> percent;
	cout << "Your amount is " << yourAmount << endl
		 << "My amount is " << myAmount << endl;
	cout << percent << "% of your amount is " << yourAmount.percent(percent) << endl
		 << "15% of my amount is " << myAmount.percent(15) << endl << endl;
	
	
	if (yourAmount == myAmount)
		cout << "We have the same amounts.\n";
	else
		cout << "One of us is richer.\n";
	
	Money ourAmount = yourAmount + myAmount;
	cout << yourAmount << " + " << myAmount
		 << " equals " << ourAmount << endl;
	
	Money diffAmount = yourAmount - myAmount;
	cout << yourAmount << " - " << myAmount
		 << " equals " << diffAmount << endl;
	cout << "Your amount is " << yourAmount << endl
		 << "My amount is " << myAmount << endl;
	
	if(yourAmount >= myAmount)
		cout << "Your amount is greater than or equal to my Amount\n";
	else
		cout << "You have less money than I do\n";
	
	if(ourAmount > diffAmount)
		cout << "The sum of our Amounts is greater than the difference.\n";
	else
		cout << "Something is terribly wrong.\n";
	
	if(yourAmount <= myAmount)
    	cout << "Your amount is less than or equal to my Amount\n";
	else
    	cout << "Your amount is greater than my Amount\n";

	if(ourAmount < diffAmount)
    	cout << "The sum of our Amounts is less than the difference..\n";
	else
    	cout << "The sum of our Amounts is greater than the difference.\n";	
		 
	return 0;
}

const Money operator +(const Money& amount1, const Money& amount2)
{
	int allCents1 = amount1.getCents() + amount1.getDollars()*100; 
	int allCents2 = amount2.getCents() + amount2.getDollars()*100;
	int sumAllCents = allCents1 + allCents2;
	int absAllCents = abs(sumAllCents);  //Money can be negetive
	int finalDollars = absAllCents / 100;
	int finalCents = absAllCents % 100;
	
	if (sumAllCents < 0) 
	{
		finalDollars = -finalDollars;
		finalCents = -finalCents;
	}
	
	return Money(finalDollars, finalCents);
}
//Uses cstdlib
const Money operator -(const Money& amount1, const Money& amount2)
{
	int allCents1 = amount1.getCents() + amount1.getDollars()*100; 
	int allCents2 = amount2.getCents() + amount2.getDollars()*100;
	int diffAllCents = allCents1 - allCents2;
	int absAllCents = abs(diffAllCents);
	int finalDollars = absAllCents / 100;
	int finalCents = absAllCents % 100;
	
	if (diffAllCents < 0) 
	{
		finalDollars = -finalDollars;
		finalCents = -finalCents;
	}
	
	return Money(finalDollars, finalCents);
}

bool operator ==(const Money& amount1, const Money& amount2)
{
	return((amount1.getDollars()==amount2.getDollars()) && (amount1.getCents() == amount2.getCents()));
}

const Money operator -(const Money& amount)
{
	return Money(-amount.getDollars(), -amount.getCents());
}

Money::Money() : dollars(0), cents(0)
{};

Money::Money(double amount)
				: dollars(dollarsPart(amount)), cents(centsPart(amount))
{};

Money::Money(int theDollars) : dollars(theDollars), cents(0)
{};

//Uses cstdlib:
Money::Money(int theDollars, int theCents)
{
	if ((theDollars < 0 && theCents > 0) || (theDollars > 0 && theCents < 0))
	{
		cout << "Inconsistent money data.\n";
		exit(1);
	}
	dollars = theDollars;
	cents = theCents;
}

double Money::getAmount() const
{
	return (dollars + cents*0.01);
}

int Money::getDollars() const
{
	return dollars;
}

int Money::getCents() const
{
	return cents;
}

int Money::dollarsPart(double amount) const
{
	return static_cast<int>(amount);
}
//Uses cmath
int Money::centsPart(double amount) const
{
	double doubleCents = amount * 100;
	int intCents = (round(fabs(doubleCents))) % 100;
	//% can misbehave on negatives
	if (amount < 0)
		intCents = -intCents;
	return intCents;
}

//Uses cmath
int Money::round(double number) const
{
	return static_cast<int>(floor(number + 0.5));
}

ostream& operator <<(ostream& outputStream, const Money& amount)
{
	int absDollars = abs(amount.dollars);
	int absCents = abs(amount.cents);
	if (amount.dollars < 0 || amount.cents < 0)
		//accounts for dollars == 0 or cents == 0
		outputStream << "$-";
	else
		outputStream << '$';
	outputStream << absDollars;
	
	if (absCents >= 10)
		outputStream << '.' << absCents;
	else
		outputStream << '.' << '0' << absCents;
		
	return outputStream;
}

//Uses iostream and cstblib:
istream& operator >>(istream& inputStream, Money& amount)
{
	char dollarSign;
	inputStream >> dollarSign;  //hopefully
	if (dollarSign != '$')
	{
		cout << "No dollar sign in Money input.\n";
		exit(1);
	}
	
	double amountAsDouble;
	inputStream >> amountAsDouble;
	amount.dollars = amount.dollarsPart (amountAsDouble);
	amount.cents = amount.centsPart (amountAsDouble);
	
	return inputStream;
}

const Money Money::percent (int percentFigure) const
{
	int d = dollars * percentFigure / 100;
	int c = dollars * percentFigure % 100 + cents * percentFigure / 100;
	
	return Money(d, c);
}

bool operator <(const Money& amount1, const Money& amount2)
{
   return (amount1.dollars < amount2.dollars) ||
          ((amount1.dollars == amount2.dollars) &&
           (amount1.cents < amount2.cents));
}

bool operator <=(const Money& amount1, const Money& amount2)
{
   return ((amount1.dollars < amount2.dollars) ||
           ((amount1.dollars == amount2.dollars) &&
            (amount1.cents < amount2.cents)))  ||
          ((amount1.dollars == amount2.dollars)
               && (amount1.cents == amount2.cents));
}

bool operator >(const Money& amount1, const Money& amount2)
{
   return (amount1.dollars > amount2.dollars) ||
          ((amount1.dollars == amount2.dollars) &&
           (amount1.cents > amount2.cents));

}

bool operator >=(const Money& amount1, const Money& amount2)
{
   return ((amount1.dollars > amount2.dollars) ||
           ((amount1.dollars == amount2.dollars) &&
            (amount1.cents > amount2.cents)))  ||
          ((amount1.dollars == amount2.dollars)
               && (amount1.cents == amount2.cents));
}
