#include <iostream>
#include <stack>
#include <string>
using namespace std;
struct Bracket {
    Bracket(char type, int position):
        type(type),
        position(position)
    {}

    bool Matchc(char c) {
        if (type == '[' && c == ']')
            return true;
        if (type == '{' && c == '}')
            return true;
        if (type == '(' && c == ')')
            return true;
        return false;
    }

    char type;
    int position;
};

int main() {
    string text;
    getline(cin, text);



    stack <Bracket> opening_brackets_stack;
    for (int position = 0; position < text.length(); ++position) {
        char next = text[position];

        if (next == '(' || next == '[' || next == '{') {
            // Process opening bracket, write your code here
            opening_brackets_stack.push(Bracket(next, position));


        }

        else if (next == ')' || next == ']' || next == '}') {
            // Process closing bracket, write your code here
            if(opening_brackets_stack.size() <= 0)
            {
                cout << position+1;
                return 0;
            }
            Bracket element =  opening_brackets_stack.top();
            opening_brackets_stack.pop();
            if(!element.Matchc(next))
            {
                cout << position+1;
                return 0;

            }

        }
    }

    // Printing answer, write your code here
    if(opening_brackets_stack.size() == 0)
        cout<<"Success";
    else
        cout << opening_brackets_stack.top().position + 1;

    return 0;
}
