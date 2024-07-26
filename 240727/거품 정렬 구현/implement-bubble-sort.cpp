#include <iostream>
#include <vector>
using namespace std;

int n, count;
vector<int> arr;
bool sorted;

int main() {
    cin >> n;

    for(int i=0; i<n; i++){
        int tmp;
        cin >> tmp;
        arr.push_back(tmp);
    }

    sorted = false;

    do{
        count = 0;

        for(int i=0; i<n-1; i++){
            if(arr[i] > arr[i+1]){
                int tmp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = tmp;
                count++;
            }
        }

        if(count == 0){ sorted = true; }

    }while(!sorted);

    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }

    return 0;
}