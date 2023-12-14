#ifndef __SLIST_H__
#define __SLIST_H__

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int SLTDataType;


typedef struct SListNode
{
	SLTDataType data;
	SLTNode* next;
}SLTNode;





#endif /* __SLIST_H__ */
