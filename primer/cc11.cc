#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

// 后置返回类型
template <typename R, typename T, typename U>
R add(T t, U u) {
    return (t + u);
}

template <typename T, typename U>
auto add_2(T t, U u) -> decltype(t + u) {
    return t + u;
}

// 显示覆盖
struct Base {
    virtual void some_func(float);
    int integer;
};

// struct Derived : Base {
//    virtual void some_func(int) override; // 这里应该要报错，这是 override
//    的作用
//};

// 空指针常量
void foo(int n) { cout << "You are using a number" << endl; }

void foo(char* cArr) { cout << "You are using a pointer" << endl; }

void show_11() {
    int nArr[5] = {1, 2, 3, 4, 5};
    for (int x : nArr) {
        cout << x << endl;
    }

    auto i = 6, j = 7;
    cout << i << endl;
    auto func = [i, &j](int k) -> int {
        j = 8;
        return i + j + k;
    };
    cout << func(10) << " i:" << i << "j:" << j << endl;

    int a = 10;
    float b = 20.1;
    auto c1 = add<decltype(a + b)>(a, b);
    auto c2 = add_2(a, b);
    cout << c1 << endl;
    cout << c2 << endl;

    // foo(NULL);
    foo(nullptr);

    long long int lli;
    cout << sizeof(lli) << endl;
    cout << sizeof(Base::integer) << endl;

    // 元组访问
    std::tuple<int, int, vector<int>> tupleTest(1, 4, {5, 6, 7, 8});

    // 元组个数
    int tupleTestSize = std::tuple_size<decltype(tupleTest)>::value;
    cout << "tuple size is : " << tupleTestSize << endl;

    auto first = get<0>(tupleTest);
    cout << "first value is : " << first << endl;

    auto second = get<1>(tupleTest);
    cout << "second value is : " << second << endl;

    auto third = get<2>(tupleTest);
    for (const auto& iter : third) {
        cout << "third value is : " << iter << endl;
    }

    auto catTupleTest = make_tuple(1, 4);
    // 元组合并
    auto newTuple = std::tuple_cat(catTupleTest, tupleTest);
    int newTupleSize = std::tuple_size<decltype(newTuple)>::value;
    cout << "after cat, new tuple size is : " << newTupleSize << endl;
}