#include <iostream>
using namespace std;

typedef struct BiTNode{
    char ch;//����
    BiTNode *lchild;
    BiTNode *rchild;
}BiTNode, *BiTree;

void CreateBiTree(BiTree &T){//�ݹ鷽ʽ����������
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

void PreOrTra(BiTree &T/*BiTNode * T*/){//�ݹ鷽ʽǰ�����
    if(T){
	cout << T->ch <<endl;
	PreOrTra(T->lchild);
	PreOrTra(T->rchild);
    }
}

void inOrTra(BiTree &T/*BiTNode * T*/){//�ݹ鷽ʽ�������
    if(T){
	inOrTra(T->lchild);
	cout << T->ch <<endl;
	inOrTra(T->rchild);
    }
}

void PostOrTra(BiTree &T/*BiTNode * T*/){//�ݹ鷽ʽ�������
    if(T){
	PostOrTra(T->lchild);
	PostOrTra(T->rchild);
	cout << T->ch <<endl;
    }
}

int main(){
    BiTNode * T;
    CreateBiTree(T);
    printf("ǰ�����\n");
    PreOrTra(T);
    printf("�������\n");
    inOrTra(T);
    printf("�������\n");
    PostOrTra(T);
    return 0;
}
