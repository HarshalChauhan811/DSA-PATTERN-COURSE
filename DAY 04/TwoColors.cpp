// -------------------------------------------------------------
// 🧩 Problem:
// Given an array containing only 0s and 1s,
// sort the array in-place so that all 0s come first
// and all 1s come after.
//
// Example:
// Input:  [1,0,1,0,0,1]
// Output: [0,0,0,1,1,1]
// -------------------------------------------------------------
//
// 🧠 Approach (Two Pointer):
// - Use two pointers: i (left) and j (right).
// - Left side should contain 0s, right side should contain 1s.
// - Traverse while i <= j.
//   - If nums[i] == 0 → it's already correct → move i forward.
//   - If nums[i] == 1 → swap with nums[j] and move j backward.
// - Do NOT move i on swap, because swapped value needs checking.
// -------------------------------------------------------------

void sortTwoColors(vector<int>& nums) {

    int i = 0;                     // left pointer → 0s zone
    int j = nums.size() - 1;       // right pointer → 1s zone

    while (i <= j) {

        if (nums[i] == 0) {
            // 0 is already in the correct region
            i++;
        }
        else {
            // 1 ko right side bhejna hai → swap with j
            swap(nums[i], nums[j]);
            j--;    // right boundary shrink hogi
            // i ko move nahi karte → check swapped element
        }
    }
}

// -------------------------------------------------------------
// ⏱ Time Complexity:  O(n)
// → Single pass algorithm, each element processed once.
//
// 💾 Space Complexity: O(1)
// → Only two integer pointers used, no extra memory.
// -------------------------------------------------------------
