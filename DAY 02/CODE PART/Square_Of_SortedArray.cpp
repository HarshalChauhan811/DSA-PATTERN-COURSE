class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);         // final sorted squares store karne ke liye
        int left = 0;                  // left pointer (start)
        int right = n - 1;             // right pointer (end)
        int index = n - 1;             // result array me fill karne ke liye (end se)

        // 🔁 Two-pointer approach
        while (left <= right) {
            int leftSquare = nums[left] * nums[left];
            int rightSquare = nums[right] * nums[right];

            // jo square bada hoga, wo end me place hoga
            if (leftSquare > rightSquare) {
                result[index] = leftSquare;
                left++;                // left pointer aage badhao
            } else {
                result[index] = rightSquare;
                right--;               // right pointer peeche lao
            }
            index--;                   // result array me position move karo
        }

        return result;                 // sorted squares array return karo
    }
};

/*
--------------------------------------------
💡 Short Notes (Hinglish me):

🔹 Problem:
   → Given sorted array (may contain negatives)
   → Har element ka square nikalna hai aur sorted order me return karna hai

🔹 Example:
   Input:  [-4, -1, 0, 3, 10]
   Output: [0, 1, 9, 16, 100]

🔹 Approach (Two Pointers):
   1️⃣ Array sorted hai lekin negative numbers ke square bade ho sakte hain  
   2️⃣ Ek pointer start me (left) aur ek end me (right) rakho  
   3️⃣ Dono ke squares compare karo  
   4️⃣ Jo bada ho, usse result ke end me daal do  
   5️⃣ Pointer move karo aur index-- karte jao

🔹 Why Two Pointer?
   → Because max square hamesha extremes pe milega (left ya right)
   → Isliye middle se compare karne ki zarurat nahi

🔹 Time Complexity:  O(n)
   → Har element ek hi baar check hota hai

🔹 Space Complexity: O(n)
   → Ek extra array result store karne ke liye

--------------------------------------------
🔹 Example Dry Run (nums = [-4, -1, 0, 3, 10]):

Step | left | right | left² | right² | result
-----|-------|--------|--------|---------|--------
 1   |  -4  |  10    |  16   |  100    | [ , , , , 100]
 2   |  -4  |   3    |  16   |   9     | [ , , , 16, 100]
 3   |  -1  |   3    |   1   |   9     | [ , , 9, 16, 100]
 4   |  -1  |   0    |   1   |   0     | [ , 1, 9, 16, 100]
 5   |   0  |   0    |   0   |   0     | [0, 1, 9, 16, 100]

✅ Final Output → [0, 1, 9, 16, 100]
--------------------------------------------
*/
