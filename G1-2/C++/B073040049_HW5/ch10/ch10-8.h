#include<iostream>
#include<string>

using namespace std;

class tv{
	public:
		tv(){
			dimesion=0;
			supportTypes=0;
			name="Default TV";
			displayType="\0";
		}
		tv(const tv& cp,int index){
			this->dimesion=cp.dimesion;
			this->supportTypes=cp.supportTypes;
			char *num;
			num=new char('0'+index);
			this->name="TV#";
			this->name.append(num);
			this->displayType=cp.displayType;
			connectivitySupport=new string [this->supportTypes];
			for(int i=0;i<this->supportTypes;i++){
				connectivitySupport[i]=cp.connectivitySupport[i];
			}
		}
		void set(){
			if(this->supportTypes>0){
				delete [] connectivitySupport;
				supportTypes=0;
			}
			cout<<"Enter "<<name<<" display Type:\n";
			cin>>this->displayType;
			cout<<"Enter "<<name<<" tv dimesion:\n";
			cin>>this->dimesion;
			cout<<"Enter "<<name<<" tv number of connectivity modes :\n";
			cin>>this->supportTypes;
			cout<<"Enter "<<name<<" tv number of connectivity Support types :\n";
			connectivitySupport=new string [this->supportTypes];
			for(int i=0;i<this->supportTypes;i++){
				cin>>*(connectivitySupport+i);
			}
		}
		void output(){
			cout<<name<<"\n";
			cout<<"Display Type : "<<this->displayType<<"\n";
			cout<<"Dimesion : "<<this->dimesion<<"\n";
			cout<<"Connectivity support Types :\n";
			for(int i=0;i<this->supportTypes;i++){
				cout<<connectivitySupport[i]<<"\n";
			}
		}
		

	private:
		string name;
		int supportTypes;
		double dimesion;
		string displayType;
		string *connectivitySupport;
};