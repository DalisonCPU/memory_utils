
/**
*Write by Roger in Setember of 2021
* Based in tinymudserver utils....
*https://github.com/nickgammon/tinymudserver
*Suggestions, criticisms, send me one e-mail: rogerlasch@gmail.com
*This library contains some functions to exclude objects and containers.
*use this library at your own risk. You can use and modify this library. No acknowledgment needed, but I'd like something in your documentation.
**/

#ifndef MEMORY_UTILS_H
#define MEMORY_UTILS_H

#include<algorithm>
#include<list>
#include<map>
#include<unordered_map>
#include<vector>

//Delete a single object...
struct DeleteObject
{
public:
/**
*This metod must by used to delete a single object allocated with new operator.
* example:
* int* x=new int;
*Don't use it with arrays!
*int* x=new int[5];//Don't make it!
**/
template<class T>
void operator()(T* ptr)const
{
if(ptr!=NULL)
{
delete ptr;
}
}
/**
*This metod it's simillary with before metod.
*Addictionaly, he can anullate the variable.
*example:
*int* x=new int(5);
*DeleteObject(&x, true);
*This variable will contain null in this result.
**/
template<class T>
void operator()(T** ptr, bool nullobj=false)
{
if((ptr==NULL)||(*ptr==NULL))
{
return;
}
delete *ptr;
if(nullobj==true)
{
*ptr=NULL;
}
}
};

//Delete one maped value on the map
struct DeleteMapObject
{
/**
*This metod delete a pointer on the second member, in the std::pair and anulate the same.
**/
template<class _FIRST, class _SECOND>
void operator()(std::pair<_FIRST, _SECOND>& spair)const
{
if(spair.second!=NULL)
{
delete spair.second;
spair.second=NULL;
}
}
};

//Cleanup a container...
struct DeleteContainer
{
/**
*This metod delete a std::vector of pointers and optionaly, invoque the clean metod.
**/
template<class T>
void operator()(std::vector<T>& vect, bool erase_ctl=false)const
{
struct DeleteObject dobj;
for(auto it=vect.begin(); it!=vect.end(); ++it)
{
dobj(*it);
*it=NULL;//Doesn't work yet.
}
if(erase_ctl==true)
{
vect.clear();
}
}
//This metod work like the previous one.
template<class T>
void operator()(std::list<T>& lst, bool erase_ctl=false)const
{
struct DeleteObject dobj;
for(auto it=lst.begin(); it!=lst.end(); ++it)
{
dobj(*it);
*it=NULL;//Doesn't work one.
}
if(erase_ctl==true)
{
lst.clear();
}
}
//Now, in this metod use to cleanup the std::map, or similary.
template<class T>
void operator()(T& smap, bool erase_ctl=false)const
{
std::for_each(smap.begin(), smap.end(), DeleteMapObject());
if(erase_ctl==true)
{
smap.clear();
}
}
};

//Functions
//Optionaly, some functions to use the structs

//One object...
template<class T>
void _DeleteObject(T* ptr)
{
static struct DeleteObject dobj;
dobj(ptr);
}

template<class T>
void _DeleteObject(T** ptr)
{
static struct DeleteObject dobj;
dobj(ptr, true);
}

template<class T>
void _DeleteContainer(T& scontainer, bool erase_ctl=false)
{
static DeleteContainer dc;
dc(scontainer, erase_ctl);
}

#endif
