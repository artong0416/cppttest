#include <memory>
#include <iostream>
//�ο�http://blog.csdn.net/l04205613/article/details/8243773 
typedef size_t size_type;//��С����

template <typename T>
class vector1{
	public:
        vector1();//Ĭ�Ϲ��캯�� 
        vector1(size_type n, T value);//�вι��캯�� 
        vector1(size_type n);//�вι��캯�� 
        vector1(vector1& v);//�������캯�� 
        virtual ~vector1();
        
        vector1& operator = (const vector1& v);//��ֵ���������
		T& operator[](size_type i){return *(start + i);};//��������أ������� 
		
		bool empty() const{ return begin() == end(); };//�ж��Ƿ�Ϊ�� 
		size_type size() const{return (size_type)(finish - start);};//�洢��С 
		size_type capacity() const{return (size_type)(end_of_storage - start);}; //ʵ�ʿռ� 
		
		T* begin(){ return start; };//����ͷ ������ 
		T* end(){ return finish;}; //����β������ 
		//һ���ǻ������� 
		void insert(T* pos, size_type n, const T& val);//���� 
		void push_back(const T& val);//β������ 
		void pop_back();//���� 
		void erase(T* fir , T* la);//����[fir,la)
		void erase(T* pos);//����ָ��λ�� 
		void clear();//���

        
	protected:
		T* data;
		T* start;//�ռ�ͷ 
		T* finish;//�ռ�β 
		T* end_of_storage;//���ÿռ�β��
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
//��pos��ʼ����n��Ԫ�أ�ÿ��Ԫ�صĳ�ʼֵΪval 
	T* i=start;//ָ�� 
	T* new_finish;
	T* old_start=start;//��¼lao 
	//T* old_finish=finish;//��¼�� 
	bool needToDestory = false;//���ݱ�ʶ 
	if(finish+n>end_of_storage){//��Ҫ���� 
		needToDestory=true; 
		const size_type old_size=this->size();
		const size_type len=old_size+n;
		//�µı��� 
		start=new T[len];
		new_finish=start;
		end_of_storage=start+len;
	} 
	else{
		new_finish=start;
		end_of_storage=finish+n;
	}
	
	while(i<pos){//���벿��֮ǰ 
		*new_finish++=*i++;
	}
	while(n--){//���벿�� 
		*new_finish++=val;
	}
	while(i<finish){//���벿��֮�� 
		*new_finish++=*i++;
	}
	finish=new_finish;
	if(needToDestory==true){
		delete[] old_start;
	} 
}

template <typename T> 
void vector1<T>::push_back(const T& val){//β������ 
	insert(finish, 1 , val);
}

template <typename T> 
void vector1<T>::pop_back(){//����
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

