#include<bits/stdc++.h>

using namespace std;

struct cmp_str{
    bool operator()(char const *a, char const *b) const{
        return strcmp(a, b) < 0;
    }
};

map<char *, int, cmp_str> m;
char arr[100001][21];

int main(){    
    int N, M; cin >> N >> M;
    for(int n=1; n<=N; ++n){
        scanf("%s", arr[n]);
        m[arr[n]] = n;        
    }
    for(int i=0; i<M; ++i){
        char temp[21]; scanf("%s",temp);
        if(!isdigit(temp[0])){
            printf("%d\n", m[temp]);
        }else{
            printf("%s\n", arr[atoi(temp)]);
        }
    }
    return 0;
}

//stoi는 atoi 보다 드럽게 느리다.