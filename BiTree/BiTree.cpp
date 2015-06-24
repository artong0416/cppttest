#include <iostream>
using namespace std;

typedef struct BiTNode{
    char ch;//数据
    BiTNode *lchild;
    BiTNode *rchild;
}BiTNode, *BiTree;

void CreateBiTree(BiTree &T){//递归方式创建二叉树
    char c;
    cin >> c;
    if ('#'==c){
	T=NULL;
    }
    else {
	T=new BiTNode;
	T->ch=c; 
	CreateBiTree(T->lchild);
	CreateBiTree(T->rchild);
    }
}

void PreOrTra(BiTree &T/*BiTNode * T*/){//递归方式前序遍历
    if(T){
	cout << T->ch <<endl;
	PreOrTra(T->lchild);
	PreOrTra(T->rchild);
    }
}

void inOrTra(BiTree &T/*BiTNode * T*/){//递归方式中序遍历
    if(T){
	inOrTra(T->lchild);
	cout << T->ch <<endl;
	inOrTra(T->rchild);
    }
}

void PostOrTra(BiTree &T/*BiTNode * T*/){//递归方式后序遍历
    if(T){
	PostOrTra(T->lchild);
	PostOrTra(T->rchild);
	cout << T->ch <<endl;
    }
}

int main(){
    BiTNode * T;
    CreateBiTree(T);
    printf("前序遍历\n");
    PreOrTra(T);
    printf("中序遍历\n");
    inOrTra(T);
    printf("后序遍历\n");
    PostOrTra(T);
    return 0;
}
