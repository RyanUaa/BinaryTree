//tree.cpp
//2018年 06月 04日 星期一 13:08:37 CST
#include "tree.h"
#include <iostream>
#include <string.h>
#include <string>
#include <stack>
#include <queue>

using namespace std;

BtNode* Buynode()
{
	BtNode* s = (BtNode*)malloc(sizeof(BtNode));
	if(NULL == s)
		exit(1);

	return s;
}

void Freenode(BtNode* p)
{
	free(p);
}

void PreOrder(BtNode* p)
{
	if(NULL != p)
	{
		cout<<p->data<<" ";
		PreOrder(p->leftchild);
		PreOrder(p->rightchild);
	}
}

void InOrder(BtNode* p)
{
	if(NULL != p)
	{
		InOrder(p->leftchild);
		cout<<p->data<<" ";
		InOrder(p->rightchild);
	}
}

void PastOrder(BtNode* p)
{
	if(NULL != p)
	{
		PastOrder(p->leftchild);
		PastOrder(p->rightchild);
		cout<<p->data<<" ";
	}
}

//标准输入Elem创建 先序
BtNode* CreateTree1()
{
	BtNode* s = NULL;
	ElemType item;
	cin>>item;
	if(END != item)
	{
		s = Buynode();
		s->data = item;
		s->leftchild = CreateTree1();
		s->rightchild = CreateTree1();
	}
	return s;
}

//传入Elem串引用创建 先序
BtNode* CreateTree2(const ElemType*& str)
{
	BtNode* s = NULL;
	if(NULL != str && END != *str)
	{
		s = Buynode();
		s->data = *str;
		s->leftchild = CreateTree2(++str);
		s->rightchild = CreateTree2(++str);
	}
	return s;
}

//传入Elem串二级指针创建 先序
BtNode* CreateTree3(const ElemType** str)
{
	BtNode* s = NULL;
	if(NULL != str && END != **str)
	{
		s = Buynode();
		s->data = **str;
		s->leftchild = CreateTree3(&++*str);
		s->rightchild = CreateTree3(&++*str);
	}
	return s;
}

//在中序序列中找到划分点（父节点）
static int Findls(const ElemType *is, int len, ElemType val)
{
	int pos = 0;
	for(int i = 0; i < len; ++i)
	{
		if(is[i] == val)
		{
			pos = i;
			break;
		}
	}
	return pos;
}


//通过先序序列和中序序列创建
BtNode* CreatePI(const ElemType* ps, const ElemType* is, int n)
{
	BtNode* s = NULL;
	if(NULL != ps && NULL != is && n > 0)
	{
		s = Buynode();
		s->data = ps[0];
		int pos = Findls(is, n, ps[0]);	
		s->leftchild = CreatePI(ps+1, is, pos);
		s->rightchild = CreatePI(ps+1+pos, is+pos+1, n-pos-1);
	}
	return s;
}

//通过先序序列和中序序列创建
BtNode* CreateIL(const ElemType *is, const ElemType *ls, int n)
{
	BtNode* s = NULL;
	if(NULL != is && NULL != ls && n > 0)
	{
		s = Buynode();
		s ->data = ls[n-1];
		int pos = Findls(is, n, ls[n-1]);
		s->leftchild = CreateIL(is, ls, pos);
		s->rightchild = CreateIL(is+pos+1, ls+pos, n-pos-1);
	}
	return s;
}

//先序遍历 非递归
void NicePreOrder(BtNode* p)
{
	if(NULL == p)
		return ;

	stack<BtNode*> st;
	stack.push(p);
	while(!st.empty())
	{
		p = st.top();st.pop();
		cout<<p->data<<" ";
		if(NULL != p->rightchild)
			st.push(p->rightchild);

		if(NULL != p->leftchild)
			st.push(p->leftchild);
	}
	
	cout<<endl;
}

//中序遍历 非递归
void NiceInOrder(BtNode* p)
{
	if(NULL == p)
		return ;

	stack<BtNode*> st;
	while(!st.empty() && NULL != p)
	{
		while(NULL != p)
		{
			st.push(p);
			p = p->leftchild;
		}

		p = st.top();st.pop();
		cout<<p->data<<" ";
		p = p->rightchild();
	}
	cout<<endl;
}

//后序遍历 非递归
void NicePastOrder(BtNode* p);



































