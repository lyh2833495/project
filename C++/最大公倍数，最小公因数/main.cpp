#include <iostream>

using namespace std;
int a,b,n,m;
int main()
{
    cout<<"��������������"<<endl;
    while(cin>>a>>b)
    {int f();
    int g();
    f();
    cout<<"��С������"<<n<<endl<<endl;
    g();
    cout<<"�������"<<m<<endl;}
    return 0;
}

int f()
{
    int i;
    for(i=1,n=a*i; n%b!=0; ++i)
    {
        n=a*i;
    }
    return(n);

}
int g()
{
    int i,m;
    for(i=1,m=a/i; i<a;)
    {
        if(a%i==0)//m�Ƿ�������
        {
            if(b%m==0) break;
            if(b%m!=0)

            {
                i=i+1;
                m=a/i;
            }
        }
        else
        {
            i=i+1;
            m=a/i;
        }

    }
    return(m);
}
