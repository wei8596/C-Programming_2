#include<iostream>
using namespace std;

struct Record{
	int score[5][5];
};

class Grade{
	public:
		Grade();
		void setid(int );
		void setquiz(int , int );
		void setexam(int , int );
		void output();
	private:
		Record r;
		int count;
};

int main(){
	Grade student;
	int num1, num2;
	
	for(int i = 0; i < 5; i++){
		cout<<"enter the student number: ";
		cin>>num1;
		student.setid(num1);
		cout<<num1<<"\n";
		cout<<"enter two 10 point quizes\n";
		cin>>num1;
		cin>>num2;
		student.setquiz(num1, num2);  //two quizzes, each graded on the basis of 10 points.
		cout<<num1<<" "<<num2<<"\n";
		cout<<"enter the midterm and final exam grades. These are 100 point tests\n";
		cin>>num1;
		cin>>num2;
		student.setexam(num1, num2);  //one midterm exam and one final exam,
		cout<<num1<<" "<<num2<<"\n\n";  // each graded on the basis of 100 points.		
	}
	student.output();
	
	return 0;
}

Grade::Grade():count(0){
}

void Grade::setid(int id){
	r.score[count][0] = id;
}

void Grade::setquiz(int quiz1, int quiz2){
	r.score[count][1] = quiz1;
	r.score[count][2] = quiz2;
}

void Grade::setexam(int mid, int final){
	r.score[count][3] = mid;
	r.score[count][4] = final;
	count++;
}

void Grade::output(){
	double ave;
	
	for(int i = 0; i < 5; i++){
		cout<<"The record for student number: "<<r.score[i][0]<<"\n"
			<<"The quiz grades are: "<<r.score[i][1]<<" "<<r.score[i][2]<<"\n"
			<<"The midterm and exam grades are: "<<r.score[i][3]<<" "<<r.score[i][4]<<"\n";
			
		ave = r.score[i][4]*0.5 + r.score[i][3]*0.25 + (r.score[i][1]+r.score[i][2])*10*0.5*0.25;
		//final exam counts for 50%, midterm counts for 25%, two quizzes together count for a total of 25%
		cout<<"The numeric average is: "<<ave<<"\n"
			<<"and the letter grade assigned is ";
		
		if(ave >=90)
			cout<<"A\n\n";
		else if(ave>=80 && ave<90)
			cout<<"B\n\n";
		else if(ave>=70 && ave<80)
			cout<<"C\n\n";
		else if(ave>=60 && ave<70)
			cout<<"D\n\n";
		else
			cout<<"F\n\n";
	}
}
