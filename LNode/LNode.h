#include "/home/hw/桌面/LRZ/Coding/C/DataStruct/DataStruct.h"

// 寻找 i-1 的节点
LNode * Find (Linklist &L, int location, string type) {
  LNode *p = L;

  // 定义计数器
  int count;

  // 带头节点的计数器为 0 ，不带头节点的计数器为 1
  if (type == "HLNode") count = 0;
  else if (type == "NHLNode") count = 1;
  
  // 将指针 p 移动到 i-1 的位置
  while (count < location-1 && p != NULL) {
    p = p->next;
    count++;
  }

  // 返回在 i-1 位置的 p 指针
  return p;
}

// 后插操作
bool BackInsert (LNode *p, string e) {
  LNode *inP = new LNode;

  // 内存申请失败
  if (inP == NULL) return false;

  // 插入
  inP->data.data = e;

  inP->next = p->next;
  p->next = inP;

  cout << "\033[1;30m数据为: \033[0m\033[1;32m" << e << "\033[0m \033[1;30m的节点已插入链表\033[0m" << endl;

  // 插入成功
  return true;
}

// 按位删除
bool DelByLocation (LNode *p) {
  LNode *delP = p->next;

  // 删除
  string e = delP->data.data;
  p->next = delP->next;

  delete delP;

  // 打印删除结果
  cout << "\033[1;30m数据为: \033[0m\033[1;31m" << e << "\033[0m \033[1;30m的节点已被删除！\033[0m" << endl;

  // 删除成功
  return true;
}

// 按位修改
bool ChangeByLocation (LNode *p, string e) {
  LNode *cP = p->next;

  string ce = cP->data.data;
  cP->data.data = e;

  cout << "\033[1;30m数据为: \033[0m\033[1;31m" << ce << "\033[0m 的节点已被修改为: \033[1;32m" << e << "\033[0m" << endl;

  // 修改成功
  return true;
}

// 带头节点的单链表
class HLNode {
private:
  // 私有方法
  // 初始化带头节点的单链表
  bool Init();
  // 销，销毁
  bool Destroy();

public:
  // 公有方法
  // 创建单链表节点
  Linklist L;

  // 计算长度
  int Lenght();
  // 判断链表是否为空
  bool Empty();
  // 打印
  void Print();

  // 增删改查
  // 增，插入
  bool Insert(int location, string e);
  // 删，删除
  bool Delete(int location);
  // 改，修改
  bool Change(int location, string e);
  // 查, 查看
  bool Check();

  // 生命函数
  HLNode();
  ~HLNode();
};

// 生命函数
// 类生成时调用
HLNode :: HLNode() {
  cout << endl;
  cout << "\033[1;30m初始化: \033[0m" << (this->Init() ? "\033[1;32m成功!\033[0m" : "\033[1;31m失败!\033[0m") << endl;
}

// 类销毁时调用
HLNode :: ~HLNode() {
  this->Destroy();
}

// 初始化
bool HLNode :: Init() {
  this->L = new LNode;

  if (L == NULL) return false;

  this->L->data.data = "Head";
  this->L->next = NULL;

  // 初始化成功
  return true;
}

// 计算长度
int HLNode :: Lenght() {
  // 若为空链表则返回长度为 0
  if (this->Empty()) return 0;

  int lenght = 0;

  LNode *p = this->L;

  while (p->next != NULL) {
    lenght++;
    p = p->next;
  }

  return lenght;
}

// 是否为空
bool HLNode :: Empty() {
  if (this->L->next == NULL) return true;
  else return false;
}

// 打印
void HLNode :: Print() {
  cout << endl;
  cout << "\033[1;30m———————————————————————————————————————————\033[0m" << endl;

  cout 
    << "\033[1;30m|\033[0m" << setw(8) << "\033[1;30m Number \033[0m" 
    << "\033[1;30m|\033[0m" << setw(15) <<  "\033[1;30m DataArea Data \033[0m" 
    << "\033[1;30m|\033[0m" << setw(14) <<  "\033[1;30m     Pointer    \033[0m" 
    << "\033[1;30m|\033[0m" << endl;

  cout << "\033[1;30m———————————————————————————————————————————\033[0m" << endl;

  LNode *p = this->L;

  for (int i = 0; i <= this->Lenght(); i++) {
    cout 
      << "\033[1;30m|\033[0m" << setw(8)  <<  i 
      << "\033[1;30m|\033[0m" << setw(15) <<  p->data.data 
      << "\033[1;30m|\033[0m " << setw(14) <<  p->next 
      << " \033[1;30m|\033[0m" << endl;
    cout << "\033[1;30m———————————————————————————————————————————\033[0m" << endl;
    // 指向下一节点
    p = p->next;
  }

  cout << endl;
}

// 插入
bool HLNode :: Insert (int location, string e) {
  // 插入位置不合法
  if (location < 1) return false;

  LNode *p = Find(this->L, location, "HLNode");

  // i 值不合法
  // if (p == NULL) return false;

  // 插入时不需要判断 p 的下一节点是否为空
  // 因为为空也要在该空位置 i 插入节点
  // if (p->next == NULL) return false;

  return BackInsert(p, e);
}

// 删除
bool HLNode :: Delete (int location) {
  // 删除位置不合法
  if (location < 1) return false;

  LNode *p = Find(this->L, location, "HLNode");

  // 但是删除操作需要判断
  // 因为如果是空的就无需删除
  // 即删除位置不合法
  if (p->next == NULL) return false;

  return DelByLocation(p);
}

// 修改
bool HLNode :: Change (int location, string e) {
  // 修改位置不合法
  if (location < 1) return false;

  LNode *p = Find(this->L, location, "HLNode");

  if (p->next == NULL) return false;

  return ChangeByLocation(p, e);
}

// 销毁
bool HLNode :: Destroy () {
  int lenght = this->Lenght();
  // 消除所有数据，包括头节点
  for (int i = 0; i <= lenght; i++) {
    this->Delete(lenght-i);
  }
  // 释放头节点内存，销毁头节点
  // free(this->L);

  cout << "\033[1;31m链表已被销毁！！！\033[0m" << endl;

  return true;
}

// 不带头节点的单链表
class NHLNode {
private:
  // 初始化
  bool Init();
  // 销毁
  bool Destroy();

public:
  // 创建单链表节点
  Linklist L;

  // 计算长度
  int Lenght();
  // 判断链表是否为空
  bool Empty();
  // 打印
  void Print();

  // 增删改查
  // 增，插入
  bool Insert(int location, string e);
  // 删，删除
  bool Delete(int location);
  // 改，修改
  bool Change(int location, string e);
  // 查, 查看
  bool Check();
  
  NHLNode();
  ~NHLNode();
};

NHLNode :: NHLNode() {
  cout << endl;
  cout << "\033[1;30m初始化: \033[0m" << (this->Init() ? "\033[1;32m成功!\033[0m" : "\033[1;31m失败!\033[0m") << endl;
}

NHLNode :: ~NHLNode() {
  this->Destroy();
}

// 初始化
bool NHLNode :: Init() {
  // 指针指向空
  this->L = NULL;

  return true;
}

// 计算长度
int NHLNode :: Lenght() {
  // 若为空链表则返回长度为 0
  if (this->Empty()) return 0;

  int lenght = 1;

  LNode *p = L;

  while (p->next != NULL) {
    p = p->next;
    lenght++;
  }

  return lenght;
}

// 是否为空
bool NHLNode :: Empty() {
  // 如果头节点为空，则链表为空
  if (this->L == NULL) return true;
  else return false;
}

// 打印
void NHLNode :: Print() {
  cout << endl;
  cout << "\033[1;30m———————————————————————————————————————————\033[0m" << endl;

  cout 
    << "\033[1;30m|\033[0m" << setw(8) << "\033[1;30m Number \033[0m" 
    << "\033[1;30m|\033[0m" << setw(15) <<  "\033[1;30m DataArea Data \033[0m" 
    << "\033[1;30m|\033[0m" << setw(14) <<  "\033[1;30m     Pointer    \033[0m" 
    << "\033[1;30m|\033[0m" << endl;

  cout << "\033[1;30m———————————————————————————————————————————\033[0m" << endl;

  LNode *p = this->L;

  for (int i = 1; i <= this->Lenght(); i++) {
    cout 
      << "\033[1;30m|\033[0m" << setw(8)  <<  i
      << "\033[1;30m|\033[0m" << setw(15) <<  p->data.data 
      << "\033[1;30m|\033[0m " << setw(14) <<  p->next 
      << " \033[1;30m|\033[0m" << endl;
    cout << "\033[1;30m———————————————————————————————————————————\033[0m" << endl;
    // 指向下一节点
    p = p->next;
  }

  cout << endl;
}

// 插入
bool NHLNode :: Insert (int location, string e) {
  // 插入位置不合法
  if (location < 1) return false;

  if (location == 1) {
    LNode *inP = new LNode;
    // 赋值
    inP->data.data = e;
    // 节点指向 L
    inP->next = this->L;
    // L 指向节点
    this->L = inP;
    
    cout << "\033[1;30m数据为: \033[0m\033[1;32m" << e << "\033[0m \033[1;30m的节点已插入链表\033[0m" << endl;

    return true;
  }

  LNode *p = Find(this->L, location, "NHLNode");

  // i 值不合法
  // if (p == NULL) return false;

  return BackInsert(p, e);
}

// 删除
bool NHLNode :: Delete (int location) {
  // 插入位置不合法
  if (location < 1) return false;

  if (location == 1) {
    LNode *delP = this->L;

    // 存取被删除数据，并指向下一节点
    string e = L->data.data;
    this->L = L->next;

    delete delP;

    // 打印删除结果
    cout << "\033[1;30m数据为: \033[0m\033[1;31m" << e << "\033[0m \033[1;30m的节点已被删除！\033[0m" << endl;

    return true;
  }

  LNode *p = Find(this->L, location, "NHLNode");

  // 但是删除操作需要判断
  // 因为如果是空的就无需删除
  // 即删除位置不合法
  if (p->next == NULL) return false;

  return DelByLocation(p);
}

// 修改
bool NHLNode :: Change (int location, string e) {
  // 修改位置不合法
  if (location < 1) return false;

  if (location == 1) {
    if (this->Empty()) return false;

    string ce = this->L->data.data;
    this->L->data.data = e;

    cout << "\033[1;30m数据为: \033[0m\033[1;31m" << ce << "\033[0m 的节点已被修改为: \033[1;32m" << e << "\033[0m" << endl;

    return true;
  }
  
  LNode *p = Find(this->L, location, "NHLNode");

  if (p->next == NULL) return false;

  return ChangeByLocation(p, e);
}

// 销毁
bool NHLNode :: Destroy () {
  int lenght = this->Lenght();
  // 消除所有数据，包括头节点
  for (int i = 0; i < lenght; i++) {
    this->Delete(lenght-i);
  }
  // 释放头节点内存，销毁头节点
  // free(this->L);

  cout << "\033[1;31m链表已被销毁！！！\033[0m" << endl;

  return true;
}