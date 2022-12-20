#ifndef ALGORITHMS_STUDENT_H
#define ALGORITHMS_STUDENT_H

#include <iostream>

using namespace std;

struct Student {
    string name;
    int score;

    bool operator<(const Student &otherStudent) {
        return score != otherStudent.score ? score < otherStudent.score : name < otherStudent.name;
    }

    friend ostream &operator<<(ostream &output, const Student &stu) {
        output << "Student: " << stu.name << " " << stu.score << endl;
        return output;
    }
};

#endif //ALGORITHMS_STUDENT_H
