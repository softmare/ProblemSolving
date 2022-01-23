#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int N; cin >> N;
    vector<int> v(N);
    for(int i=0; i<N; ++i) cin >> v[i];
    sort(v.begin(), v.end());
    long long ans = 3e9;
    int arr[3];
    for(int i=0; i<N-2;++i){
        int left = i+1, right = N-1;
        while(left < right){            
            long long res = (long long)v[i] + v[left] + v[right];
            if(abs(res) < ans){
                arr[0] = v[i], arr[1] = v[left], arr[2] = v[right];
                ans = abs(res);
            }
            res > 0 ? --right:++left;
        }
    }
    cout << arr[0] << ' ' << arr[1] << ' ' << arr[2] << endl;
    return 0;
}