memory_utils A simple library to help delete some pointers

/**
*Write by Roger in Setember of 2021
* Based in tinymudserver utils....
*https://github.com/nickgammon/tinymudserver
*Suggestions, criticisms, send me one e-mail: rogerlasch@gmail.com
*This library contains some functions to exclude objects and containers.
*use this library at your own risk. You can use and modify this library. No acknowledgment needed, but I'd like something in your documentation.
**/


Example of use:

example one... Deleting a simple object...


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


Example two, deleting a std::map


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

void init_map(map<int, Test*>& ts, int n)
{
static int x=0;
for(int i=0; i<n; i++)
{
x++;
ts.insert(make_pair(i, new Test(x)));
}
}

int main()
{
map<int, Test*> t1;
map<int, Test*> t2;
map<int, Test*> t3;
cout<<"Initializing the t1..."<<endl;
init_map(t1, 5);
cout<<"Initializing the t2..."<<endl;
init_map(t2, 5);
cout<<"Initializing the t3..."<<endl;
init_map(t3, 5);
cout<<"Deleting map with a struct..."<<endl;
DeleteContainer dc;
dc(t1);
cout<<"Deleting with function..."<<endl;
_DeleteContainer(t2);
cout<<"Deleting with a for_each..."<<endl;
for_each(t3.begin(), t3.end(), DeleteMapObject());
return 0;
};
