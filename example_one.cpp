//example one... Deleting a simple object...


#include<iostream>
#include"memory_utils.h"

using namespace std;

class Test
{
public:
int id;
Test(int x)
{
this->id=x;
cout<<"Hello world! My name is Test "<<id<<endl;
}
~Test()
{
cout<<"Good bye friend... My name is Test "<<id<<endl;
}
};

int main()
{
Test* t1=new Test(1);
Test* t2=new Test(2);
Test* t3=new Test(3);
cout<<"Deleting a object with a struct..."<<endl;
DeleteObject dobj;
cout<<"This is not null..."<<endl;
dobj(t1);
dobj(&t2, true);
cout<<"T1 is null? "<<boolalpha<<(t1==NULL)<<endl;
cout<<"T2 is null? "<<boolalpha<<(t2==NULL)<<endl;
cout<<"Test two, deleting with a function..."<<endl;
_DeleteObject(&t3);
cout<<"T3 is null? "<<boolalpha<<(t3==NULL)<<endl;
return 0;
};
