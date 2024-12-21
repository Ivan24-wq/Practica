#include <iostream>
#include <stack>
#include <sstream>
#include <vector>
#include <cctype>
#include <map>

using namespace std;


bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}


int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}


string infixToPostfix(const string& expression) {
    stack<char> operators;
    string postfix;
    
    for (size_t i = 0; i < expression.length(); i++) {
        char token = expression[i];
        
        if (isdigit(token)) { 
            postfix += token;
            while (i + 1 < expression.length() && isdigit(expression[i + 1])) {
                postfix += expression[++i]; 
            }
            postfix += ' '; 
        } else if (token == '(') { 
            operators.push(token);
        } else if (token == ')') { 
            while (!operators.empty() && operators.top() != '(') {
                postfix += operators.top();
                postfix += ' ';
                operators.pop();
            }
            operators.pop(); // Убираем '('
        } else if (isOperator(token)) { 
            while (!operators.empty() && precedence(operators.top()) >= precedence(token)) {
                postfix += operators.top();
                postfix += ' ';
                operators.pop();
            }
            operators.push(token);
        }
    }
    
    
    while (!operators.empty()) {
        postfix += operators.top();
        postfix += ' ';
        operators.pop();
    }
    
    return postfix;
}

double evaluentePostfix(const string& postfix){
    stack <double> operands;
    istringstream iss(postfix);
    string token;

    while(iss >> token){
        if(isdigit(token[0])){
            double b = operands.top(); operands .pop();
            double a = operands.top(); operands.pop();
            switch(token[0]){
                case '+': operands.push(a+b); break;
                case '-': operands.push(a-b); break;
                case '*': operands.push(a*b); break;
                case '/': operands.push(a/b); break;
            }
        }
    }
    return operands.top();
}

int main(){
    setlocale(LC_ALL, "RU");
    string infixExpression;
    cout << "Введите выражение";
    cin >> infixExpression;
    string postfix = infixToPostfix(infixExpression);
    cout << "ОПН " << postfix << endl;
    double result = evaluentePostfix(postfix);
    cout << "Результат " << result << endl;
    return 0;
}
