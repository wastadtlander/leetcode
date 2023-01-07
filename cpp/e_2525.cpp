class Solution {
public:
    string categorizeBox(int length, int width, int height, int mass) {
        long long v = (long long)length * (long long)width * (long long)height;
        bool isHeavy = mass >= 100, isBulky = length >= 1e4 || width >= 1e4 || height >= 1e4 || v >= 1e9;
        if (isHeavy && isBulky) return "Both";
        else if (isBulky && !isHeavy) return "Bulky";
        else if (isHeavy && !isBulky) return "Heavy";
        return "Neither"; 
    }
};
