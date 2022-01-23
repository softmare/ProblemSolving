#include<bits/stdc++.h>

using namespace std;

int a[500002], s[500002], n,q,k;

int main(){
    cin >> n >> q >> k;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    a[n+1] = k+1;
    for(int i=1; i<=n; i++){
        int p = min(k+1, a[i+1]);
        s[i] = max(p - a[i-1] -2, 0);
    }
    for(int t=0; t< q; t++){
        long long l, r, ans = 0, avo=0; cin >> l >> r; 
        if(l == r){
            if(s[l] <= k) ans -= 1;
            ans += k;
            printf("l==r\n");
            cout << ans << endl;
            continue;
        }
        for(int i=r; i > r -2; i--){
            if(a[i] >= k) avo++;
        }
        if(avo>=2){
            printf("avo>=2\n");
            cout << 0 << endl;
            continue;
        }
        if(avo == 1){
            printf("avo==1\n");
            if(a[r] == k) ans -= 1;
            ans+= k-a[r-1];
            for(int i=l; i < r; i++){
                ans += s[i];
            }
            cout << ans << endl;
            continue;
        }
        for(int i=l; i < r+1; i++){
            ans += s[i];
            printf("s[i] : %d ", s[i]);    
        }
        printf("elses\n");
        cout << ans << endl;
    }
    return 0;
}