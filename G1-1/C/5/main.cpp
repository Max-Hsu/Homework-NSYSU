#include <stdio.h>
#include <math.h>
#define PI 3.14159
int main()
{
    int x_range_min,x_range_max;
    int a,b,c,d,e;
    int find_x;
    printf("請輸入5個係數:");
    scanf("%d %d %d %d %d",&a,&b,&c,&d,&e);
    printf("請輸入x軸範圍:");
    scanf("%d %d",&x_range_min,&x_range_max);
    printf("請輸入索求切點的x值");
    scanf("%d",&find_x);
    int tans_m=((c*cos(d*PI*find_x/30))*PI*d/30)-((a*sin(b*PI*find_x/30))*PI*b/30)+e;
    //printf("實際切線斜率:%ld",tans_m);
    int tans_its_y=((a*cos(b*PI*find_x/30))+(c*sin(d*find_x*PI/30))+e);
    printf("實際切線斜率:%d\n",tans_m);
    printf("   -35  -30  -25  -20  -15  -10  -5    0     5    10   15   20   25   30   35");
    printf("\n");
    for(int x=x_range_min; x<=x_range_max; x++)
    {

        for(int y=-39; y<=40; y++)
        {
            int func=((a*cos(b*PI*x/30))+(c*sin(d*x*PI/30))+e);
            if(x==x_range_min)
            {
                if(func==y){
                    printf("*");
                }
                else if(y==0)
                {
                    printf("%d",x);
                }
                else if(y==40){
                    printf("Y");
                }
                else if(y%5==0)
                {
                    printf("+");

                }
                else
                {
                    printf("-");
                }
            }
            else{
                if(func==y){
                    if(x==find_x){
                        printf("P(%d,%d)",find_x,func);
                    }
                    else{
                    printf("*");
                    }
                }
                else if((x-find_x)<=5&&(x-find_x)>0){
                int tans_line_cur_y=tans_m*(x-find_x)+tans_its_y;
                if(tans_line_cur_y==y){
                    if(tans_m==0){
                        printf("|");
                    }
                    else if(tans_m>0&&tans_m<=10){
                        printf("\\");
                    }
                    else if(tans_m<0&&tans_m>=-10){
                        printf("/");
                    }
                }
                else if((x%5)==0&&y==0){
                printf("%d",x);
                y+=(int)(log10(x));
                }
                else if(y==0){
                    printf("|");
                }
                else{
                    printf(" ");
                }
                }
                else if((find_x-x)<=5&&(find_x-x)>0){
                int tans_line_cur_y=tans_m*(x-find_x)+tans_its_y;
                if(tans_line_cur_y==y){
                    if(tans_m==0){
                        printf("|");
                    }
                    else if(tans_m>0&&tans_m<=10){
                        printf("\\");
                    }
                    else if(tans_m<0&&tans_m>=-10){
                        printf("/");
                    }
                }
                else if((x%5)==0&&y==0){
                printf("%d",x);
                y+=(int)(log10(x));
                }
                else if(y==0){
                    printf("|");
                }
                else{
                    printf(" ");
                }
                }
                else if((x%5)==0&&y==0){
                printf("%d",x);
                y+=(int)(log10(x));
                }
                else if(y==0){
                    printf("|");
                }

                else{
                    printf(" ");
                }
            }

        }
        printf("\n");
    }

    return 0;
}
