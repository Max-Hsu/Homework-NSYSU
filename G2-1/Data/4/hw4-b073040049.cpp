/*
Author:許家愷
Date:October.7,2019
Purpose:recursive practice
*/
#include <iostream>

using namespace std;
int dire[9][2]={{0,0},{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1}};     //this two dimension store all the possible direction
int board[7][7];                                                                    //size of the board
int chesswalk(int step,int x,int y,int size,int choose_dire){                       //need to input current step,x,y,size of board,choose_dire for previous check
    board[x][y]=step;                                                               //write the step into the board
    bool ok=1;                                                                      //ok is for checking all directions
    bool reproc=0;                                                                  //reproc is for go back to previous step and check
    if(step==size*size){                                                            //if the step is the final one means the searching is done so return -2
        return -2;
    }
    for(int i=1;i<=8;i++){                                                          //for checking all 8 directions
        if((x+dire[i][0]>=1&&x+dire[i][0]<=size)&&(y+dire[i][1]>=1&&y+dire[i][1]<=size)&&(board[x+dire[i][0]][y+dire[i][1]]==0)){       //checking if it is legal step
            ok=0;                                                                   //then setting ok and reproc into 0 for finding new position
            reproc=0;
            int ans=chesswalk(step+1,x+dire[i][0],y+dire[i][1],size,i);             //and then call another searching function
            if(ans==-1){                                                            //if the previous one return -1 means there is no possible route to continue
                reproc=1;                                                           //set the reproc flag
            }
            else if(ans==-2){                                                       //it means the searching is done and pass the message to the previous calling function
                
                return -2;
            }
        }
    }
    if((reproc||ok) && step==1){                                                    //if there is reproc or ok flag during step 1 it means there is no possible route to find so outputing "no solution"
        cout <<"no solution\n\n";
        return -3;
    }
    if (ok){                                                                        //if there is still a possible chance but need to go back
        board[x][y]=0;                                                              //then reset the board in current position with 0
        return -1;                                                                  //invoke previous to set reproc and start another search
    }

    if (reproc){                                                                    //same as the ok flag
        board[x][y]=0;
        return -1;
    }

}
int main(){
    for(int run=1;run<=6;run++){                                                //for board size from 1 to 6
        for(int i=0;i<7;i++){                                                   
            for (int j=0;j<7;j++){
                board[i][j]=0;                                                  //initialize the board with 0
            }
        }
        if(chesswalk(1,1,1,run,-1)!=-3){                                        //run the checking function if it return -3 means no solution
            for(int i=1;i<=run;i++){                                            //then print out the board array
                for (int j=1;j<=run;j++){
                    printf("%4d ",board[i][j]);
                }
                cout<<"\n";
            }
            cout<<"\n";
        }
    }
}