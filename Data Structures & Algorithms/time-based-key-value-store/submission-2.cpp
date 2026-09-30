class TimeMap {
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        m[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        pair<string, int> res = {"", -1};
        for (auto const& [value, time] : m[key]) {
            if (time <= timestamp && time >= res.second) {
                res.second = time;
                res.first = value;
            }
        }

        return res.first;
    }

private:
    unordered_map<string, vector<pair<string, int>>> m;
};
