#include <iostream>
#include <queue>
using namespace std;

int main()
{

    deque<int> D;

    D.push_back(1);
    D.push_back(2);
    D.push_back(3);
    D.push_back(4);

    D.push_front(4);
    D.push_front(3);
    D.push_front(2);
    D.push_front(1);

    // 1 2 3 4 1 2 3 4

    D.pop_back();

    D.pop_front();

    // Printing the last element
    cout << "Last Element : " << D.back() << endl;

    // Printing the first element
    cout << "First Element : " << D.front() << endl;

    // Printing the size
    cout << "Size : " << D.size() << endl;
}