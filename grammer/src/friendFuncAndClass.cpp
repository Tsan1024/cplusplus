#include <iostream>

class FriendClass;  // 前向声明

class MyClass {
private:
    int privateMember;

    friend void friendFunction(const MyClass& obj);  // 友元函数声明
    friend void friendFunctionA(MyClass& obj);
    friend class FriendClass;  // 友元类声明

public:
    MyClass(int value) : privateMember(value) {}

    void displayPrivateMember() {
        std::cout << "Private Member: " << privateMember << std::endl;
    }
};

// 友元函数定义
void friendFunction(const MyClass& obj) {
    std::cout << "Friend Function Accessing Private Member: " << obj.privateMember << std::endl;
}

// 友元函数定义
void friendFunctionA(MyClass& obj) {
    obj.privateMember = 12;
    std::cout << "Friend FunctionA Accessing Private Member: " << obj.privateMember << std::endl;
}

// 友元类定义
class FriendClass {
public:
    void accessPrivateMember(const MyClass& obj) {
        std::cout << "Friend Class Accessing Private Member: " << obj.privateMember << std::endl;
    }

    void getPrivateMember(MyClass& obj) {
        obj.privateMember = 13;
        std::cout << "obj privateMember " << obj.privateMember << std::endl;
    }
};

int main() {
    MyClass myObject(42);

    // 使用友元函数访问私有成员
    friendFunction(myObject);

    // 使用友元类访问私有成员
    FriendClass friendObj;
    friendObj.accessPrivateMember(myObject);

    // 使用成员函数访问私有成员
    myObject.displayPrivateMember();
    friendObj.getPrivateMember(myObject);

    return 0;
}


