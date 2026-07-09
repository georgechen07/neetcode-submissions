class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        auto res = vector<int>(temperatures.size());
        
        stack<int> temps;
        temps.push(0);
        for (int i = 1; i < temperatures.size(); ++i) {
            while (!temps.empty() && temperatures[i] > temperatures[temps.top()]) {
                res[temps.top()] = i - temps.top();
                temps.pop();
            }
            temps.push(i);
        }

        return res;
    }
};
