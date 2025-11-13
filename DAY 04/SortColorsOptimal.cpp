class Solution {
public:
    void sortColors(vector<int>& nums) {
    int low = 0, mid = 0;
    int high = nums.size() - 1;

    // --------------------------------------------------------
    // 3-pointer approach:
    // low  -> boundary for 0s
    // mid  -> current element to process
    // high -> boundary for 2s
    // --------------------------------------------------------
    while (mid <= high) {

        // Case 1: If element is 0 → send it to the start
        if (nums[mid] == 0) {
            swap(nums[low], nums[mid]);
            low++;      // 0s ka boundary aage move
            mid++;      // next element check
        }

        // Case 2: If it's 1 → already in correct region
        else if (nums[mid] == 1) {
            mid++;      // just move ahead
        }

        // Case 3: If it's 2 → send it to the end
        else { // nums[mid] == 2
            swap(nums[mid], nums[high]);
            high--;     // 2s ki boundary peeche move
            // mid ko increase nahi karte → swapped element phir check hoga
        }
    }
 }
};

// ---------------------------------------------------------
// 📌 Time Complexity:  O(n)
//    → Pure single pass, har element max 1–2 baar touch hota hai.
//
// 📌 Space Complexity: O(1)
//    → No extra data structure, sirf 3 pointers use kiye hain.
// ---------------------------------------------------------
