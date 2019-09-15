#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include "primer.h"

using namespace std;

void ch81() {
  wcin.imbue(locale("chs"));
  wcout.imbue(locale("chs"));
  wcout << L"你好，世界" << endl;
  wstring x;
  wcin >> x;
  wcout << x << endl;
}

void ch82() {
  int ival;
  // read cin and test only for EOF;
  // loop is executed even if there are other IO failures
  while (cin >> ival, !cin.eof()) {
    if (cin.bad())  // input stream is corrupted; bail out
      throw runtime_error("IO stream corrupted");
    if (cin.fail()) {                 // bad input
      cerr << "bad data, try again";  // warn the user
      cin.clear(istream::failbit);    // reset the stream
      continue;                       // get next input
    }
    // ok to process ival
  }
  cout << ival;
}

void ch83() {
  // flush for last <<
  cout << "hello world!" << flush;
  // flush for the whole line
  cout << "hello world!" << endl;
  // flush for every <<
  cout << unitbuf << "hello "
       << "world!" << nounitbuf;
  cout << endl;

  // tie will flush cout before cin
  int a;
  cin.tie(&cout);
  ostream* old_tie = cin.tie();
  for (int i = 0; i < 5; i++) {
    cin >> a;
    cout << a << "\n";
  }
}

void ch84() {
  // 存储字符串最好用 string
  string ifile("in.txt");
  string ofile("out.txt");
  string tfile("temp.txt");

  // 但是 IO 是使用字符串
  ifstream infile(ifile.c_str());
  ofstream outfile(ofile.c_str());

  if (!infile) {
    cerr << "error: unable to open input file: " << ifile << endl;
  }

  string a;
  infile >> a;
  outfile << a;

  outfile.close();
  outfile.clear();                            // 清除失败状态
  outfile.open(tfile.c_str(), fstream::app);  // append
  infile >> a;
  outfile << a;
}

void ch85() {
  string s("Chiale Kuan");
  istringstream sstrm(s);
  cout << sstrm.str() << endl;

  sstrm.str("Chiale");
  cout << sstrm.str() << endl;

  int i = 0;
  string line, word;

  while (getline(cin, line)) {
    istringstream stream(line);
    while (stream >> word) {
      cout << ++i << " " << word;
    }
    cout << endl;
  }
}

void ch8() { ch85(); }
