/*
Author:許家愷
Date:October.28,2019
Purpose:Polynomial operation
*/
#include <iostream>
using namespace std;
struct node{                                //using a struct for dynamic linked list
    int coff;                               //for coefficient
    int expo;                               //for exponational
    node * next;                            //for saving next node
};
class numa{
    public:
        numa(){                             //init with no input
            first = nullptr;                //set the pointer to null
        }
        void inserta(int coff,int expo){    //insert element
            if(coff != 0){                  //if coefficient == 0 means no data so we avoid saving that situation
                if(first == nullptr){       //if there is no element yet
                    node * newa = new node; //make a new node
                    newa->coff = coff;      //fill those data
                    newa->expo = expo;
                    newa->next = nullptr;   //because this is the only element so next is null
                    first = newa;           //and the first element need to save
                }
                else{                       //so there is actually has more than 0 elements
                    node * runa = first;    //and we need to sort , therefore two pointer for traveling the linked list
                    node * before = first;
                    while((runa != nullptr)&&(runa->expo > expo )){ //if the current pointer isn't null and still bigger than current inserting coefficient
                        before = runa;                              //save the pointer before go to the next one
                        runa = runa->next;                          //go to next one
                    }
                    if((runa!= nullptr) && (runa->expo == expo)){   //if the traveling pointer's exponational equal inserting one's exponational 
                        runa->coff+=coff;                           //we can add there coefficient together
                        if(runa->coff == 0 ){                       //if adding together is 0
                            if(runa ==first){                       //delete the node check if the deleting one is the head
                                first=runa->next;                   //if it is the first element just shift to next element
                            }
                            else{
                                before->next=runa->next;            //if not we need to connect the before one into the next one
                            }
                            delete(runa);                           //delete it
                        }
                    }
                    else{                                           //means there is no same exponational number
                        node * newa = new node;                     //we need another node to save info
                        newa->coff = coff;                          //save those data
                        newa->expo = expo;
                        if(runa == first){                          //means the biggest element
                            newa->next = first;                     //so first should change
                            first = newa;                           
                        }
                        else if(runa == nullptr){                   //means the smallest element
                            before->next = newa;                    
                            newa->next = nullptr;                   //so the last one pointer change into null
                        }
                        else{                                       //means insert inside of linked list
                            before->next = newa;                    
                            newa->next = runa;
                        }
                    }
                }
            }
        }
        void printall(){
            node * runnode = first;
            if(runnode == nullptr){                                 //if no element print 0
                cout<<"0 0\n";
            }
            while(runnode != nullptr){                              //travel in the linked list
                cout<<runnode->coff<<" "<<runnode->expo<<"\n";      //and print it out
                runnode = runnode->next;                            //go to next node
            }
        }
        numa operator +(numa & b){                                  
            numa T;
            node * trA = first;                                     //two pointer for traveling two node
            node * trB = b.first;
            for(;trA!=nullptr;trA=trA->next){                       //travel until nullptr
                T.inserta(trA->coff,trA->expo);                     //just insert all the element , my insert will do all the job:)
            }
            for(;trB!=nullptr;trB=trB->next){                       //travel until nullptr
                T.inserta(trB->coff,trB->expo);                     //just insert all the element , my insert will do all the job:)
            }
            return T;
        }
        numa operator *(numa & b){
            numa T;
            node * trA = first;
            node * trB = b.first;
            for(;trA!=nullptr;trA=trA->next){                           //travel until nullptr
                trB = b.first;
                for(;trB!=nullptr;trB=trB->next){                       //travel until nullptr
                    T.inserta(trA->coff*trB->coff,trA->expo+trB->expo); //MULTIPLY means exponational add together and coefficient multiply together , and my insert will deal with it 
                }
            }
            
            return T;
        }
    private:
        node * first;
};
int main(){
    int p,q;
    int casea = 1;
    while(true){
        cin>>p;                                             //input the numbers of first Polynomial
        numa A;
        for(int i=0;i<p;i++){                               //so we do a for loop to receive all the numbers
            int coffa,expoa;
            cin>>coffa>>expoa;
            A.inserta(coffa,expoa);                         //and insert into A linked list
        }
        cin>>q;                                             //input the numbers of second Polynomial
        if (p==0&&q==0){
            break;
        }
        numa B;                                             //same procedure as A
        for(int i=0;i<q;i++){
            int coffa,expoa;
            cin>>coffa>>expoa;
            B.inserta(coffa,expoa);
        }
        numa C;
        numa D;
        C=A+B;                                              //using two operator overloading
        D=A*B;                                                       
        cout<<"Case"<<casea<<":\n";
        cout<<"ADD\n";
        C.printall();                                       //and print it out
        cout<<"MULTIPLY\n";
        D.printall();
        casea++;                                       //and print it out
    }

    
}