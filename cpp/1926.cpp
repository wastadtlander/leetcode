class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        vector<vector<char>> visited = maze;
        visited[entrance[0]][entrance[1]] = 'x';

        queue<int> q;

        q.push(entrance[0]);
        q.push(entrance[1]);
        q.push(0);

        while (!q.empty()) {
            int row = q.front();
            q.pop();
            int col = q.front();
            q.pop();
            int steps = q.front();
            q.pop();

            if ((row == 0 || col == 0 || row == maze.size() - 1 || col == maze[0].size() - 1) && (row != entrance[0] || col != entrance[1])) {
                return steps;
            }

            if (row + 1 < maze.size() && maze[row + 1][col] == '.' && visited[row + 1][col] != 'x') {
                q.push(row + 1);
                q.push(col);
                q.push(steps + 1);
                visited[row + 1][col] = 'x';
            }
            if (row - 1 >= 0 && maze[row - 1][col] == '.' && visited[row - 1][col] != 'x') {
                q.push(row - 1);
                q.push(col);
                q.push(steps + 1);
                visited[row - 1][col] = 'x';
            }
            if (col + 1 < maze[0].size() && maze[row][col + 1] == '.' && visited[row][col + 1] != 'x') {
                q.push(row);
                q.push(col + 1);
                q.push(steps + 1);
                visited[row][col + 1] = 'x';
            }
            if (col - 1 >= 0 && maze[row][col - 1] == '.' && visited[row][col - 1] != 'x') {
                q.push(row);
                q.push(col - 1);
                q.push(steps + 1);
                visited[row][col - 1] = 'x';
            }
        }

        return -1;
    }
};
