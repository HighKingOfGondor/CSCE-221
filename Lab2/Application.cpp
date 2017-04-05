//
//  main.cpp
//  Programming Homework 2
//
//  Created by Jared Wheeler on 7/16/16.
//  Copyright (c) 2016 Jared Wheeler. All rights reserved.
//

#include "My_stack.h"
#include "My_stack.cpp"
#include <stdexcept>

//This is the function for Algorithm 1
void spans1(Stack<int> &x, Stack<int> &s)
{
    for(int i = 0; i < x.size(); i ++)
    {
        int j = 1;
        while((j <= i) && (x[i-j] <= x[i]))
            j++;
        s.push(j);
    }
}

//This is the function for Algorithm
void spans2(Stack<int> &a, Stack<int> &x, Stack<int> &s)
{
    //int j = 0;
    for(int m = 0; m < x.size(); m++)
    {
        while((!a.empty()) && (x[a.top()] <= x[m]))
        {
            a.pop();
            //j = a.top();
        }
        if(a.empty())
            s[m] = (m+1);
        else
            s[m] = m - a.top();
        a.push(m);
    }
}


int main()
{
    try
    {
        int in;
        bool once = true;
        vector<int>vec;
        Stack<int> x(vec);
        Stack<int> s(vec);
        Stack<int> a(vec);
        
        //Get user input to put through the functions
        cout << "Enter numbers to put on the stack: ";
        while(cin >> in)
        {
            if(once)  //I did this so the message within the loop isn't spammed
            {
                cout << "Enter any character to continue... " << endl;
                once = false;
            }
            x.push(in);
        }
        //output for Algorithms
        cout << "Numbers on Algorithm 1: ";
        spans1(x, s);
        for(int k = 0; k < s.size(); k++)
        {
            cout << s.peek(k);
        }
        cout << endl << "Numbers on Algorithm 2: ";
        spans2(a, x, s);
        for(int n = 0; n < s.size(); n++)
        {
            cout << s.peek(n);
        }
    }
    catch(exception &e)
    {
        cerr << "Error: " << e.what() << endl;
    }
    catch(...)
    {
        cerr << "Undefined error! " << endl;
    }
    return 0;
}
