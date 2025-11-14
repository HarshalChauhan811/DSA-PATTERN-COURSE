class Solution {
public:
    int appendCharacters(string s, string t) {

        int i = 0 , j = 0; 
        int n = s.size(), m = t.size();

        // 🔥 Idea:
        // Hum dekh rahe hain ki string t ka kitna prefix (starting part)
        // string s ke andar subsequence ke form me already present hai.
        // Jo part t ka s me match nahi hota, wahi hume s ke end me append karna padega.

        // 🔁 Two Pointer Approach:
        // i → s me move karega
        // j → t me move karega (sirf tab jab match mile)
        // Goal = t ke maximum prefix ko s me match karna

        // Jab tak s aur t dono ke pointers valid hain,
        // tab tak characters compare karte rahenge
        while (i < n && j < m) {

            // ✔️ Agar s[i] == t[j], matlab t ka current character match mil gaya
            // To t ka pointer j++ (next character match karna start)
            if (s[i] == t[j]) 
                j++;

            // 👉 i to hamesha aage badhega kyunki s ko left se right scan karna hi hai
            i++;
        }

        // ℹ️ Loop khatam hone ke baad:
        // j = t ke kitne characters match ho chuke hain
        // m - j = t ka kitna part abhi bhi match nahi hua
        // Jo part match nahi hua, wahi hume s ke end me append karna padega

        return m - j;   // final answer
    }
};

/*
------------------ DRY RUNS (Step-by-step) ------------------

Example 1:
Input: s = "abc", t = "abfgh"
n = 3, m = 5
i=0, j=0

Iteration details:
- iter1: i=0 -> s[i]='a', j=0 -> t[j]='a'   => match -> j becomes 1; then i becomes 1
- iter2: i=1 -> s[i]='b', j=1 -> t[j]='b'   => match -> j becomes 2; then i becomes 2
- iter3: i=2 -> s[i]='c', j=2 -> t[j]='f'   => no match -> j stays 2; then i becomes 3
Loop ends because i == n

Final j = 2 (means "ab" matched)
Answer = m - j = 5 - 2 = 3
=> Need to append "fgh" (3 chars)

------------------------------------------------------------

Example 2:
Input: s = "xyz", t = "abc"
n = 3, m = 3
i=0, j=0

Iteration details:
- iter1: i=0 -> s[i]='x', j=0 -> t[j]='a'  => no match -> j stays 0; i -> 1
- iter2: i=1 -> s[i]='y', j=0 -> t[j]='a'  => no match -> j stays 0; i -> 2
- iter3: i=2 -> s[i]='z', j=0 -> t[j]='a'  => no match -> j stays 0; i -> 3
Loop ends

Final j = 0 (no char of t matched)
Answer = m - j = 3 - 0 = 3
=> Need to append whole "abc"

------------------------------------------------------------
Edge case example 3:
Input: s = "abcde", t = "ace"
n = 5, m = 3
i=0, j=0

- iter1: s[0]='a', t[0]='a' => match -> j=1, i=1
- iter2: s[1]='b', t[1]='c' => no match -> j=1, i=2
- iter3: s[2]='c', t[1]='c' => match -> j=2, i=3
- iter4: s[3]='d', t[2]='e' => no match -> j=2, i=4
- iter5: s[4]='e', t[2]='e' => match -> j=3, i=5
Loop ends (j == m -> full t matched)

Final j = 3 (full match)
Answer = m - j = 3 - 3 = 0
=> No characters to append

------------------ COMPLEXITY (TC / SC) ------------------

Time Complexity:
- Let n = s.size(), m = t.size()
- The while loop scans s at most once and t pointer advances at most m times.
- So overall time = O(n) in practice, but considering cost to compare up to both lengths it's O(n + m).
- We usually state: Time = O(n + m).

Space Complexity:
- Extra space used = O(1) (only integer counters i,j and sizes).
- No additional data structures proportional to input size.
- So Space = O(1).

------------------ WHY THIS IS CORRECT (SHORT PROOF) ------------------

- The algorithm greedily matches t from left to right using characters from s in the same order (subsequence).
- If a character of t can be matched using some character of s earlier, matching it greedily cannot hurt future matches (standard subsequence greedy proof).
- After scanning s, j tells how many prefix chars of t are already present as a subsequence.
- Remaining characters (m - j) must be appended to s to make t a subsequence — minimal by construction.

------------------------------------------------------------
*/
