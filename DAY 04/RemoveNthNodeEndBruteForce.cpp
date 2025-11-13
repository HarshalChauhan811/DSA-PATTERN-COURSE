class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        // Step 1: Find total length of the linked list
        int length = 0;
        ListNode* temp = head;
        while (temp != nullptr) {
            length++;
            temp = temp->next;
        }

        // Edge Case: If the node to remove is the head itself
        if (n == length) {
            return head->next;
        }

        // Step 2: Move to the (length - n)-th node
        // This node is just before the one we want to delete
        temp = head;
        for (int i = 1; i < length - n; i++) {
            temp = temp->next;
        }

        // Step 3: Skip the target node
        temp->next = temp->next->next;

        return head;
    }
};

// ---------------------------------------------------------
// 📌 APPROACH (Length Method):
// 1. Linked list ki total length count karo.
// 2. Agar n == length → head ko remove karna hai → head->next return.
// 3. Warna (length - n)-th node tak jao (ye delete wale node ka previous hoga).
// 4. Uska next pointer: temp->next = temp->next->next se skip kar do.
// 5. List modify ho jaayegi.
//
// 📌 Time Complexity:  O(L)
//     → Ek baar length find karne ka loop,
//       ek baar delete position tak jaane ka loop.
//
// 📌 Space Complexity: O(1)
//     → No extra space used, sirf pointers hi use kiye.
//
// ---------------------------------------------------------
