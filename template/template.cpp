#include <iostream>
#include <string>
using namespace std;

template <typename T>
T maxValue(T value1, T value2){
	if(value1>value2){
		return value1;
	}
	else{
		return value2;
	}
} 

int main(int argc, char** argv) {
	cout<<"比较1和3，大的是："<<maxValue(1,3)<<endl;
	cout<<"比较1.5和3.5，大的是："<<maxValue(1.5,3.5)<<endl;
	cout<<"比较a和n，大的是："<<maxValue('a','n')<<endl;
	return 0;
}

