//main.cpp

#include "tree.h"

#include <iostream>
using namespace std;

int main()
{
	const ElemType *str = "ABC##DE##F##G#H##";
	const ElemType* ps = "ABCDEFGH";
	const ElemType* is = "CBEDFAGH";
	const ElemType* ls = "CEFDBHGA";
	int len = sizeof(ps)/sizeof(ps[0]) - 1;
	BinaryTree root = NULL;

	root = CreateIL(is, ls, 8);
	PreOrder(root);
	cout<<endl;
	InOrder(root);
	cout<<endl;
	PastOrder(root);
	cout<<endl;

	return 0;
}
