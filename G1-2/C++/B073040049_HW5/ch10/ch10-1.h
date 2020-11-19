#include<iostream>

using namespace std;

class TwoD{
	public:
		TwoD(){
			this->MaxRows=0;
			this->MaxCols=0;
		}
		TwoD(int MaxRows,int MaxCols){
			this->MaxRows=MaxRows;
			this->MaxCols=MaxCols;
			totalArray = new double*[this->MaxRows];
			for(int i=0;i<this->MaxRows;i++){
				totalArray[i]=new double[this->MaxCols];
			}
		}
		TwoD(int MaxRows,int MaxCols,double **total){
			this->MaxRows=MaxRows;
			this->MaxCols=MaxCols;
			this->totalArray=total;
		}
		TwoD(const TwoD& in){
			this->MaxRows=in.MaxRows;
			this->MaxCols=in.MaxCols;
			this->totalArray=in.totalArray;
			/*
			totalArray = new double*[this->MaxRows];
			for(int i=0;i<this->MaxRows;i++){
				totalArray[i]=new double[this->MaxCols];
			}
			for(int i=0;i<in.MaxRows;i++){
				for(int j=0;j<in.MaxCols;j++){
					this->totalArray[i][j]=in.totalArray[i][j];
					cout<<this->totalArray[i][j];
				}
			}
			*/
		}
		~TwoD(){
			for(int i=0;i<MaxRows;i++){
				delete [] totalArray[i];
			}
			delete [] totalArray;
		}
		void set(int Rows,int column,double value){
			totalArray[Rows][column]=value;
		}
		double get(int Rows,int column){
			return totalArray[Rows][column];
		}
		void returnsize(){
			cout<<"Row\t"<<this->MaxRows<<"\tCol\t"<<this->MaxCols<<"\n";
		}
		friend TwoD operator+(TwoD& mat1,TwoD& mat2){
			if(mat1.MaxRows!=mat2.MaxRows || mat1.MaxCols!=mat2.MaxCols){
				cout<<"The size is not match between mat1 and mat2\n";
				return TwoD();
			}
			else{
				double **adder;
				adder = new double*[mat1.MaxRows];
				for(int i=0;i<mat1.MaxRows;i++){
					adder[i]=new double[mat1.MaxCols];
				}
				for(int i=0;i<mat1.MaxRows;i++){
					for(int j=0;j<mat1.MaxCols;j++){
						adder[i][j]=mat1.totalArray[i][j]+mat2.totalArray[i][j];
					}
				}
				return TwoD(mat1.MaxRows,mat1.MaxCols,adder);
			}
		}
		//remember: a operator cannot call constructor again.But why??
		TwoD& operator = (const TwoD& in){
			this->MaxCols=in.MaxCols;
			this->MaxRows=in.MaxRows;
			this->totalArray=in.totalArray;
			return *this;
			//my old solution: return TwoD(in);
		}
	
	private:
		double **totalArray;
		int MaxRows,MaxCols;
};