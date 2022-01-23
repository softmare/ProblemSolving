#include<iostream>
#include<cmath>


using namespace std;

long long ms[1000000];
bool paint[1000001];

int main(){
    long long a, b, cm=0; cin >> a >> b;
    int painted = 0;

    for(long long i=2; i <= sqrt(b); i++){
        ms[cm++] = i*i;
    }

   for(int i=0; i < cm; i++){
       long long st = a;
       if(st%ms[i]){
           st = (st/ms[i]+1)*ms[i];
       }
       for(long long paint_here = st; paint_here <= b; paint_here+=ms[i]){
           if(!paint[paint_here-a]) {
               paint[paint_here-a] = true;
               painted++;
           }
       }
   }

   cout << b-a+1 - painted << endl;

    return 0;
}