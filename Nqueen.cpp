#include <iostream>
#include <vector>
using namespace std;

bool dk_con(vector<int> &arr, int i, int j){
    if (i == arr[0] || j == arr[1]){return 0;}
    if (j == i + (arr[1] - arr[0])){return 0;}
    if (j == -1*i + (arr[1] + arr[0])){return 0;}
    return 1;
    }

bool dk(vector<vector<int>> &arr, int i, int j){
    for (vector<int> a : arr){
        if (!dk_con(a, i, j)){return 0;}
    }
    arr.push_back({i, j});
    return 1;
}

bool Nqueen(vector<vector<int>> &arr, int max_queen, int board_size){
    if (arr.size() == max_queen){
        return 1;
    }
    for (int i = 0; i < board_size; i ++){
        for (int j = 0; j < board_size; j++){
            if (dk(arr, i, j)){
                if (Nqueen(arr, max_queen, board_size)){return 1;}
                else{
                    arr.pop_back();
                }
            }
        }
    }
    return 0;
}

void print_arr(vector<vector<int>> &arr){
    for (vector<int> i : arr){
            cout << "{"<< i[0] << ", "<< i[1] << "}" << ", ";
    }
}

int main(){
    vector<vector<int>> arr = {};
    int max_queen = 6;
    int board_size = 5;
    bool a = Nqueen(arr, max_queen, board_size);
    print_arr(arr);
    return 0;
}
