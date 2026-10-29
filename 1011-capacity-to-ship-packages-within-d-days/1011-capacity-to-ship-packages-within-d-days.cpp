
class Solution {
public:
    bool canShip(vector<int>& weights, int days, int capacity) {
        int requiredDays = 1;
        int currentLoad = 0;

        for (int weight : weights) {
            if (currentLoad + weight > capacity) {
                requiredDays++;
                currentLoad = 0;
            }

            currentLoad += weight;
        }

        return requiredDays <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int start = *max_element(weights.begin(), weights.end());
        int end = accumulate(weights.begin(), weights.end(), 0);

        while (start < end) {
            int mid = start + (end - start) / 2;

            if (canShip(weights, days, mid)) {
                end = mid;
            } else {
                start = mid + 1;
            }
        }

        return start;
    }
};
