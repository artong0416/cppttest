#include <iostream>
#include "HashTable.h"
using namespace std;

int main()
{
	HashTable<int> hashtable = HashTable<int>(13);  //����ɢ�б�
	//���β���Ԫ��
	hashtable.insertHash(66);
	hashtable.insertHash(32);
	hashtable.insertHash(98);
	hashtable.insertHash(478);
	hashtable.insertHash(11);
	hashtable.insertHash(23);
	hashtable.insertHash(43);
	hashtable.insertHash(55);
	hashtable.insertHash(67);
	hashtable.insertHash(108);
	hashtable.insertHash(230);
	hashtable.insertHash(223);
	hashtable.insertHash(10);
	//���Ԫ��
	cout<<"���е�Ԫ��Ϊ��";
	for(int i = 1;i<=13;i++)
		cout<<hashtable.getData(i)<<" ";
	cout<<endl;
	//����Ԫ��55
	cout<<"Ԫ��55��λ�ã�"<<hashtable.searchHash(55)<<endl;
	return 0;
}

