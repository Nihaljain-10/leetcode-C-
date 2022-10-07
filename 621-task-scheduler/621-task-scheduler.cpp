class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
          unordered_map<char, int>mp;

for(auto task:tasks){
        mp[task]++;
}
priority_queue<int>maxHeap;
for (auto it : mp) {
	maxHeap.push(it.second);
}
int time = 0;
queue<pair<int, int>>q;
while (!maxHeap.empty() || !q.empty()) {
	time++;
	if (!maxHeap.empty()) {
		int cnt = maxHeap.top();
		maxHeap.pop();
                --cnt;
		if (cnt > 0) {
			q.push({cnt, time+n});
		}
	}

	if (!q.empty() && q.front().second == time) {
                auto temp=q.front();
                q.pop();
		maxHeap.push(temp.first);
	}
}

return time;
    
    }
};