/*
https://leetcode.com/problems/pascals-triangle/
*/

/*
The code provided generates Pascal's Triangle up to n rows. Pascal's Triangle is a triangular array where each element is the sum of the two directly above it. The first and last elements of each row are always 1, and other elements are binomial coefficients.
*/

// Optimal approach
class Solution {
public:
    vector<vector<int>> generate(int n) {
        // Initialize the vector of vectors to hold the entire Pascal's Triangle
        vector<vector<int>> ans;

        // Loop through each row from 1 to n
        for (int row = 1; row <= n; row++) {
            // Temporary vector to store the current row
            vector<int> temp;
            
            // The first element of every row is always 1
            int product = 1;
            temp.push_back(product);

            // Calculate the values for the rest of the row
            for (int col = 1; col < row; col++) {
                // Compute the next element using the formula:
                // product = product * (row - col) / col
                product *= (row - col);
                product /= col;
                temp.push_back(product);      
            }
            // Add the completed row to the answer vector
            ans.push_back(temp);
        }
        // Return the completed Pascal's Triangle
        return ans;
    }
};

