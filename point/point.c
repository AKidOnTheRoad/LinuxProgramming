#include <stdio.h>

void fun(char*p)
{
	p = malloc(10);
	*p = 'a';
}

int main(int argc, const char *argv[])
{
	char p[] = "abdef\n";
	printf("pint:%s\n",p);
	fun(p);
	printf("pint:%s\n",p);
	return 0;
}
