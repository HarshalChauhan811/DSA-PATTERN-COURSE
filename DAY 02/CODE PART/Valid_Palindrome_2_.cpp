// ✅ LeetCode 680: Valid Palindrome II
// Problem: Check if a string can become a palindrome after deleting at most one character
// Approach: Two Pointer Technique (Beginner Friendly Version)
// Time Complexity: O(n)
// Space Complexity: O(1)

#include <string>
using namespace std;

class Solution {
public:
    bool validPalindrome(string s) {
        int left = 0;                       // left pointer (string ke start par)
        int right = s.size() - 1;           // right pointer (string ke end par)

        // Two-pointer traversal: dono ends se check karte hain
        while (left < right) {
            // agar dono characters same hain → pointers ko andar move karo
            if (s[left] == s[right]) {
                left++;
                right--;
            } 
            else {
                /*
                 ⚠️ Yaha mismatch mila hai — iska matlab ye string abhi palindrome nahi hai.

                 Lekin question me bola gaya hai:
                 👉 Hum at most 1 character delete kar sakte hain.
                 
                 To ab hum do possibilities check karte hain:
                 
                 1️⃣ Left character hata ke baaki string check karte hain kya palindrome hai?
                     Example: "abca" → remove 'b' → "aca"
                 
                 2️⃣ Right character hata ke baaki string check karte hain kya palindrome hai?
                     Example: "abca" → remove 'c' → "aba"
                 
                 Agar koi ek case palindrome mil gaya → string valid hai ✅
                 Dono fail hue → string fix nahi ho sakti ❌
                */

                bool skipLeft  = isPalindrome(s, left + 1, right);   // left char skip karke check
                bool skipRight = isPalindrome(s, left, right - 1);   // right char skip karke check

                // agar dono me se koi bhi case palindrome ban gaya → return true
                if (skipLeft || skipRight)
                    return true;
                else
                    return false;
            }
        }

        // agar loop bina mismatch ke complete ho gaya → string already palindrome hai
        return true;
    }

private:
    /*
     Helper Function:
     Ye function check karta hai ki substring s[l..r] palindrome hai ya nahi.
     Isme same two-pointer technique use hoti hai.
    */
    bool isPalindrome(const string &s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r])
                return false;                // mismatch mila → not palindrome
            l++;                             // left pointer aage
            r--;                             // right pointer peeche
        }
        return true;                         // poora match hua → palindrome
    }
};
