#include <iostream>
#include <algorithm>
#include <vector>
#include <string>


using namespace std;

void print(int n)
{
    cout << n << " ";
}

bool even(int n)
{
    return (n % 2 == 0);
}

int main()
{
    vector<string> vec;
    vector<int> v;

    /*for (int i = 0; i < 10; ++i)
        v.push_back(i);


    cout << *max_element(v.begin(), v.end()) << endl; //v.end() points past the end of the vector
    cout << *max_element(v.begin(), v.begin() + 4) << endl;
    cout << *min_element(v.begin() + 5, v.end()) << endl;

    string x("hello"), y("world");
    //cout << max(3, -5) << endl;
    cout << max(x, y) << endl;*/

    vec.push_back("5");
    vec.push_back("1");
    vec.push_back("3");
    vec.push_back("2");
    vec.push_back("4");

    /*for (int i = 0; i < vec.size(); ++i)
    {
        cout << vec[i] << " ";
    }
    cout << endl;

    sort(vec.begin(), vec.end());
    for (int i = 0; i < vec.size(); ++i)
    {
        cout << vec[i] << " ";
    }
    cout << endl;*/

    /*random_shuffle(v.being(), v.end());
    for (int i = 0; i < v.size(); ++i)
        cout<<v[i] << " ";
    cout << endl;

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);

    do
    {
        for (int i = 0; i < v.size(); ++i)
            cout << v[i] << " ";
        cout << endl;

    } while(next_permutation(v.begin(), v.end())); */


    /*v.push_back(3);
    v.push_back(2);
    v.push_back(3);
    v.push_back(1);
    v.push_back(1);

    for (int i = 0; i < v.size(); ++i)
        cout << v[i] << " ";
    cout << endl;

    cout << count(v.begin(), v.end(), 2) << endl; */ //counts the number of times the specified value is present


    //counting the number of even numbers in the vector
    /*v.push_back(3);
    v.push_back(2);
    v.push_back(3);
    v.push_back(1);
    v.push_back(1);
    v.push_back(5);
    v.push_back(4);

    for (int i = 0; i < v.size(); ++i)
        cout << v[i] << " ";
    cout << endl;

    cout << count_if(v.begin(), v.end(), even) << endl;

    //find() function
    if (find(v.begin(), v.end(), 99) == v.end())
        cout << "not in vector" << endl;
    else
        cout << "in vector" << endl;

    //find_if() function
    if (find_if(v.begin(), v.end(), even) == v.end())
        cout << "not in vector" << endl;
    else
        cout << *find_if(v.begin(), v.end(), even) << endl;

    //find returns pointer/index (iterator)
    cout << *find(v.begin(), v.end(), 99) << endl;

    for_each(v.begin(), v.end(), print);
    cout << endl;*/


    /*v.push_back(3);
    v.push_back(21);
    v.push_back(3);
    v.push_back(1);
    v.push_back(1);
    v.push_back(5);
    v.push_back(4);

    vector<int> w(v.size()); //allocate space when using 'copy' function*/

    //copy_backward(v.begin(), v.end(), w.end()); //goes from right to left, so you need the endpoint (same result as 'copy')

    //copy only the even elements
    //remove_copy_if(v.begin(), v.end(), w.begin(), even);

    //replaces the specified value
    //replace_copy(v.begin(), v.end(), w.begin(), 5, 99);

    //for_each(w.begin(), w.end(), print);
    //cout << endl;

    //swapping values
    //swap(v[0], v[1]);

    //reverse vector
    //reverse(v.begin(), v.end());

    //remove
    //remove(v.begin(), v.end(), 5);

    //fill vector with a value
    //fill(v.begin(), v.end(), -1);

    //for_each(v.begin(), v.end(), print);
    //cout << endl;


}

