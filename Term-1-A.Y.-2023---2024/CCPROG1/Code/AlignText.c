#include <stdio.h>

int main()
{
	int date;	
	
	printf ("Enter a date (MMDDYYYY): ");
	scanf ("%d", &date);
	
	printf ("%s%s%s%s", "----------", "----------", "----------", "----------\n");
	printf ("%*s%02d-%02d-%04d\n", 15, "", date / 1000000, date / 10000 % 100, date % 10000);
	printf ("%*s\n", 20 + 5 / 2, "Hello");
	printf ("Total:%*s", 35, "10000\n");
	printf ("%s%s%s%s", "----------", "----------", "----------", "----------\n\n");
}
