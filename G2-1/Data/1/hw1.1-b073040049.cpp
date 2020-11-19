/*
Author:許家愷
Date:September.9,2019
Purpose:Magic Square
*/
#include <iostream>
using namespace std;

int main(){
    cout << "1\n\n";
    int square[11][11];                 //for 9*9 arrays , I add 4 sides of extra array for extra protection
    for(int q = 0; q <11;q++){
        for(int w = 0;w<11;w++){
            square[q][w]=-1;
        }
    }                                   //initiation the arrays with value -1
    int xpos,ypos;                      //in order to calculate the current position
    for(int i = 3 ; i <= 9 ;i += 2 ){
        square[1][i/2+1] = 1;           //set the number one in the right place according to the instruction
        xpos = i/2+1;                   //saving the xposition
        ypos = 1;                       //saving the yposition
        for(int j = 2 ; j <= i*i ; j++){//run through all the number this Magic Square have
            xpos-=1;                    //moving left
            ypos-=1;                    //moving up
            if(xpos<1){                 //if xposition is on the edge then move it to the right place
                xpos+=i;
            }
            if(ypos<1){                 //same as line 25 but this time is yposition
                ypos+=i;
            }
            if(square[ypos][xpos]!=-1){ //if the place which is decide to fill is fulled
                xpos+=1;                //move right
                ypos+=2;                //move down two blocks
                if(ypos>i){             //same as line 25 checking down edge
                    ypos-=i;
                }
                if(xpos>i){             //same as line 25 checking right edge
                    xpos-=i;
                }
            }                           //moving is completed
            square[ypos][xpos]=j;       //fill the number into the "square" array using coordinates of xpos,ypos
        }
        for(int k = 1 ; k <= i ;k++){
            for(int l = 1; l <=i ; l++){
                cout<<square[k][l]<<" ";//nesting loop for outputing the Square Magic arrays
            }
            cout<<"\n";
        }
        for(int q = 0; q <11;q++){
            for(int w = 0;w<11;w++){    
                square[q][w]=-1;        //reset the array value with -1
            }
        }
        cout<<"\n";                     //for seperation
    }


}