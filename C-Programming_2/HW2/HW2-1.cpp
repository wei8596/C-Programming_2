#include<iostream>
using namespace std;

void func(int& , int& );

int main(){
	int b, l;
	
	cout<<" Enter length & Breadth of the rectangle :";
	cin>>l>>b;
	func(l, b);
	
	return 0;
}

void func(int& l, int& b){
	int a, s;
	
	a = b * l;
	s = 2 * (b+l);
	cout<<"Rectangle Length :"<<l
		<<" Breadth :"<<b
		<<" Area:"<<a
		<<" Perimeter :"<<s<<"\n";
}
