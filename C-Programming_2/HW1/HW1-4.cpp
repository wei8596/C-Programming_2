/*"Ninety Nine Bottles of Beer on the Wall" song*/
#include<iostream>
using namespace std;

void digit(int);  //ones

int main(){
	int i, count, num = 99;
	
	while(num >= 0){
		count = 1;
		if(num == 99)
			i = 1;
		else
			i = 0;
		for(; i < 3; i++){
			switch(num / 10){  //tens
				case 9:
					cout<<"Ninety ";
					digit(num);
					break;
				case 8:
					cout<<"Eighty ";
					digit(num);
					break;
				case 7:
					cout<<"Seventy ";
					digit(num);
					break;
				case 6:
					cout<<"Sixty ";
					digit(num);
					break;
				case 5:
					cout<<"Fifty ";
					digit(num);
					break;
				case 4:
					cout<<"Forty ";
					digit(num);
					break;
				case 3:
					cout<<"Thirty ";
					digit(num);
					break;
				case 2:
					cout<<"Twenty ";
					digit(num);
					break;
				case 0:
					digit(num);
					break;
			}			
			if(num == 0 )
				cout<<"Zero ";  //0
			else if(num == 10)
				cout<<"Ten ";  //10
			else if(num == 11)
				cout<<"Eleven ";  //11
			else if(num == 12)
				cout<<"Twelve ";  //12
			else if(num == 13)
				cout<<"Thirteen ";  //13
			else if(num == 14)
				cout<<"Fourteen ";  //14
			else if(num == 15)
				cout<<"Fifteen ";  //15
			else if(num == 16)
				cout<<"Sixteen ";  //16
			else if(num == 17)
				cout<<"Seventeen ";  //17
			else if(num == 18)
				cout<<"Eighteen ";  //18
			else if(num == 19)
				cout<<"Nineteen ";  //19
			cout<<"bottle"<<((num != 1) ? "s" : "")<<" of beer";
			switch(count){
				case 1:
				case 2:
					cout<<(((num==99 && count==1) || (num!= 99)) ? " on the wall" : "")<<((num != 99 && count == 1) ? ".\n\n" : ",\n");
					break;				
				case 3:
					cout<<",\n";
					break;
			}
			if(num == 0)
				break;
			count++;
		}
		if(num != 0)
			cout<<"Take one down, pass it around,\n";
		num--;
	}
	
	return 0;
}

void digit(int n){  //ones
	switch(n % 10){
		case 9:
			cout<<"Nine ";
			break;
		case 8:
			cout<<"Eight ";
			break;
		case 7:
			cout<<"Seven ";
			break;
		case 6:
			cout<<"Six ";
			break;
		case 5:
			cout<<"Five ";
			break;
		case 4:
			cout<<"Four ";
			break;
		case 3:
			cout<<"Three ";
			break;
		case 2:
			cout<<"Two ";
			break;
		case 1:
			cout<<"One ";
			break;
	}
}
