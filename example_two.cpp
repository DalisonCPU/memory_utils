//Example two, deleting a std::map


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
