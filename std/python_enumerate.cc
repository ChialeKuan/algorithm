// Author: Huahua
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <tuple>
using namespace std;
 
// Python-Like enumerate() In C++17
// http://reedbeta.com/blog/python-like-enumerate-in-cpp17/
template <typename T,
          typename TIter = decltype(std::begin(std::declval<T>())),
          typename = decltype(std::end(std::declval<T>()))>
constexpr auto enumerate(T && iterable) {
  struct iterator {
    int i;
    TIter iter;
    bool operator != (const iterator & other) const { return iter != other.iter; }
    void operator ++ () { ++i; ++iter; }
    auto operator * () const { return std::tie(i, *iter); }
  };
  struct iterable_wrapper {
    T iterable;
    auto begin() { return iterator{ 0, std::begin(iterable) }; }
    auto end() { return iterator{ 0, std::end(iterable) }; }
  };
  // return iterable_wrapper{ iterable }; // this makes a copy if iterable is a rvalue.
  return iterable_wrapper{ std::forward<T>(iterable) };  
}
 
struct A {
  int val;
  A(int val): val(val) { cout << "A(int)" << endl; }
  A(const A& a): val(a.val) { cout << "A(A&)" << endl; }
  A(A&& a): val(a.val) { cout << "A(A&&)" << endl; }    
};
 
int main(int argc, char** argv) {
  vector<int> arr{1, 2, 4};  
  
  for (size_t i = 0; i < arr.size(); ++i)
    cout << i << " " << arr[i] << endl;
 
  size_t idx = 0;
  for (int v : arr)
    cout << idx++ << " " << v << endl;
 
  for (auto it = begin(arr); it != end(arr); ++it)
    cout << distance(begin(arr), it) << " " << *it << endl;
  
 
  for (const auto& [i, v] : enumerate(arr))
    cout << i << " " << v << endl;
 
  list<string> lst{"hello", "world!"};  
 
  for (const auto& [i, v] : enumerate(lst))
    cout << i << " " << v << endl;
 
  for (const auto& [i, v] : enumerate(string("abcde")))
    cout << i << " " << v << endl;
 
  vector<A> vec;
  vec.reserve(3);
  vec.emplace_back(1);
  vec.emplace_back(2);
  vec.emplace_back(4);
 
  for (const auto& [i, v] : enumerate(vec))
    cout << i << " " << v.val << endl;
 
  for (const auto& [i, v] : enumerate(vector<A>{A(1), A(2), A(4)}))
    cout << i << " " << v.val << endl;
 
  return 0;
}