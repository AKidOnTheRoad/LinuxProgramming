#include <stdio.h>
#include <libgen.h>
#include <string.h>
#include <stdlib.h>

int main(int argc,char *argv[])
{
	char *t1, *t2;
	int j;
	for (j = 1; j < argc; j++) {
		t1 = strdup(argv[j]);

		t2 = strdup(argv[j]);

		printf("%s ===> %s  +  %s\n", argv[j], dirname(t1), basename(t2));
		
		printf("original value:%s dirname:%s modified value:%s\n",argv[j], (argv[j]), argv[j]);
	
		free(t1);
		free(t2);
		//
	}
	t1 = t2 =  NULL;
	return 0;
}
