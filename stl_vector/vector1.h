#include <memory>
#include <iostream>
//参考http://blog.csdn.net/l04205613/article/details/8243773 
typedef size_t size_type;//大小类型

template <typename T>
class vector1{
	public:
        vector1();//默认构造函数 
        vector1(size_type n, T value);//有参构造函数 
        vector1(size_type n);//有参构造函数 
        vector1(vector1& v);//拷贝构造函数 
        virtual ~vector1();
        
        vector1& operator = (const vector1& v);//赋值运算符重载
		T& operator[](size_type i){return *(start + i);};//运算符重载，迭代器 
		
		bool empty() const{ return begin() == end(); };//判断是否为空 
		size_type size() const{return (size_type)(finish - start);};//存储大小 
		size_type capacity() const{return (size_type)(end_of_storage - start);}; //实际空间 
		
		T* begin(){ return start; };//返回头 迭代器 
		T* end(){ return finish;}; //返回尾迭代器 
		//一下是基本操作 
		void insert(T* pos, size_type n, const T& val);//插入 
		void push_back(const T& val);//尾部插入 
		void pop_back();//弹出 
		void erase(T* fir , T* la);//擦除[fir,la)
		void erase(T* pos);//擦除指定位置 
		void clear();//清空

        
	protected:
		T* data;
		T* start;//空间头 
		T* finish;//空间尾 
		T* end_of_storage;//可用空间尾巴
};

template <typename T> 
inline vector1<T>::vector1():start(0),finish(0),end_of_storage(0){
}

template <typename T>
inline vector1<T>::vector1(size_type n, T value){
	start= new T[n];
	finish=start; 
	end_of_storage=start+n;
	
	while(n--){
		*finish++ = value;
	}
}

template <typename T>
inline vector1<T>::vector1(size_type n){
	start= new T[n];
	finish=start; 
	end_of_storage=start+n;
	
	while(n--){
		*finish++ = 0;
	}
}

template <typename T>
inline vector1<T>::vector1(vector1& v){
	start=new T[v.capacity()];
	finish=start;
	end_of_storage=start+v.capacity();
	size_type fi=v.size();
	T* vstart=v.begin();
	while(fi--){
		*finish++=*vstart++;
	}
}

template <typename T> 
vector1<T>::~vector1(){
	delete [] start;
}

template <typename T> 
vector1<T>& vector1<T>::operator=(const vector1& v)
{
	start=new T[v.capacity()]; 
	finish=start;
	end_of_storage=start+v.capacity();
	size_type fi=v.size();
	T* vstart=v.begin();
	while(fi--){
		*finish++=*vstart++;
	}
  	return *this;
}

template <typename T> 
void vector1<T>::insert(T* pos, size_type n, const T& val){
//从pos开始插入n个元素，每个元素的初始值为val 
	T* i=start;//指针 
	T* new_finish;
	T* old_start=start;//记录lao 
	//T* old_finish=finish;//记录老 
	bool needToDestory = false;//扩容标识 
	if(finish+n>end_of_storage){//需要扩容 
		needToDestory=true; 
		const size_type old_size=this->size();
		const size_type len=old_size+n;
		//新的变量 
		start=new T[len];
		new_finish=start;
		end_of_storage=start+len;
	} 
	else{
		new_finish=start;
		end_of_storage=finish+n;
	}
	
	while(i<pos){//插入部分之前 
		*new_finish++=*i++;
	}
	while(n--){//插入部分 
		*new_finish++=val;
	}
	while(i<finish){//插入部分之后 
		*new_finish++=*i++;
	}
	finish=new_finish;
	if(needToDestory==true){
		delete[] old_start;
	} 
}

template <typename T> 
void vector1<T>::push_back(const T& val){//尾部插入 
	insert(finish, 1 , val);
}

template <typename T> 
void vector1<T>::pop_back(){//弹出
	finish->~T();
	finish--;
} 

template <typename T> 
void vector1<T>::erase(T* fir, T* la){
	unsigned int j = end()-la;  
    for(int i=0;i<j;i++){  
        *(fir+i) = *(la+i);  
    }  
    while(end()>fir+j){  
        pop_back();  
    }  

} 
template <typename T> 
void vector1<T>::erase(T* pos){
	erase(pos,pos+1);
}

template <typename T> 
void vector1<T>::clear(){
	erase(begin(),end());
}

