#ifndef PRIMER_H
#define PRIMER_H
// 预处理器变量，防止重复包含

// 声明的集中存放
// 保证所有文件使用给定实体的同一声明
extern int head_int;

void chA();   // 代码
void ch12();  // 输入输出
void ch13();  // 注释
void ch14();  // 控制结构
void ch15();  // 用于演示外部文件
void ch1();

void ch21();  // 基本数据类型
void ch22();  // 字面值常量
void ch23();  // 变量
void ch24();  // const
void ch25();  // 引用
void ch26();  // typedef
void ch27();  // enum
void ch2();

void ch32();  // string
void ch33();  // vector
void ch34();  // iterator
void ch35();  // bitset
void ch3();

void ch41();  // array
void ch42();  // pointer
void ch43();  // character strings
void ch44();  // 3D
void ch4();

void ch5();

void ch6();

// 在编译时会自动被展开，减少函数调用的开销
// 应当放在头文件里面，让编译器能够可见
inline bool compare(int x, int y) { return x < y; }

void ch71();             // declaration
void ch72();             // argument passing
void ch73();             // return
void ch74(int def = 0);  // function declaration
void ch75();             // local objects
void ch76();             // inline
void ch78();             // overload
void ch79();             // pointer to function
void ch7();

void ch81();  // io object
void ch82();  // condition state
void ch83();  // output buffer
void ch84();  // file
void ch85();  // string stream
void ch8();

// sequential container
// string goto 9.6
void ch91();  // define a sequential container
void ch92();  // iterator
void ch93();  // operation
void ch94();  // capacity
void ch96();  // string viewed as a container
void ch97();  // adaptor
void ch9();

// associative container
void chA1();  // pair
void chA3();  // map, associative array
void chA4();  // set
void chA5();  // multimap, multiset
void chA();

void chB2();  // algorithm category
void chB3();  // inserter
void chB5();  // list algorithm
void chB();

void chC2();  // class basic
void chC3();  // name scope
void chC4();  // constructor
void chC();
enum Tokens { INLINE = 128, VIRTUAL = 129 };
#endif