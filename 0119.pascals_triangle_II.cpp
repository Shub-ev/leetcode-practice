class Solution {
    public:
        vector<int> getRow(int rowIndex) {
            vector<int> prevRow;

            for (int i = 0; i <= rowIndex; i++) {
                vector<int> currRow(i+1, 1);

                for(int j = 1; j < i; j++) {
                    currRow[j] = prevRow[j-1] + prevRow[j];
                }

                prevRow = currRow;
            }

            return prevRow;
        }
};
