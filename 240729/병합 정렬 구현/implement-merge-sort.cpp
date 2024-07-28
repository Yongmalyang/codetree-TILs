#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> arr, tmp_arr;

// 두 배열 합치기
void merge(int st, int en){
    int mid = (st + en) / 2;

    int l_idx = st;
    int r_idx = mid;

    for(int i=st; i<en; i++){
        if(r_idx == en) tmp_arr[i] = arr[l_idx++];
        else if(l_idx == mid) tmp_arr[i] = arr[r_idx++];
        else if(arr[l_idx] <= arr[r_idx]) tmp_arr[i] = arr[l_idx++];
        else tmp_arr[i] = arr[r_idx++];
    }
    
    for(int i = st; i < en; i++) arr[i] = tmp_arr[i];
}

// 배열 정렬하기
void merge_sort(int st, int en){

    if(st+1==en){
        return;
    }

    int mid = (st + en) / 2;
    merge_sort(st, mid);
    merge_sort(mid, en);
    merge(st, en);
}

int main() {
    cin >> n;

    for(int i=0; i<n; i++){
        int tmp;
        cin >> tmp;
        arr.push_back(tmp);
    }
    tmp_arr.assign(n, 0);

    merge_sort(0, n);

    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }

    return 0;
}