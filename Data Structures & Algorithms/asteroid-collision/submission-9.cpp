class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> s;
        s.reserve(asteroids.size());
        for (auto ast : asteroids) {
            while (ast < 0 && !s.empty()) {
                if (s.back() > 0) {
                    if (s.back() + ast == 0) {
                        s.pop_back();
                        ast = 0;
                    } else if (s.back() + ast < 0) {
                        s.pop_back();
                    } else {
                        ast = 0;
                    }
                } else {
                    break;
                }
            }
            if (ast != 0) {
                s.push_back(ast);
            }
        }

        // vector<int> res(s.size());
        // int i = 1;
        // while (!s.empty()) {
        //     res[res.size() - i] = s.top();
        //     s.pop();
        //     ++i;
        // }

        s.shrink_to_fit();
        return s;
    }
};