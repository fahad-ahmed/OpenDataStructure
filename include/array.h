  /******************************************************
   *  : Fahad Ahmed
   ******************************************************/

#ifndef ARRAY_H
#define ARRAY_H
#include <cstddef>
#include <cmath>
#include <math.h>
#include <stdio.h>
#include <iostream>
using namespace std;
template<class T>
class array
{
    public:
        array<T>();
        array<T>(int len);
        virtual ~array();
        T& operator[](int index);
        array<T>& operator =(array<T> &obj);
        int length;
    protected:
    private:
        T *a;


};

template<class T>
array<T>::array()
{
    length = 0 ;
    //ctor
}

template<class T>
array<T>::array(int len)
{
    a = new T[len];
    length = len ;
    //ctor
}
template<class T>
array<T>::~array()
{
    delete[] a;
    //dtor
}
template<class T>
T& array<T>::operator[](int index)
{
    return a[index];
}

template<class T>
array<T>& array<T>::operator =(array<T> &obj)
{
    if(a!=NULL) delete[] a;
    a = obj.a;
    length = obj.length;
    obj.a = NULL;
    return *this;
}


template<class T>
class arraystack
{
    public:
        arraystack();
        virtual ~arraystack();
        T set(int index , T value);
        T get(int index);
        void add(int i, T value);
        void print();
        void remove(int i);
        void resize();
    protected:
    private:
        array<T> a;
        int n;

};

template<class T>
arraystack<T> :: arraystack()
{
    n = 0;
    //nothing to do in constructor
}
template<class T>
arraystack<T> :: ~arraystack()
{
    //will decide later what to do in destructor
}
template<class T>
T arraystack<T>::set(int index , T value)
{
    T temp = a[index];
    a[index] = value;
    return temp;
    //will set up later
}
template<class T>
T arraystack<T>::get(int index)
{
    return a[index];
    //will setup later
}
template<class T>
void arraystack<T>::add(int index, T value)
{
    //resize code and condition here
    cout<<"add( "<<index<<" , "<<value<<" )"<<endl;
    if((n+1)>a.length) resize();
    for(int i = n ; i>index;i--)
        a[i] = a[i-1];

    a[index] = value;
    n++;
    //add element here
}

template<class T>
void arraystack<T>::remove(int index)
{
    cout<<"remove( "<<index<<" )"<<endl;
    //remove element here
    for(int i=index;i<n;i++)
        a[i] = a[i+1];
    n--;
    if(a.length>=(3*n)) resize();
}

template<class T>
void arraystack<T>::resize()
{
    cout<<"resizing"<<endl;
    array<T> b(max(2*a.length,1));

    for(int i=0;i<a.length;i++)
        b[i] = a[i];
    a=b;
    //resize array stack here
}

template<class T>
void arraystack<T>::print()
{
    cout<<"Array = [";
    for(int i=0;i<n;i++)
        cout<<"-"<<a[i];
    cout<<"-]"<<endl;
}



#endif // ARRAY_H
