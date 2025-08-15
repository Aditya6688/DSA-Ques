class MedianFinder {
public:
    std::vector<int> list;

    MedianFinder() {
        // The list is initialized automatically.
    }
    
    void addNum(int num) {
        int insertionPoint = findInsertionPoint(num);
        list.insert(list.begin() + insertionPoint, num);
    }

    double findMedian() {
        int l = list.size();
        if (l == 0) {
            return 0.0;
        }

        if (l % 2 == 1) {
            return list[l / 2];
        } else {
            return (list[l / 2 - 1] + list[l / 2]) / 2.0;
        }
    }

private:
    int findInsertionPoint(int target) {
        int s = 0;
        int e = list.size() - 1;
        int m;

        if (list.empty()) {
            return 0;
        }

        while (s <= e) {
            m = s + (e - s) / 2;
            int midVal = list[m];
            
            if (midVal == target) {
                return m;
            } else if (midVal < target) {
                s = m + 1;
            } else {
                e = m - 1;
            }
        }
        
        return s;
    }
};