#include<iostream>
#include<cstdlib>
#include<string>
#include<fstream>
#include<ctime>
using namespace std;

class BoxOfProduce{
	public:
		BoxOfProduce();
		void setItem(string );
		void display();
		void change(int , string );
	private:
		string items[5];
		int count;
};

int main(){
	fstream file;
	BoxOfProduce my;
	string str1[5], str2[5];
	int i, index;
	char ch = '\0';
	srand(time(NULL));
	
	file.open("items.txt", ios::in);	
	if(!file){
		cout<<"FILE ERROR!\n";
		exit(1);
	}
	
	i = 0;
	while(!file.eof()){
		file>>str1[i];
		i++;
	}
	for(int i = 0; i < 3; i++){
		str2[i] = str1[rand()%5];
		my.setItem(str2[i]);
	}
	while(ch != 'q'){
		my.display();
		cout<<"\nEnter 'a' to add a new bundle.\n"
			<<"Enter 'c' to change a bundle.\n"
			<<"Enter 'q' to quit.\n";
		cin>>ch;
		if(ch == 'a'){
			cout<<"Enter item to add.\n"
				<<"LIST================\n";
			for(int i = 0; i < 5; i++)
				cout<<str1[i]<<"\n";
			cin>>str2[0];
			my.setItem(str2[0]);
			my.display();
			cout<<"\n\n";
		}
		else if(ch == 'c'){
			cout<<"LIST================\n";				
			for(int i = 0; i < 5; i++)
				cout<<str1[i]<<"\n";
			cout<<"Enter index of item to change.\n";
			cin>>index;
			cout<<"Enter item to substitute.\n";
			cin>>str2[0];
			my.change(index, str2[0]);
			my.display();
			cout<<"\n\n";
		}
		else if(ch == 'q'){
			cout<<"Final Contents:\n";
			my.display();
			cout<<"\n";
			break;
		}
	}	
	
	return 0;
}

BoxOfProduce::BoxOfProduce():count(0){
	for(int i = 0; i < 5; i++)
		items[i] = "";
}

void BoxOfProduce::setItem(string str){
	items[count] = str;
	count++;
}

void BoxOfProduce::display(){
	int i = 0;
	
	cout<<"The box contains:  ";
	while(items[i][0] != '\0'){
		cout<<"("<<i+1<<")"<<items[i]<<" ";
		i++;
	}
}

void BoxOfProduce::change(int index, string str){
	items[index-1] = str;
}
