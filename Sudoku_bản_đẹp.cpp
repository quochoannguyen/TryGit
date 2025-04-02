#include <iostream>
using namespace std;

// Kiểm tra xem số có thể đặt vào vị trí (row, col) không
bool isSafe(int num, int arr[9][9], int row, int col) {
    // Kiểm tra hàng và cột
    for (int x = 0; x < 9; x++) {
        if (arr[row][x] == num || arr[x][col] == num) {
            return false;
        }
    }

    // Xác định vùng 3x3
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    
    // Kiểm tra vùng 3x3
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (arr[i + startRow][j + startCol] == num) {
                return false;
            }
        }
    }
    return true;
}

// Giải Sudoku bằng đệ quy
bool solveSudoku(int arr[9][9], int row = 0, int col = 0) {
    // Điều kiện dừng: đã xử lý hết bảng
    if (row == 9) {
        return true;
    }

    // Chuyển sang ô tiếp theo
    int nextRow = (col == 8) ? row + 1 : row;
    int nextCol = (col == 8) ? 0 : col + 1;

    // Nếu ô hiện tại đã có số, bỏ qua và xử lý ô tiếp theo
    if (arr[row][col] != 0) {
        return solveSudoku(arr, nextRow, nextCol);
    }

    // Thử các số từ 1-9
    for (int num = 1; num <= 9; num++) {
        if (isSafe(num, arr, row, col)) {
            arr[row][col] = num;
            
            if (solveSudoku(arr, nextRow, nextCol)) {
                return true;
            }
            
            // Backtrack: nếu không thành công, đặt lại về 0
            arr[row][col] = 0;
        }
    }
    
    return false;
}

// In bảng Sudoku
void printArr(int arr[9][9]) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int arr[9][9] = {
        {6, 0, 0, 2, 8, 0, 0, 0, 0},
        {0, 4, 0, 0, 9, 0, 0, 0, 8},
        {0, 3, 8, 0, 5, 7, 4, 9, 0},
        {0, 0, 0, 6, 7, 2, 0, 3, 0},
        {0, 1, 0, 5, 4, 0, 0, 0, 0},
        {0, 5, 0, 8, 3, 0, 6, 0, 0},
        {8, 0, 0, 0, 1, 0, 9, 6, 2},
        {0, 0, 4, 7, 6, 0, 1, 0, 5},
        {0, 6, 5, 9, 0, 0, 3, 0, 4},
    };
    
    if (solveSudoku(arr)) {
        printArr(arr);
    } else {
        cout << "No solution exists" << endl;
    }
    
    return 0;
}
// Tóm lại, quay lui xảy ra khi trường hợp sau trường hợp hiện tạ sai hoặc không thể giải