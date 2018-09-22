#include<iostream>
#include<cstring>
#define N 21
using namespace std;

int Input(char*);
void Print(char*);
int Add(char* , char* , char* );

int main(){
	char num1[N] = {'\0'}, num2[N] = {'\0'}, num3[N] = {'\0'};
	
	cout<<"Large integer summing program\n"
		<<"Please enter  an integer, 20 digits or less\n";
	while(Input(num1) == -1){
		cout<<"\nLarge integer summing program\n"
			<<"Please enter  an integer, 20 digits or less\n";
		continue;
	}		
	cout<<"you entered\n";
	Print(num1);
	cout<<"Enter another integer, 20 digits or less\n";
	Input(num2);
	cout<<"you entered\n";
	Print(num2);
	cout<<"The sum is:\n";
	Print(num1);
	Print(num2);
	cout<<"----------------------\n";
	if(Add(num1, num2, num3) != -1)	
		Print(num3);
	
	return 0;
}

int Input(char* num){
	char s[N];
	int l;

	for(int i = 0; i < N; i++)
		num[i] = 0;
	cin>>s;
	l = strlen(s);
	if(l > 20){
		cout<<"Input number size too large. Aborting.\n";
		return -1;
	}
	for(int i = 0; i < l; i++)
		num[i] = s[l-i-1]-'0';

	return 0;
}

void Print(char* num){
	int i;

	for(i = N-1; i > 0; i--){
		cout<<" ";
		if(num[i] != 0)
			break;
	}
	for(; i >= 0; i--)
		cout<<(int)num[i];

	cout<<"\n";
}

int Add(char* num1, char* num2, char* num3){
	int l;
	
	for(int i = 0; i < N; i++)
		num3[i] = num1[i] + num2[i];
	for(int i = 0; i < N-1; i++){
		if(num3[i] >= 10){
			num3[i+1] += num3[i]/10;
			num3[i] = num3[i]%10;

		}
	}
	l = strlen(num3);
	if(l > 20){
		cout<<"An overflow has occurred. Result is set to 0\n";
		return -1;
	}
	return 0;
}
