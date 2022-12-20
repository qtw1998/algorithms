#include <iostream>

using namespace std;

class Student {
private:
    string name;
    int number;
    float score;
public:
    Student();

    Student(string n, int num, float sc);

    ~Student();

    const string &getName() const;

    int getNumber() const;

    float getScore() const;

    void setScore(float score);

    Student operator+(Student &stu);

    Student &operator++();

    const Student operator++(int);

    friend ostream &operator<<(ostream &output, const Student &stu);
};

Student::Student() {

}

Student::Student(string n, int num, float sc) {
    name = n;
    number = num;
    score = sc;
}

Student::~Student() {

}

const string &Student::getName() const {
    return name;
}

int Student::getNumber() const {
    return number;
}

float Student::getScore() const {
    return score;
}

Student Student::operator+(Student &stu) {
    Student tmp;
    tmp.score = this->score + stu.score;
    return tmp;
}

void Student::setScore(float score) {
    Student::score = score;
}

Student &Student::operator++() {
    ++this->score;
    return *this;
}

const Student Student::operator++(int) {
    Student tmp = *this;
    ++(*this);
    return tmp;
}

ostream &operator<<(ostream &output, const Student &stu) {
    output << stu.name << ":" << stu.number << ". Score: " << stu.getScore();
    return output;
}


Student operator-(Student &stu_1, Student &stu_2) {
    Student tmp;
    tmp.setScore(stu_1.getScore() - stu_2.getScore());
    return tmp;
}


int main() {
    Student stu_1("a", 1, 100);
    Student stu_2("b", 2, 50);
    Student stu_new;
    stu_new = stu_1++;
    stu_new.setScore(stu_new.getScore());
    cout << stu_new.getScore() << endl;
    stu_1.getScore();
    cout << stu_1.getScore() << endl;

    cout << endl;
    cout << stu_new << endl;
    return 0;
}