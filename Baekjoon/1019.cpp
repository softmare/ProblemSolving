#include <iostream>

using namespace std;

typedef long long LL;

LL cnt[10];
LL cnt2[10];

void pcnt2();

void cc(LL n){
    for(LL i= 1; i < n+1; i++){
        LL t = i;
        while(t){
            cnt2[t % 10]++;
            t /= 10;
        }
    }
    pcnt2();
}

int pick(LL n, int i){
    LL div = 1;
    for(int j=0; j<i; j++){
        div *= 10;
    }
    return (n/div)%10;
}

LL p10(int i){
    LL res = 1;
    for(int k=0; k<i; k++){
        res *= 10;
    }
    return res;
}

void add1to(int k, LL add){
    for(int i=1; i<k+1; i++){
        cnt[i] += add;
    }
}

void adda(LL add){
    for(int i=0; i<10; i++){
        cnt[i] += add;
    }
}

void pcnt(){
    for (int i=0; i<10; i++){
        cout << cnt[i] << ' ';
    }cout << endl;
}
void pcnt2(){
    for (int i=0; i<10; i++){
        cout << cnt2[i] << ' ';
    }cout << endl;
}

int main(){

    LL n; cin >> n;

    int i = 0;

    while(true){
        if(p10(i) > n) break;
        
        adda(i*pick(n,i)*p10(i-1));

        if(i == 0){
            add1to(n%10,1);
        }else{
            if(!pick(n,i)){
                cnt[0] -= p10(i);
            }
            add1to(pick(n,i)-1,p10(i));
            cnt[pick(n,i)] += n%p10(i)+1;
        }
        i++;
    }
    pcnt();
    //cc(n);
    return 0;
}