class SmallestInfiniteSet {
public:
    priority_queue<int, vector<int>, greater<>> pq;
    unordered_set<int> s;

    SmallestInfiniteSet() {
        for (int i = 1; i <= 1000; i++) {
            pq.push(i);
            s.insert(i);
        }
    }

    int popSmallest() {
        int x = pq.top();
        s.erase(pq.top());
        pq.pop();
        return x;
    }

    void addBack(int num) {
        if (s.find(num) == s.end()) {
            pq.push(num);
            s.insert(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */