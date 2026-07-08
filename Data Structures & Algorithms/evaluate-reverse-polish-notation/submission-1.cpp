class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> order;
        for (auto const& str : tokens) {
            if (str == "+") {
                int temp = stoi(order.top());
                order.pop();
                temp += stoi(order.top());
                order.pop();
                order.push(to_string(temp));
            } else if (str == "-") {
                int temp = -stoi(order.top());
                order.pop();
                temp += stoi(order.top());
                order.pop();
                order.push(to_string(temp));
            } else if (str == "*") {
                int temp = stoi(order.top());
                order.pop();
                temp *= stoi(order.top());
                order.pop();
                order.push(to_string(temp));
            } else if (str == "/") {
                int temp = stoi(order.top());
                order.pop();
                temp = stoi(order.top()) / temp;
                order.pop();
                order.push(to_string(temp));
            } else {
                order.push(str);
            }
        }

        return stoi(order.top());
    }
};
