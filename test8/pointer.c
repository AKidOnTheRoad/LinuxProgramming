#include <stdio.h>

char * swap(char *str,int len)
{
	char *ps = str;
	char *pe = str + len -1;
	char temp;
	while(ps < pe)
	{
		temp = *ps;
		*ps++ = *pe;
		*pe-- = temp;
	}

	return str;
}
int main(int argc, char *argv[])
{
	char a[] = "abcdefg";
	char *b = NULL;
	swap(a,strlen(a));

	printf("a:%s\n",a);
	return 0;
}
