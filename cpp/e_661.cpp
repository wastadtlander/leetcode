class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size(), n = img[0].size();
        vector<vector<int>> imgNew(m, vector<int>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int count = 1;
                imgNew[i][j] = img[i][j];
                if (i > 0) {
                    imgNew[i][j] += img[i - 1][j];    
                    count++;
                }
                if (j > 0) {
                    imgNew[i][j] += img[i][j - 1];    
                    count++;
                }
                if (i < m - 1) {
                    imgNew[i][j] += img[i + 1][j];    
                    count++;
                }
                if (j < n - 1) {
                    imgNew[i][j] += img[i][j + 1];    
                    count++;
                }
                if (i > 0 && j > 0) {
                    imgNew[i][j] += img[i - 1][j - 1];    
                    count++;
                }
                if (i > 0 && j < n - 1) {
                    imgNew[i][j] += img[i - 1][j + 1];    
                    count++;
                }
                if (i < m - 1 && j > 0) {
                    imgNew[i][j] += img[i + 1][j - 1];    
                    count++;
                }
                if (i < m - 1 && j < n - 1) {
                    imgNew[i][j] += img[i + 1][j + 1];        
                    count++;
                }
                imgNew[i][j] /= count;
            }   
        }
        return imgNew;
    }
};
