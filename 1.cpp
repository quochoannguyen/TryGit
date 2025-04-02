#include <iostream>
#include <vector>
using namespace std;

const int sizearr = 4;

bool isSafe(int arr[sizearr][sizearr], int size, int i, int j){
    if (arr[i][j] == 1 || i >= size || j >= size){
        return 0;
    }
    return 1;
}

void delette(int arr[sizearr][sizearr], int size, vector<vector<int>> &current_arr){
    for (vector<int> i : current_arr){arr[i[0]][i[1]] = 0;}
    current_arr.clear();
}

bool shortest(int arr[sizearr][sizearr], int size, int i , int j , vector<vector<int>> &current_arr, vector<vector<int>> &shortest_way ){
    if (i == size-1 && j == size-1){
        if(shortest_way.size() == 0){shortest_way = current_arr;}
        else if (shortest_way.size() > current_arr.size()){shortest_way = current_arr;}
        delette(arr, size, current_arr);
        return 1;
    }
    if (i >= size || j >=size || arr[i][j] == 1){
        return 0;
    }
    current_arr.push_back({i, j});
    arr[i][j] = 1;
    bool a = shortest(arr, size, i + 1, j, current_arr, shortest_way);
    bool b = shortest(arr, size, i, j + 1, current_arr, shortest_way);
    bool c = shortest(arr, size, i - 1, j, current_arr, shortest_way);
    bool d = shortest(arr, size, i, j - 1, current_arr, shortest_way);

    if (a){return a;}
    if (b){return b;}
    if (c){return c;}
    if (d){return d;}
    arr[i][j] = 0; current_arr.pop_back();
    return 0;
}

void print(vector<vector<int>> &arr){
    for (vector<int> i : arr){
            cout << "{"<< i[0] << ", "<< i[1] << "}" << ", ";
    }
}

void printArr(int arr[sizearr][sizearr]) {
    for (int i = 0; i < sizearr; i++) {
        for (int j = 0; j < sizearr; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    int arr[sizearr][sizearr] = {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };
    vector<vector<int>> current_arr = {};
    vector<vector<int>> shortest_way = {};
    bool a = shortest(arr, sizearr, 0, 0, current_arr, shortest_way);
    printArr(arr);
    return 0;
}