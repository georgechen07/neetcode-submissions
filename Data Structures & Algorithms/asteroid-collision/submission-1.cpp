class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;
        for (auto ast : asteroids) {
            while (ast < 0 && !s.empty()) {
                if (s.top() > 0) {
                    if (s.top() + ast == 0) {
                        s.pop();
                        ast = 0;
                    } else if (s.top() + ast < 0) {
                        s.pop();
                    } else {
                        ast = 0;
                    }
                } else {
                    break;
                }
            }
            if (ast != 0) {
                s.push(ast);
            }
        }

        vector<int> res(s.size());
        int i = 1;
        while (!s.empty()) {
            res[res.size() - i] = s.top();
            s.pop();
            ++i;
        }

        return res;
    }
};