#include <iostream>
#include <vector>
#define M 100
#define N 2
using namespace std;

int main(){
	int grade, i, max, index, number, tmpdata, tmpcount;
	bool again;
	vector<vector<int> > v;
	
	v.resize(M);
	for(int i = 0; i != M; i++)
		v[i].resize(N);
	cout<<"Enter each grade and then -1 to stop.\n";
	i = 0;
	max = grade = 0;
	while(true){
		again = false;
		cin>>grade;
		if(grade == -1)
			break;
		else if(grade > max)
			max = grade;
		for(int k = 0; k < M; k++){
			if(grade == v[k][1]){
				v[k][0]++;
				again = true;
				break;
			}				
		}
		if(again){
			i++;
			continue;
		}
		else{
			v[i][1] = grade;
			v[i][0]++;
			index = number = 0;
			while(number < max){
				if(v[index][0] != 0){
					index++;
					continue;
				}
				for(int k = 0; k < M; k++){
					if(number == v[k][1]){
						number++;
						break;
					}				
				}
				v[index][1] = number;
				index++;
				number++;			
			}
			i = index;
		}		
	}
	
	for(int i = 0; i < M-1; i++){
		for(int j = i+1; j < M; j++){
			if(v[i][1] > v[j][1]){
				tmpdata = v[i][1];
				v[i][1] = v[j][1];
				v[j][1] = tmpdata;
				tmpcount = v[i][0];
				v[i][0] = v[j][0];
				v[j][0] = tmpcount;
			}
		}
	}
	
	i = 0;
	while(v[i][1] == 0)
		i++;
	for(--i; v[i][1] < max; i++)
		cout<<v[i][0]<<" grade(s) of "<<v[i][1]<<"\n";
	cout<<v[i][0]<<" grade(s) of "<<v[i][1]<<"\n";
	
	return 0;
}
