/*
 * @Description: Judge Route Circle
 * @Author: Chiale
 * @Date: 2022-03-28 20:26:49
 * @LastEditTime: 2022-03-28 20:44:29
 */

#include <iostream>
#include <map>
#include <string>

using namespace std;

bool judgeCircle_v1(string &moves) {
    int cx{0};
    int cy{0};
    for (const char move : moves) {
        switch (move) {
            case 'U':
                ++cy;
                break;
            case 'D':
                --cy;
                break;
            case 'L':
                --cx;
                break;
            case 'R':
                ++cx;
                break;
        }
    }
    return cx == 0 && cy == 0;
}

bool judgeCircle_v2(string &moves) {
    int cx{0};
    int cy{0};
    map<char, int> dx{{'U', 0}, {'D', 0}, {'L', -1}, {'R', 1}};
    map<char, int> dy{{'U', 1}, {'D', -1}, {'L', 0}, {'R', 0}};
    for (const char move : moves) {
        cx += dx[move];
        cy += dy[move];
    }
    return cx == 0 && cy == 0;
}

int main(int argc, const char *argv[]) {
    string moves;
    while (cin >> moves) {
        cout << judgeCircle_v2(moves) << endl;
    }
}