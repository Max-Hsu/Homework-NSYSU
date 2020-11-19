/*
Author:許家愷
Date:September.13,2019
Purpose:operator practice
*/
#include <iostream>
#include <unistd.h>
#include <algorithm>
using namespace std;
char * delete_excessive_element(char * characters , int target ,int edge){          //use this function to push to delete non-needed element
    while(characters[target]!='\0' && target < edge){                               //if the current pushing is not until the end sign or the edge
        characters[target]=characters[target+1];
        target++;
    }
}
bool check_same(char str1,char str2){                                               //to check if two chars are the same
    return str1==str2;
}
class Tset{
    public:
        Tset(){                                                                     //initiation with no input
            characters = NULL;
            num = 0;
        }
        Tset(char * characters,int num){                                            //initiation with characters and the edge number
            sort(characters,characters+num);                                        //sort the char array in order to delete excessive element
            for(int i=0;i < num-1;i++){
                while(characters[i]==characters[i+1]){                              //when detect same characters
                    delete_excessive_element(characters , i+1,num);                 //call the deleting function
                    num--;
                }
            }
            this->characters = characters;
            this->num = num;
        }
        Tset operator +(Tset set2){
            char * processing = new char[40];                                       //assign a new array with maximum characters
            for(int i=0;i<this->num;i++){
                processing[i]=this->characters[i];                                  //adding two set to the assign array                              
            }
            for(int i=this->num;i<this->num+set2.num;i++){
                processing[i]=set2.characters[i-this->num];
            }
            return Tset(processing,this->num+set2.num);                             //calling the initiation of Tset in order to sort and delete_excessive_element
        }
        Tset operator * (Tset set2){
            char * processing = new char[20];
            int set2_pointer=0;
            int processing_pointer=0;
            for(int i = 0 ;i<this->num;i++){                                                            //run through the first Tset array
                while(this->characters[i] > set2.characters[set2_pointer] && set2_pointer < set2.num){  //in this while loop it make sure that tset2 is close enough to tset1 characters
                    set2_pointer++;                                                                     
                }
                if(this->characters[i] == set2.characters[set2_pointer]){                               //check if it is the same as tset2 element
                    processing[processing_pointer]=this->characters[i];                                 
                    processing_pointer++;
                }
            }
            return Tset(processing,processing_pointer);                                                 //calling the initiation of Tset in order to sort and delete_excessive_element
        }
        Tset operator - (Tset set2){                                                                                        //implementing think : (tset1)-(intersetion of tset1 and tset2)
            Tset intersetion;
            intersetion = *(this)*set2;                                                                                     //assign a new set for intersetion
            char * processing = new char[20];                                                                               
            int intersetion_pointer=0;
            int processing_num = this->num;
            for(int i=0;i<this->num;i++){                                                                                   //for copy the tset1
                processing[i] = this->characters[i];
            }
            for(int i = 0 ;i<processing_num;i++){
                while(processing[i] > intersetion.characters[intersetion_pointer] && intersetion_pointer<intersetion.num){  //in this while loop it make sure that intersetion is close enough to tset1 characters
                    intersetion_pointer++;
                }
                if(processing[i] == intersetion.characters[intersetion_pointer]){
                    delete_excessive_element(processing,i,processing_num);                                                  //if the character also appear in the Tset intersetion then delete_excessive_element
                    processing_num--;
                    i--;
                }
                
            }
            return Tset(processing,processing_num);                                                                         //calling the initiation of Tset in order to sort and delete_excessive_element
        }
        bool operator >= (Tset set2){                                                                                       //implementing thinking : if tset1 contains tset2 than their intersetion should be all the elements of tset2
            Tset intersetion;
            intersetion = *(this)*set2;                                                                                     //assign a new tset of intersetion
            if(intersetion.num == set2.num){
                for(int i = 0;i<intersetion.num;i++){                                                                       //run through all the elements of intersetion
                    if(check_same(intersetion.characters[i],set2.characters[i])!=true){                                     //check if it is the same as tset2
                        return false;
                    }
                }
                return true;
            }
            return false;
        }
        void output(){                                                                                                      //for output all the characters in the array
            for(int i=0;i<num;i++){
                cout<<characters[i]<<" ";
            }
            cout<<"\n";
        }
        friend ostream & operator << (ostream & output , const Tset set){                                                   //for cout output string
            cout<<"{";
            for(int i=0;i<set.num;i++){
                cout<<set.characters[i];
            }
            cout<<"}";
        }
    private:
        char * characters;
        int num;
};
int main(){
    int circulation = -1;
    int num1=-1;
    int num2=-1;
    char set1[20];
    char set2[20];
    char in_check;
    cin>>circulation;                                                       //first input for how many times that input will give
    for(int running = 0 ; running < circulation ; running++){       
        for(int i=0;i<20;i++){
            set1[i]='\0';                                                   //initiation for two input array
            set2[i]='\0';
        }
        read(0,set1,20);                                                    //read until "\n"
        read(0,set2,20);
        for(int i=0;i<20;i++){                                              //transfer "\n" into "\0" and also record the array's length
            if(set1[i]=='\n'){
                set1[i]='\0';
                if(num1==-1){
                    num1=i;
                }
            }
            if(set2[i]=='\n'){
                set2[i]='\0';
                if(num2==-1){
                    num2=i;
                }
            }
        }
        cin>>in_check;                                                      //enter the checking case
        cout<<"Test Case "<<running+1<<":\n";                               //output test case
        Tset tset1(set1,num1);                                              //create instance tset1
        cout<<"A: "<<tset1<<"\n";                                           //output tset1
        Tset tset2(set2,num2);                                              //create instance tset2
        cout<<"B: "<<tset2<<"\n";                                           //output tset2
        Tset tset3;                                                         //create instance tset3
        tset3 = tset1+tset2;                                                //assign to tset1+tset2
        cout<<"A+B: "<<tset3<<"\n";
        Tset tset4;                                                         //create instance tset4
        tset4 = tset1*tset2;                                                //assign to tset1*tset2
        cout<<"A*B: "<<tset4<<"\n";
        Tset tset5;                                                         //create instance tset5
        tset5 = tset1-tset2;                                                //assign to tset1-tset2
        cout<<"A-B: "<<tset5<<"\n";
        Tset tset6;                                                         //create instance tset5
        tset6 = tset2-tset1;                                                //assign to tset2-tset1
        cout<<"B-A: "<<tset6<<"\n";
        if(tset1>=tset2){                                                   //using >= operator will return true or false
            cout<<"A contains B\n";
        }
        else{
            cout<<"A does not contain B\n";
        }
        if(tset2>=tset1){
            cout<<"B contains A\n";
        }
        else{
            cout<<"B does not contain A\n";
        }

        Tset in_check_set(&in_check,1);                                     //implementing thinking : see the checking character as another Tset instance and check with contains will give us same result
        if(tset1>=in_check_set){
            cout<<"'"<<in_check<<"' is in A\n";
        }
        else{
            cout<<"'"<<in_check<<"' is not in A\n";
        }
        if(tset2>=in_check_set){
            cout<<"'"<<in_check<<"' is in B\n";
        }
        else{
            cout<<"'"<<in_check<<"' is not in B\n";
        }
        cout<<"\n";
        num1=-1;                                                            //reset the character array for next input
        num2=-1;
    }
}