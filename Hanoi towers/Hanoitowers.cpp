#include <iostream>
using namespace std;
int cnt=0;
int move(int n/*��Ҫ�ƶ�������*/, char x, char y, char z){
	if(n==1){
		printf("%c-->%c\n",x,z);
		cnt++;
	}
	else{
		move(n-1,x,z,y);// n-1����x�ƶ���y������z 
		printf("%c-->%c\n",x,z);//���ĸ���x��z 
		cnt++;
		move(n-1,y,x,z);//n-1����y�ƶ���z������x 
	}
	return cnt;
}

int main(){
	int num=move(3,'X','Y','Z'); 
	cout<<"����Ҫ"<<num<<"��"<<endl; 
	return 0;
}
