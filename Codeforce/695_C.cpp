#include<iostream>
#include<algorithm>

typedef long long int LL;

using namespace std;


void adder(LL &Am, LL &As, const LL An){
    LL temp;
    for(LL i=0; i< An; i++){
        cin >> temp;
        Am = min(Am, temp);
        As += temp;
    }
    As -= Am;
    return;
}

int main() {

    LL Am, As, Bm, Bs, Cm, Cs, An, Bn, Cn, cost[3];
    As = Bs = Cs = 0;
    Am = Bm = Cm = 987654321; 
    cin >> An >> Bn >> Cn;

    adder(Am, As, An);
    adder(Bm, Bs, Bn);
    adder(Cm, Cs, Cn);

    cost[0] = min(Am+As,Bm+Bs);
    cost[1] = min(Cm+Cs,Am+Bm);
    cost[2] = min(Bm+Cm,Am+Cm);
    cost[1] = min(cost[1],cost[2]);
    cost[0] = min(cost[0],cost[1]);

    cout << Am+As+Bm+Bs+Cm+Cs-cost[0]*2 << endl;
    
    return 0;
}