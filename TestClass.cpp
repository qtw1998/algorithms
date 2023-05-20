#include <iostream>

class Test {
public:
    static int num_s;

    Test();

    explicit Test(int val);

    Test(const Test &obj);

    void operator=(const Test &obj);

    Test &operator+=(const Test &obj);

    int getValue();

    virtual void print();

    virtual ~Test();

private:
    int *ptr;
};

void Test::print() {
    std::cout << "Test Class..." << std::endl;
}

Test::Test(int val) {
    ptr = new int;
    *ptr = val;
}

Test::Test() : Test(10) {}

Test::Test(const Test &obj) {
    ptr = new int;
    *ptr = *obj.ptr;
}

Test::~Test() {
    std::cout << "delete: " << "Test." << std::endl;
    delete ptr;
}

void Test::operator=(const Test &obj) {
    *ptr = *obj.ptr + 1;
}

int Test::getValue() {
    return *ptr;
}

Test &Test::operator+=(const Test &obj) {
    *ptr += *obj.ptr;
    return *this;
}

class TestSon1 : public Test {
public:
    void print() {
        std::cout << "TestSon1" << std::endl;
    }

    ~TestSon1() {
        std::cout << "delete: " << "TestSon1" << std::endl;
    }
};

class TestSon2 : public Test {
public:
    void print() {
        std::cout << "TestSon2" << std::endl;
    }

    ~TestSon2() {
        std::cout << "delete: " << "TestSon2" << std::endl;
    }
};

int Test::num_s = 2;

int main() {
    Test *test;
    TestSon1 t1;
//    TestSon2 t2;

    test = new TestSon2();
    delete test;
    test->print();

    return 0;
}