#include <iostream>

using namespace std;
void bubble(int s_c[],int sizeof_array){
	for(int i=0; i<sizeof_array-1; i++)
    {
        for(int j=0; j<sizeof_array-1-i; j++)
        {
            if(s_c[j]>s_c[j+1])
            {
                int temp;
                temp=s_c[j];
                s_c[j]=s_c[j+1];
                s_c[j+1]=temp;
            }
        }
	}
}
void select(int s_c[],int sizeof_array){
	int maxa;
    int maxv=0;
	for(int i=0; i<sizeof_array-1; i++)
    {
        for(int j=0; j<sizeof_array-i-1; j++)
        {
            if(s_c[j]>s_c[j+1]&&s_c[j]>maxv)
            {
                maxa=j;
                maxv=s_c[j];
            }
            else if(s_c[j]<s_c[j+1]&&s_c[j+1]>maxv)
            {
                maxa=j+1;
                maxv=s_c[j+1];
            }
        }
        int temp;
        temp=s_c[sizeof_array-i-1];
        s_c[sizeof_array-i-1]=s_c[maxa];
        s_c[maxa]=temp;
        maxv=0;

    }
	
	
}
int main(){
	int arraa[100]={0};
	int choice=0;
	int x;
	cout<<"enter the sorting code (1:bubble sort 2:selection sort)"<<endl;
	cin>>choice;
	int counter=0;
	cin>>x;
	while(x!=-1){
		arraa[counter]=x;
		counter++;
		cin>>x;
	}
	/*
	for(int i=0;i<counter;i++){
		cout<<arraa[i]<<" ";
	}
	*/
	if(choice==1){
		cout<<"bubble sort:\n";
		bubble(arraa,counter);
		for(int i=0;i<counter;i++){
			cout<<arraa[i]<<" ";
		}
		cout<<endl;
	}
	else if(choice==2){
		cout<<"selection sort:\n";
		select(arraa,counter);
		for(int i=0;i<counter;i++){
			cout<<arraa[i]<<" ";
		}
		cout<<endl;
	}
	
	
	return 0;
}