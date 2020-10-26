/*
 * @Description: fstream
 * @Author: Chiale
 * @Date: 2019-09-16 10:24:40
 * @LastEditTime: 2020-10-23 10:36:19
 */
#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, const char* argv[]) {
    fstream f("./demo.cc");
    string s;
    f >> s;
    cout << s << endl;
    f.close();
    return 0;
}