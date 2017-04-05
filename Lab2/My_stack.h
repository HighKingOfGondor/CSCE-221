//
//  My_stack.h
//  Programming Homework 2
//
//  Created by Jared Wheeler on 7/16/16.
//  Copyright (c) 2016 Jared Wheeler. All rights reserved.
//

#ifndef _MY_STACK_H_
#define _MY_STACK_H_
#include <iostream>
#include <vector>
#include <string>
using namespace std;


template<class T>
class Stack {
public:
    Stack(const vector<T>& i) : vec(i) {} //constructor assigns the vector in main() to vec
    int size() const {return vec.size();} //returns the size of the vector
    bool empty() const {return vec.empty();} //find out if the vector is empty
    void push(const T&);
    T pop();
    int peek(int &);
    T top();
    char& operator[](int i) const;
    int& operator[](int i);
private:
    vector<T> vec;  //the vector that the Stack class deals with
};


#endif