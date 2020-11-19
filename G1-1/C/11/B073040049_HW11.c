#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define bubble_sort_size 11
#define magic_block 15
int c_count(int x,int y){
int upper_x=1;
for(int i=x;i>x-y;i--){
    upper_x*=i;
}
for(int i=y;i>=2;i--){
    upper_x/=i;
}
return upper_x;
}
void binomial(int x){
for(int i=0;i<=x;i++){
for(int j=0;j<=i;j++){
    printf("%d ",c_count(i,j));
}
printf("\n");
}
}
void bubble_sort(int *sorta){
for(int i=0;i<bubble_sort_size-1;i++){
    for(int j=0;j<bubble_sort_size-1-i;j++){
        if(sorta[j]>sorta[j+1]){
            int temp;
            temp=sorta[j];
            sorta[j]=sorta[j+1];
            sorta[j+1]=temp;
        }
    }
}
}
void median(int *sorta){
    bubble_sort(sorta);
    for(int i=0;i<bubble_sort_size;i++){
        printf("%d ",sorta[i]);
    }
    printf("\n中位數是:%d\n\n",sorta[5]);
}
int * magic_square(int *magic,int x,int y,int range,int current){
    static int r_cn[2];
    x-=1;
    y-=1;
    if(x<0){
        x+=range;
    }
    if(y<0){
        y+=range;
    }
    if(*(magic+x*magic_block+y)!=-1){
        x+=2;
        y+=1;
        if(x>=range){
            x-=range;
        }
        if(y>=range){
            y-=range;
        }
    }
    r_cn[0]=x;
    r_cn[1]=y;
    *(magic+x*magic_block+y)=current;
    return r_cn;
}
int main()
{

    int bio_number;
    int sortaa[bubble_sort_size];
    printf("請輸入二項式次方數:");
    scanf("%d",&bio_number);
    binomial(bio_number);
    printf("\n請輸入11個數字:\n");
    for(int i=0;i<bubble_sort_size;i++){
        scanf("%d",&sortaa[i]);
    }
    median(sortaa);

    int magic[magic_block][magic_block];
    memset(magic,-1,sizeof(magic));

    int magic_num;
    printf("請輸入魔方陣大小:");
    scanf("%d",&magic_num);
    int r_can[2]={0,magic_num/2};
    magic[0][magic_num/2]=1;
    for(int i=2;i<=magic_num*magic_num;i++){
        int *r_pcan;
        r_pcan=magic_square(magic,r_can[0],r_can[1],magic_num,i);
        r_can[0]=r_pcan[0];
        r_can[1]=r_pcan[1];
    }

    for(int i=0;i<magic_num;i++){
        for(int j=0;j<magic_num;j++){
            printf("%3d ",magic[i][j]);
        }
        printf("\n");
    }
    //magic_square(magic,5,5);
    //printf("%d",);
    return 0;
}
