class NumberContainers {
public:
    unordered_map<int, int> index_map; // {index -> number}
    unordered_map<int, set<int>> num_map; // {number -> set of indices}

    NumberContainers() {}

    void change(int index, int number) {
        // Agar index pe pehle koi number tha, toh uske index ko remove karna padega
        if (index_map.find(index) != index_map.end()) {
            int old_number = index_map[index];
            num_map[old_number].erase(index);

            // Agar set khali ho gaya toh uss number ko map se hata do
            if (num_map[old_number].empty()) {
                num_map.erase(old_number);
            }
        }

        // Update index_map
        index_map[index] = number;
        num_map[number].insert(index); // Set me index daal do
    }

    int find(int number) {
        if (num_map.find(number) == num_map.end() || num_map[number].empty()) {
            return -1;
        }
        return *num_map[number].begin(); // Min index nikalne ka O(1) ka tareeka
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */