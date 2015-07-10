#include <iostream>
using namespace std;
/********************ɢ�б��壬���ÿ��Ŷ�ַ�������ͻ****************/
template<typename DataType> class HashTable
{
public:
	HashTable(int size)
	{
		maxSize = size;                             //��ʼ�����洢�ռ�
		count = 0;
		elements = new DataType[size];             //�������ݿռ�
		if(elements == NULL)                       //�жϴ洢�ռ��Ƿ����ɹ�
			exit(1);
		for(int i=0;i<size;i++)                     //��ʼ��ÿ���洢�ռ��ֵ
			elements[i] = NULL;
	}
	~HashTable()
	{
		delete[] elements;
	}
	//ɢ�к���
	int hash(DataType value);
	//���Һ���,����������Ԫ�صĵ�ַ
	int searchHash(DataType value);
	//��ȡɢ�б�ĵ�i��Ԫ�ص�ֵ
	DataType getData(int i)
	{
		if(i<=0)
		{
			std::cout<<"����ֵ���󣡱���Ϊ������"<<endl;
		}
		return elements[i-1];
	}
	//�������
	bool insertHash(DataType value);
private:
	int maxSize;                          //�������
	int count;                            //��ǰԪ����
	DataType *elements;                   //������
};

/***********************hash����***********************/
template<typename DataType> int HashTable<DataType>::hash(DataType value)
{
	return value % 13;                    //���ó����෨����ɢ�е�ַ
}

/**********************�����㷨***********************/
template<typename DataType> int HashTable<DataType>::searchHash(DataType value)
{
	int p = hash(value);                            //�����ַ
	if(elements[p] == value)                        //�����ȣ�û�з�����ͻ������p
	{
		return p;                                 
	}
	int rp = (p+1) % maxSize;                      //����̽�ⷨ�����ͻ��ѡȡd=1
	while(rp != p)                                 //rp==pʱ˵��û���ҵ�����Ԫ��
	{
		if(elements[rp] == value)                  //����µ�ַ��ֵ��value��ȣ������µ�ַ
			return rp;
		if(elements[rp] == NULL)                   //�ҵ��հ׵�ַ
			break;
		rp = (rp+1) % maxSize;                     //ѭ��ʹ������̽�ⷨ�ҿհ׵�ַ
	}
	if(rp == p)                                    //����ʧ��
		return -2;
	else
	{
		//elements[rp] = value;                      //�ڿհ׵�ַ�ϲ����Ԫ�ز����ص�ַ
		return rp;
	}

}

/************************�������**************************/
template<typename DataType> bool HashTable<DataType>::insertHash(DataType value)
{
	int pos = searchHash(value);                  //����ָ��Ԫ�أ�����ɢ�б����Ƿ��Ѿ�����
	if(pos<0)                                     //����ʧ���ұ���
	{
		return false;
	}		
	else if(elements[pos] == value)               //���ظ�Ԫ��
	{
		cout<<"�ظ���Ԫ�أ�"<<endl;
		return false;
	}
	else
	{
		elements[pos] = value;                    //�ڿհ׵�ַ����Ԫ��
		return true;
	}
}


