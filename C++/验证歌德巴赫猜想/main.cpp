#include <iostream>

using namespace std;
int a,p;

int main()
{
    int gotbaha();
    cout<<"����һ������6��ż����������֤��°ͺղ���"<<endl;
    cin>>a;
    if(a>=6&&a%2==0){gotbaha();}
    else{cout<<"δ��Ҫ�����룬������"<<endl;}
return(0);
}
int gotbaha()
{
    int b=1,c=a-b;
    int prime(int x);
    prime(b);
        for(;p=0;)
        {
            b=b+1;
            c=a-b;
            prime(b);
        }
prime(c);
if(p=1)
{cout<<a<<"="<<b<<"+"<<c<<endl;}

return(0);

}

int prime(int x)
{
    int i;
    for(i=2; i<x;)
    {
        if(x%i==0)
        {
            p=0;
            break;
        }
        if(x%i!=0)i=i+1;

    }

    if(i==x)p=1;
    return (p);

}
