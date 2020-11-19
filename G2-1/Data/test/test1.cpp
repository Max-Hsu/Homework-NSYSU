#include <iostream>
using namespace std;
void prem(char * a ,const int k ,const int m){
    if(k==m){
        for(int i=0;i<=m;i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
    else{
        for(int i=k;i<=m;i++){
            swap(a[k],a[i]);
            prem(a,k+1,m);
            swap(a[k],a[i]);
        }

    }

}

int main(){
    char b[10]={'a','b','c'};
    prem(b,0,2);

}