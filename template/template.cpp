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
	cout<<"�Ƚ�1��3������ǣ�"<<maxValue(1,3)<<endl;
	cout<<"�Ƚ�1.5��3.5������ǣ�"<<maxValue(1.5,3.5)<<endl;
	cout<<"�Ƚ�a��n������ǣ�"<<maxValue('a','n')<<endl;
	return 0;
}

