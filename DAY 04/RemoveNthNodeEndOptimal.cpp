class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        // Do pointers banate hain -> fast & slow
        ListNode* fast = head;
        ListNode* slow = head;

        // -----------------------------------------------------
        // Step 1: Pehle fast pointer ko n steps aage le jaate hain
        // Taaki jab fast end pe पहुंचे, slow delete wale node ke just pehle ho
        // -----------------------------------------------------
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }

        // Agar fast NULL ho gaya, matlab first node hi delete karni hai
        if (fast == NULL) {
            return head->next;
        }

        // -----------------------------------------------------
        // Step 2: Ab fast aur slow ko saath-saath move karte hain
        // Jab fast last node pe hota hai, slow ekdum delete wale ke pehle hota hai
        // -----------------------------------------------------
        while (fast->next != NULL) {
            fast = fast->next;
            slow = slow->next;
        }

        // -----------------------------------------------------
        // Step 3: slow ke next wala hi delete wala node hota hai
        // Pointer ko skip karwa dete hain
        // -----------------------------------------------------
        slow->next = slow->next->next;

        return head;
    }
};

// ---------------------------------------------------------
// 📌 APPROACH (Two Pointer / One-Pass Trick):
//
// - Do pointers banate hain: fast aur slow.
// - Fast ko n steps aage move kar dete hain.
// - Agar fast NULL ho jaye → matlab head ko hi delete karna hai.
// - Phir fast & slow ko ek-saath move karte jao.
// - Jab fast end tak pahunch jata hai, slow bilkul delete wale node ke pehle hota hai.
// - Bas slow->next ko skip kar do → node delete ho jata hai.
//
// Ye method isliye best hai kyunki list ko sirf **1 hi traversal** chahiye.
//
// ---------------------------------------------------------
// 📌 Time Complexity:  O(L)
//     → Pure linked list sirf ek hi baar scan hoti hai.
//
// 📌 Space Complexity: O(1)
//     → Sirf 2 pointers use kiye, koi extra memory nahi.
//
// ---------------------------------------------------------
