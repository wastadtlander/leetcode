/*
 * Intuition:
 * If you see an closing paren when you have never seen a opening paren then you know you need to add an opening paren.
 * Also add leftover opening parens needing closing parens.
 */
class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0, close = 0;
        for (char c : s) {
            if (c == '(') {
                open++;
            } else if (open > 0){
                open--;
            } else {
                close++;
            }
        }
        return open + close;
    }
};
