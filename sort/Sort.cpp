#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

void InsertSort(vector<int> &arr) {//插入排序 --插入类  
	int tmp,i,j;
	for (i=1;i<arr.size();i++){
		tmp=arr[i];
		for(j=i-1; j>=0&&tmp<arr[j];j--){
			arr[j+1]=arr[j];
		}
		arr[j+1]=tmp;
	}
}

void ShellSort(vector<int> &arr) {//shell排序 （相当于分组插入）--插入类  
	int tmp,i,j,k;
	for (k=arr.size()/2;k>0;k=k/2){//控制增量 
		for (i=k;i<arr.size();i++){
			tmp=arr[i];
			for(j=i-k; j>=0&&tmp<arr[j];j-=k){
				arr[j+k]=arr[j];
			}
			arr[j+k]=tmp;
		}	
	}
}

void swap(vector<int> &arr, int i, int j){
	int tmp=arr[i];
	arr[i]=arr[j];
	arr[j]=tmp;
}

void BubbleSort(vector<int> &arr){//冒泡排序 --交换类 
	for(int i=1;i<arr.size();i++){
		for(int j=arr.size()-1; j>=i;j--){
			if(arr[j]<arr[j-1]){
				swap(arr,j,j-1);
			}
		}
	}	 
} 

void QuickSort(int s[], int l, int r)//快速排序 --交换类 
{
    if (l < r)
    {      
      int i = l, j = r, x = s[l];
        while (i < j)
        {
            while(i < j && s[j] >= x) // 从右向左找第一个小于x的数
                            j--; 
            if(i < j)
                            s[i++] = s[j];
                    
            while(i < j && s[i] < x) // 从左向右找第一个大于等于x的数
                            i++; 
            if(i < j)
                            s[j--] = s[i];
        }
        s[i] = x;
        QuickSort(s, l, i - 1); // 递归调用
        QuickSort(s, i + 1, r);
    }
}

void change(int arr[], int i, int j){
	int tmp=arr[i];
	arr[i]=arr[j];
	arr[j]=tmp;
}

int getpos(int a[], int l, int r){//获取基准元素的位置 
	int key=a[r];//将最右边元素设为基准
	int pos=l-1;//初始化位置 
	for(int i=l; i<r; i++){
		if(a[i]<=key){
			pos+=1;
			change(a,pos,i);//小于等于的放在同一边 
		}
	} 
	change(a,pos+1,r);//将基准元素交换到基准位置
	return pos+1; 
} 

void qs(int a[], int l, int r){//快排的另一种实现 
	if(l<r){
		int pos=getpos(a,l,r);
		qs(a,l,pos-1);
		qs(a,pos+1,r);
	}
}

void SelectSort(vector<int> &arr){//直接选择排序 --选择类 
	int index=-1; 
	for(int i=0;i<arr.size()-1;i++){
		for(int j=i+1; j<arr.size();j++){
			if (arr[j]<arr[i]){
				swap(arr,j,i);
			}
			
		}
	}
	 
} 


void heapRebuild(int arr[],int root,int size)
{
	int child=2*root+1;
	if(child<=size-1)
	{
		int rightChild=child+1;
		if(rightChild<=size-1)
			if(arr[child]<arr[rightChild])
				child=rightChild;
		if(arr[root]<arr[child])
		{
			int temp=arr[child];
			arr[child]=arr[root];
			arr[root]=temp;
			heapRebuild(arr,child,size);
		}
	}
}
void heapSort(int arr[],int size)//堆排序 --选择类 
{
	for(int i=size-1;i>=0;i--)
	{
		heapRebuild(arr,i,size);//建立堆 
	}
	int last=size-1;
	for(int i=1;i<=size;i++,last--)
	{
		int temp=arr[0];
		arr[0]=arr[last];
		arr[last]=temp;
		heapRebuild(arr,0,last);
		
	}

}

void merge(vector<int>data, int p, int q, int r)
{
	int n1, n2, i, j, k;
    int *left=NULL, *right=NULL;
 
    n1 = q-p+1; 
	n2 = r-q;
 
    left = (int *)malloc(sizeof(int)*(n1)); 
    right = (int *)malloc(sizeof(int)*(n2));
    for(i=0; i<n1; i++)  //对左数组赋值
		left[i] = data[p+i];
    for(j=0; j<n2; j++)  //对右数组赋值
		right[j] = data[q+1+j];
 
    i = j = 0; 
	k = p;
    while(i<n1 && j<n2) //将数组元素值两两比较，并合并到data数组
    {
		if(left[i] <= right[j])
			data[k++] = left[i++];
		else
			data[k++] = right[j++];
    }
 
    for(; i<n1; i++) //如果左数组有元素剩余，则将剩余元素合并到data数组
		data[k++] = left[i];
    for(; j<n2; j++) //如果右数组有元素剩余，则将剩余元素合并到data数组
		data[k++] = right[j];
}
 
void mergeSort(vector<int>data, int p, int r)//归并排序 
{
    int q;
    if(p < r) //只有一个或无记录时不须排序 
    {
		q = (int)((p+r)/2);      //将data数组分成两半   
		mergeSort(data, p, q);   //递归拆分左数组
		mergeSort(data, q+1, r); //递归拆分右数组
		merge(data, p, q, r);    //合并数组
    }
}

void merge1(int a[],int b[], int c[], int la, int lb){
	int i=0, j=0, cnt=0;
	while(cnt<la+lb){
		if(a[i]<b[j]){
			c[cnt++]=a[i++];
		}
		else{
			c[cnt++]=b[j++];
		}
		if(i==la){//a数组已经遍历完毕 
			while(j<lb){
				c[cnt++]=b[j++];
			}
		}
		else if(j==lb){//a数组已经遍历完毕
			while(i<la){
				c[cnt++]=a[i++];
			}
		}
	}
	//cout<< i << ":" << j << ":"<<cnt<< ":" << la << ":" << lb <<endl; 
}

void mergesort1(int a[], int n){
	if(n>1){
		int i=n/2, j=n-n/2;
		int b[n/2],c[n-n/2];
		for(int k=0;k<i;k++){
			b[k]=a[k];
		}
		for(int k=0;k<j;k++){
			c[k]=a[k+i];
		}
		mergesort1(b,i);
		mergesort1(c,j);
		merge1(b,c,a,i,j);
	}
}

void prinarr(vector<int> &arr){
	for (int i=0;i<arr.size();i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

void initarr(vector<int> &pre){
	pre[0]=1;
    pre[1]=2;
    pre[2]=4;
    pre[3]=7;
    pre[4]=3;
    pre[5]=5;
    pre[6]=6;
    pre[7]=8;
} 

int main (){
	vector<int> pre(8);//={1,2,4,7,3,5,6,8};
    initarr(pre);
	InsertSort(pre);
	cout<<"直接插入排序"<<endl;
	prinarr(pre); 
	
	initarr(pre);
	ShellSort(pre);
	cout<<"shell排序"<<endl;
	prinarr(pre); 
	
	initarr(pre);
	BubbleSort(pre);
	cout<<"冒泡排序"<<endl;
	prinarr(pre); 
	
	int array[]={1,2,4,7,3,5,6,8};
	QuickSort(array,0,7);
	cout<<"快速排序"<<endl;
	for (int i=0;i<8;i++){
		cout<<array[i]<<" ";
	}
	cout<<endl;
	
	int array2[]={1,2,4,7,3,5,6,8};
	qs(array2,0,7);
	cout<<"快排解法2"<<endl;
	for (int i=0;i<8;i++){
		cout<<array2[i]<<" ";
	}
	cout<<endl;
	
	initarr(pre);
	SelectSort(pre);
	cout<<"直接选择排序"<<endl;
	prinarr(pre);
	
	int array1[]={1,2,4,7,3,5,6,8};
	heapSort(array1,7);
	cout<<"堆排序"<<endl;
	for (int i=0;i<8;i++){
		cout<<array[i]<<" ";
	}
	cout<<endl;
	
	initarr(pre);
	mergeSort(pre, 0, 7);
	cout<<"归并排序"<<endl;
	prinarr(pre);
	
	int array3[]={1,2,4,7,3,5,6,8};
	mergesort1(array3,7);
	cout<<"归并排序2"<<endl;
	for (int i=0;i<8;i++){
		cout<<array3[i]<<" ";
	}
	cout<<endl;
	
	return 0;
}


