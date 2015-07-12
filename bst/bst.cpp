#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

struct BST{
	int val;
	BST* l;
	BST* r;
};

BST* creatBST(int n, BST* L, BST* R){
	BST* newNode=new BST;
	newNode->val=n;
	newNode->l=L;
	newNode->r=R;
	return newNode;
}

BST* insert_BST(BST* t, int n){
	if(t==NULL){
		return creatBST(n,NULL,NULL);
	}
	if(n<t->val){
		t->l=insert_BST(t->l, n);
	}
	else{
		t->r=insert_BST(t->r, n);
	}
	return t;
}

void pprint(BST* root){
	//cout<<"(";
	if(root!=NULL){
		cout<<root->val<<" ";
		pprint(root->l);
		pprint(root->r);
	}
	//cout<<")";
}

void output_impl(BST* n, bool left, string const& indent) 
{ 
    if (n->r) 
    { 
        output_impl(n->r, false, indent + (left ? "|     " : "      ")); 
    } 
    cout << indent; 
    cout << (left ? '\\' : '/'); 
    cout << "-----"; 
    cout << n->val << endl; 
    if (n->l) 
    { 
        output_impl(n->l, true, indent + (left ? "      " : "|     ")); 
    } 
} 
  
void output(BST* root) 
{ 
    if (root->r) 
    { 
        output_impl(root->r, false, ""); 
    } 
    cout << root->val << endl; 
    if (root->l) 
    { 
        output_impl(root->l, true, ""); 
    } 
} 
 
  
bool search_BST(BST* root, int n){
	if(root==NULL){
		return false;
	}
	if(n<root->val){
		return search_BST(root->l,n);
	}
	else if(n>root->val){
		return search_BST(root->r,n);
	}
	return 1;
}

BST* remove_BST(BST* root, int n){
	if(root==NULL){
		return NULL;
	}
	if(n<root->val){
		root->l = remove_BST(root->l,n);
	}
	else if(n>root->val){
		root->r = remove_BST(root->r,n);
	}
	else{
		BST* tmp;
		if(root->l){
			for(tmp=root->l;tmp->r; tmp=tmp->r){
				;
			}
			root->val=tmp->val;
			root->l=remove_BST(root->l,root->val);
		}
		else if(root->r){
			for(tmp=root->r;tmp->l; tmp=tmp->l){
				;
			}
			root->val=tmp->val;
			root->r=remove_BST(root->r,root->val);
		}
		else{
			 delete root;
			 root=NULL;
		}
		return root;
	}
	
}

int main(){
	srand(time(NULL));
	BST* root = NULL;
	for(int i=0;i<10;i++){
		root=insert_BST(root,rand()%100);
	}
	pprint(root);
	cout<<endl;
	output( root) ;
	cout<<endl;
	cout<<search_BST(root,45)<<endl;
	remove_BST(root,45);
	output( root) ;
	return 0;
}
