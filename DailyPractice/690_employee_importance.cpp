#include <vector>
using namespace std;
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        int result = 0;
        Employee * current = getEmployByID(id, employees);
        // self importance
        result += current->importance;
        // child
        for (auto childID : current->subordinates) {
            result += getImportance(employees, childID);
        } 
        return result;   
    }

    Employee * getEmployByID(int id, vector<Employee*> employees) {
        for (auto employ : employees) {
            if (employ->id == id) {
                return employ;
            }
        }
        return nullptr;
    }
};
