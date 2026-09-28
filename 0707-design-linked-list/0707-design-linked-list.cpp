class MyLinkedList {
public:
    ListNode* head;
    ListNode* tail;

    MyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    int get(int index) {
        int count = 0;
        ListNode* temp = head;

        while (count < index && temp) {
            temp = temp->next;
            count++;
        }

        return temp ? temp->val : -1;
    }

    void addAtHead(int val) {
        ListNode* new_node = new ListNode(val);

        new_node->next = head;
        head = new_node;

        if (tail == nullptr)
            tail = new_node;
    }

    void addAtTail(int val) {
        ListNode* new_node = new ListNode(val);

        if (tail == nullptr) {
            head = tail = new_node;
            return;
        }

        tail->next = new_node;
        tail = new_node;
    }

    void addAtIndex(int index, int val) {

        if (index == 0) {
            addAtHead(val);
            return;
        }

        ListNode* prev = head;

        for (int i = 1; i < index && prev; i++) {
            prev = prev->next;
        }

        if (!prev)
            return;

        ListNode* new_node = new ListNode(val);

        new_node->next = prev->next;
        prev->next = new_node;

        if (new_node->next == nullptr)
            tail = new_node;
    }

    void deleteAtIndex(int index) {

        if (!head)
            return;

    
        if (index == 0) {
            ListNode* temp = head;
            head = head->next;

            if (head == nullptr)
                tail = nullptr;

            delete temp;
            return;
        }

        ListNode* prev = head;

        for (int i = 1; i < index && prev; i++) {
            prev = prev->next;
        }

        if (!prev || !prev->next)
            return;

        ListNode* temp = prev->next;
        prev->next = temp->next;

        if (temp == tail)
            tail = prev;

        delete temp;
    }
};