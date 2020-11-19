#include <iostream>
#include "ch11-3.h"

using namespace Rainbow;
int status=1;
RainbowColor::RainbowColor(){}
RainbowColor::RainbowColor(int co){
	if(co>=1&&co<=7){
		color=co-1;
	}
}
RainbowColor::RainbowColor(char co){
	for(int i=0;i<7;i++){
		if(RainbowAsChar[i]==co){
			status=0;
			color=i;
			break;
		}
	}
}
int RainbowColor::getRainbowColorByName(char name){
	int sta=0;
	for(int i=0;i<7;i++){
		if(RainbowAsChar[i]==name){
			sta=1;
			color=i;
			break;
		}
	}
	return sta;
}
int RainbowColor::getRainbowColorByInt(int no){
	int sta=0;
	if(no>=1&&no<=7){
		color=no-1;
		sta=1;
	}
	return sta;
}
void RainbowColor::outputRainbowColorInt(){
	cout<<color+1<<" ";
}
void RainbowColor::outputRainbowColorChar(){
	cout<<RainbowAsChar[color]<<"\n";
}
class RainbowColor RainbowColor::getNextRainbowColor(){
	if(color==6){
		return RainbowColor(1);
	}
	else{
		return RainbowColor(color+2);
	}
}
int main(){
	using std::cout;
	using std::cin;
	cout<<"Testing RainbowColor(char) constructor\n";
	for(int i=0;i<7;i++){
		class RainbowColor constructerTest(RainbowAsChar[i]);
		constructerTest.outputRainbowColorInt();
		constructerTest.outputRainbowColorChar();
	}
	cout<<"\n\nTesting RainbowColor(int) constructor\n";
	for(int i=1;i<=7;i++){
		class RainbowColor constructerTest(i);
		constructerTest.outputRainbowColorInt();
		constructerTest.outputRainbowColorChar();
	}
	int status=1;
	char coNa;
	class RainbowColor fortest;
	while(status){
		cout<<"Testing the getRainbowColorByName and outputRainbowColor\n";
		cin>>coNa;
		status=fortest.getRainbowColorByName(coNa);
		if(status==1){
			fortest.outputRainbowColorInt();
			fortest.outputRainbowColorChar();
		}
	}
	cout<<coNa<<" is not a RainbowColor. Exiting\n\nEnd of loops\n\n";
	
	status=1;
	coNa='\0';
	while(status){
		cout<<"Testing nextRainbowColor member\n";
		cin>>coNa;
		status=fortest.getRainbowColorByName(coNa);
		if(status==1){
			class RainbowColor theNext=fortest.getNextRainbowColor();
			cout<<"current RainbowColor ";
			fortest.outputRainbowColorInt();
			fortest.outputRainbowColorChar();
			cout<<"next RainbowColor ";
			theNext.outputRainbowColorInt();
			theNext.outputRainbowColorChar();
		}
	}
	cout<<coNa<<" is not a RainbowColor. Exiting\n";
	return 0;
}