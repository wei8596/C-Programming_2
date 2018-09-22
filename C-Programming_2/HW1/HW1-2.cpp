/*prints the sum of the digits of an integer. */
#include<iostream>
using namespace std;

int main(){
	int num, sum = 0;
	
	cout<<" Enter an Integer\n";
	cin>>num;
	cout<<" Sum of the digits of "<<num<<" is ";
	while(num > 0){
		sum += num%10;
		cout<<num%10<<(((num % 100) > 10) ? "+" : " = ");
		num /= 10;  //truncate the least significant digits
	}
	cout<<sum<<"\n";
	
	return 0;
}
