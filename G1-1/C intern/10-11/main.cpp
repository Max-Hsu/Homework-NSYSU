#include <iostream>

using namespace std;

int main()
{
    int x;
    cin>>x;
    do{
    for(int y=1;y<=x;y++){
        for(int z=x-y;z>=0;z-=1){
            cout<<" ";
        }
        for(int p=0;p<y*2-1;p++){
        cout<<"*";
        }
        cout<<endl;
    }
    cin>>x;
    }while(x!=0);

    return 0;
}
