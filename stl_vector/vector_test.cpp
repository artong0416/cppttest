#include <vector>
#include <iostream>
#include "vector1.h"
#include "myvector.h "
using namespace std ;

struct te{
		int x;
		char y;
	};

int main(){

	vector1<char> a(10,'d');
	for (int i=0;i<a.size();i++){
		cout << a[i]<< " ";
	}
	cout<<endl;
	a[5]='h';
	for (int i=0;i<a.size();i++){
		cout << a[i]<< " ";
	}
	cout<<endl;
	vector1<char>&c=a;
	
	vector1<char> b(c);
	for (int i=0;i<c.size();i++){
		cout << c[i]<< " ";
	}
	cout<<endl;
	cout<<b.capacity()<<" "<<b.size()<<endl;
	cout<<a.capacity()<<" "<<a.size()<<endl;
	vector1<char> d = a;
	for (int i=0;i<d.size();i++){
		cout << d[i]<< " ";
	} 
	cout<<endl;
	
	char* pos=b.begin()+5;
	b.insert(pos,5,'a');
	for (int i=0;i<b.size();i++){
		cout << b[i]<< " ";
	} 
	cout<<endl;
	
	b.pop_back();
	for (int i=0;i<b.size();i++){
		cout << b[i]<< " ";
	} 
	cout<<endl;
	
	b.push_back('f');
	for (int i=0;i<b.size();i++){
		cout << b[i]<< " ";
	} 
	cout<<endl;
	
	b.push_back('f');
	for (int i=0;i<b.size();i++){
		cout << b[i]<< " ";
	} 
	cout<<endl;
	
	pos=b.begin()+14;
	b.erase(pos);
	for (int i=0;i<b.size();i++){
		cout << b[i]<< " ";
	} 
	cout<<endl;
	
	b.clear();
	for (int i=0;i<b.size();i++){
		cout << b[i]<< " ";
	} 
	cout<<endl;
	//vector1<te> te(10);//只支持内建类型的数据 
	return 0;
}

