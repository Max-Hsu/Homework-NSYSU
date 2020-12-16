/*
 *algorithm Homework2
 *TSP solved by dynamic programming
 *B073040049
 *B063040060 
 *last update : 12/2
 */
#include<iostream>
#include<fstream>
#include<cmath>//for compute the distance
#include<ctime>//count the execution time
#include "gnuplot.h" //draw the graph
#include <bitset>//print binary
#include <vector>
using namespace std;
#define INT_MAX 1e9

//The class store the name and position of city
class CITY {
	public:
		CITY(){}
		CITY(int a,int b , int c):name(a),x(b),y(c){}
		int name;
		int x;
		int y;
};
int N=0;//the number of city
int first; //record the first city for retrace path
fstream output;//output position to file for draw graph
CITY *city;//the object of city;
float **dis;//the distance table

float **DP;//2^N * N //store the state for dynamic programming

int FINISH ;//binary:(000011111111111) //have visit all city //1:visited 0:not visited

float compute(int c1,int c2);//compute the distance 

//return the shorted length from start 
float tsp(int mask,int start){

    if(mask==FINISH){
		
        return dis[start][0]; //return to origin
    }
    if(DP[mask][start]!=-1){
       return DP[mask][start]; //the state have runned
    }

    float min = INT_MAX;
    //Visit all city that not visited
    for(int i=0;i<N;i++){//city from 0 to N

        if((mask&(1<<i))==0){//not visit

            float now = dis[start][i] + tsp( mask|(1<<i), i);
			if(now<min)
			{
				min =now;		
			}
        }
    }
	
    return DP[mask][start] = min;
} 
void retrace(int mask,int start);//retrace the path

int main(int argc , char *argv[])
{
	
	fstream f;//the input file
	output.open("data.txt",ios::out);//output position to file
	
	//Open from example or open from User
	if(argc==1)
	{
		f.open("readfile.txt");//open the example file 
	}
	else if(argc==2)
	{
		f.open(argv[1]);//open the input file 
	}
	
	vector<class CITY> citys;
	int n_in,x_in,y_in;
	do{
		f>>n_in>>x_in>>y_in;
		citys.push_back(CITY(n_in,x_in,y_in));
		N+=1;
	}while(!f.eof());
	N--;
	city = new CITY[N];
	for(int i=0;i<N;i++)
	{
		city[i]=citys[i];
	}


	//dynamic allocation
	dis= new float*[N];
	for(int i=0 ; i<N;i++)
	{
		dis[i]=new float[N];
	}
	//compute and store all distance 
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			dis[i][j]=compute(i,j);
		}
	}

	//dynamic allocation
	int M = pow(2,N);
	DP= new float*[M];
	for(int i=0 ; i<M;i++)
	{
		DP[i]=new float[N];
	}
	
	//initialization
	for(int i=0;i<M;i++)
	{
		for(int j=0;j<N;j++)
		{
			DP[i][j]=-1;
		}
	}
	FINISH = (1<<N) -1;
	float total=tsp(1,0);
	
	//print the Best Visit Order
	cout<<"Best Visit Order : "<<city[0].name<<" ";
	output<<city[0].x <<" "<<city[0].y<<endl;//start from city 0
	retrace(1,0);//retrace the path
	output<<city[0].x <<" "<<city[0].y<<endl;//end at city 0
	//print the Best distance
	cout<<endl<<"Best distance : "<<total<<endl;
	
	//print the Execution Time
	clock_t execution_time=clock();//The time from the start of program to now
	cout<<"Execution Time : "<<double(execution_time)/CLOCKS_PER_SEC<<"(s)"<<endl;
	
	
	GnuplotPipe gp;
    gp.sendLine("plot 'data.txt' w lp ls 2\n");
	
	//free all memory
	for(int i=0 ; i<N;i++)//free subarray
	{
		delete [] dis[i];
	}
	delete [] dis;
	for(int i=0 ; i<M;i++)//free subarray
	{
		delete [] DP[i];
	}
	delete [] DP;
	delete [] city;

	
	return 0;
}

void retrace(int mask,int start){
    if(mask==FINISH) 
	{
		return;
	}
    int min = INT_MAX;
	int c;
    for(int i=0;i<N;i++)
	{

        if((mask&(1<<i))==0){

            float now = dis[start][i] + DP[mask|(1<<i)][i];
            if(now <= min)
			{
                min = now;
                c = i;
            }
        }

    }
    cout<<city[c].name<<" "; 
	output<<city[c].x <<" "<<city[c].y<<endl;
    retrace(mask|(1<<c),c);
}
float compute(int c1,int c2)
{
	float distance;
	distance=pow((city[c1].x-city[c2].x),2)+pow((city[c1].y-city[c2].y),2);
	distance=pow(distance,0.5);
	return distance;
}
