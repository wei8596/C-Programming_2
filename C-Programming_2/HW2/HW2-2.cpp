#include<iostream>
#define N 11
using namespace std;

double ConvertToKPH(int , int );
double ConvertToKPH(double );

int main(){
	char ch[N] = {'\0'};
	bool flag;
	int i, min, sec, count = 0;
	double mph;
	
	while(count < 6){
		for(int k = 0; k < N; k++)
			ch[k] = '\0';
		flag = false;
		cout<<"Enter minutes and seconds per mile or mph\n";
		cin>>ch;
		for(i = 0; i < N; i++){
			if(ch[i] == ':')
				flag = true;
			else if(ch[i]==' ' || ch[i]=='\n')
				break;
		}
		if(flag){
			i = 0;
			min = 0;
			while(ch[i] != ':'){
				min *= 10;
				min += (ch[i]-'0');
				i++;
			}
			sec = 0;
			i++;
			while(ch[i]!=' ' && ch[i]!='\n' && ch[i]!='\0'){
				sec *= 10;	
				sec += (ch[i]-'0');	
				i++;
			}
			cout<<ch<<" pace is "<<ConvertToKPH(min, sec)<<" KPH.\n\n";
		}
		else{
			i = 0;
			mph = 0;		
			while(ch[i]!=' ' && ch[i]!='\n' && ch[i]!='\0'){
				mph *= 10;
				mph += (ch[i] - '0');
				i++;
			}	
			cout<<ch<<" mph is "<<ConvertToKPH(mph)<<" KPH.\n\n";
		}
		count++;
	}			
	
	return 0;
}

double ConvertToKPH(int min, int sec){
	return 1.61/((double)(min*60+sec)/3600);
}

double ConvertToKPH(double mph){
	return mph*1.61;
}
