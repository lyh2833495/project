#include <iostream>
#include<stdio.h>
#include<windows.h>
using namespace std;

int main()
{
    int x,a,b,c,d,e;
    cout<<"����һ��С����λ������"<<endl;
    cin>>x;
    if(9999<x&&x<99999)
    {

        a=x/10000;
        b=(x-10000*a)/1000;
        c=(x-10000*a-1000*b)/100;
        d=(x-10000*a-1000*b-100*c)/10;
        e=(x-10000*a-1000*b-100*c-10*d);
        cout<<"��λ"<<a<<endl;
        cout<<"ǧλ"<<b<<endl;
        cout<<"��λ"<<c<<endl;
        cout<<"ʮλ"<<d<<endl;
        cout<<"��λ"<<e<<endl;
        cout<<"����"<<e<<d<<c<<b<<a;
    }
    if(999<x&&x<9999)
    {

        a=0;
        b=(x-10000*a)/1000;
        c=(x-10000*a-1000*b)/100;
        d=(x-10000*a-1000*b-100*c)/10;
        e=(x-10000*a-1000*b-100*c-10*d);

        cout<<"ǧλ"<<b<<endl;
        cout<<"��λ"<<c<<endl;
        cout<<"ʮλ"<<d<<endl;
        cout<<"��λ"<<e<<endl;
        cout<<"����"<<e<<d<<c<<b;
    }
    if(99<x&&x<999)
    {
        a=0;
        b=0;
        c=(x-10000*a-1000*b)/100;
        d=(x-10000*a-1000*b-100*c)/10;
        e=(x-10000*a-1000*b-100*c-10*d);

        cout<<"��λ"<<c<<endl;
        cout<<"ʮλ"<<d<<endl;
        cout<<"��λ"<<e<<endl;
        cout<<"����"<<e<<d<<c;
    }
    if(9<x&&x<99)
    {
        a=0;
        b=0;
        c=0;
        d=(x-10000*a-1000*b-100*c)/10;
        e=(x-10000*a-1000*b-100*c-10*d);


        cout<<"ʮλ"<<d<<endl;
        cout<<"��λ"<<e<<endl;
        cout<<"����"<<e<<d;
    }
    if(0<=x&&x<=9)
    {

        a=0;
        b=0;
        c=0;
        d=0;
        e=(x-10000*a-1000*b-100*c-10*d);


        cout<<"��λ"<<e<<endl;
        cout<<"����"<<e;
    }
    return(0);
}
