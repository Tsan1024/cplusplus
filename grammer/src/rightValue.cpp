#include <iostream>

class Complex {
public:
    // 构造函数声明，参数带有默认值
    Complex(double real = 0.0, double imaginary = 0.0);

    // 重载加法操作符 '+'
    const Complex operator+(const Complex& other) ;

    // 重载减法操作符 '-'
    Complex operator-(const Complex& other) const;

    // 重载乘法操作符 '*'
    Complex operator*(const Complex& other) const;
    Complex& operator+=(const Complex& other);

    // 打印复数值
    void display() const;
    void setReal(double real) {
        this->real = real;
    }

    void setImaginary(double imaginary) {
        this->imaginary = imaginary;
    }

private:
    double real;
    double imaginary;
};

// 构造函数定义，参数带有默认值
Complex::Complex(double real, double imaginary) : real(real), imaginary(imaginary) {}

// 重载加法操作符定义
const Complex Complex::operator+(const Complex& other)  {
    Complex result;
    result.real = this->real + other.real;
    result.imaginary = this->imaginary + other.imaginary;
    return result;
}

// 重载减法操作符定义
Complex Complex::operator-(const Complex& other) const {
    Complex result;
    result.real = this->real - other.real;
    result.imaginary = this->imaginary - other.imaginary;
    return result;
}

// 重载乘法操作符定义
Complex Complex::operator*(const Complex& other) const {
    Complex result;
    result.real = this->real * other.real - this->imaginary * other.imaginary;
    result.imaginary = this->real * other.imaginary + this->imaginary * other.real;
    return result;
}

Complex& Complex::operator+=(const Complex& other) {
    // Complex result;
    this->real = this->real + other.real;
    this->imaginary = this->real + other.imaginary;
    return *this;
}

// 打印复数值定义
void Complex::display() const {
    std::cout << real << " + " << imaginary << "i" << std::endl;
}

int main() {
    // 使用默认值初始化复数对象
    Complex a; // 默认构造函数，a = 0.0 + 0.0i
    a.display();

    // 使用给定值初始化复数对象
    Complex b(2.0, 3.0); // b = 2.0 + 3.0i
    b.display();
    a += b;
    a.display();
    a.setReal(3);
    a.display();
    auto c = a + b;
    c.display();

    return 0;
}
