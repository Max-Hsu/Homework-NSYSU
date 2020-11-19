/*
Author:許家愷
Date:November.30,2019
Purpose:comparing 5 differents sorting algorithm
*/
#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;
int TimeTest[] = {100,500,1000,5000,10000,50000,100000,500000};             //specify the number of sorting
int compare (const void * a, const void * b){                               //for qsort comparing numbers , it was send in by the type of pointer void
    return (*(int*)a - *(int*)b);                                           //in this case , it need a typecast
}
bool Bcompare (int i , int j){                                              //for the std::sort
    return (i<j);                                                           //return the compared result
}
void insertSort(vector<int> &in){                                           //sort1 : insertSort (the argument passed in is one vector)
    vector<int>sortOne;
    for(vector<int>::iterator run=in.begin();run!=in.end();run++){          //a iterator for run through all the elements
        int pos = 0;
        for(int run_one = 0;run_one<sortOne.size();run_one++){              //for the sorting element
            if(*(run)<sortOne[pos]){                                        //if the current element is bigger
                break;
            }
            pos++;
        }
        sortOne.insert(sortOne.begin()+pos,*(run));                         //then swap into the back
    }
    in = sortOne;
}
static vector<int> DEFAULT_VECTOR;
void mergeSort(vector<int> &left , vector<int> &right = DEFAULT_VECTOR){    //sort2 : mergeSort (the argument passed for the left and right vector)
    bool combineF = 0;
    if (right.size()==0)                                                    //if the starting situation there is no element on the right
    {
        combineF = 1;                                                       //a indicator which will later used
        right.assign(left.begin()+int(left.size()/2),left.end());           //so spilt into two vector
        left.assign(left.begin(),left.begin()+int(left.size()/2));          //left and right
        mergeSort(left,right);                                              //and recall the function
    }
    vector<int>combineL;
    vector<int>combineR;                                                        
    if(left.size()==1){                                             
        combineL.push_back(left[0]);                                        //in the edge condition there is only one element left
    }                                                                       //so just return them
    if(right.size()==1){
        combineR.push_back(right[0]);                                       //so did this
    }
    if(left.size()>1 && right.size()>=1){                                   //if the left vector has more than one element , it means that it need to be split again
        vector<int>LSpLeft;                                                 //assign to new vector
        vector<int>LSpRight;
        LSpLeft.assign(left.begin(),left.begin()+int(left.size()/2));       //split into new left
        LSpRight.assign(left.begin()+int(left.size()/2),left.end());        //split into new right
        mergeSort(LSpLeft,LSpRight);                                        //recall the function for recursion
        int counter_LSpL=0,counter_LspR=0;                                  //counter for counting the position of vector
        int Edge_LSpL=LSpLeft.size(),Edge_LSpR=LSpRight.size();             //edge for the size of the vector
        while((Edge_LSpL>counter_LSpL)&&(Edge_LSpR>counter_LspR)){          //when there is no vector exceed the edge
            if(LSpLeft[counter_LSpL]<LSpRight[counter_LspR]){               //do the element-like sort :smaller is first push into the new vector
                combineL.push_back(LSpLeft[counter_LSpL]);                  //left is smaller , so push
                counter_LSpL++;
            }
            else{
                combineL.push_back(LSpRight[counter_LspR]);                 //or the other situation , right is smaller , and push
                counter_LspR++;                                             
            }
        }
        if(Edge_LSpL==counter_LSpL){                                        //when program comes here , it means either left or right vector exceeds the edge , so ckeck which one
            for(;counter_LspR<Edge_LSpR;counter_LspR++){                    //and push the opposite vector into the combined one
                combineL.push_back(LSpRight[counter_LspR]);
            }
        }
        else{
            for(;counter_LSpL<Edge_LSpL;counter_LSpL++){                    //so did when the other situation
                combineL.push_back(LSpLeft[counter_LSpL]);
            }
        }
    }
    if(right.size()>1 && left.size()>=1){                                   //if the right vector has more than one element , it means that it need to be split again
        vector<int>RSpLeft;                                                 //assign to new vector
        vector<int>RSpRight;
        RSpLeft.assign(right.begin(),right.begin()+int(right.size()/2));    //split into new left
        RSpRight.assign(right.begin()+int(right.size()/2),right.end());     //split into new right
        mergeSort(RSpLeft,RSpRight);                                        //recall the function for recursion
        int counter_RSpL=0,counter_RspR=0;                                  //counter for counting the position of vector
        int Edge_RSpL=RSpLeft.size(),Edge_RSpR=RSpRight.size();             //edge for the size of the vector
        while((Edge_RSpL>counter_RSpL)&&(Edge_RSpR>counter_RspR)){          //when there is no vector exceed the edge
            if(RSpLeft[counter_RSpL]<RSpRight[counter_RspR]){               //do the element-like sort :smaller is first push into the new vector
                combineR.push_back(RSpLeft[counter_RSpL]);                  //left is smaller , so push
                counter_RSpL++;
            }
            else{
                combineR.push_back(RSpRight[counter_RspR]);                 //or the other situation , right is smaller , and push
                counter_RspR++;
            }
        }
        if(Edge_RSpL==counter_RSpL){
            for(;counter_RspR<Edge_RSpR;counter_RspR++){                    //when program comes here , it means either left or right vector exceeds the edge , so ckeck which one
                combineR.push_back(RSpRight[counter_RspR]);                 //and push the opposite vector into the combined one
            }
        }
        else{
            for(;counter_RSpL<Edge_RSpL;counter_RSpL++){                    //so did when the other situation
                combineR.push_back(RSpLeft[counter_RSpL]);
            }
        }
    }    
    if(right.size()==1 && left.size()==1){
        return;
    }
    left = combineL;
    right = combineR;
    if(combineF){                                                           //this is for the the first time to call the function , it need to combine the left and right vector back
        vector<int>combine;
        int counter_R=0,counter_L=0;                                        //well the procedure are the same from the above
        int Edge_R=combineR.size(),Edge_L=combineL.size();                  //there is counter and edge
        while((Edge_R>counter_R)&&(Edge_L>counter_L)){                      //and the smallest being push first
            if(combineL[counter_L]<combineR[counter_R]){                    //if left one is the smallest then go first
                combine.push_back(combineL[counter_L]);                     //push
                counter_L++;
            }
            else{                                                           //if right one is the smallest then go first
                combine.push_back(combineR[counter_R]);                     //push
                counter_R++;
            }
        }
        if(Edge_L==counter_L){                                              //if exceed the edge check which one , in this case is the left one
            for(;counter_R<Edge_R;counter_R++){                             //so push the rest of the right vector
                combine.push_back(combineR[counter_R]);                     //push
            }
        }
        else{                                                               //the opposite situation , the right one
            for(;counter_L<Edge_L;counter_L++){                             //so push the rest of the right vector
                combine.push_back(combineL[counter_L]);
            }
        }
        left = combine;
    }
}

void quickSort(vector<int> &left){                                          //sort 3 : quickSort (the argument is the single vector)
    if(left.size()>1){                                                      //if the size is smaller than 1 , there is no need to split again
        int pivot = left[left.size()-1];                                    //pivot is set on the rightest element
        vector<int>SL;                                                      //assign two vector to split
        vector<int>SR;                                                                  
        for(vector<int>::iterator run = left.begin();run!=left.end()-1;run++){  //run through every element
            if(*(run)<pivot){                                                   //if smaller than the pivot than
                SL.push_back(*(run));                                           //push into the left vector
            }
            else{
                SR.push_back(*(run));                                           //else push into the right vector
            }
        }
        quickSort(SL);                                                          //do recursive
        quickSort(SR);                                                          //do recursive
        vector<int>combine;                                                     //combine them together with the pivot in the middle
        combine.insert(combine.end(),SL.begin(),SL.end());                      
        combine.push_back(pivot);
        combine.insert(combine.end(),SR.begin(),SR.end());
        left = combine;
    }
}
int main(){
    int x;
    fstream In,oA,oB,oC,oD,oE;                                                  //five sort for five output file and one for input file
    In.open("input.txt",fstream::in);                                           //open them
    oA.open("outputA.txt",fstream::out);
    oB.open("outputB.txt",fstream::out);
    oC.open("outputC.txt",fstream::out);
    oD.open("outputD.txt",fstream::out);
    oE.open("outputE.txt",fstream::out);
    oA<<"insertSort\n";                                                         //as for the requirement : input the texts
    oB<<"mergeSort\n";
    oC<<"quickSort\n";
    oD<<"qSort\n";
    oE<<"Sort\n";
    In>>x;
    for(int i = 0; i < 8;i++){                                                  //there is 8 iterations for the numbers of sorting
        In.seekg(0 , In.beg);                                                   //well , i don't want to let the size of the input file so big so each time of the iteration will go back to the head of the file
        for(int j = 0 ; j < 10 ; j++){                                          //and the requirement ask 10 time for each
            int * all;
            all = new int[TimeTest[i]];                                         //set the size for current sorting
            for(int re = 0 ; re < TimeTest[i] ; re++){
                In>>all[re];                                                    //and read out all the numbers
            }
            vector<int>all_inVec;
            vector<int>forA;
            vector<int>forB;
            vector<int>forC;
            vector<int>forE;
            clock_t t1,t2;                                                              //clock for recording the time has used
            all_inVec.assign(all , all+(TimeTest[i]-1));                                //array into vector
            forA.assign(all_inVec.begin(),all_inVec.end());                             //and also assign A sort
            t1 = clock();                                                               //record time
            insertSort(forA);                                                           //do the sort
            t2 = clock();                                                               //record time
            printf("A:%d   %lfsec\n",TimeTest[i], (t2-t1)/(double)(CLOCKS_PER_SEC));    //print out the elasped time
            for(vector<int>::iterator run = forA.begin();run!=forA.end();run++){
                oA<<*(run)<<"\n";                                                       //output the sorted numbers
            }
            forA.erase(forA.begin(),forA.end());                                        //clean the vector to save memory

            forB.assign(all_inVec.begin(),all_inVec.end());                             //also assign B sort
            t1 = clock();                                                               //record time
            mergeSort(forB);                                                            //do the sort
            t2 = clock();                                                               //record time
            printf("B:%d   %lfsec\n",TimeTest[i], (t2-t1)/(double)(CLOCKS_PER_SEC));    //print out the elasped time
            for(vector<int>::iterator run = forB.begin();run!=forB.end();run++){
                oB<<*(run)<<"\n";                                                       //output the sorted numbers
            }
            forB.erase(forB.begin(),forB.end());                                        //clean the vector to save memory

            forC.assign(all_inVec.begin(),all_inVec.end());                             //also assign C sort
            t1 = clock();                                                               //record time
            quickSort(forC);                                                            //do the sort
            t2 = clock();                                                               //record time
            printf("C:%d   %lfsec\n",TimeTest[i], (t2-t1)/(double)(CLOCKS_PER_SEC));    //print out the elasped time
            for(vector<int>::iterator run = forC.begin();run!=forC.end();run++){
                oC<<*(run)<<"\n";                                                       //output the sorted numbers
            }
            forC.erase(forC.begin(),forC.end());                                        //clean the vector to save memory

            t1 = clock();                                                               //record time
            qsort(all,TimeTest[i],sizeof(int),compare);                                 //qsort use array
            t2 = clock();                                                               //record time
            printf("D:%d   %lfsec\n",TimeTest[i], (t2-t1)/(double)(CLOCKS_PER_SEC));    //print out the elasped time
            for(int Drun = 0 ; Drun < TimeTest[i] ; Drun++){
                oD<<all[Drun]<<"\n";                                                    //output the sorted numbers
            }

            forE.assign(all_inVec.begin(),all_inVec.end());                             //also assign E sort
            t1 = clock();                                                               //record time
            sort(forE.begin(),forE.end());                                              //do the sort
            t2 = clock();                                                               //record time
            printf("E:%d   %lfsec\n",TimeTest[i], (t2-t1)/(double)(CLOCKS_PER_SEC));    //print out the elasped time
            for(vector<int>::iterator run = forE.begin();run!=forE.end();run++){
                oE<<*(run)<<"\n";                                                       //output the sorted numbers
            }
            forE.erase(forE.begin(),forE.end());                                        //clean the vector to save memory
            oA<<"\n";                                                                   //seperation for each of the test
            oB<<"\n";
            oC<<"\n";
            oD<<"\n";
            oE<<"\n";
            printf("\n");
        }
    }
    
}