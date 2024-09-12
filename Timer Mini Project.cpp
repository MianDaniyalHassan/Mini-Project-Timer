#include<iostream>
#include<cstdlib>
#include<windows.h>
using namespace std;
int main(){
	short minutes , seconds ; int time ;
	
	// for seconds
	do{
		cout<<"Enter Seconds ::  ";
		cin>>seconds;
	}while(seconds>59);
	
	
		// for minutes
	do{
		cout<<"Enter Minutes ::  ";
		cin>>minutes;
	}while(minutes>59);
	
	// convert minutes into seconds (condition)
time = (minutes != 0) ? minutes * 60 : 0;
time += seconds;

	
	for(int i= time ; i>0 ;i--){
		system("cls");
		cout<<"The time remaning is 0 : "<<minutes<<" : "<<seconds <<endl;
		minutes = (i%60==0)?  --minutes : minutes;
		seconds = (seconds == 0)? 59 : --seconds;
		system ("TIMEOUT 1");
	}
	system("cls");
	cout<<"*****************\nTimer Ended !\a\nLasted for "<<time <<" seconds "<<"\n*****************\n\n\n\n\n"<<endl;
	return 0;
}

