class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if (intervals.empty()) {
        intervals.emplace_back(newInterval);

        return intervals;
    }

    bool inserted = false;
    for (int i = 0; i < intervals.size(); i++) {
        if (intervals[i][0] > newInterval[0]) {
            intervals.insert(intervals.begin() + i, newInterval);
            inserted = true;
            break;
        }
    }

    if (!inserted) {
        intervals.emplace_back(newInterval);
    }

    vector<vector<int>> newIntervals;
    newIntervals.push_back(intervals[0]);

    for (int i = 1; i < intervals.size(); i++) {
        if (newIntervals.back()[1] >= intervals[i][0]) {
            if (newIntervals.back()[1] <= intervals[i][1]) {
                newIntervals.back() = {newIntervals.back()[0], intervals[i][1]};
            }

            continue;
        }

        newIntervals.emplace_back(intervals[i]);
    }

    return newIntervals;  
    }
};