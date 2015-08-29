#include <iostream>
#include <queue>
using namespace std;
struct BTNode
{
	char m_value;
	BTNode *chile[5];
};

//先序创建树
void CreatBTree(BTNode *&root)
{	
	char nValue = 0;
	cin >> nValue;
	if ('#' == nValue)
	{
		return;
	}
	else
	{
		root = new BTNode();
		root->m_value = nValue;
		for(int i=0;i<5;i++){
			CreatBTree(root->chile[i]);
		}
	}	
}

//求深度
int GetDepth(BTNode *pRoot)
{
	if (pRoot == NULL)
	{
		return 0;
	}
	int max=0;
	for(int i=0;i<5;i++){
		if(max<GetDepth(pRoot->chile[i]) + 1){
			max=GetDepth(pRoot->chile[i]) + 1;
		}
	}
	return max;
}

//求宽度
int GetWidth(BTNode *pRoot)
{
	if (pRoot == NULL)
	{
		return 0;
	}

	int nLast = 0;//上一层的宽度
	int nTemp = 0;
	int nCur = 0;//当前层的宽度
	int nWidth = 1;//数宽度
    queue<BTNode *> myQueue;
	myQueue.push(pRoot);
	nLast = 1;	
	BTNode *pCur = NULL;
	while (!myQueue.empty())//队列不空
	{
		nTemp = nLast;
		while (nTemp)
		{
            pCur = myQueue.front();//取出队列头元素
			myQueue.pop();//将队列头元素出对
			for(int i=0;i<5;i++){
				if(pCur->chile[i]){
					myQueue.push(pCur->chile[i]);
				}
			} 
			nTemp--;
		}

		nCur = myQueue.size();
		if(nWidth<nCur){
			nWidth = nCur;
		}
		nLast = nCur;
	}

	return nWidth;
}

int main() 
{
	BTNode *pRoot = NULL;	
	CreatBTree(pRoot);
    cout << "树的深度为：" << GetDepth(pRoot) << endl;
	cout << "树的宽度为：" << GetWidth(pRoot) << endl;	
	return 0;
}

