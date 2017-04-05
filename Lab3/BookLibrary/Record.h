//
//  Record.h
//  Wheeler-Jared-A3
//
//  Created by Jared Wheeler on 7/28/16.
//  Copyright (c) 2016 Jared Wheeler. All rights reserved.
//

#ifndef Wheeler_Jared_A3_Record_h
#define Wheeler_Jared_A3_Record_h
#include<string>
#include<iostream>
#include<vector>
#include <fstream>
using namespace std;

class Record
{
    
public:
    //all are string. Template power!
    string book_title;
    string author_first;
    string author_last;
    string ibsn;
    string year;
    string edition;
    
    //assign to variables
    Record& operator =(const Record& r)
    {
        book_title = r.book_title;
        author_first = r.author_first;
        author_last = r.author_last;
        ibsn = r.ibsn;
        year = r.year;
        edition = r.edition;
        
        return *this;
    }
    //supports sorting
    bool operator<(const Record& r)
    {
        if (book_title < r.book_title)
            return true;
        if (book_title == r.book_title && edition < r.edition)
            return true;
        if (book_title == r.book_title && edition == r.edition && ibsn < r.ibsn)
            return true;
        return false;
    }
    
};


//output stream changed to fit the file printing
ostream& operator<<(ostream& out, Record& r)
{
    out << r.book_title << endl
    << r.author_first << " "
    << r.author_last << endl
    << r.ibsn << endl
    << r.year << endl
    << r.edition << endl;
    return out;
}

//assign the lines in the file to their variables
istream& operator>>(istream& in, Record& r)
{
    string temp;
    
    getline(in,temp);
    r.book_title = temp;
    
    getline(in, temp);
    r.author_first = temp;
    
    getline(in, temp);
    r.author_last = temp;
    
    getline(in, temp);
    r.ibsn = temp;
    
    getline(in, temp);
    r.year = temp;
    
    getline(in, temp);
    r.edition = temp;
    
    in.ignore();
    return in;
}

#endif