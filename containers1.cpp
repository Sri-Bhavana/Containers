#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

// Student data structure
struct Student {
    std::string name;
    int age;
};

// Custom comparator to sort students by age first and then by name
bool compareStudents(const Student& student1, const Student& student2) {
    if (student1.age != student2.age) {
        return student1.age < student2.age;
    }
    else {
        return student1.name < student2.name;
    }
}

int main() {
    std::vector<Student> students = {
        {"Alice", 12},
        {"Bob", 13},
        {"Charlie", 12},
        {"David", 14},
        {"Eve", 12}
    };

    // Sort the vector of students using the custom comparator
    std::sort(students.begin(), students.end(), compareStudents);
    std::set<Student, decltype(compareStudents)> studentSet(students.begin(), students.end(), compareStudents);

    // Display the sorted students
    for (const Student& student : students) {
        std::cout << student.name << " (" << student.age << ")" << std::endl;
    }

    return 0;
}