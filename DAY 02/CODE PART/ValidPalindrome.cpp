class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0;                   // left pointer (string ke start pe)
        int j = s.length() - 1;      // right pointer (string ke end pe)

        // check characters from both ends
        while (i < j) {
            char left = s[i];
            char right = s[j];

            // agar left char letter ya digit nahi hai to skip karo
            if (!isalnum(left)) {
                i++;
                continue;
            }

            // agar right char letter ya digit nahi hai to skip karo
            if (!isalnum(right)) {
                j--;
                continue;
            }

            // dono characters ko lowercase me convert karke compare karo
            if (tolower(left) != tolower(right)) {
                return false;        // agar match nahi hua → palindrome nahi hai
            }

            // dono side ke characters match hue → ab andar move karo
            i++;
            j--;
        }

        // sab match ho gaye → palindrome hai
        return true;
    }
};

/*
--------------------------------------------
💡 Short Notes (Hinglish me):

🔹 isalnum(ch)
   → Check karta hai ki character letter ya digit hai ya nahi.
   → Example: 'A', 'z', '9' → true  |  ' ', ',', '#' → false

🔹 tolower(ch)
   → Character ko lowercase me convert karta hai.
   → Example: 'A' → 'a',  'b' → 'b' (no change)

🔹 Approach:
   → Two pointer: start aur end se compare karo
   → Non-alphanumeric skip karo
   → Case ignore karke compare karo
   → Sab match ho gaye to return true ✅

🔹 Time Complexity:  O(n)
🔹 Space Complexity: O(1)
--------------------------------------------
*/