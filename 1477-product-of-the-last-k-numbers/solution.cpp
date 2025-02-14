class ProductOfNumbers {
public:
    ProductOfNumbers() {
        products.push_back(1);
    }
    
    void add(int num) {
        if (num == 0) {
            products.clear();
            products.push_back(1);
        } else {
            products.push_back(products.back() * num);
        }
    }
    
    int getProduct(int k) {
        if (k >= products.size()) {
            return 0;
        }
        return products[products.size() - 1] / products[products.size() - 1 - k];
    }

private:
    vector<int> products;
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
