#include <iostream>
#include "friendClass.h"
using namespace std;

class AccessDate{
	public:
		static void p(){//定义静态函数
			Date birthData(2010, 3, 4);
			birthData.year=2000;
			cout<<birthData.year<<endl;//通过友元类可直接访问私有成员函数 
		} 
		
};
int main(){
	AccessDate::p(); //静态成员函数推荐调用方法 
	return 0;
}
