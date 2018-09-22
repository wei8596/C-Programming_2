#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Trivia
{
	public:
		Trivia();
		void setQuestion(string );
		void setAnswer(string );
		void setAmount(int );
		string getQuestion();
		bool checkAnswer(string );
		string getAnswer();
		int getAmount();
	private:
		string ques, ans;
		int amount;
};

int main()
{
	int money = 0;
	string str;
	vector<Trivia> v;
	v.clear();
	v.resize(5);
	v[0].setQuestion("What is the 49th state admitted to the USA?\n");
	v[0].setAnswer("alaska");
	v[0].setAmount(2);
	v[1].setQuestion("Geometric shape most like a lost parrot?\n");
	v[1].setAnswer("polygon");
	v[1].setAmount(10);
	v[2].setQuestion("Year that Amelia Earhart disappeared?\n");
	v[2].setAnswer("1938");
	v[2].setAmount(5);
	v[3].setQuestion("Capital of Burundi?\n");
	v[3].setAnswer("bujumbura");
	v[3].setAmount(5);
	v[4].setQuestion("Fifth president of the United States?\n");
	v[4].setAnswer("james monroe");
	v[4].setAmount(7);
	cout << "Trivia Game!\n"
		 << "You have $" << money << endl;
	for(int i = 0; i < 5; i++)
	{
		cout << v[i].getQuestion();
		getline(cin, str);
		if(v[i].checkAnswer(str))
		{
			cout << "That's right!	You win $" << v[i].getAmount() << endl;
			money += v[i].getAmount();
		}
		else
		{
			cout << "That's wrong!\n"
				 << "Ans:\n"
				 << v[i].getAnswer() << endl;
		}
		cout << "You have $" << money << endl;
	}
	cout << "Game over.	Your total winnings are: $" << money << endl;
		
	return 0;
}

Trivia::Trivia() :amount(0)
{}

void Trivia::setQuestion(string q)
{
	ques = q;
}

void Trivia::setAnswer(string a)
{
	ans = a;
}

void Trivia::setAmount(int a)
{
	amount = a;
}

string Trivia::getQuestion()
{
	return ques;
}

bool Trivia::checkAnswer(string a)
{
	return (a == ans);
}

string Trivia::getAnswer()
{
	return ans;
}

int Trivia::getAmount()
{
	return amount;
}
