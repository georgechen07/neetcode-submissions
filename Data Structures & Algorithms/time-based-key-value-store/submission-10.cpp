class TimeMap {
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        m[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        int l = 0;
        auto& vec = m[key];
        int r = vec.size() - 1;
        int med;
        if (vec.empty()) {
            return "";
        }
        if (vec[0].second > timestamp) {
            // cout << vec[r].second << '\n';
            return "";
        }
        while (l < r) {
            med = (r + l) / 2;
            // cout << vec[med].first << '\n';
            if (vec[med].second == timestamp) {
                // cout << "this" << vec[med].first << ' ' << vec[med].second << '\n';
                return vec[med].first;
            } else if (vec[med].second > timestamp) {
                r = med - 1;
            } else if (vec[med].second < timestamp) {
                if (vec[med + 1].second > timestamp) {
                    return vec[med].first;
                }
                l = med + 1;
            }
        }

        return vec[r].first;
    }

private:
    unordered_map<string, vector<pair<string, int>>> m;
};
