/*
 * @Description: fstream
 * @Author: Chiale
 * @Date: 2019-09-16 10:24:40
 * @LastEditTime: 2019-09-16 10:26:53
 */
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, const char * argv[]){
  fstream f("./demo.cc");
  string s;
  f >> s;
  cout<< s<<endl;
  f.close();
  return 0;
}