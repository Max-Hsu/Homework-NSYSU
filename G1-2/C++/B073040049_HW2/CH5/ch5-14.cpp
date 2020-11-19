#include <iostream>
#include <math.h>
using namespace std;

int main(){
	int scoreVPepople[4][6]={{3,1,5,2,1,5},{4,2,1,4,2,4},{3,1,2,4,4,1},{5,1,4,2,4,2}};
	int diff[4]={0};
	int input_movie;
	int input_rate;
	for(int i=0;i<3;i++){
		cout<<"Enter a movie to rate (100-105)"<<endl;
		cin>>input_movie;
		input_movie-=100;
		cout<<"Enter rating (1-5) for this movie"<<endl;
		cin>>input_rate;
		for(int j=0;j<4;j++){
			diff[j]+=sqrt(pow((scoreVPepople[j][input_movie]-input_rate),2));
			scoreVPepople[j][input_movie]=-1;
		}
	}
	int min=100;
	int people=-1;
	for(int i=0;i<4;i++){
		if(min>diff[i]){
			min=diff[i];
			people=i;
		}
	}
	cout<<"the cloest reviewer is number "<<people<<endl;
	cout<<"Predictions for movies you have not seen yet : "<<endl;
	for(int i=0;i<6;i++){
		if(scoreVPepople[people][i]!=-1){
			cout<<"Movie "<<i+100<<" : Predicted Ratings = "<<scoreVPepople[people][i]<<endl;
		}
	}
	
	
}