
#include<iostream>

using namespace std;

char *ptr="Hello world";

int main()
{
  char *pt=ptr;
  if(*pt!='\0')
  {
    ++ptr;
    main();
    printf("%c",*pt);
  }
  
  return 0;

}
