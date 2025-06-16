class Solution {
public:
    bool check(vector<int>& heights, vector<int>& cost, int mid) {
        long long costMid = 0;
        long long costMidP1 = 0;

        for (int i = 0; i < heights.size(); i++) {
            costMid += 1LL * abs(heights[i] - mid) * cost[i];
            costMidP1 += 1LL * abs(heights[i] - (mid + 1)) * cost[i];
        }

        return costMid < costMidP1;
    }

    int minCost(vector<int>& heights, vector<int>& cost) {
        int s = *min_element(heights.begin(), heights.end());
        int e = *max_element(heights.begin(), heights.end());

        int target_Height = s;

        while (s <= e) {
            int mid = s + (e - s) / 2;

            if (check(heights, cost, mid)) {
                target_Height = mid;
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }

        // Compute the actual cost for target_Height
        long long finalCost = 0;
        for (int i = 0; i < heights.size(); i++) {
            finalCost += 1LL * abs(heights[i] - target_Height) * cost[i];
        }

        return (int)finalCost;
    }
};
