#include <iostream>
#include <stdexcept>
#include "My_vec.h"

int main() {
    try {
        
        auto su = [](){cout << "Presupposed size: ";};
        // define an object v of My_vec type
        // insert 'B' at the rank 0 into the vector v
        // use the overloaded operator << to display vector elements
        // display the vector v size
        My_vec v;
        v.insert_at_rank(0,'B');
        cout << "Current v: " << v;
        cout << "Testing for v: [B]" << endl;
        cout << "Size of vector v: " << v.get_size() << endl;
        su(); cout << "1" << endl << endl;
        
        // insert 'A' at the rank 0 into the vector v
        // use the overloaded operator << to display vector elements
        // display the vector v size
        v.insert_at_rank(0,'A');
        cout << "Current v: " << v;
        cout << "Testing for v: [A B]" << endl;
        cout << "Size of vector v: " << v.get_size() << endl;
        su(); cout << "2" << endl << endl;

        for(int i = 0; i < 13; i++)
            v.insert_at_rank(i, 'C' + i);
        cout << "Current v: " << v;
        cout << "Testing for v: [C D E F G H I J K L M N O A B]" << endl;
        cout << "Size of vector v: " << v.get_size() << endl;
        su(); cout << "15" << endl << endl;
        
        // insert 'D' at the rank 10 into the vector v
        // use the overloaded operator << to display vector elements
        // display the vector v size
        v.insert_at_rank(10,'D');
        cout << "Current v: " << v;
        cout << "Testing for v: [C D E F G H I J K L D M N O A B]" << endl;
        cout << "Size of vector v: " << v.get_size() << endl;
        su(); cout << "16" << endl << endl;
        
        // remove a character at the rank 2 from the vector v
        // use the overloaded operator << to display vector elements
        // display the vector v size
        v.remove_at_rank(2);
        cout << "Current v: " << v;
        cout << "Testing for v: [C D F G H I J K L D M N O A B]" << endl;
        cout << "Size of v is: " << v.get_size() << endl;
        su(); cout << "15" << endl << endl;
        
        // replace a character at the rank 2 by the character 'E'
        // use the overloaded operator << to display vector elements
        // display the vector v size
        v.replace_at_rank(2,'E');
        cout << "Current v: " << v;
        cout << "Testing for v: [C D E G H I J K L D M N O A B]" << endl;
        cout << "Size of v is: " << v.get_size() << endl;
        su(); cout << "15" << endl << endl;

        // create a copy v1 of the vector v using a copy constructor
        // use the overloaded operator << to display the vector v1
        // replace a character at the rank 2 of the vector v1 with the character 'Y'
        // use the overloaded operator << to display vector v1 elements
        My_vec v1(v);
        cout << "Current v1: " << v1;
        cout << "Testing for v1: [C D E G H I J K L D M N O A B]" << endl;
        v1.replace_at_rank(2,'Y');
        cout << v1;
        cout << "Testing for v1: [C D Y G H I J K L D M N O A B]" << endl << endl;
        
        // define an object v2 of My_vec type
        // insert 'K' at the rank 0 into the vector v2
        // use the overloaded operator << to display vector elements
        // display the vector v2 size
        My_vec v2;
        v2.insert_at_rank(0,'K');
        cout << "Current v2: " << v2;
        cout << "Testing for v2: [K ]" << endl;
        cout << "Size of vector v2: " << v2.get_size() << endl;
        su(); cout << "1" << endl << endl;
        
        // test the assignment operator and copy the vector v1 to v2
        // use the overloaded operator << to display vector v2
        // display the vector v2 size
        v2 = v1;
        cout << "Current v2: " << v2;
        cout << "Testing for v2: [C D Y G H I J K L D M N O A B]" << endl;
        cout << "Size of vector v2: " << v2.get_size() << endl;
        su(); cout << "15" << endl << endl;
        
        // test the function find_max_index using v2
        // test the function sort_max using v2
        cout << "Maximum index of v2: " << find_max_index(v2, v2.get_size()) << endl;
        su(); cout << "2" << endl;
        sort_max(v2);
        cout << "Current v2: " << v2;
        cout << "Testing for v2: [A B C D G H I J K L D M N O Y]" << endl << endl;
        
        // replace in the vector v2 a character at the rank 14 with 'S'
        v2.replace_at_rank(14, 'S');
        cout << "Current v2: " << v2;
        cout << "Testing for v2: [A B C D D G H I J K L M N O S ]";
    }
    
    catch (exception &e)
    {
        cerr << "Error: " << e.what() << endl;
    }
    catch(...)
    {
        cerr << "Unidentified error!" << endl;
    }
}
