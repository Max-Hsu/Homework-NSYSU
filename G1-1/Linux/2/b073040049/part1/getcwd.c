#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
	char *a;
	a=(char *)malloc(1000*sizeof(char));
	getcwd(a,1000);
	printf("%s\n",a);

return 0;}
