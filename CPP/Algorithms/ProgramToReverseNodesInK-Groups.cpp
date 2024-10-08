#include <iostream>
using namespace std;

// Definition for singly-linked list node
struct ListNode {
    int val;
    ListNode* next;

    // Constructor to create a new node
    ListNode(int x) : val(x), next(NULL) {}
};

// Class Solution containing the function to reverse nodes in k-groups
class Solution {
public:
    // Function to reverse the nodes of a linked list in groups of size k
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL) // Base case: if the list is empty, return NULL
            return NULL;

        // Check if there are at least k nodes left in the list
        ListNode* check = head;
        for (int i = 0; i < k; i++) {
            if (check == NULL) // If less than k nodes, return the head as is
                return head;
            check = check->next;
        }

        // Initialize pointers for the current, previous, and forward nodes
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* forward = NULL;

        // Reverse the first k nodes
        for (int i = 0; i < k; i++) {
            forward = curr->next;  // Store the next node
            curr->next = prev;     // Reverse the current node's pointer
            prev = curr;           // Move prev to current
            curr = forward;        // Move to the next node
        }

        // Recursively reverse the remaining list and connect it to the current group
        head->next = reverseKGroup(forward, k);

        // Return the new head of the reversed group
        return prev;
    }
};

// Helper function to insert a new node at the end of the linked list
ListNode* insertNode(ListNode* head, int value) {
    ListNode* newNode = new ListNode(value);
    if (head == NULL) {
        return newNode; // If list is empty, return new node as the head
    }

    ListNode* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

// Helper function to print the linked list
void printList(ListNode* head) {
    ListNode* temp = head;
    while (temp != NULL) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    int n, k, value;

    // Input number of nodes in the linked list
    cout << "Enter the number of nodes in the linked list: ";
    cin >> n;

    ListNode* head = NULL;

    // Input the values of the linked list nodes
    cout << "Enter the values of the nodes in the linked list: ";
    for (int i = 0; i < n; i++) {
        cin >> value;
        head = insertNode(head, value); // Insert each node
    }

    // Input the value of k
    cout << "Enter the value of k: ";
    cin >> k;

    // Create an object of the Solution class
    Solution sol;

    // Call the reverseKGroup function and get the new head of the modified list
    head = sol.reverseKGroup(head, k);

    // Output the modified list
    cout << "Modified linked list after reversing every " << k << " nodes: ";
    printList(head);

    return 0;
}
