#include <iostream>
#include "friendClass.h"
using namespace std;

class AccessDate{
	public:
		static void p(){//���徲̬����
			Date birthData(2010, 3, 4);
			birthData.year=2000;
			cout<<birthData.year<<endl;//ͨ����Ԫ���ֱ�ӷ���˽�г�Ա���� 
		} 
		
};
int main(){
	AccessDate::p(); //��̬��Ա�����Ƽ����÷��� 
	return 0;
}
