#include <iostream>
#include <cstdio>
#include <ctime>

int main() {
    std::clock_t start;
    double duration;

    start = std::clock();

    /* Your algorithm here */

    duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;

    std::cout<<"printf: "<< duration <<'\n';
}

