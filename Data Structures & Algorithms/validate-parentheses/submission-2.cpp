class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        if (s.size() % 2 != 0) {
            return false;
        }
        for (auto const& character : s) {
            if (character == '(' || character == '[' || character == '{') {
                st.push(character);
            } else if (st.empty()) {
                return false;
            } else if (st.top() == '(' && character != ')') {
                return false;
            } else if (st.top() == '[' && character != ']') {
                return false;
            } else if (st.top() == '{' && character != '}') {
                return false;
            } else {
                st.pop();
            }
        }

        return st.empty();
    }
};
