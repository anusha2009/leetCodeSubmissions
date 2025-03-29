/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int row, int col);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        int rows = binaryMatrix.dimensions()[0];
        int cols = binaryMatrix.dimensions()[1];

        int currRow = 0;
        int currCol = cols - 1;

        while(currRow < rows && currCol >= 0) {
            if(binaryMatrix.get(currRow, currCol) == 0) {
                currRow++;
            } else {
                currCol--;
            }
        }

        return (currCol == cols - 1)? -1 : currCol + 1;
    }
};