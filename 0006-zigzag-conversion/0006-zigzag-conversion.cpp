class Solution {
public:
    string convert(string s, int numRows) {
        // If there's only one row or not enough letters for zigzag, just return as is
        if (numRows == 1 || numRows >= s.size()) return s;

        // We'll use a vector to store each row
        vector<string> rows(numRows, "");          // initialize numRows empty strings

        int currRow = 0;                           // start at the first row
        bool goingDown = false;                    // flag for the direction

        // Loop through the entire string one char at a time
        for (int i = 0; i < s.size(); i++) {
            rows[currRow] += s[i];                 // put the current character in the current row

            // If we are at first or last row, flip the direction
            if (currRow == 0 || currRow == numRows - 1) goingDown = !goingDown;

            // Move up or down depending on our direction
            currRow += goingDown ? 1 : -1;
        }

        // Now, merge all the rows into one result string
        string result = "";
        for (int i = 0; i < rows.size(); i++) {
            result += rows[i];                     // add all chars from this row
        }
        return result; 
    }
};