#include <iostream>
using namespace std;

bool condition(int num, int arr[9][9], int i, int j){
    for (int k = 0; k < 9; k ++){
        if (num == arr[k][j] || num == arr[i][k]){return 0;}
    }
    int hang_min, hang_max;
    int cot_min, cot_max;

    if (i <=2){
        hang_min = 0 ; hang_max = 2;
        if (j <=2){
            cot_min = 0; cot_max = 2;
        }
        else if (j <=5){
            cot_min = 3; cot_max = 5;
        }
        else if(j <= 8){
            cot_min = 6; cot_max = 8;
        }
    }
    else if (i <= 5){
        hang_min = 3 ; hang_max = 5;
        if (j <=2){
            cot_min = 0; cot_max = 2;
        }
        else if (j <=5){
            cot_min = 3; cot_max = 5;
        }
        else if(j <= 8){
            cot_min = 6; cot_max = 8;
        }
    }
    else if (i<=8){
        hang_min = 6 ; hang_max = 8;
        if (j <=2){
            cot_min = 0; cot_max = 2;
        }
        else if (j <=5){
            cot_min = 3; cot_max = 5;
        }
        else if(j <= 8){
            cot_min = 6; cot_max = 8;
        }
    }

    for (int h = hang_min; h <= hang_max; h ++){
        for (int c = cot_min; c <=cot_max; c++){
            if (num == arr[h][c]){return 0;}
        }
    }
    return 1;
}

bool sudoku(int arr[9][9], int i = 0, int j = 0){
    if (i == 9 && j == 0){ // lỗi 1 : điều kiện dừng đệ quy chưa đúng
        return 1;
    }

    int new_i, new_j;
    if (j == 8){new_i = i + 1; new_j = 0;}
    else{new_i = i; new_j = j + 1;}

    bool sai = 1;
    if (arr[i][j] != 0){ // lỗi 2: không xét riêng với những trường hợp đặc biệt.
        return sudoku(arr, new_i, new_j); // gặp phần tử khác 0 thì chạy tiếp những vị trí sau
    }
    else{
        for (int num = 1; num <=9; num ++){
            if (condition(num, arr, i, j)){
                arr[i][j] = num; sai = 0;
                if (!sudoku(arr, new_i, new_j)){
                    sai = 1;
                    continue;}
                else{return 1;} // lỗi: nếu điền đúng thì các trường hợp phải trả toàn bộ về true
            }
        }
    if (sai){ // lỗi 4: điều kiện quay lui
        arr[i][j] = 0; // không điền được thì phần tử đó phải được gán trở lại bằng 0
        return 0;} // không điền được thì tức là phần tử trước đó sai, quay lui lại từ dòng 74
    }
    return 1; // trình biên dịch không thể nhận thức được ta đã quét toàn bộ trường hợp, thêm dòng này để tránh lỗi 
             // warning: control reaches end of non-void function [-Wreturn-type]
}

void print_arr(int arr[9][9]){
    for (int i = 0; i < 9; i ++){
        for (int j = 0; j < 9; j ++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    int arr[9][9] = {
        {0, 0, 0, 5, 0, 0, 0, 0, 0},
        {0, 0, 5, 0, 0, 2, 9, 4, 0},
        {0, 0, 6, 0, 0, 0, 0, 7, 0},
        {0, 0, 0, 0, 5, 0, 0, 2, 0},
        {0, 0, 7, 0, 0, 4, 1, 0, 0},
        {8, 0, 0, 3, 9, 0, 0, 0, 0},
        {4, 0, 3, 0, 0, 0, 0, 0, 6},
        {0, 0, 0, 4, 0, 0, 0, 0, 7},
        {0, 8, 0, 0, 6, 0, 0, 0, 2}
    };
    bool a = sudoku(arr);
    if (a){
        print_arr(arr);
    }
    else{
        cout << "khong the giai duoc. Hay kiem tra lai";
    }
    return 0;
}