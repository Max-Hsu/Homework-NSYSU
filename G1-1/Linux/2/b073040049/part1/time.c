#include <time.h>
#include <stdio.h>

int main(){
	struct tm *a;
	time_t x;
	char s[10];
	time(&x);
	//printf("%ld",x);
	a=localtime(&x);
	//printf("%d",a->tm_sec);
	strftime(s, 10, "%b", a);
	printf("%s  ", s);
	strftime(s, 10, "%d", a);
	printf("%s", s);
	strftime(s, 10, "%a", a);
	printf("(%s),", s);
	strftime(s, 10, "%G", a);
	printf("%s  ", s);	
	strftime(s, 10, "%R", a);
	printf("%s  ", s);
	strftime(s, 10, "%p", a);
	printf("%s  ", s);
}
