#include <iostream>
#include <string.h>
using namespace std;

int main()
{



    char a[11]="CLASS",b[]="BASE";
    strcat(a,b);
    cout<<a<<endl<<endl;//����2


    string c="CLASS",d="BASE";
    c=c+d;
    cout<<c<<endl;//����3
    return 0;
}
