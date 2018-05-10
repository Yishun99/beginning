#include<iostream>
#include<sstream>
#include<cstring>
using namespace std;


/*
(1)	istream& getline (istream& is, string& str, char delim);

(2)	istream& getline (istream& is, string& str);
*/

/*
1.
Extracts characters from is and stores them into str until the
delimitation character delim is found (or the newline character, '\n', for (2)).

2.
If the delimiter is found, it is extracted and discarded
(i.e. it is not stored and the next input operation will begin after it)
*/

void test1() {
    string s = "123:dafs:dadfds";
    stringstream ss(s);
    string t1,t2,t3;
    getline(ss, t1, ':');//读取直到:
    getline(ss, t2, ':');
    getline(ss, t3, ':');
    cout<<t1<<" "<<t2<<" "<<t3<<endl;
}

void test2() {
    string name;
    cout << "Please, enter your full name: ";
    getline (cin, name);//读取直到换行
    cout << "Hello, " << name << "!\n";
}
int main() {
    test1();
    //test2();
    return 0;
}
