class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int, int> m;
        for (int& num: arr) {
            int r = ((num % k) + k)%k;
            ++m[r];
        }
        for (auto it = m.begin(); it != m.end(); ++it) {
            int target = (k-it->first)%k;
            if (!target) {
                if (m[0]%2) return false;
            } else {
                if (it->second != m[target]) return false;
            }
        }
        return true;
    }
};