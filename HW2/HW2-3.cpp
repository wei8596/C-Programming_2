#include<iostream>
#include<string>
#include<fstream>
#define N 70
using namespace std;

void getHighScore(string& , int& );

int main(){
	fstream file;
	string player1, player2, player3, player4, player5;
	int score1, score2, score3, score4, score5, max;
	
	file.open("scores.txt", ios::in);
	if(!file)
		cout<<"ERROR!\n";
	else{
		while(!file.eof()){
			file>>player1;
			file>>score1;
			file>>player2;
			file>>score2;
			file>>player3;
			file>>score3;
			file>>player4;
			file>>score4;
			file>>player5;
			file>>score5;
		}
		file.close();
		max = score1;
		if(max < score2)
			max = score2;
		if(max < score3)
			max = score3;
		if(max < score4)
			max = score4;
		if(max < score5)
			max = score5;
	}
	if(max == score1)
		getHighScore(player1, max);
	else if(max == score2)
		getHighScore(player2, max);
	else if(max == score3)
		getHighScore(player3, max);
	else if(max == score4)
		getHighScore(player4, max);
	else if(max == score5)
		getHighScore(player5, max);
	
	return 0;
}

void getHighScore(string& player, int& score){
	cout<<"The high score is "<<score<<" by "<<player<<"\n";
}
