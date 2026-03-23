
// 必要头文件
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// 初始容量
#define INIT_CAPACITY 4

// 数据类型
typedef int SLDataType;

// 动态顺序表结构
typedef struct SeqList
{
    SLDataType* a;   // 指向动态开辟的数组
    int size;        // 有效数据个数
    int capacity;    // 当前容量
} SL;


// ================= 初始化 & 销毁 =================
void SLInit(SL* ps);
void SLDestroy(SL* ps);


// ================= 基本功能 =================
void SLPrint(SL* ps);


// ================= 扩容 =================
void SLCheckCapacity(SL* ps);


// ================= 插入 & 删除 =================

// 尾插 / 尾删
void SLPushBack(SL* ps, SLDataType x);
void SLPopBack(SL* ps);

// 头插 / 头删
void SLPushFront(SL* ps, SLDataType x);
void SLPopFront(SL* ps);


// ================= 指定位置操作 =================

// 在 pos 位置之前插入
void SLInsert(SL* ps, int pos, SLDataType x);

// 删除 pos 位置元素
void SLErase(SL* ps, int pos);


// ================= 查找 =================
int SLFind(SL* ps, SLDataType x);
