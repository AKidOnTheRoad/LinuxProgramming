/***************************************************************************
  > File name:      test_main.h
  > Author:         xiaofeifeng
  > Mail:           xiaofeifeng@nettech-global.com
  > Created Time:   2017-12-04 16:46:22 weeks:49
***************************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

#define MYMALLOC(Size,Type)   (Type *)malloc(Size)
#define MYFREE(Ptr)  free(Ptr)

typedef int INT4;
typedef unsigned int UINT4;
typedef char INT1;


typedef struct 
{
	INT4 *OwnId;
	INT1 *TmpValue;
	INT1 *StringValue;	
}tTmpStruct;

