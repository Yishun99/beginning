// constructing vectors
#include <iostream>
#include <vector>
#include<map>
using namespace std;

void constructTwoDim() {
    // first
    int row = 3, col = 4, init_value = 1;
    vector<vector<int>> a(row, vector<int>(col, init_value));
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout<<a[i][j]<<" ";
        }
        cout<<"\n";
    }

    //second
    std::vector<std::vector<int>> b{ { 1, 1, 1 },
                                     { 2, 2, 2 } };

}

int main ()
{
  // constructors used in the same order as described above:
  std::vector<int> first;                               // empty vector of ints
  std::vector<int> second (4, 100);                       // four ints with value 100
  std::vector<int> third (second.begin(),second.end());  // iterating through second
  std::vector<int> fourth (third);                       // a copy of third
  std::vector<int> six = {1, 2, 3, 4, 5};
  // the iterator constructor can also be used to construct from arrays:
  int myints[] = {16,2,77,29};
  std::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );
    fifth.push_back(10);
  std::cout << "The contents of fifth are:";
  for (vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

    constructTwoDim();

    return 0;
}



