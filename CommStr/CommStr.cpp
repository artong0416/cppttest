//����ͨ������ַ���ƥ������ 
//luheng 2015.8.20 

#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

bool isMatch(const char* str1, const char* str2)

{
    if (str1 == NULL) return false;
    if (str2 == NULL) return false;
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int xing = 0;//�ǵ�λ�� 
    int p1 = 0, p2 = 0;
    while (p1<len1 && p2<len2)
   {
        if (str2[p2] == '*')
        {
            p2++;
            xing = p2;
            continue;
        }
        if (str1[p1] != str2[p2])
        {
            if (p1 == 0 && p2 == 0)
            {
                return false;
            }
            p1 -= p2 - xing - 1;//p1�ص�ԭ��δƥ�����һ��λ�� ���±Ƚ� 
            p2 = xing;//p2�ص�*���� 
            continue;
        }
        p1++;
        p2++;
    }
     if (p2 == len2)
    { 
        if (p1 == len1)
        {
            return true;
        }
        if (str2[p2 - 1] == '*')
        {
            return true;
        }
    }    
    return true;
}

int main()

{

 char a[100];
 char b[100];
 cin.getline(a,100);
 cin.getline(b,100);
 char *str1 = a;
 char *str2 = b;
 cout<<isMatch(str1,str2);
 return 0;

}

