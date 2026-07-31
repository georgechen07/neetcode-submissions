class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        for (auto const& num : nums) {
            pq_.push(num);
        }
        k_ = k;
    }
    
    int add(int val) {
        pq_.push(val);
        stack<int> temp;
        for (int i = 1; i < k_; ++i) {
            temp.push(pq_.top());
            pq_.pop();
        }

        int res = pq_.top();
        while (!temp.empty()) {
            pq_.push(temp.top());
            temp.pop();
        }

        return res;
    }

private:
    int k_;
    priority_queue<int> pq_;
};

