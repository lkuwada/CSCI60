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
    ifstream in("inputDocument.txt");
    if (in.fail())
    {
        cout <<"Can't open in.txt for reading" << endl;
        exit(1);
    }

    int position(0);

    //ideces: string (word in the doc), type of data stored: list<int>
    map<string, list<int> > m;
    string word;

    while (in >> word)
    {
        m[word].push_back(position++);
    }

    for (map<string, list<int> >::iterator i = m.begin(); i != m.end(); ++i)
    {
        cout << i->first << ": ";
        list<int> word_positions = i->second;
        for (list<int>::iterator j = word_positions.begin(); j != word_positions.end(); ++j)
            cout << *j << ", ";
        cout << endl;
    }





    return 0;
}

