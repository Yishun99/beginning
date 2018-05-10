// set::insert (C++98)
#include <iostream>
#include <set>

using namespace std;

int main ()
{
  set<int> myset;
  set<int>::iterator it;
  pair<set<int>::iterator, bool> ret;
  // set some initial values:
  for (int i=1; i<=5; ++i)
    myset.insert(i*10);    // set: 10 20 30 40 50

  ret = myset.insert(20);               // no new element inserted

  if (ret.second==false)
    it=ret.first;  // "it" now points to element 20

  myset.insert (it, 25);                 // max efficiency inserting
  myset.insert (it, 24);                 // max efficiency inserting
  myset.insert (it, 26);                 // no max efficiency inserting

  int myints[]= {5,10,15};              // 10 already in set, not inserted
  myset.insert (myints,myints+3);

  std::cout << "myset contains:";
  for (it=myset.begin(); it!=myset.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}
