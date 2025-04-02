#include "iostream"
#include <string>
#include <vector>
using namespace std;

void bin(int n, string &a){ // 10 - >2
	if (n == 1){a = a +"1";}
	else if (n == 2){a = a+ "10";}
	else{
		if (n%2 == 0){
			bin(n/2, a);
			a = a + "0";
		}
		else{
			bin(n/2, a);
			a = a + "1";
		}
	}
}

void to_hex(int n, string &a){ // Bài toán cơ sở 
	if (n%16 < 10){
		a = a + to_string(n%16);
	}
	else{
		switch (n%16)
		{
		case 10:
			a = a + "A";
			break;
		case 11:
			a = a + "B";
			break;
		case 12:
			a = a + "C";
			break;
		case 13:
			a = a + "D";
			break;
		case 14:
			a = a + "E";
			break;
		case 15:
			a = a + "F";
			break;
		default:
			break;
		}
	}
}

void hex(int n, string &a){ //10 -> 16
	if (n<16){
		to_hex(n, a);
	}
	else{
		hex(n/16, a);
		to_hex(n, a);
	}
}

int sum_of_n(int n) { // tính tổng các chữ số trong n
	if (n < 10){
		return n;
	}
	else{
		return sum_of_n(n/10) + n%10;
	}
}
int sum_of_even_n(int n){ // lưu ý: Đầu vào rất lớn thì nên chuyển thành string
	if (n < 10){
		if (n%2 == 0){return n;}
		else{return 0;}
	}
	else{
		return sum_of_even_n(n/10) + sum_of_even_n(n%10);
	}
}

void S(int arr[], int size, vector<vector<int>> &subSetArr, vector <int> currentSubset = {}, int i = 0){ //sinh tập con
    if (i >= size){
        subSetArr.push_back(currentSubset);
        return;
    }
    S(arr, size, subSetArr, currentSubset, i+1);
    currentSubset.push_back(arr[i]);
    S(arr, size, subSetArr, currentSubset, i + 1);
}

void backtrack(int i, vector<string> &arr, string a =""){ // liệt kê tất cả nhị phân
	if (i == 0){
		arr.push_back(a); return;
	}
	a.push_back('0');
	backtrack(i-1, arr, a); 
	a.pop_back(); a.push_back('1');
	backtrack(i-1, arr, a);
}
// S và backtrack là điển hình cho phương pháp vét cạn trong thuật toán quay lui

int main(){
    vector<string> arr(0);
	backtrack(3, arr);
	for (string i : arr){
		cout << i << " ";
	}

}