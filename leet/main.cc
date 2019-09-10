#include<iostream>
#include<cstdlib>
#include"solutions.h"
#include"algorithms.h"
#include"primer.h"
#include"courses.h"

#include <fstream>
#include <string>
#include<vector>

using namespace std;

int modular(int a, int b, int n) {
    int res = 1;
    vector<int> b_bytes_reverse;
    while (b>0) {
        b_bytes_reverse.push_back(b % 2);
        b /= 2;
    }
    for (auto i = 0; i < b_bytes_reverse.size(); i++) {
        res = (res * res) % n;
        if (b_bytes_reverse[i])
            res = (res * a) % n;
    }
    return res;
}

int main(){

    //show_11();
    //type_test();
    //a1();
    //a2();
    //a3();
    //a4();
    
    //ch1();
    //ch2();
    //ch3();
    //ch4();
    //ch5();
    //ch6();
    //ch7();
    //ch8();
    //ch9();
    //chA();
    //chB();
    //chC();
    ch35();
    //cout << modular(3, 13, 10) << endl;
    //software_security();

    //t4();
    //t5();
    //t6();
    //t7();
    //t14();

    //max_subarray();
    //t40();

    // 实际上是调用了 PAUSE 这个程序，使用了 execv()
    system("PAUSE");        // cstdlib
    return EXIT_SUCCESS;    // cstdlib
}