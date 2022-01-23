#include<bits/stdc++.h>

using namespace std;

int solve(vector<int> &fence, int left, int right){
    if(left == right) return fence[left];
    int mid = (left + right) / 2;
    int ret = max(solve(fence, left, mid), solve(fence, mid+1, right));
    int lw = mid -1, rw = mid+2;
    int height = min(fence[mid], fence[mid+1]);
    ret = max(ret, height*2);
    while(lw != left-1 || rw != right + 1){        
        //if(lw == left-1){
        if(lw == left-1 || rw != right+1 && fence[lw] < fence[rw]){
            height = min(height, fence[rw++]);
            ret = max(ret, (rw - lw - 1) * height);            
        }else{
            height = min(height, fence[lw--]);
            ret = max(ret, (rw - lw - 1) * height);
        }
    }
    return ret;
}

int main(){
    int T; cin >> T;
    for(int t=0; t<T; ++t){
        int n, ret = 0; cin >> n;
        vector<int> fence;
        for(int i=0, temp; i<n; ++i){
            cin >> temp; fence.push_back(temp);
        }
        cout << solve(fence, 0, n-1) << endl;
    }        
    return 0;
}