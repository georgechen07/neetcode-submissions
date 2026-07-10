class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> cars;

        for (int i = 0; i < position.size(); ++i) {
            cars.push_back({position[i], speed[i]});
        }

        auto sort_pos = [](pair<int, int> a, pair<int, int> b) {
            return a.first > b.first; 
        };

        sort(cars.begin(), cars.end(), sort_pos);

        vector<double> arrival_times;

        for (auto const& car : cars) {
            arrival_times.push_back(static_cast<double>(target - car.first) / car.second * 1.0);
        }

        stack<double> fleets;
        for (auto const& time : arrival_times) {
            cout << time << '\n';
            if (fleets.empty() || time > fleets.top()) {
                fleets.push(time);
            }
            cout << "curr top = " << fleets.top() << '\n';
        }

        return fleets.size();
    }
};
