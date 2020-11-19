#include<iostream>
#include<string>

using namespace std;

class subscriber{
	public:
		subscriber(){
			numChannels=0;
			name="\0";
		}
		~subscriber(){
			delete [] channelList;
			numChannels=0;
			name="\0";
		}
		void set(){
			cout<<"Enter person name:";
			cin>>this->name;
			cout<<"Enter number of channels :";
			cin>>this->numChannels;
			channelList=new string [this->numChannels];
			for(int i=1;i<=this->numChannels;i++){
				cout<<"Enter name of channel "<<i<<"\n";
				cin>>*(channelList+i-1);
			}
		}
		void output(){
			cout<<"Name:"<<this->name;
			cout<<"\nNumber of channels:"<<this->numChannels<<"\n";
			for(int i=1;i<=this->numChannels;i++){
				cout<<"\tChannel "<<i<<":"<<*(channelList+i-1)<<"\n";
			}
		}
		void reset(){
			delete [] channelList;
			numChannels=0;
		}
		subscriber& operator = (subscriber& in){
			if(numChannels){
				reset();
			}
			this->numChannels=in.numChannels;
			this->name=in.name;
			channelList=new string [this->numChannels];
			for(int i=1;i<=this->numChannels;i++){
				this->channelList[i-1]=in.channelList[i-1];
			//this->*(channelList+i-1)=in.*(channelList+i-1);
			}
			return *this;
		}
	private:
		int numChannels;
		string name;
		string *channelList;
};