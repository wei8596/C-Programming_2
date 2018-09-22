/*complete the HW3-3 Modify the main function with a loop */
#include<iostream>
#include<cstdlib>  //srand, rand
#include<string>
#include<fstream>  //file
#include<ctime>  //time
using namespace std;

class BoxOfProduce{
	public:
		BoxOfProduce();
		void setItem1(string );  //creating boxes
		void setItem2(string );  //add
		void output();
		void change(int , string );  //change
		void reset();
		void checkFlyer();  //check containg a recipe flyer
	private:
		string items[5];
		int count;
		static int flyer;
		bool containFlyer, inFlyer;
};

int BoxOfProduce::flyer = 5;

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
		my.setItem1(str2[i]);
	}
	while(true){
		my.output();
		cout<<"\nEnter 'a' to add a new bundle.\n"
			<<"Enter 'c' to change a bundle.\n"
			<<"Enter 'q' to quit.\n";
		cin>>ch;
		if(ch == 'a'){
			cout<<"Enter item to add.\n";
			cin>>str2[0];
			my.setItem2(str2[0]);
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
			my.output();
			cout<<"\n\n";
		}
		else if(ch == 'q'){
			cout<<"Final Contents:\n";
			my.output();
			my.checkFlyer();
			cout<<"\n\nAdd another box? (y/n)\n";
			cin>>ch;
			if(ch == 'y'){
				my.reset();
				for(int i = 0; i < 3; i++){
					str2[i] = str1[rand()%5];
					my.setItem1(str2[i]);
				}
				continue;
			}				
			else
				break;
		}
	}	
	
	return 0;
}

BoxOfProduce::BoxOfProduce():count(0),containFlyer(false),inFlyer(false){
	for(int i = 0; i < 5; i++)
		items[i] = "";
}

void BoxOfProduce::setItem1(string str){
	if(str == "Tomatillo")
		inFlyer = true;
	items[count] = str;
	count++;
}

void BoxOfProduce::setItem2(string str){
	if(str == "Tomatillo" && !inFlyer)
		containFlyer = true;	
	items[count] = str;
	count++;
}

void BoxOfProduce::output(){
	int i = 0;
	
	cout<<"The box contains:  ";
	while(items[i][0] != '\0'){
		cout<<"("<<i+1<<")"<<items[i];
		if(items[i+1][0] != '\0')
			cout<<" ";
		i++;
	}
	if((inFlyer||containFlyer) && flyer>0)
		cout<<".  Bonus - Salsa Verde Recipe Flyer\n";
}

void BoxOfProduce::change(int index, string str){
	int count = 0;
	
	for(int i = 0; i < 5; i++){
		if(items[i] == "Tomatillo")
			count++;
	}
	
	if(count > 1)
		containFlyer = true;
	else if(str == "Tomatillo")
		containFlyer = true;
	else
		containFlyer = false;
		
	items[index-1] = str;
}

void BoxOfProduce::reset(){
	count = 0;
	containFlyer = false;
	inFlyer = false;
	for(int i = 0; i < 5; i++)
		items[i] = "";
}

void BoxOfProduce::checkFlyer(){
	if(inFlyer || containFlyer)
		flyer--;
}
