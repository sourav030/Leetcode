class ProductOfNumbers {
public:
    vector<int> prefix;  // Prefix product store karega
    ProductOfNumbers() {
        prefix = {1}; // Initialize with 1 for easier division
    }
    
    void add(int num) {
        if (num == 0) {
            // Zero aaya to pura reset kar do
            prefix = {1};
        } else {
            prefix.push_back(prefix.back() * num);
        }
    }
    
    int getProduct(int k) {
        int n = prefix.size();
        if (k >= n) {
            return 0; // Agar k available elements se bada hai to zero return karo
        }
        return prefix[n-1] / prefix[n-1-k];
    }
};
