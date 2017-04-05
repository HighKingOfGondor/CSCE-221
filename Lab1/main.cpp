//
//  main.cpp
//  HWAssignment1
//
//  Created by Jared Wheeler on 7/8/16.
//  Copyright (c) 2016 Jared Wheeler. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stdio.h>
#include <math.h>
using namespace std;

struct Binary
{
public:
    vector<int>vec_assign();
    int b_search(int);
    int get_comp();
private:
    vector<int>powers = {};
    int comparisons = 0;
    
    
};

int Binary::b_search(int f)
{
    int left = 0;
    int right = powers.size();
    int mid = 0;
    for(int i = 0; right >= left; i++)
    {
        comparisons++;
        mid = (left + right)/2;
        if(powers[mid] == f)
            return mid;
        if(powers[mid] < f)
            left = mid + 1;
        else
            right = mid - 1;
    }
    throw range_error("Not found!");
    return NULL;
}

vector<int>Binary::vec_assign()
{
    int max_index = 12;
    for(int i = 0; i < max_index; i++)
        powers.push_back(pow(2, i));
    for(int j = 0; j < powers.size(); j++)
    {
        cout << powers[j] << endl;
        if(!is_sorted(powers.begin(), powers.end()))
            throw "Not sorted";
    }
    return powers;
}

int Binary::get_comp()
{
    return comparisons;
}


int main()
{
    try
    {
        int find_that_number = 2048, how = 0, found = 0;
        Binary b;
        b.vec_assign();
        found = b.b_search(find_that_number);
        how = b.get_comp();
        cout << "Looking for the element that contains the number 2048. " << endl;
        cout << "Found the desired number! It's at element " << found << endl;
        cout << "It took " << how << " comparisons to find! " << endl;
    }
    catch(exception& e)
    {
        cerr << "Problem: " << e.what() << endl;
    }
    catch(...)
    {
        cerr << "Unknown issue" << endl;
    }
}