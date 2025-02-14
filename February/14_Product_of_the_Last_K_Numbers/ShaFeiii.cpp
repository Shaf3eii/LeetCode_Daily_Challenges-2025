class ProductOfNumbers { // RunTime: 87.73% , Memory: 43.27%
    vector<int> productPrefix;
    int sz = -1;
    int zeroIdx = -1;
public:
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        sz++;
        if (num == 0) {
            zeroIdx = sz;
            productPrefix.push_back(0);
        } else {
            if (!productPrefix.empty() and productPrefix.back() == 0) {
                productPrefix.push_back(num);
            } else {
                int mul = num * (!productPrefix.empty() ? productPrefix.back() : 1);
                productPrefix.push_back(mul);
            }
        }
    }
    
    int getProduct(int k) {
        if (sz - k + 1 <= zeroIdx) {
            return 0;
        }
        if (sz - k == zeroIdx) {
            return productPrefix[sz];
        } else {
            return productPrefix[sz] / productPrefix[sz - k];
        }
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */





 // Another Solution 
 class ProductOfNumbers { // RunTime: 51.45% , Memory: 93.67%
    vector<int> productPrefix {1};
public:
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        if (num == 0) {
            productPrefix.clear();
            productPrefix.push_back(1);
        } else {
            int mul = num * productPrefix.back();
            productPrefix.push_back(mul);
        }
    }
    
    int getProduct(int k) {
        int sz = (int)productPrefix.size();
        return k < sz ? productPrefix.back() / productPrefix[sz - k - 1] : 0;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */