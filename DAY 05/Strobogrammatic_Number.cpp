class Solution {
public:
    bool isStrobogrammatic(string num) {

        // Ye map batata hai ki kaunsa digit rotate hone par kis digit me badalta hai
        // 0 -> 0
        // 1 -> 1
        // 8 -> 8
        // 6 -> 9
        // 9 -> 6
        unordered_map<char,char> rot = {
            {'0','0'}, {'1','1'}, {'8','8'},
            {'6','9'}, {'9','6'}
        };

        int l = 0, r = num.size() - 1;

        // Jab tak dono pointers beech me nahi mil jaate, tab tak check karo
        while (l <= r) {
            
            char L = num[l];   // left side digit
            char R = num[r];   // right side digit

            // Agar left ka digit rotation map me exist hi nahi karta
            // matlab use rotate nahi kar sakte → number strobogrammatic nahi ho sakta
            if (!rot.count(L)) 
                return false;

            // Rotate hone ke baad left ka digit, right wale digit ke equal hona chahiye
            if (rot[L] != R) 
                return false;

            // dono pointers ko beech ki taraf move karo
            l++;
            r--;
        }

        // Sab digits rotate karke match ho gaye → number strobogrammatic hai
        return true;
    }
};


/*
----------------------- DRY RUN -----------------------

Example 1:
num = "69"
l = 0, r = 1

Step 1:
L = '6', R = '9'
rot['6'] = '9' → matches ✔
l=1, r=0 → loop end
Return true

------------------------------------------------------

Example 2:
num = "818"
l = 0, r = 2

Step 1:
L='8', R='8'
rot['8']='8' ✔ → OK
l=1, r=1

Step 2:
L='1', R='1'
rot['1']='1' ✔ → OK
l=2, r=0 → loop end
Return true

------------------------------------------------------

Example 3:
num = "962"
l = 0, r = 2

Step 1:
L='9', R='2'
rot['9']='6' → but R='2' ❌
Return false

------------------------------------------------------

****************** TIME & SPACE COMPLEXITY ******************

Time Complexity:
- Hum sirf ek baar string ko dono ends se scan kar rahe hain
- Loop total num.size() / 2 iterations chalti hai
- So Time = O(n) where n = length of num

Space Complexity:
- Rotation map (constant size = 5 characters)
- So extra space = O(1)

**************************************************************

*/
