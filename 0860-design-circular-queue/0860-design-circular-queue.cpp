class MyCircularQueue {
public:
    vector<int> arr;
    int start = -1;
    int end = -1;
    int size;

    MyCircularQueue(int k) {
        arr.resize(k, -1);
        size = k;
    }

    bool enQueue(int value) {
        if (isFull()) return false;

        if (isEmpty()) {
            start = 0;
            end = 0;
        } else {
            end = (end + 1) % size;
        }

        arr[end] = value;
        return true;
    }

    bool deQueue() {
        if (isEmpty()) return false;

        if (start == end) {
            // Queue becomes empty
            start = -1;
            end = -1;
        } else {
            start = (start + 1) % size;
        }

        return true;
    }

    int Front() {
        if (isEmpty()) return -1;
        return arr[start];
    }

    int Rear() {
        if (isEmpty()) return -1;
        return arr[end];
    }

    bool isEmpty() {
        return start == -1;
    }

    bool isFull() {
        return ((end + 1) % size) == start;
    }
};
