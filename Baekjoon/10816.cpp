#include<bits/stdc++.h>

using namespace std;

int main(){    
    int N, M;
    map<int, int> m;
    scanf("%d", &N);
    for(int temp, i=0; i<N; ++i){
        scanf("%d", &temp);
        if(m.find(temp) == m.end()){
            m[temp] = 1;
        }else{
            ++m[temp];
        }
    }
    scanf("%d", &M);
    for(int temp, i=0; i<M; ++i){
        scanf("%d", &temp);
        printf("%d ", ((m.find(temp) == m.end()) ? 0 : m[temp]));
    }printf("\n");
    return 0;
}