// Couldn't implement on my own but had the intuition.
class Solution {
public:
    int minimumOneBitOperations(int n) {
        // bitset<32> bits(n);
        int count = 0, flip = 1;
        for (int i = 30; i >= 0; i--) {
            if (n & (1 << i)) {
                count += ((1 << (i + 1)) - 1) * flip;
                flip *= -1;
            }
        }
        // while (bits.any()) {
        //     // for (int idx = 0; idx < 32; idx++) cout << bits[idx] << " ";
        //     // cout << endl;
        //     if (bits.count() == 1) {
        //         count += bits.to_ulong() * 2 - 1;
        //         bits.reset();
        //         break;
        //     }
        //     int onesFound = 0, onesCount = bits.count();
        //     for (int i = 31; i > 0; --i) {
        //         if (bits[i]) onesFound++;
        //         if (bits[i - 1] && onesCount - onesFound == 1) {
        //             bits.flip(i);
        //             count++;
        //         }
        //     }
        // }
        return count;
    }
};
