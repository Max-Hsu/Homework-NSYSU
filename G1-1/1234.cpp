#include <iostream>
#include <unistd.h>
extern "C"{
#include <pthread.h>
}
using namespace std;
void * hello_F(){
cout<<"hello"<<endl;
sleep(5);
}
int main(){
pthread aaa[100];
cout<<"helloa"<<endl;
for(int i=0;i<100;i++){
pthread_create(&aaa[i],NULL,hello_F,NULL);
}
for(int i=0;i<100;i++){
pthread_join(aaa[i],NULL);
}

return 0;
}