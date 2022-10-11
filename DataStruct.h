#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// 可变可扩容的数据类型结构体
typedef struct ElemType {
  string data;
} ElemType;

// 单链表
typedef struct LNode
{
  // 定义单链表的数据域
  ElemType data;
  // 定义单链表指针域
  struct LNode *next;

} LNode, *Linklist;