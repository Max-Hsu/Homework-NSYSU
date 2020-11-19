#include <iostream>
using namespace std;

const int megabyte=8000;
float calculate(int bitRate,float duration){
	return bitRate*duration/megabyte*60;
}
int main(){
	int bitRate=0;
	float duration=0;
	cout<<"Bit rate : ";
	cin>>bitRate;
	cout<<"The duration in minutes of a video clip : ";
	cin>>duration;
	cout<<"The file size of the video clip in megabytes : "<<calculate(bitRate,duration)<<endl;
	return 0;
}