#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero = 0, one = 0, two = 0;

        // Step 1: Count how many 0, 1, 2 hain array me
        for(int x : nums){
            if(x == 0) zero++;      // kitne 0 hai
            else if(x == 1) one++;  // kitne 1 hai
            else two++;             // kitne 2 hai
        }

        // Step 2: Array ko dobara overwrite karna
        int index = 0;

        // ---- 0s fill kar rahe ----
        while(zero--){
            nums[index++] = 0;
        }

        // ---- 1s fill kar rahe ----
        while(one--){
            nums[index++] = 1;
        }

        // ---- 2s fill kar rahe ----
        while(two--){
            nums[index++] = 2;
        }
    }
};

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements (0, 1, 2 only): ";
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    Solution obj;
    obj.sortColors(nums);  // function call

    cout << "Sorted Colors: ";
    for(int x : nums){
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
