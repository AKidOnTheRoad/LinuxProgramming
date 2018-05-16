#define _XOPEN_SOURCE 600
#include <stdio.h>
#include <unistd.h>
#include <ftw.h>
#include <sys/types.h>
#include <sys/stat.h>


int dirTree(const char *pathname, const struct stat* buf, int type, struct FTW *ftwb)
{
	printf("mode:%d\n",buf->st_mode&S_IFMT);

	if (type == FTW_D)
		printf ("this is a directory.!!!\n");

	return 0;
}



int main(int argc, char *argv[])
{
	int opt, flag = 0;
	while ((opt = getopt(argc,argv,"d")) != -1)
	{
		switch(opt)
		{
		case 'd':
			flag = FTW_DEPTH;
			break;
		default:
			printf("error!!!\n");
			break;
		}
	}

	printf("flag:%d\n",flag);
	if (optind < (argc - 1))
	{
		printf("error1!!!\n");
		return -1;
	}
	
	if (nftw(argv[optind], dirTree, 10, flag) < 0)
	{
		printf("error2!!!\n");
		return -2;
	}

	return 0;
}
