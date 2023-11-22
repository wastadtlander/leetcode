class Solution {
public:
    bool isRobotBounded(string instructions) {
        int x = 0, y = 0, dir = 0;
        for (int i = 0; i < 4; ++i) {
            for (char c : instructions) {
                if (c == 'G') {
                    if (dir == 0) {
                        y++;
                    } else if (dir == 1) {
                        x++;
                    } else if (dir == 2) {
                        y--;
                    } else {
                        x--;
                    }
                } else if (c == 'L') {
                    if (dir == 0) {
                        dir = 3;
                    } else if (dir == 1) {
                        dir--;
                    } else if (dir == 2) {
                        dir--;
                    } else {
                        dir--;
                    }
                } else if (c == 'R') {
                    if (dir == 0) {
                        dir++;
                    } else if (dir == 1) {
                        dir++;
                    } else if (dir == 2) {
                        dir++;
                    } else {
                        dir = 0;
                    }
                }
            }
            if (x == 0 && y == 0 && dir == 0) return true;
        }
        return false;
    }
};
