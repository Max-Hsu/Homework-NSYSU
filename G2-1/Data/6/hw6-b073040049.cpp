/*
Author:許家愷
Date:November.14,2019
Purpose:binary tree operation
*/
#include <iostream>
#include <vector>
using namespace std;
struct tree{                                //this tree node contains its own value and two childs:left,right
    int value;
    tree * left;
    tree * right;
};
void delete_all(tree * top){                //this is for when the user type in -1 it will destory all the tree nodes
    if(top->left!=nullptr){                 //go to the left child if can
        delete_all(top->left);              //see the child as the top of next subtree and delete it
    }
    if(top->right!=nullptr){                //go to the right child if can
        delete_all(top->right);             //see the child as the top of next subtree and delete it
    }
    delete top;                             //delete the top
}
void delete_tree(tree * deleting , tree * upper , bool direction , tree * &top){    //for delete one node , deleting is for the delete one , upper is for its parent , direction is for parent and child direction , top means root for it might change so need modification
    if(deleting->left == nullptr && deleting->right == nullptr){                    //case1 if the deleting node doesn't have any child
        if(deleting == top){                                                        //also check if it is on the root
            top == nullptr;                                                         //so set the root to nullptr
        }
        if(!direction){                                                             //means the direction from parent to child is left
            upper->left = nullptr;
        }
        else{
            upper->right = nullptr;                                                 //means the direction from parent to child is right
        }
        delete deleting;                                                            //delete the deleting
    }
    else if(deleting->left == nullptr ^ deleting->right == nullptr){                //case2 the deleting node has one child
        if(deleting == top){                                                        //also check if the deleting node is the root
            if(deleting->left != nullptr){                                          //then we need to change the root according to the direction
                top = deleting->left;                                               //means the left
            }
            else{
                top = deleting->right;                                              //means the right
            }
        }
        if(deleting->left != nullptr){                                              //normal situation for deleting node left child
            if(!direction){                                                         //means left from deleting parent to the deleting
                upper->left = deleting->left;                                       //so make upper left = deleting left
            }
            else{
                upper->right = deleting->left;                                      //means right from deleting parent to the deleting
            }                                                                       //so make upper right = deleting left
        }
        else{                                                                       //normal situation for deleting node right child
            if(!direction){                                                         //means left from deleting parent to the deleting
                upper->left = deleting->right;                                      //so make upper left = deleting right
            }
            else{
                upper->right = deleting->right;                                     //means right from deleting parent to the deleting
            }                                                                       //so make upper right = deleting right
        }
        delete deleting;                                                            //delete the deleting
    }
    else{                                                                           //case3 deleting has two child , the assignment ask for replacement of leftest in the right subtree
        tree * travel_to_left = deleting->right;                                    //this is right subtree
        tree * before_travel_to_left = deleting;                                    //for record the previous travel_to_left for recall the delete_tree function and pass in as upper
        bool dire_cut = 1;                                                          //direction record because the right subtree might not have child , so the direction first is right for saveing deleting to the right subtree direction
        while(1){                                                                   
            if(travel_to_left->left == nullptr){                                    //so trying to go to the leftest element of the right subtree
                break;                                                              //if no chance just break
            }
            dire_cut = 0;                                                           //and save the direction left(if the right subtree doesn't have any child it won't come to this code)
            before_travel_to_left = travel_to_left;                                 //for saving
            travel_to_left = travel_to_left->left;
        }
        deleting->value = travel_to_left->value;                                    //switching the value between the deleting and the chosen one
        delete_tree(travel_to_left,before_travel_to_left,dire_cut,top);             //and recall the function but this time it is deleting the chosen one
    }
    
}
void adding(tree * &top , int add_value){                                           //for adding a node , top is for root , add_value is for the value to add
    tree * before;                                                                  //for saving the previous running
    tree * adding;
    tree * running = top;
    bool direction; //0 for left , 1 for right
    if(top == nullptr){                                                             //if the root has no element
        adding = new tree;                                                          //then create one
        adding->left = nullptr;                                                     //and assign them with correct value
        adding->right = nullptr;
        adding->value = add_value;
        top = adding;
        return ;
    }
    while(running != nullptr){                                                      //this while is for going to the right direction until there is no node
        before = running;                                                           //save the previos place
        if(running->value > add_value){                                             //add_value is smaller than the top node ,so go left
            running = running->left;                                                //going to the left
            direction = 0;                                                          //save the direction info if collide with same value node
        }
        else if(running->value < add_value){                                        //add_value is bigger than the top node ,so go right
            running = running->right;                                               //going to the right
            direction = 1;                                                          //save the direction info if collide with same value node
        }
        if(running != nullptr && running->value == add_value){                      //collide with same value
            if(top->left == nullptr && top->right == nullptr && running == top){    //if it is the root and no child
                delete top;                                                         //then delete it
                top = nullptr;                                                      //and reset it
                return;
            }
            delete_tree(running , before , direction , top);                        //or do the delete_tree function

            return ;                                                                //end the while loop
        }
    }
    adding = new tree;                                                              //if there is no collision , add a new leaf
    adding->left = nullptr;                                                         //assign with right value
    adding->right = nullptr;
    adding->value = add_value;
    if(!direction){                                                                 //and also assign their parents by direction
        before->left = adding;
    }
    else{
        before->right = adding;
    }

}
void travel(tree * top , vector<int> & out_vec1 , vector<int> & out_vec2 , vector<int> & out_vec3){ //travel is for going through the tree and save their info back into vector , also impletmenting by infix
    if(top == nullptr){                                                                             //if there is no tree exist , just exit the function (I add this for safety)
        //cout<<"EMPTY\n";
        return ; 
    }
    if(top->left!=nullptr){                                                                         //if left subtree is exist them travel them
        travel(top->left , out_vec1 , out_vec2 , out_vec3);                                         //so top->left
        out_vec2.push_back(top->left->value);                                                       //and also record the value of the left subtree
    }
    else{
        out_vec2.push_back(0);                                                                      //if there is no left subtree , add 0
    }
    out_vec1.push_back(top->value);                                                                 //and also pushing its value into the vector
    if(top->right!=nullptr){                                                                        //if right subtree is exist them travel them
        out_vec3.push_back(top->right->value);                                                      //so top->right
        travel(top->right , out_vec1 , out_vec2 , out_vec3);                                        //and also record the value of the left subtree
    }
    else{
        out_vec3.push_back(0);                                                                      //if there is no left subtree , add 0
    }
}
int main(){
    int num;                                                                                        //for input a number
    tree * root = nullptr;                                                                          //init the root with nullptr
    vector<int> every0;                                                                             //init vectors
    vector<int> every1;
    vector<int> every2;
    while(cin>>num){                                                                                //while not EOF , and also input the num
        if(num == -1){                                                                              //if the num is -1
            travel(root,every0 , every1 ,every2);                                                   //then travel
            cout<<"node: ";
            for(vector<int>::iterator e0 = every0.begin();e0!=every0.end();e0++){                   //and print out every vector elements
                cout<<*e0<<" ";
            }
            cout<<"\nleft: ";
            for(vector<int>::iterator e1 = every1.begin();e1!=every1.end();e1++){
                cout<<*e1<<" ";
            }
            cout<<"\nright: ";
            for(vector<int>::iterator e2 = every2.begin();e2!=every2.end();e2++){
                cout<<*e2<<" ";
            }
            cout<<"\n\n";
            delete_all(root);                                                                       //delete all the node
            every0.erase(every0.begin(),every0.end());                                              //also delete the vector
            every1.erase(every1.begin(),every1.end());
            every2.erase(every2.begin(),every2.end());
            root = nullptr;                                                                         //reset the root
        }
        else{                                                                                       //if the num is not -1
            adding(root,num);                                                                       //then add the value by adding
        }
    }
}