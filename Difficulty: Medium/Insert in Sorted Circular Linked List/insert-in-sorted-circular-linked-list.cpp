/* structure for a node
class Node {
 public:
  int data;
  Node *next;

  Node(int x){
      data = x;
      next = NULL;
  }
}; */

class Solution {
  public:
    Node* sortedInsert(Node* head, int data) {
        // code here
         Node* newNode = new Node(data);

        // Case 1: Empty list
        if (head == NULL) {
            newNode->next = newNode;
            return newNode;
        }

        Node* curr = head;

        // Case 2: Insert before head (new minimum)
        if (data < head->data) {
            // Find last node
            while (curr->next != head)
                curr = curr->next;

            curr->next = newNode;
            newNode->next = head;
            return newNode; // new node becomes head
        }

        // Case 3: Insert somewhere after head
        Node* prev = nullptr;
        curr = head;
        do {
            prev = curr;
            curr = curr->next;

            if (data <= curr->data) {
                prev->next = newNode;
                newNode->next = curr;
                return head;
            }
        } while (curr != head);

        // Case 4: Insert at the end (data is largest)
        prev->next = newNode;
        newNode->next = head;
        return head;
    }
};