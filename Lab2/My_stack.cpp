//
//  My_stack.cpp
//  
//
//  Created by Jared Wheeler on 7/16/16.
//
//
#ifndef _MY_STACK_CPP_
#define _MY_STACK_CPP_
#include "My_stack.h"
#include "assert.h"

//push fuction for the stack, implemented with the vector function push_back
template<class T>
void Stack<T>::push(const T& t)
{
    vec.push_back(t);
}

//pop fuction for the stack, implemented with the vector function pop_back
template<class T>
T Stack<T>::pop()
{
    if (empty())
        throw out_of_range("Stack underflow! ");
    auto x = vec.back();
    vec.pop_back();
    return x;
}

//this peek function simply allows visuals on what is in a given element in a vector index.
template<class T>
int Stack<T>::peek(int &n)
{
    return vec[n];
}

//top fuction for the stack, implemented with the vector function back
template <class T>
T Stack<T>::top() //returns item at top of stack
{
    if(vec.back()<=-1)
        throw runtime_error("Stack underflow! ");
    
    return (vec.back());
}

//overloading the [] allows interaction with elements
template <class T>
char& Stack<T>::operator[](int i) const
{
    if (vec.size() > i && i >= 0)
        return vec[i];
    
    throw runtime_error("Problem with assignment! ");
}

template <class T>
int& Stack<T>::operator[](int j)
{
    if (vec.size() > j && j >= 0)
        return vec[j];
    
    throw runtime_error("Problem with assignment! ");
}

#endif




