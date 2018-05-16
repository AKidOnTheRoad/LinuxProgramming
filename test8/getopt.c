#include <stdio.h>
#include <unistd.h>

int main(int argc,char *argv[])
{
	int opt;
	printf("original optind:%d\n",optind);
	opterr = 1;
	while((opt = getopt(argc,argv,"abc:d:")) != -1)
	{
		printf("optind:%d\n",optind);
		switch(opt)
		{
			case 'a':
				printf("a\n");
				break;
			case 'b':
				printf("b\n");
				break;
			case 'c':
				printf("c %s\n",optarg);
				break;
			case 'd':
				printf("%s\n",optarg);
				break;
			default:
				printf("error!!!!\n");
				break;
		}
	}
	printf("optopt:%c\n",optopt);
	printf("modified optind:%d\n",optind);

}
