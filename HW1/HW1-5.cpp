/*a simple two player dice game in which the first player to reach
100 or more points wins. Players take turns. On each turn a player rolls a
six-sided die.*/
#include<iostream>
#include<cstdlib>  //srand, rand
#include<ctime>  //time
using namespace std;

int humanTurn(int );
int computerTurn(int );

int main(){
	int humanTotal = 0, computerTotal = 0;
	char ch;
	srand(time(NULL));
	
	do{
		cout<<"It's your turn!  Enter 'r' to roll.\n";  //human turn
		cin>>ch;
		if(ch == 'r')
			humanTotal += humanTurn(humanTotal);
		if(humanTotal >= 100){  //human wins
			cout<<"You win!\n";
			break;
		}
		
		cout<<"It's the computer's turn!\n";  //computer turn
		computerTotal += computerTurn(computerTotal);
		if(computerTotal >= 100){  //the computer wins
			cout<<"The computer wins!\n";
			break;
		}
	}while(humanTotal<100 && computerTotal<100);
	
	return 0;
}

int humanTurn(int humanTotalScore){
	int point, score = 0;
	char ch;
	
	do{		
		point = rand()%6 + 1; //roll the die
		cout<<"You rolled "<<point<<"\n";		
		if(point == 1){
			cout<<"You lose your turn.  Enter 'c' to continue.\n";  //rolls a 1
			cin>>ch;
			if(ch == 'c')				
				break;
		}		
		score += point;  //each round's score
		cout<<"Your score this round is: "<<score<<"\n"
			<<"If you hold, your total score would be: "<<humanTotalScore+score<<"\n";
		if((point != 1) && ((humanTotalScore+score)<100)){
			cout<<"Press 'h' to hold or 'r' to roll again.\n";
			cin>>ch;
			if(ch == 'h')
				return score;  //hold
		}
	}while((ch=='r') && ((humanTotalScore+score)<100));
	
	if((point != 1) && ((humanTotalScore+score)>=100))
		return score;
	else
		return 0;  //rolls a 1
}

int computerTurn(int computerTotalScore){
	int point, score = 0;
	char ch;	
	
	do{
		point = rand()%6 + 1; //roll the die
		cout<<"The computer rolled "<<point<<"\n";
		if(point == 1){
			cout<<"The computer loses its turn.  Enter 'c' to continue.\n";  //rolls a 1
			cin>>ch;
			if(ch == 'c')
				break;
		}		
		score += point;  //each round's score
		cout<<"The computer's score this round is: "<<score<<"\n"
			<<"If the computer holds, its total score would be: "<<computerTotalScore+score<<"\n";
	}while((score<20) && ((computerTotalScore+score)<100));
	
	if((score>=20) && ((computerTotalScore+score)<100)){  //the computer has accumulated 20 or more points
		cout<<"The computer holds.  Enter 'c' to continue.\n";
		cin>>ch;
		return score;
	}
	else if((computerTotalScore+score) >= 100)
		return score;
	else	
		return 0;  //rolls a 1
}
