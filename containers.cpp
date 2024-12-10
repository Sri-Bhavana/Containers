
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Customer {
public:
    string name;
    int age;

    Customer(const string& name, int age) : name(name), age(age) {}
};

bool compareAgeAscending(const Customer& c1, const Customer& c2) {
    return c1.age < c2.age;
}
bool compareNameDescending(const Customer& c1, const Customer& c2) {
    return c1.name > c2.name;
}
int main() {
    vector<Customer> customers = {
        Customer("Alice", 30), Customer("Bob", 25),
        Customer("Charlie", 28), Customer("David", 32)
    };
    // display in unsorted order
    for (const auto& customer : customers) {
        cout << "Name: " << customer.name << ", Age: " << customer.age << endl;
    }
    /* Sort the vector using custom comparator - "compareAgeAscending" - so that age appears in ascending order*/
    sort(customers.begin(), customers.end(), compareAgeAscending);

    cout << "\nCustomers sorted by age in ascending order:\n";
    for (const auto& customer : customers) {
        cout << "Name: " << customer.name << ", Age: " << customer.age << endl;
    }


    sort(customers.begin(), customers.end(), compareNameDescending);

    cout << "\nCustomers sorted by name in descending order:\n";
    for (const auto& customer : customers) {
        cout << "Name: " << customer.name << ", Age: " << customer.age << endl;
    }

    return 0;
}

