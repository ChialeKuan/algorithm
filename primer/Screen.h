#pragma once
//#include<string>
//
//using namespace std;
//
//// chapter 12
//
//class Screen {
//public:
//    typedef std::string::size_type index;
//    // ���캯����������Ϊconst
//    Screen(index h, index w){
//        height = h;
//        width = w;
//        contents = string(h * w, '_');
//        cursor = 0;
//        access_ctr = 0;
//    };
//    // �������ÿ���ʵ�� screen.move(4,0).set('#');
//    Screen& move(index r, index c);
//    Screen& set(char);
//    Screen& set(index, index, char);
//    // display overloaded on whether the object is const or not
//    Screen& display(std::ostream& os) {
//        do_display(os); 
//        return *this;
//    }
//    const Screen& display(std::ostream& os) const {
//        // const object will only use the const member
//        do_display(os); 
//        return *this;
//    }
//    // implicitly inline when defined inside the class declaration
//    char get() const { return contents[cursor]; }
//    // explicitly declared as inline; will be defined outside the class declaration
//    inline char get(index ht, index wd) const;
//    // inline not specified in class declaration, but can be defined inline later
//    index get_cursor() const;
//private:
//    std::string contents;
//    index cursor;
//    index height, width;
//    mutable size_t access_ctr; // �ɱ����ݳ�Ա��may change in a const members
//    void do_display(std::ostream& os) const {
//        ++access_ctr;
//        os << contents;
//    }
//
//};
//
//Screen& Screen::set(char c) {
//    contents[cursor] = c;
//    // this ��һ��constָ�룬���Ը����ݣ������Ըĵ�ַ
//    // const ��Ա����ʱ������Ҳ�����Ըģ���һ��ָ��const���͵�constָ��
//    return *this;
//}
//
//Screen& Screen::set(index r, index c, char t) {
//    index row = r * width;
//    cursor = row + c;
//    contents[cursor] = t;
//    return *this;
//}
//
//Screen& Screen::move(index r, index c) {
//    index row = r * width; // row location
//    cursor = row + c;
//    return *this;
//}
//
//// inline declared in the class declaration; no need to repeat on the definition
//char Screen::get(index r, index c) const {
//    index row = r * width;    // compute the row location
//    return contents[row + c]; // offset by c to fetch specified character
//}
//// not declared as inline in the class declaration, but ok to make inline in definition
//inline Screen::index Screen::get_cursor() const {
//    return cursor;
//}
//
//
