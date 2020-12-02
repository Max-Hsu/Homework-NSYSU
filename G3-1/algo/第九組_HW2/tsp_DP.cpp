/*
 *algorithm Homework2
 *TSP solved by dynamic programming
 *��9�� 
 *B073040049 �\�a�_ 
 *B063040060 ���a�� 
 *2020/11
 */
#include<iostream>
#include<fstream>
#include<cmath>//for compute the distance
#include<ctime>//count the execution time
#include <set>//to store not visited
#include "gnuplot.h" 
using namespace std;

//The class store the name and position of city
class CITY {
	public:
		int name;
		int x;
		int y;
};
CITY city[11];//the object of city;
int order[11];//store the name of best visit order
int first;
float compute(int c1,int c2);//compute the distance 
float dis(int c1,int c2);//return distance from table
float distance_table[11][11];//the table store distance 


//The S is the set of city that has not been visited 
//i is the postion of the man now 
//return shortest length starting at i visit S and ending at 0
float tsp(int i,set<int> S)
{
	int size=S.size();
	
	if(size==0)
	{
		return 0;
	}
	else if(size==1)//return to origin
	{
		return dis(i,*S.begin())+dis(*S.begin(),0);
		
	}
	else
	{
		float min=999;
		set<int>::iterator j,t;
		int p;
		for(j=S.begin();j!=S.end();j++)//visit the remain
		{
			if(*j==i)//don't visit again
			{
				continue;
			}
			set<int> temp(S.begin(), S.end());
			temp.erase(*j);
			float tsp_min=tsp(*j,temp);
			float now=dis(i,*j)+tsp_min;
		
		
			if(now<min)
			{
				min=now;
				if(size==10)
				{
					first=*j;
				}
			}
			//else{cout<<endl;}
		}
		return min;
	}
	
}
int o=0;
void retrace(int i,float tsp_min_in,set<int> S)//retrace the path;
{
	//Using the latest visit point to retrace 
	order[o]=i;
	o++;
	set<int>::iterator itr;
	for(itr = S.begin();itr!=S.end();itr++)
	{
		set<int> temp(S.begin(), S.end());
		temp.erase(*itr);
		float tsp_min=tsp(*itr,temp);
		float now=dis(i,*itr)+tsp_min;
		if(now <=tsp_min_in)
		{
			retrace(*itr,tsp_min,temp);
		}
	}
}


int main(int argc , char *argv[])
{
	
	fstream f;//the input file
	//Open from example or open from User
	if(argc==1)
	{
		f.open("readfile.txt");//open the example file 
	}
	else if(argc==2)
	{
		f.open(argv[1]);//open the input file 
	}
	
	//read file
	for(int i=0;i<11;i++)
	{
		f>>city[i].name>>city[i].x>>city[i].y;
	}
	
	for(int i=0;i<11;i++)
	{
		for(int j=0;j<11;j++)
		{
			distance_table[i][j]=compute(i,j);
		}
	}
	/*TSP CODE*/

	set<int> s;//the set of city that has not been visited 
	for(int i=1;i<11;i++)
	{
		s.insert(i);	
	}
	float total=tsp(0,s); //call the TSP ,start from 0
	
	s.erase(first);
	retrace(first,total-dis(0,first),s);
	
	//print the Best Visit Order
	cout<<"Best Visit Order : ";
	cout<<city[0].name<<" ";
	for(int i=0;i<11;i++)
	{
		cout<<city[order[i]].name<<" ";			
	}
	
	//print the Best distance
	cout<<endl<<"Best distance : "<<total<<endl;
	
	//print the Execution Time
	clock_t execution_time=clock();//The time from the start of program to now
	cout<<"Execution Time : "<<double(execution_time)/CLOCKS_PER_SEC<<"(s)"<<endl;
	
	//draw graph
	fstream output;
	output.open("data.txt",ios::out);
	output<<city[0].x <<" "<<city[0].y<<endl;
	for(int i=0;i<11;i++)
	{
		output<<city[order[i]].x <<" "<<city[order[i]].y<<endl;
	}
	GnuplotPipe gp;
    gp.sendLine("plot 'data.txt' w lp ls 2\n");
    
	return 0;
}
float dis(int c1,int c2)
{
	return distance_table[c1][c2];

}
float compute(int c1,int c2)
{
	float distance;
	distance=pow((city[c1].x-city[c2].x),2)+pow((city[c1].y-city[c2].y),2);
	distance=pow(distance,0.5);
	return distance;
}
