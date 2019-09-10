/*
 * @Description: 
 * @Author: Chiale
 * @Date: 2019-04-05 13:04:38
 * @LastEditTime: 2019-08-20 15:01:20
 */
#include<iostream>
#include<string>
#include<stdexcept>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::overflow_error;
using std::runtime_error;

int main() {
    // throw runtime_error("Just throw it");
    int i = INT_MAX;
    int j = 1;
    int k;
    try {
        k = i + j;
    }
    catch (overflow_error err) {
        cout << err.what() << endl;
    }
    cout << i << endl;
    cout << j << endl;
    cout << k << endl;

    cout << __FILE__ << endl;
    cout << __LINE__ << endl;
    cout << __TIME__ << endl;
    return 0;   
}
