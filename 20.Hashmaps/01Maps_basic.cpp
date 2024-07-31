#include <iostream>
using namespace std;
#include <unordered_map>

int main() {
  // creation of map
  unordered_map<string, int> m;

  // insertion
  pair<string, int> p = make_pair("babbar", 3);
  m.insert(p);

  // searching
  cout << m["babbar"] << endl;
  cout << m.at("babbar") << endl;

  // directly accessing pair without creating it - error - out of the bound
  //  cout << m.at("love") << endl;

  // creating and then accessing the pair
  cout << m["love"] << endl;

  cout << m.at("love") << endl;

  // size
  cout << m.size() << endl;

  // check if key is present or not
  cout << m.count("love") << endl; // this will return 0 if key is not present
                                   // and will return 1 if key is present

  // erase
  cout << m.erase("love") << endl;
  cout << m.size() << endl;

  // traversing
  unordered_map<string, int>::iterator it = m.begin();
  while (it != m.end()){
    cout<<it->first <<" "<< it->second<<endl;
    it++;
  }
}
