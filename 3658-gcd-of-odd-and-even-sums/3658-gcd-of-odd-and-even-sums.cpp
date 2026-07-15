class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        long long sumOdd = 0;
        long long sumEven = 0;
        int cntOdd = 0, cntEven = 0;
        int i = 1, j = 2;
        while (cntOdd < n) {
            sumOdd += i;
            i += 2;
            cntOdd++;
        }
        while (cntEven < n) {
            sumEven += j;
            j += 2;
            cntEven++;
        }
        while (sumOdd != 0) {
            long long rem = sumEven % sumOdd;
            sumEven = sumOdd;
            sumOdd = rem;
        }
        return (int)sumEven;
    }
};