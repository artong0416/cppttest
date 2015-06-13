#include <iostream>
using namespace std;
class X{
   int i;
public:
   X(int ii=0){i=ii;}
   X operator   +(const X &rx){
       i+=rx.i;
       return X(i);
   }
   int GetI(){return i;}
};
int main(){
   X a(1),b(3);
   cout<<(a+b).GetI()<<endl;
   return 0;
}

