#include <iostream>
#include <queue>
using namespace std;
struct BTNode
{
	char m_value;
	BTNode *chile[5];
};

//���򴴽���
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

//�����
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

//����
int GetWidth(BTNode *pRoot)
{
	if (pRoot == NULL)
	{
		return 0;
	}

	int nLast = 0;//��һ��Ŀ��
	int nTemp = 0;
	int nCur = 0;//��ǰ��Ŀ��
	int nWidth = 1;//�����
    queue<BTNode *> myQueue;
	myQueue.push(pRoot);
	nLast = 1;	
	BTNode *pCur = NULL;
	while (!myQueue.empty())//���в���
	{
		nTemp = nLast;
		while (nTemp)
		{
            pCur = myQueue.front();//ȡ������ͷԪ��
			myQueue.pop();//������ͷԪ�س���
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
    cout << "�������Ϊ��" << GetDepth(pRoot) << endl;
	cout << "���Ŀ��Ϊ��" << GetWidth(pRoot) << endl;	
	return 0;
}

