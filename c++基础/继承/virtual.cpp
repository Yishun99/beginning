#include<iostream>
using namespace std;
class animal
{
protected:
    int age;
public:
    virtual void print_age(void) = 0;
};
class dog : public animal
{
public:
       dog() {this -> age = 2;}
       ~dog() { }
       virtual void print_age(void)
       {
           cout<<"Wang, my age = "<<this -> age<<endl;
       }
};
class cat: public animal
{
public:
    cat() {this -> age = 1;}    ~cat() { }
    virtual void print_age(void)
    {
        cout<<"Miao, my age = "<<this -> age<<endl;
    }
};
int main(void)
{
    cat kitty;
    dog jd;
    animal * pa;
    int * p = (int *)(&kitty);
    int * q = (int *)(&jd);
    p[0] = q[0];
    pa = &kitty;
    pa -> print_age();
    return 0;
}



/*
 含有虚函数的类的对象在内存的第一项是指向虚函数表的指针

p[0] = q[0];把q的虚表指针赋给了p的第一项

但是后面的内容没有变，age没有变

pa指向kitty，交换指向虚函数表的指针后，pa调用jd的print_age，显示的kitty的age
*/
