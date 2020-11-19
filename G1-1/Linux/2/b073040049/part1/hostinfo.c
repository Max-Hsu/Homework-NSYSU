#include <stdio.h>
#include <sys/utsname.h>
#include <unistd.h>
#include <stdlib.h>
int main(){
	struct utsname a;
	uname(&a);
	printf("hostname: %s \n",a.nodename);
	printf("%s %s \n",a.sysname,a.release);
	long c=gethostid();
	printf("hostid: %ld \n",c);
return 0;
}
