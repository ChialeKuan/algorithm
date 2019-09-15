
#include <iostream>
#include <stack>

struct Quad {
    Quad();
    Quad(int n, char a, char b, char c) : _n(n), _x(a), _y(b), _z(c) {
    }
    int _n; 		// 要移动的盘子数量
    char _x, _y, _z; 	// 保存柱子名称
}; // 保存当前状态

void hanoi(int n, char x, char y, char z)
{
    std::stack<Quad> s;
    s.push(Quad(n, x, y, z));
    while (!s.empty()) {
        Quad q = s.top();
        s.pop();
        n = q._n;
        x = q._x;
        y = q._y;
        z = q._z;
        if (n == 1) {// 单个的结束条件
            std::cout << q._x << "-> " << q._z << std::endl;
        }
        else {
            // 还可以更小
            s.push(Quad(n - 1, y, x, z));
            s.push(Quad(1, x, y, z));
            s.push(Quad(n - 1, x, z, y));
        }
    }
}

void a2() {
    hanoi(3, 'A', 'B', 'C');
}