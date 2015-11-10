#include<stdio.h>
int main()
{
    char c1[40]={"ECFAJKLBDGHIVWZYMNOPQRSTUX"};
    char c2[40]={"erwqtyghbnuiopsjkdlfazxcvm"};
    int i,j;
    char a;
    int b;
    while(~scanf("%c",&a))
    {
        if(a=='#') break;
        if(a>='A'&&a<='Z')
        {
          b=a-'A'; printf("%c",c1[b]);
        }
        else if(a>='a'&&a<='z')
        {
            b=a-'a';printf("%c",c2[b]);
        }
        else if(a==' ') printf(" ");
        else if(a=='\n') printf("\n");
    }
    return 0;
}
