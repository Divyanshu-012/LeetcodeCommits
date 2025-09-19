class Spreadsheet {
public:
    vector<vector<int>> grid;
    int rows;

    
    Spreadsheet(int rows) {
        
        grid = vector<vector<int>>(rows, vector<int>(26, 0));
    }

   
    void setCell(string cell, int value) {
        int col = cell[0] - 'A';          
        int row = stoi(cell.substr(1)) - 1;  
        grid[row][col] = value;
    }

    
    void resetCell(string cell) {
        int col = cell[0] - 'A';
        int row = stoi(cell.substr(1)) - 1;
        grid[row][col] = 0;
    }

    
    int getValue(string formula) {
        if (formula[0] != '=') return 0;

        int sum = 0;
        int pos = 1;  
        string part = "";

        while (pos <= formula.size()) {
            if (pos == formula.size() || formula[pos] == '+') {
                bool isNumber = true;
                for (int i = 0; i < part.size(); i++) {
                    if (!isdigit(part[i])) {
                        isNumber = false;
                        break;
                    }
                }

                int value;
                if (isNumber) {
                    value = stoi(part);
                } else {
                    int col = part[0] - 'A';
                    int row = stoi(part.substr(1)) - 1;
                    value = grid[row][col];
                }

                sum += value;
                part = "";
            } else {
                part += formula[pos];
            }
            pos++;
        }

        return sum;
    }
};


/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */