#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <set>
#include <map>
#include <fstream>
#include <cstdlib>

using namespace std;

int main()
{
    //collection of something, never declare just "vector"
    //parameters (number of spaces, initial value)
    //allocates a large space of memory...?
    /*vector<int> v(10);

   for(int i = 0; i < 5; ++i)
   {
       int temp;

       cout << "Enter integer: ";
       cin >> temp;

       //function of vectors. How you add element to end of vector
       v.push_back(temp);

   }

   for(int i = 0; i < 10; ++i)
   {
       cout << v[i] << endl;
   }

   cout << "Size = " << v.size() << endl;

   //removes last element of vector
   v.pop_back();
   cout << "Size = " << v.size() << endl;*/


   /*list<string> l;

   l.push_back("Hello");
   l.push_front("world");
   l.push_back("2013");

   cout << "size = " << l.size() << endl;

   for (list<string>::iterator i = l.begin(); i != l.end(); ++i)
       cout << *i << endl;*/

    /*vector<int> v;
    v.push_back(3);
    v.push_back(2);
    v.push_back(1);

    for(vector<int>::iterator i = v.begin(); i !=v.end(); ++i)
        cout << *i << endl;*/

    /*set<double> s;

    s.insert(3.14159);
    s.insert(2.71828);
    s.insert(-1);
    s.insert(-1);

    for (set<double>::iterator i = s.begin(); i !=s.end(); ++i)
    {
        cout << *i << endl;
    }

    cout << "size of set =" << s.size() << endl;*/

    /*map<string, int> m; //indeces are Strings (first parameter). type of data stored are int (second param)

    m["Monday"] = 200;
    m["Tuesday"] = 400;
    m["Wednesday"] = 500;

    for (map<string,int>::iterator i = m.begin(); i !=m.end(); ++i)
    {
        cout << i->first << ", " << i->second << endl;  // '->' point to location (similar to '*')
    }*/

    /*ifstream in("in.txt");
    if (in.fail())
    {
        cout <<"Can't open in.txt for reading" << endl;
        exit(1);
    }

    string w;
    map<string, int> m;

    while(in >> w)
    {
        m[w]++;
    }

    for (map<string,int>::iterator i = m.begin(); i != m.end(); ++i)
        cout << i->first << ", " << i->second << endl;*/


   return 0;
}

