/*read the marks scored by a student in six subjects and announce
the result of the student as per the following guidelines. To graduate, the student
should score a minimum of 40 marks in each subject.*/
#include<iostream>
using namespace std;

int main(){
	int sub1, sub2, sub3, sub4, sub5, sub6, sum = 0;
	
	cout<<"Enter the Marks scored in Subject1:";
	cin>>sub1;
	cout<<"Enter the Marks scored in Subject2:";
	cin>>sub2;
	cout<<"Enter the Marks scored in Subject3:";
	cin>>sub3;
	cout<<"Enter the Marks scored in Subject4:";
	cin>>sub4;
	cout<<"Enter the Marks scored in Subject5:";
	cin>>sub5;
	cout<<"Enter the Marks scored in Subject6:";
	cin>>sub6;
	sum = sub1 + sub2 + sub3 + sub4 + sub5 + sub6;
	if(sub1<40 || sub2<40 || sub3<40 || sub4<40 || sub5<40 || sub6<40)
		cout<<" Not eligible for Promotion\n";
	else{
		cout<<"\n Eligible for Promotion to next semester\n"
			<<" Percentage is "<<sum/6<<" Grade is ";
			if(sum/6 > 90)
				cout<<"AA\n";
			else if(sum/6 > 80)
				cout<<"AB\n";
			else if(sum/6 > 70)
				cout<<"BB\n";
			else if(sum/6 > 60)
				cout<<"BC\n";
			else if(sum/6 > 50)
				cout<<"CC\n";
			else if(sum/6 > 40)
				cout<<"CD\n";
			else if(sum/6 >= 35)
				cout<<"DD\n";
			else if(sum/6 < 35)
				cout<<"FF\n";
	}		
	
	return 0;
}
