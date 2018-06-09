//tree.h
#pragma once 

#include <stdlib.h>

typedef char ElemType;
#define END '#'

typedef struct BtNode
{
	ElemType data;
	BtNode* leftchild;
	BtNode* rightchild;
}BtNode, *BinaryTree;

BtNode* Buynode();

void Freenode(BtNode* p);

//先序遍历 递归
void PreOrder(BtNode* p);

//中序遍历 递归
void InOrder(BtNode* p);

//后序遍历 递归
void PastOrder(BtNode* p);

//输入Elem创建 先序
BtNode* CreateTree1();

//传入Elem串引用创建 先序
BtNode* CreateTree2(const ElemType *& str);

//传入Elem串二级指针创建 先序
BtNode* CreateTree3(const ElemType ** str);

//通过先序序列和中序序列创建
BtNode* CreatePI(const ElemType* ps, const ElemType* is, int n);

//通过先序序列和中序序列创建
BtNode* CreateIL(const ElemType* is, const ElemType* ls, int n);

//先序遍历 非递归
void NicePreOrder(BtNode* p);

//中序边路 非递归
void NiceInOrder(BtNode* p);

//后序遍历 非递归
void NicePastOrder(BtNode* p);
