#include<iostream>
#include<cstring>
using namespace std;

void func(char* , int );

int main(){
	char str1[70] = "Mary had a little lamb. its fleece was white as snow.";
	char str2[70] = "Now is the time for all good men to come to the aid of the country.";
	
	cout<<str1<<"\n";
	cout<<"size = "<<strlen(str1)<<"\n";
	cout<<"reduced array = ";
	func(str1, strlen(str1));
	
	cout<<str2<<"\n";
	cout<<"size = "<<strlen(str2)<<"\n";
	cout<<"reduced array = ";
	func(str2, strlen(str2));
	
	return 0;
}

void func(char* array, int size){
	char str[70];
	int j = 0;
	
	for(int i = 0; array[i] != '\0'; i++){
		switch(array[i]){
			case 'a':
			case 'A':
			case 'e':
			case 'E':
			case 'i':
			case 'I':
			case 'o':
			case 'O':
			case 'u':
			case 'U':
				continue;
			default:
				str[j] = array[i];
				j++;
		}
	}
	str[j] = '\0';
	cout<<str<<"...............\n";
	cout<<"reduced array size = "<<strlen(str)<<"\n";
}
