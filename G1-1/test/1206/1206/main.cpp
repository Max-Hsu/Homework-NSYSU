#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef enum { Sunday=0, Monday=1, Tuesday=2, Wednesday=3, Thursday=4, Friday=5, Saturday=6, Undef=-1 } weekday;

char weekdaystring[][10] = {"Sunday", "Monday", "Tuesday", "wednesday", "Thursday", "Friday", "Saturday"};

weekday getweekday(char day[])
{
	weekday i=Sunday; // that means i=0

	for(i=Sunday;i<=Saturday;i++)
	{
		if(strcmp(day, weekdaystring[i])==0)
		  return i;
	}
	return Undef;
}

int main(void)
{
	int day;
	Printf("What day (of the week) is it today? Monday how many days after today?");
	scanf("%d", &day);
	weekday getweekday(day);
	if(char day[]=Undef) printf("unknown weekday\n");
	else
	printf("%d days later is %s",5,i);

	system("pause");
	return 0;
}
