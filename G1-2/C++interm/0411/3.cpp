#include <iostream>

using namespace std;
struct Point{
	int x,y;
};
struct Line{
	struct Point a1,a2;
	int diff_x,diff_y;
};
int main(){
	struct Line L1,L2;
	cout<<"A\n";
	cin>>L1.a1.x>>L1.a1.y;
	cout<<"B\n";
	cin>>L1.a2.x>>L1.a2.y;
	cout<<"C\n";
	cin>>L2.a1.x>>L2.a1.y;
	cout<<"D\n";
	cin>>L2.a2.x>>L2.a2.y;
	L1.diff_x=L1.a1.x-L1.a2.x;
	L2.diff_x=L2.a1.x-L2.a2.x;
	L1.diff_y=L1.a1.y-L1.a2.y;
	L2.diff_y=L2.a1.y-L2.a2.y;
	//cout<<L1.diff_x<<" "<<L1.diff_y<<" "<<L2.diff_x<<" "<<L2.diff_y<<"\n";
	if((L1.diff_x*L2.diff_x+L1.diff_y*L2.diff_y)==0){
		cout<<"vertical\n";
	}
	else{
		cout<<"not vertical\n";
	}
	return 0;
}