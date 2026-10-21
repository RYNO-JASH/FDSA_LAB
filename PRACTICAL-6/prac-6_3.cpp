#include <iostream>
#include <string>
#include <stack>
#include <cctype>
using namespace std;

// Practical 6 - Problem 3: Calculator Infix to Postfix Expression Conversion
// Helper function to return operator precedence
int getPrecedence(char op) {
    if (op == '^')
        return 3;
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return -1;
}

// Helper function to check operator associativity
// Returns true if right-associative (e.g. '^')
bool isRightAssociative(char op) {
    return op == '^';
}

// Function to convert infix expression to postfix expression
string infixToPostfix(const string& infix) {
    stack<char> st;
    string postfix = "";

    for (size_t i = 0; i < infix.length(); i++) {
        char ch = infix[i];

        // Skip whitespace characters
        if (isspace(ch)) {
            continue;
        }

        // If character is an operand (letter or digit), append to output
        if (isalnum(ch)) {
            postfix += ch;
        }
        // If opening bracket '(', push to stack
        else if (ch == '(') {
            st.push(ch);
        }
        // If closing bracket ')', pop until '(' is encountered
        else if (ch == ')') {
            while (!st.empty() && st.top() != '(') {
                postfix += st.top();
                st.pop();
            }
            if (!st.empty() && st.top() == '(') {
                st.pop(); // Pop the '('
            } else {
                cout << "\nWarning: Mismatched parentheses in expression!" << endl;
            }
        }
        // If character is an operator (+, -, *, /, ^)
        else {
            while (!st.empty() && st.top() != '(' &&
                   (getPrecedence(st.top()) > getPrecedence(ch) ||
                   (getPrecedence(st.top()) == getPrecedence(ch) && !isRightAssociative(ch)))) {
                postfix += st.top();
                st.pop();
            }
            st.push(ch);
        }
    }

    // Pop all remaining operators from the stack
    while (!st.empty()) {
        if (st.top() == '(') {
            cout << "\nWarning: Mismatched parentheses in expression!" << endl;
            st.pop();
            continue;
        }
        postfix += st.top();
        st.pop();
    }

    return postfix;
}

int main() {
    cout << "===== Practical 6 - Problem 3: Infix to Postfix Converter =====" << endl;
    cout << "Enter infix expression (e.g., (3+4)*2 or a+b*(c^d-e)): ";
    string infix;
    getline(cin, infix);

    string postfix = infixToPostfix(infix);
    cout << "\nOriginal Infix Expression   : " << infix << endl;
    cout << "Converted Postfix Expression: " << postfix << endl;

    return 0;
}
