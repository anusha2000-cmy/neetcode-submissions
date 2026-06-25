class Solution {
public:
    int getSum(int a, int b) {
    int res = 0;
    int carry = 0;
    int i = 0;
    int mask = 0xFFFFFFFF;

    while (i<32) {
        int bit1 = a & 1;
        int bit2 = b & 1;
        a >>= 1;
        b >>= 1;

        // Calculate sum before updating carry
        int total = bit1+bit2+carry;
        int sum_bit = total % 2;
        carry = total / 2; 

        res |= (sum_bit << i);
        i++;
    }
    if (res > 0x7FFFFFFF) {
            res = ~(res ^ mask);
        }
    return res;
    }
};
