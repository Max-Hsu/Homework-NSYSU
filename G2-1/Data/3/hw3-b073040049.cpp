/*
Author:許家愷
Date:September.13,2019
Purpose:stack and iteration practice
*/
#include <iostream>

using namespace std;
struct stacka{                                          //a struct design to store current coordinates and moving direction and the pointer of before one
    int x;                                              //x coordinate
    int y;                                              //y coordinate
    int direction;                                      //moving direction
    struct stacka * before;                             //the before stack
};
struct stacka * head=NULL;                              //initiate the stack with NULL pointer
void push(int x,int y,int direction){                   //pushing the stack
    if(head==NULL){                                     //if the head is NULL so the 'before' pointer need to be specified with NULL
        head = (new stacka);                            //allocate a new memory
        head->x=x;                                      //assign the allocated memory with input x
        head->y=y;                                      //assign the allocated memory with input y
        head->direction=direction;                      //assign the allocated memory with input direction
        head->before=NULL;                              //assign the allocated memory with NULL pointer
    }
    else
    {
        struct stacka * newa = (new stacka);            //allocate a new memory
        newa->x=x;                                      //assign the allocated memory with input x
        newa->y=y;                                      //assign the allocated memory with input y
        newa->direction=direction;                      //assign the allocated memory with input direction
        newa->before=head;                              //assign the allocated memory with 'head' pointer
        head=newa;                                      //and replace head with current allocated memory pointer
    }
}
void go(){                                                              //this function is for travel all the stack 
    stacka * going = head;
    while(going!=NULL){                                                 //traveling until the before pointer is NULL
        cout<<going->x<<" "<<going->y<<" "<<going->direction<<"\n";     //print out inside data
        going=going->before;                                            //and go to the before stack
    }
}
void pop(int arr[3] ){                                                  //pop is for destory the current stack
    if(head == NULL){                                                   //if there is no stack
        arr[0]=-1;                                                      //then return with three -1
        arr[1]=-1;
        arr[2]=-1;
    }
    else{
        stacka * pointa = head;                                         //else -> there is more than 0 stacks
        arr[0]=pointa->x;                                               //assign the input array with stack value
        arr[1]=pointa->y;
        arr[2]=pointa->direction;
        head=head->before;
        delete pointa;                                                  //delete is to free the allocated memory
    }
}
int dire[9][2]={{0,0},{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1}};     //this two dimension store all the possible direction
int main(){
    int sarr[3];                                                                    //this array is for getting infomation from function pop
    int plate[7][7];                                                                //allocate largest possible size of the test
    for(int i=1;i<=6;i++){                                                          //test from 1*1 to 6*6 array
        for(int q=0;q<7;q++){                                                       //the nested loop is for cleaning up 'plate' array
            for(int j=0;j<7;j++){
                plate[q][j]=0;
            }
        }
        int x_pos=1;                                                                //for current x coordinate
        int y_pos=1;                                                                //for current y coordinate
        bool go_back=0;                                                             //if the queen has no way to choose go_back will be true 
        int dirr=0;                                                                 //for current direction also when go_back is the way that had not been searched
        for(int q=1 ; q<=i*i ;q++){                                                 //iterate for testing-square's square times
            bool direction_check=0;
            if(!go_back){
                dirr=1;                                                             //if the go_back is not on, check from the first direction
            }
            else{
                go_back=0;                                                          //and reset the flag
            }
            if(q==i*i){
               plate[x_pos][y_pos]=q;                                               //if the iteration is reaching the final then it will stop the loop
               break; 
            }
            for(;dirr <=8 ; dirr++){
                if((x_pos+dire[dirr][0]>=1 && x_pos+dire[dirr][0]<=i) && (y_pos+dire[dirr][1]>=1 && y_pos+dire[dirr][1]<=i) && plate[x_pos+dire[dirr][0]][y_pos+dire[dirr][1]]==0){     //check the direction the queen is going to , is it exceeding the edge of the current test size? and also check the place where is going to ,it value is 0
                    direction_check=1;                                              //if found one direction is possible , turn the flag on
                    push(x_pos,y_pos,dirr);                                         //then push into stack
                    plate[x_pos][y_pos]=q;                                          //set previous coordinates with step value
                    x_pos+=dire[dirr][0];                                           //change the current x position
                    y_pos+=dire[dirr][1];                                           //change the current y position
                    break;
                }
            }
            if(direction_check == 0){                                               //if not found any way to go then go back
                pop(sarr);                                                          //to retrieve previous coordinates and direction
                if(sarr[0]!=-1){                                                    //check if there is still data
                    plate[x_pos][y_pos]=0;                                          //reseting the board array of current x and y coordinate ,just in case  
                    q=plate[sarr[0]][sarr[1]]-1;                                    //get the step counter minus one
                    go_back=1;                                                      //and set the go_back flag true
                    x_pos = sarr[0];                                                //retrieving previous coordinates
                    y_pos = sarr[1];
                    dirr = sarr[2]+1;
                    plate[x_pos][y_pos]=0;                                          //reseting the board array of previous x and y coordinate ,just in case
                }
                else{
                    break;                                                          //if there is no element to pop then break
                }
            }
            if(dirr<0 && q<1){
                break;                                                              //and if it exceeds some extreme circumstances then stop the current iteration
            }
        }
        bool checker;                                                               //for checking if there is no 0 in the array
        checker=1;
        for(int p=1;p<=i;p++){
            for(int l=1;l<=i;l++){
                if(plate[p][l]==0){                                                 //iterating the array and if there is a zero
                    checker =0;                                                     //unset the flag
                    break;
                }
            }
            if(checker == 0){                                                       //stop this iteration
                break;
            }
        }

        if(checker){
            for(int p=1;p<=i;p++){
                for(int l=1;l<=i;l++){
                    printf("%3d ",plate[p][l]);                                     //for outputing the array number with alignment
                }
                cout<<"\n";
            }

        }
        else{
            cout<<"no solution\n";                                                  //or printing the no solution
        }
        cout<<"\n";
    }

}