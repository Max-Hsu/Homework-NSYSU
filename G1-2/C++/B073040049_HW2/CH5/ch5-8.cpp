#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <math.h>
using namespace std;
double peoplema(int num){
	return pow(num,num);
}
const int trial=5000;
int main(){
	srand(time(0));
	int people_birth[50];
	int current_count=-1;
	int temp_max=-1,temp_count=-1;
	double total_trial;
	for(int people=2;people<=50;people++){
		total_trial=0;
		for(int test=0;test<trial;test++){
			for(int count=0;count<people;count++){
				people_birth[count]=rand()%365;
			}
			sort(people_birth,people_birth+people);
			/*
			for(int count=0;count<people;count++){
				cout<<people_birth[count]<<endl;
			}
			cout<<"\n\n";
			*/
			temp_max=people_birth[0];
			temp_count=0;
			current_count=0;
			for(int count=1;count<people;count++){
				if(people_birth[count]==temp_max){
					if(temp_count==0){
					temp_count+=2;
					}
					else{
					temp_count++;
					}
				}
				else{
					temp_max=people_birth[count];
					current_count+=temp_count;
					temp_count=0;
				}
			}
			if(temp_count>0){
				current_count+=temp_count;
			}
			
			//cout<<"curr:"<<current_count;
			//total_trial+=(people-current_count)/peoplema(people);
			if(current_count>0){
				total_trial+=1;
			}
		}
		cout<<"For "<<people<<" people, the probability of two birthdays is about"<<(double(total_trial)/trial)<<"\n";
		
	}
	
	return 0;
}