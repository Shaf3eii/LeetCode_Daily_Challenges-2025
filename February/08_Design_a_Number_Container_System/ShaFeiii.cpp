class NumberContainers {
    unordered_map<int, set<int>> numbers;
    unordered_map<int, int> usedIdx;
public:
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if (usedIdx.find(index) != usedIdx.end()) {
            int prev = usedIdx[index];
            numbers[prev].erase(index);
        }
        usedIdx[index] = number;
        numbers[number].insert(index);
    }
    
    int find(int number) {
        if (numbers[number].empty()) return -1;
        return *numbers[number].begin();
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */