#include <iostream>
#include <string>
#include <vector>

using namespace std;
class blog{
    protected:
        vector<string> post;
};
class owner:public blog{
    public:
        void addpost(string wantToPost){
            post.push_back(wantToPost);
        }
        void display(){
            cout<<"Message posted\n";
            for(unsigned int i=0;i<post.size();i++){
                cout<<i+1<<" "<<post[i]<<"\n";
            }
        }
        void deletePost(int num){
            if(num>int(post.size())){
                cout<<"There is no Message\n";
            }
            else{
                vector<string>::iterator a;
                a=post.begin()+(num-1);
                post.erase(a);
            }
        }
        vector<string> forViewer(){
            return this->post;
        }
};
class viewer:public blog{
    public:
        void display(){
            cout<<"Message posted\n";
            for(unsigned int i=0;i<post.size();i++){
                cout<<i+1<<" "<<post[i]<<"\n";
            }
        }
        void sett(vector<string> Ori){
            this->post = Ori;
        }
};
void transfer(owner & oriOwner,viewer & gettera){
    gettera.sett(oriOwner.forViewer());
}
int main(){
    int option;
    owner A;
    cout<<"First , enter data as the owner\n";
    cout<<"Menu options\n";
    cout<<"0>Exit\n1>display all Message\n2>post new Message\n3>delete Message\n";
    cout<<"Enter command\n";
    cin>>option;
    while(option>0 && option <4){
        if(option==1){
            A.display();
        }
        else if(option==2){
            string nMess;
            cout<<"Enter new Message\n";
            cin>>nMess;
            A.addpost(nMess);
        }
        else if(option==3){
            int num;
            cout<<"Which Message do you want to delete?\n";
            cin>>num;
            A.deletePost(num);
        }
        cout<<"Menu options\n";
        cout<<"0>Exit\n1>display all Message\n2>post new Message\n3>delete Message\n";
        cout<<"Enter command\n";
        cin>>option;
    }
    viewer B;
    cout<<"Access data as viewer\n";
    transfer(A,B);
    cout<<"Menu options\n";
    cout<<"0>Exit\n1>display all Message\n";
    cout<<"Enter command\n";
    cin>>option;
    while(option>0 && option <2){
        if(option==1){
            B.display();
        }
        cout<<"Menu options\n";
        cout<<"0>Exit\n1>display all Message\n";
        cout<<"Enter command\n";
        cin>>option;
    }

    return 0;
}