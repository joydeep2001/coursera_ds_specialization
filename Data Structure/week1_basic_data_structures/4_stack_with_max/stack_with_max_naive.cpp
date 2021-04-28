#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <algorithm>

using std::cin;
using std::string;
using std::vector;
using std::cout;
using std::max_element;

class StackWithMax {
    vector<int> stack;


  public:
    int max_val;
    void Push(int value) {
        if(max_val < value)
        {
            stack.push_back(2 * value - max_val);
            max_val = value;

            return;
        }

        stack.push_back(value);


    }

    void Pop() {
        assert(stack.size());
        if(stack.back() > max_val)
        {
            max_val = 2 * max_val - stack.back();
        }
        stack.pop_back();
    }

    int Max() const {
        assert(stack.size());
        return max_val;
    }

};

int main() {
    int num_queries = 0;
    cin >> num_queries;

    string query;
    string value;

    StackWithMax stack;

    for (int i = 0; i < num_queries; ++i) {

        cin >> query;
        if (query == "push") {
            cin >> value;
            if(i == 0)
            {
                stack.max_val = std::stoi(value);
            }
            stack.Push(std::stoi(value));
        }
        else if (query == "pop") {
            stack.Pop();
        }
        else if (query == "max") {
            cout << stack.Max() << "\n";

        }
        else {
            assert(0);
        }
    }
    return 0;
}
