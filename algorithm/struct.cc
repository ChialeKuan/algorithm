
#include <iostream>
#include <string>
#include <vector>

using namespace std;
struct StudentInfo {
  char school_name[100];
  char gender;
  int age;
  bool is_absent;
};

typedef std::vector<StudentInfo> StudentInfoVec;

void print(StudentInfoVec* students) {
  for (int j = 0; j < (*students).size(); j++) {
    std::cout << (*students)[j].school_name << "\t" << (*students)[j].gender
              << "\t" << (*students)[j].age << "\t" << (*students)[j].is_absent
              << "\t" << std::endl;
  }
  return;
}

int main() {
  StudentInfo micheal = {"Micheal", 'm', 18, false};
  StudentInfo cherry = {"Cherry", 'f', 16, true};
  StudentInfoVec studentinfovec;
  studentinfovec.push_back(micheal);
  studentinfovec.push_back(cherry);
  print(&studentinfovec);
  return 0;
}