#include <iostream>
#include<cmath>
using namespace std;

int main()
{
    int r,h;
    float l,s1,s2,v1,v2;
    double P=3.1415926;
    cout<<"������ �뾶 �� ��"<<endl;
    cin>>r>>h;
    l=2*(P*r);
    s1=P*(P*r*r);
    s2=4*(P*r*r);
    v1=4*(P*r*r*r)/3;
    v2=s1*h;
    cout<<"�ܳ�"<<l<<endl;
    cout<<"Բ�����"<<s1<<endl;
    cout<<"��ı����"<<s2<<endl;
    cout<<"������"<<v1<<endl;
    cout<<"Բ�������"<<v2<<endl;
    return 0;
}
