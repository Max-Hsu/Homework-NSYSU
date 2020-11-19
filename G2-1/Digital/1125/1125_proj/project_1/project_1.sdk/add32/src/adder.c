/*
 * adder.c
 *
 *  Created on: 2019¦~11¤ë25¤é
 *      Author: user
 */


#include <stdio.h>
#include "xil_printf.h"

unsigned char A = 0 ,B = 1 ,Cin = 2;
unsigned char S = 3 ,Cout = 4;
unsigned char keep,flag = 0;
unsigned int *base = (unsigned int *) 0x43C00000;

int main(){
	while(1){
		if(flag == 0){
			printf("Input A,B,Cin\n");
			printf("enter A\n");
			scanf("%d",&base[A]);
			getchar();

			printf("enter B\n");
			scanf("%d",&base[B]);
			getchar();

			printf("enter Cin\n");
			scanf("%d" , &base[Cin]);
			getchar();

			printf("%d + %d + %d : Sum = %d ,Cout = %d\n",base[A],base[B],base[Cin],base[S],base[Cout]);
			flag = 1;
		}
		else{
			printf("Continue?(y/n)\n");
			scanf("%c",&keep);
			getchar();
			if(keep == 'y'){
				flag = 0;
			}
			else if(keep == 'n'){
				break;
			}
			else{
				flag = 1;
			}
		}
		printf("End\n");
		return 0;

	}



}
