#include <iostream>
#include <stack>
#include <map>
#include <vector>
#include <cmath>
using namespace std;

class Node {
public:
    double num = 0; //操作数
    char op = '+'; //操作符
    bool isop; //true表示操作符，false表示操作数

    Node(int num, bool isop) {
        this->num = num;
        this->isop = false;
    };
    Node(char op, bool isop) {
        this->op = op;
        this->isop = true;
    }
};

// 分别为栈外和栈内操作符优先级
map<char, int> out = { {'#', 0}, {'(', 8}, {'^', 6}, {'*', 4}, {'/', 4}, {'%', 4},
    {'+', 2},{'-', 2},{')', 1} };
map<char, int> inside = { {'#', 0}, {'(', 1}, {'^', 7}, {'*', 5}, {'/', 5}, {'%', 5},
    {'+', 3},{'-', 3},{')', 8} };


// 中缀表达式->后缀表达式
vector<Node> midToBack(string mid) {
    vector<Node> back;
    if (mid.size() == 0) return back;

    // 去空格
    string s;
    for (char c : mid) {
        if (c != ' ')
            s.push_back(c);
    }

    // 处理负数
    if (s[0] == '-') {
        s.insert(0, "0");
    }
    for (int i = 0; i < s.size() - 1; i++) {
        if (s[i] == '(' && s[i + 1] == '-')
            s.insert(i + 1, "0");
    }
    mid = s;

    stack<char> op;
    op.push('#');
    bool flag = false; //记录上次存入的是否为数字
    for (int i = 0; i < mid.size(); i++) {
        if (mid[i] >= '0' && mid[i] <= '9') { // 操作数不进栈
            if (flag == false) {
                flag = true;
                int tmp = mid[i] - '0';
                back.push_back(Node(tmp, false));
            }
            else {
                back.back().num *= 10;
                back.back().num += mid[i] - '0';
            }
        }
        else if (out[mid[i]] > inside[op.top()]) { // 操作符比栈顶操作符优先级高，则进栈
            flag = false;
            op.push(mid[i]);
        }
        else if (out[mid[i]] < inside[op.top()]) { // 操作符比栈顶操作符优先级低，则栈顶操作符出栈
            flag = false;
            back.push_back(Node(op.top(), true));
            op.pop();
            i--;
        }
        else { // 操作符与栈顶操作符优先级相同，则匹配括号
            flag = false;
            op.pop();
        }
    }
    while (op.top() != '#') {
        back.push_back(Node(op.top(), true));
        op.pop();
    }
    return back;
}

// 求解后缀表达式
double getValue(vector<Node> back) {
    if (back.size() == 0) return 0;
    stack<double> nums;
    for (auto e : back) {
        if (!e.isop) {
            nums.push(e.num);
        }
        else {
            double b = nums.top();
            nums.pop();
            double a = nums.top();
            nums.pop();
            double res;
            switch (e.op)
            {
            case '+':
                res = a + b; break;
            case '-':
                res = a - b; break;
            case '*':
                res = a * b; break;
            case '/':
                res = a / b; break;
            case '^':
                res = pow(a, b); break;
            case '%':
                res = int(a) % int(b); break;
            default:
                break;
            }
            nums.push(res);
        }
    }
    return nums.top();
}

double handle(string &infix)
{
    auto back = midToBack(infix);
    int result = getValue(back);

    //init_mapping(op_mapping);
    //vector<string> postfix = toPostfix(infix);
    //double result = calculatePostfix(postfix);
    if (result == 24)
        return true;
    return false;
}


