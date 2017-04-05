#include "TemplateDoublyLinkedList.h"
#include "Record.h"
#include <iostream>
#include <string>
#include <cstdio>
#include <sstream>
using namespace std;

//This shows what is in the library at the time. Library meaning file.
//O(n) = n
void display(vector<DoublyLinkedList<Record>>& shelf)
{
    for (int i=0; i < shelf.size(); ++i)
    {
        cout << "LIST:" << (i+1) << endl << shelf[i];
        cout << endl << endl;
    }
}
//This checks the book title against the vector to find a spot for the book.
//It takes the first letter of the book, finds the correct node, and inserts it.
//O(1)
void insert_record(vector<DoublyLinkedList<Record>>& v, Record r)
{
    char temp = '0';
    stringstream ss;
    ss << r.book_title;
    ss >> temp;
    int index = temp-65;    //shift for ASCII
    if (index < 0)
    {
        throw "Range Error! Check capitalization. ";
    }
    v[index].insert(r);
}

//Search function. Checks the first letter of the author's last name and finds the correct location
//in the vector before comparing names.
//O(n) = 3n absolute worst case, becasue it has to pass throught the list three times
Record* search_library(vector<DoublyLinkedList<Record>>& v, Record r)
{
    Record* result = new Record;
    char temp = '0';
    stringstream ss;
    ss << r.book_title;
    ss >> temp;             //get first letter of book title
    int i = temp - 65;      //shift
    if (i < 0)
    {
        throw "Range Error! Check capitalization. ";
    }
    DoublyLinkedList<Record> list, list_two;    //making two temporary lists to narrow down the search
    
    DListNode<Record>* pages = v[i].getFirst();
    int tally = 0;
    //start by looking for the book by title
    while(pages != v[i].getAfterLast())
    {
        if (pages->getElem().book_title == r.book_title)
        {
            *result = pages->getElem();
            list.insert(*result);
            ++tally;
        }
        pages = pages->getNext();
    }
    if (tally == 0)
        return NULL;
    if (tally == 1)
        return result;
    cout <<  "Multiple results! There are " << tally << " books with that title! "
    << r.book_title << endl << "Narrowing down the search. Enter the edition of the desired book. \n";
    getline(cin, r.edition);
    tally = 0;
    //This finds the book by edition
    pages = list.getFirst();
    while(pages != list.getAfterLast())
    {
        if (pages->getElem().edition == r.edition)
        {
            *result = pages->getElem();
            list_two.insert(*result);
            ++tally;
        }
        pages = pages->getNext();
    }
    if (tally == 0)
        return NULL;
    if (tally == 1)
        return result;
    cout << "There are " << tally << " books with that title "
    << r.book_title << " and same editions " << r.edition << endl << "Input the ibsn for a match. " << endl;
    getline(cin, r.ibsn);
    tally = 0;
    //This finds the book by ibsn
    pages=list_two.getFirst();
    while(pages != list_two.getAfterLast())
    {
        if (pages->getElem().ibsn == r.ibsn)
        {
            *result=pages->getElem();
            ++tally;
        }
        pages = pages->getNext();
    }
    if (tally == 0)
        return NULL;
    if (tally == 1)
        return result;
    
    return result;
}

//insert a new book into the library
void new_book()
{
    //adds the new book to the file. It will be inserted into the library upon restart
    Record temp;
    string name;
    string first;
    string last;
    string ibsn;
    string year;
    string edition;
    fstream books("Book.txt", std::ios::app);       //put new entry at the bottom of the file
    cin.ignore();
    cout << "Enter book title: ";
    getline(cin, name);
    
    cout << "Enter author's first name: ";
    getline(cin, first);

    cout << "Enter author's last name: ";
    getline(cin, last);

    cout << "Enter IBSN: ";
    getline(cin, ibsn);

    cout << "Enter year: ";
    getline(cin, year);

    cout << "Enter edition: ";
    getline(cin, edition);
    
    //BIG, big error possibility. I have correct the whitespace handling to error free...
    //mostly. It could still possibly happen. If it gives an error, it is likely the fault of how the
    //file is set up. Check that first before trying again.
    books << endl << name << endl;
    books << first << endl;
    books << last << endl;
    books << ibsn << endl;
    books << year << endl;
    books << edition << endl ;
    
    books.close();
}

int main()
try
{
    
    Record temp;
    vector<DoublyLinkedList<Record>> library (26);
    ifstream books("Book.txt");
    char choice = 'y';
    char selection = 'y';
    char add;
    //Construct the library
    //I wanted to do this a little smoother, so that new, user added books could be searched
    //after entry. As it is, you have to restart the program to find them.
    //The definition of a rushed program! This must be how game developers feel! :P
    if(!books.is_open())
        throw 1;
    while (!books.eof())
    {
        books >> temp;
        insert_record(library, temp);
    }
    //Be careful of white space while using the main menu. This could cause a infinite loop, or the program
    //to quit. This is because I haven't been able to implement whitespace handling in time.
    while(selection == 'y')
    {
        int input;
        cout << "**************************** Main Menu ****************************" << endl;
        cout << "Enter number to select option" << endl;
        cout << "1. Display " << endl << "2. Search " << endl << "3. Add " << endl << "4. Quit "<< endl << endl;
        
        cin >> input;
        cin.ignore();
        switch(input)
        {   //display the library
            case 1: display(library); break;
            //search the library
            case 2:     while(choice == 'y')
                        {
                            string name;
                            cout << "Input book title to search, use capital letters where appropriate. " << endl;
                            getline(cin, name);
                            Record input;
                            input.book_title = name;
                            Record* result = search_library(library, input);
                            //if the book isn't in the library
                            //give an option to add it
                            if (result == NULL)
                            {
                                cout << "Match not found. " << endl;
                                cout << "Would you like to add this book to the library? (y/n)" << endl;
                                cin >> choice;
                                if(add == 'y')
                                {
                                    new_book();
                                    cout << "Excellent! The book will be there upon restarting the program. " << endl;
                                }
                            }
                            else
                            cout << "Match found! " << endl << *result;
                            cout << "Find another book? (y/n)" << endl;
                            cin >> choice;
                            cin.ignore();
                        } break;
            //option to add another book
            case 3: new_book(); break;
            //quit
            case 4: break;
        }
        //unfortuately, I didn't have enough time to handle exiting
        //the program better
        //But this works correctly
        cout << "Back to Main Menu? (y/n) " << endl;
        cin >> selection;
    }
    

    books.close();
    
    cout << "Goodbye!" << endl;
        
    if (cin.fail())
        throw 2;
    return 0;
//serveral errors to be caught. This program can be abit buggy.
}
    catch(int & e)
    {
        if (e == 1)
            cerr << "Error! Could not open the file!" << endl;
        if (e == 2)
            cerr << "Error! Check IBSN for correct input!" << endl;
        if(e != 1 || e != 2)
            cerr << "Unknown error! " << endl;
    }
    catch(string & s)
    {
        cerr << s;
    }
    catch(...)
    {
        cerr  << "Unknown error! " << endl;
    }