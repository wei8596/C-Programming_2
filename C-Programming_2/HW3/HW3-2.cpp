#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

class GasPump{
	public:
		GasPump();
		void showAmount();  //total
		void showPrice();  //the cost per gallon
		void showGallons();
		void setGallons();  //dispense fuel
		double remain();  //remain
		void reset();  //reset
	private:
		double inAmount;  //total
		double amount;  //charged
		double inPrice;  //the cost per gallon
		double price;  //charge
};

int main(){
	GasPump	sta;
	string str;
		
	cout<<"Gas Pump Modeling Program\n";
	sta.showAmount();
	sta.showPrice();
	sta.showGallons();
	cout<<"Press Y/y <CR> to run the dispesing model, anything else quits.\n";
	cin>>str;
	if(str[0]!='Y' && str[0]!='y')
		exit(1);
	system("clear");
	for(int i = 1; i < 3; i++){
		cout<<"Welcome Customer #"<<i<<"\n"
			<<"Press Y/y <CR> to start dispensing Fuel, other quits\n";
		cin>>str;
		if(str[0]!='Y' && str[0]!='y')
			continue;
		system("clear");
		cout<<"\n\n\nDISPENSING FUEL\n";
		sta.reset();
		sta.showGallons();
		cout<<"\nPress <CR> to dispense in 0.1 gallon increments.\n"
			<<"Press q or Q <CR>to terminate dispensing.\n";
		cin.ignore();
		while(cin.get() == '\n'){
			system("clear");
			cout<<"\n\n\nDISPENSING FUEL\n";
			sta.setGallons();
			sta.showGallons();
			cout<<"\nPress <CR> to dispense in 0.1 gallon increments.\n"
				<<"Press q or Q <CR>to terminate dispensing.\n";
		}
		cout<<"Thank you. Your charges are:\n";
		sta.showGallons();
		cout<<"\n\n\n\nAmount of gasoline remaining in main tank is: "
			<<sta.remain()<<" gallons\n\n";
	}
	
	return 0;
}

GasPump::GasPump():inAmount(25),amount(0),inPrice(1.5),price(0){
}

void GasPump::showAmount(){  //total
	cout<<"Amount of gasoline in main tank is: "<<fixed<<setprecision(2)<<inAmount<<"\n";
}

void GasPump::showPrice(){  //the cost per gallon
	cout<<"Gasolie price is $"<<fixed<<setprecision(2)<<inPrice<<" per gallon\n";
}

void GasPump::showGallons(){
	cout<<"gallons: "<<fixed<<setprecision(2)<<amount<<"  "
		<<"$"<<fixed<<setprecision(2)<<price<<"\n";
}

void GasPump::setGallons(){  //dispense fuel
	amount += 0.1;
	price = amount * inPrice;
	inAmount -= 0.1;
}

double GasPump::remain(){  //remain
	return inAmount;
}

void GasPump::reset(){  //reset
	amount = 0;
	price = 0;
}
