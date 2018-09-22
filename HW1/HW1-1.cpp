/*Suppose we can buy a chocolate bar from the vending machine for $1 each. Inside
every chocolate bar is a coupon. We can redeem 7 coupons for one chocolate bar
from the machine. We would like to know how many chocolate bars can be eaten,
including those redeemed via coupon, if we have n dollars.*/ 
#include<iostream>
using namespace std;

int main(){
	int dollar, coupon, chocolate, more;
	
	cout<<"Enter the number of dollars you have to spend:\n";
	cin>>dollar;
	coupon = chocolate = dollar;
	while(coupon >= 7){  //redeems coupons for bars and calculates the new number of coupons 
		more = coupon/7;
		chocolate += more;
		coupon %= 7;
		coupon += more;
	}
	cout<<"You can get "<<chocolate<<" candy bars  with "<<coupon<<" coupons letover.\n";
	
	return 0;
}
