
#include"SeqList.h"


void SLInit(SL* ps)

{

	ps->size=0;

	ps->capacity=0;

	ps->a=NULL;

}



void SLDestroy(SL* ps)

{

	assert(ps);

	free(ps->a);

	ps->a=NULL;

	ps->size=0;

	ps->capacity=0;

}

//打印

void SLPrint(SL* ps)

{

	for(int i=0;i<ps->size;i++)

	{

		printf("%d",ps->a[i]);

	}

}



//扩容

void SLCheckCapacity(SL* ps)

{

	if(ps->size==ps->capacity)

	{

		int newcapacity=ps->capacity==0?INIT_CAPACITY:ps->capacity*2;

		SLDataType* newlist=(SLDataType*)realloc(ps->a,sizeof(SLDataType)*newcapacity);

		if(newlist==NULL)

		{

		perror("malloc fail");

		return;

		}

	

		ps->a=newlist;

		ps->capacity=newcapacity;

	}

}



//头部/尾部插入删除

void SLPushFront(SL* ps,SLDataType x)

{

	assert(ps);

	if(ps->size==ps->capacity)

	{

	SLCheckCapacity(ps);

	}

//数据整体后移

	for(int i=ps->size-1;i>0;i--)

	{

	ps->a[i]=ps->a[i-1];

	}

//插入

	ps->a[0]=x;

//元素+1

ps->size++;

}



void SLPopFront(SL* ps)

{

	assert(ps);

	//直接全部往前移动一位就可以了

	for(int i=0;i<ps->size-1;i++)

	{

	ps->a[i]=ps->a[i+1];

	}

	//元素-1

	ps->size--;

}



void SLPushBack(SL* ps,SLDataType x)

{

	//如果满了要扩容

	if(ps->size==ps->capacity)

	{

	SLCheckCapacity(ps);

	}



	//直接在尾部插入

	ps->a[ps->size]=x;

	//元素+1

	ps->size++;

}



void SLPopBack(SL* ps)

{

	assert(ps);

	assert(ps->size>0)

	//尾删则更简单，直接size--就可以了

	ps->size--;

}



//指定位置之前插入及删除数据

void SLInsert(SL* ps,int pos,SLDataType x)

{

	//同样满了扩容

	if(ps->size==ps->capacity)

	{

	SLCheckCapacity(ps);

	}

//同样移动顺序表

for(int i=ps->size-1;i>pos;i++)

{

	ps->a[i]=ps->a[i-1];

}

//插入

	ps->a[pos]=x;

//元素+1

	ps->size++;

}



void SLErase(SL* ps,int pos)

{

	assert(ps);

//把整体往前移动就可以了

	for(int i=pos;i<ps->size-1;i++)

	{

	ps->a[i]=ps->a[i+1];

	}

//元素-1

ps->size--;

}



//查找

int SLFind(SL* ps,SLDataType x)

{

	assert(ps);

	if(ps->a==NULL)

	{

	return -1;

	}

//循环遍历去找

for(int i=0;i<ps->size;i++)

{

	if(ps->a[i]==x)

	{

	return i;

	}

}

return -1;

}
