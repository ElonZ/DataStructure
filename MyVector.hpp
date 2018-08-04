//
//  MyVector.hpp
//  Data Structure Vector
//
//  Created by Ziming on 7/29/18.
//  Copyright © 2018 Ziming. All rights reserved.
//

#ifndef MyVector_hpp
#define MyVector_hpp

#include <stdio.h>
typedef int Rank;
#define DEFAULT_CAPACITY 3
#include <iostream>

template <typename T> class myVector{
private:
    Rank _size;
    int _capacity;
    T* _elem;
    
protected:
    
public:
    myVector(int c = DEFAULT_CAPACITY){
        std::cout<< "Constructor 1 used."<<std::endl;
        _elem = new T[_capacity = c];
        _size = 0;
    }
     
    myVector(T * const A, Rank lo, Rank hi){
        std::cout<< "Constructor 2 used."<<std::endl;
        copyFrom(A,lo,hi);
    }
    
    myVector(myVector<T> const& V, Rank lo, Rank hi){
        std::cout<< "Constructor 3 used."<<std::endl;
        copyFrom(V._elem,lo,hi);
    }
    
    void copyFrom(T* const A, Rank lo, Rank hi);
    void printVector();
    void expand();
    void insert(Rank r, T const & A);
    
    T& operator [](Rank r);
    
    void shrink();
    Rank remove(Rank lo, Rank hi);
    Rank remove(Rank indx);
    
    Rank find(T const & e, Rank lo, Rank hi) const;
    
    Rank deduplicate();
    
    template <typename VST>
    void traverse(VST & visit);
    
    ~myVector(){
        std::cout<< "Destructor used."<<std::endl;
        delete [] _elem;
        
    };
};

#endif /* MyVector_hpp */


template <typename T> void myVector<T>::copyFrom(T* const A, Rank lo, Rank hi){
    _elem = new T[_capacity = 2*(hi-lo)];
    _size = 0;
    while(lo<hi){
        _elem[_size++] = A[lo++];
    }
}

template <typename T> void myVector<T>::printVector(){
    int i = 0;
    std::cout<<"Print vector elements"<<std::endl;
    while(i<_size){
        std::cout<<_elem[i++]<<std::endl;
    }
    std::cout<<"Size:"<<_size<<std::endl<<"Capacity:"<<_capacity<<std::endl;
}
template <typename T> void myVector<T>::expand(){
    if (_size < _capacity)
        return;
    _capacity = std::max(_capacity, DEFAULT_CAPACITY);
    T* oldVector = _elem;
    _elem = new T[_capacity <<=1];
    for(int i =0; i<_size;i++)
        _elem[i] = oldVector[i];
    delete [] oldVector;
    std::cout<<"expand method called"<<std::endl;
}

template <typename T> void myVector<T>::insert(Rank r, T const &  A){
    expand();
    for(int i = _size; i > r; i--){
        _elem[i] = _elem[i-1];
    }
    _elem[r] = A;
    _size ++;
}

template <typename T> T& myVector<T>::operator [](Rank r){
    return _elem[r];
}

template <typename T> void myVector<T>::shrink(){
    if (_size >= 0.5 * _capacity)
        return;
    _capacity = std::max(_capacity, DEFAULT_CAPACITY);

    T* oldVector = _elem;
    _elem = new T[_capacity >>=1];
    for(int i =0; i<_size; i++)
        _elem[i] = oldVector[i];
    delete [] oldVector;
    std::cout<<"shrink method called"<<std::endl;
}



template <typename T> Rank myVector<T>::remove(Rank lo, Rank hi){
    if(lo==hi) return 0;
    
    while(hi<_size){
        _elem[lo++] = _elem[hi++];
    }
    _size -= (hi-lo);
    shrink();
    return hi-lo;
    
}
template <typename T> Rank myVector<T>::remove(Rank indx){
    if (indx>=_size){
        std::cout<<"Indx out of range"<<std::endl;
        return -1;
    }
    T e = _elem[indx];
    remove(indx,indx+1);
    return e;
}

template <typename T> Rank myVector<T>::find(T const & e, Rank lo, Rank hi) const{

    while((lo<hi--)&&(_elem[hi]!=e)){
    }
    return hi;
}

template <typename T> Rank myVector<T>::deduplicate(){
    int oldSize = _size;
    Rank i = 1;
    while(i<_size){
        (find(_elem[i], 0, i)<0)? i++:remove(i);
    }
    return oldSize - _size;
    
}

template <typename T>
template <typename VST>
void myVector<T>::traverse(VST& visit){
    
}
