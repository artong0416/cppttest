#include <iostream>
using namespace std;
int cnt=0;
int move(int n/*需要移动的盘数*/, char x, char y, char z){
	if(n==1){
		printf("%c-->%c\n",x,z);
		cnt++;
	}
	else{
		move(n-1,x,z,y);// n-1个从x移动到y，借助z 
		printf("%c-->%c\n",x,z);//第哪个从x到z 
		cnt++;
		move(n-1,y,x,z);//n-1个从y移动到z，借助x 
	}
	return cnt;
}

int main(){
	int num=move(3,'X','Y','Z'); 
	cout<<"共需要"<<num<<"步"<<endl; 
	return 0;
}
