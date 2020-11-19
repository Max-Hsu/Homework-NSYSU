#include <iostream>
#include <fstream>

using namespace std;

int main(){
	int input = 1;
	int storage[6];
	fstream lottery;
	lottery.open("MyLottery.txt",fstream::out);
	cout<<"1 for random 2 for manual\n";
	cin>>input;
	while(input == 1 || input == 2){
		if(input == 1){
			for(int i=0;i<6;i++){
				storage[i]=rand()%52+1;
			}
			bool restart=false;
			do{
				restart=false;
				for(int i=0;i<6;i++){
					for(int j=0;j<6;j++){
						while (i!=j && storage[i]==storage[j]){
							storage[j]==rand()%52+1;
							restart=true;
						}
					}
				}
			}while(restart);
			for(int i=0;i<6;i++){
				for(int j=0;j<6;j++){
					if(storage[i]<storage[j]){
						int temp=storage[j];
						storage[j]=storage[i];
						storage[i]=temp;
					}
				}
			}
			lottery<<"Your lottery (random) : ";
			for(int i=0;i<6;i++){
				lottery<<storage[i]<<" ";
			}
			lottery<<"\n";
		}
		else if(input == 2){
			for(int i=0;i<6;i++){
				int num;
				cout<<"Please enter number "<<i+1<<"\n";
				cin>>num;
				for(int j=0;j<i;j++){
					while(num == storage[j]){
						cout<<"Same number\n";
						cout<<"Please enter number "<<i+1<<"\n";
						cin>>num;
					}
				}
				while(num>52 ||num<1){
					cout<<"You can only input 1-52\n";
					cout<<"Please enter number "<<i+1<<"\n";
					cin>>num;
				}
				storage[i]=num;
			}
			for(int i=0;i<6;i++){
				for(int j=0;j<6;j++){
					if(storage[i]<storage[j]){
						int temp=storage[j];
						storage[j]=storage[i];
						storage[i]=temp;
					}
				}
			}
			lottery<<"Your lottery (choose) : ";
			for(int i=0;i<6;i++){
				lottery<<storage[i]<<" ";
			}
			lottery<<"\n";
		}
	cout<<"1 for random 2 for manual\n";
	cin>>input;
	}
	lottery.close();
	return 0;
}