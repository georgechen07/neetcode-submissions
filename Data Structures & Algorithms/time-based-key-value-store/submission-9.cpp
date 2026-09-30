class TimeMap {
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        m[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        int l = 0;
        int r = m[key].size() - 1;
        int med;
        if (m[key].empty()) {
            return "";
        }
        if (m[key][0].second > timestamp) {
            // cout << m[key][r].second << '\n';
            return "";
        }
        while (l < r) {
            med = (r + l) / 2;
            // cout << m[key][med].first << '\n';
            if (m[key][med].second == timestamp) {
                // cout << "this" << m[key][med].first << ' ' << m[key][med].second << '\n';
                return m[key][med].first;
            } else if (m[key][med].second > timestamp) {
                r = med - 1;
            } else if (m[key][med].second < timestamp) {
                if (m[key][med + 1].second > timestamp) {
                    return m[key][med].first;
                }
                l = med + 1;
            }
        }

        return m[key][r].first;
    }

private:
    unordered_map<string, vector<pair<string, int>>> m;
};
