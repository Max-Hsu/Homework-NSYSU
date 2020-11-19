#include <cmath>      // std::ofstream
#include <iostream>
using namespace std;
int main () {
  long Size_of_in=10575;
  
  while(Size_of_in>0){
    long k = Size_of_in>>8;
    k=k<<8;
    k=Size_of_in-k;
    Size_of_in = Size_of_in>>8;
    cout<<k<<"\n";
  }
  return 0;
}