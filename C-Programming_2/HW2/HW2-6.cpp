#include<iostream>
#include<cmath>
using namespace std;

int main(){
	int review[6][5] = {{-1,3,4,3,5},{-1,1,2,1,1},{-1,5,1,2,4},
					{-1,2,4,4,2},{-1,1,2,4,4},{-1,5,4,1,2}};
	int i, a, b, c, d, min, closest, movie[3] = {0}, rating[3] = {0};
	
	i = 0;
	while(true){
		cout<<"Enter a movie to rate (100-105). "
			<<"Enter 0 to exit and get recommendations.\n";
		cin>>movie[i];
		if(movie[0] == 0)
			exit(1);
		else if(movie[i] == 0)
			break;
		else if(movie[i]-100 == 0)
			review[0][0] = 0;
		else if(movie[i]-100 == 1)
			review[1][0] = 1;
		else if(movie[i]-100 == 2)
			review[2][0] = 2;
		else if(movie[i]-100 == 3)
			review[3][0] = 3;
		else if(movie[i]-100 == 4)
			review[4][0] = 4;
		else if(movie[i]-100 == 5)
			review[5][0] = 5;
		cout<<"Enter rating (1-5) for this movie.\n";
		cin>>rating[i];
		i++;		
	}
	a = sqrt(pow((rating[0]-review[movie[0]-100][1]), 2) + pow((rating[1]-review[movie[1]-100][1]), 2) + pow((rating[2]-review[movie[2]-100][1]), 2));
	b = sqrt(pow((rating[0]-review[movie[0]-100][2]), 2) + pow((rating[1]-review[movie[1]-100][2]), 2) + pow((rating[2]-review[movie[2]-100][2]), 2));
	c = sqrt(pow((rating[0]-review[movie[0]-100][3]), 2) + pow((rating[1]-review[movie[1]-100][3]), 2) + pow((rating[2]-review[movie[2]-100][3]), 2));
	d = sqrt(pow((rating[0]-review[movie[0]-100][4]), 2) + pow((rating[1]-review[movie[1]-100][4]), 2) + pow((rating[2]-review[movie[2]-100][4]), 2));
	min = a;
	if(min > b)
		b = min;
	if(min > c)
		c = min;
	if(min > d)
		d = min;
	if(a == min)
		closest = 0;
	else if(b == min)
		closest = 1;
	else if(c == min)
		closest = 2;
	else if(d == min)
		closest = 3;
	cout<<"The closest reviewer is number "<<closest<<"\n";
	cout<<"Predictions for movies you have not yet seen:\n";
	for(int i = 0; i < 6; i++){
		if(review[i][0] == -1){
			if(i == 0)
				cout<<"Movie 100 : Predicted Rating = "<<review[0][closest+1]<<"\n";
			else if(i == 1)
				cout<<"Movie 101 : Predicted Rating = "<<review[1][closest+1]<<"\n";
			else if(i == 2)
				cout<<"Movie 102 : Predicted Rating = "<<review[2][closest+1]<<"\n";
			else if(i == 3)
				cout<<"Movie 103 : Predicted Rating = "<<review[3][closest+1]<<"\n";
			else if(i == 4)
				cout<<"Movie 104 : Predicted Rating = "<<review[4][closest+1]<<"\n";
			else if(i == 5)
				cout<<"Movie 105 : Predicted Rating = "<<review[5][closest+1]<<"\n";
		}
	}
	
	return 0;
}
