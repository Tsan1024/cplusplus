#include <iostream>
#include <string>

// 基类
class Base {
public:
    int value1;

    // 基类构造函数
    Base(int val) : value1(val) {
        std::cout << "Base Constructor" << std::endl;
    }

    // 虚函数
    virtual void display() const {
        std::cout << "Base Display: " << value1 << std::endl;
    }
};

// 派生类
class Derived : public Base {
public:
    int value2;

    // 使用基类的构造函数进行继承构造
    using Base::Base;

    // 派生类构造函数，增加额外的成员初始化
    Derived(int val1, int val2) : Base(val1), value2(val2) {
        std::cout << "Derived Constructor" << std::endl;
    }

    // 覆盖基类的虚函数
    void display() const override {
        std::cout << "Derived Display: " << value1 << " " << value2 << std::endl;
    }
};

int main() {
    // 使用继承构造函数创建派生类对象
    Derived derivedObj(42, 24);

    // 调用虚函数
    derivedObj.display();

    return 0;
}
