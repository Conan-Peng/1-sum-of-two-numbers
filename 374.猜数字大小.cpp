/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        if (guess(n) == 0) return n;
        int left = 1, right = n; //我们的二分法都是左闭右开区间
        while (left < right)
        {
            int mid = left + (right - left)/2;
            int t = guess(mid);
            if (t == 0) return mid;
            else if (t == 1) left = mid + 1;
            else right = mid;
        }
        return right;
    }
};
