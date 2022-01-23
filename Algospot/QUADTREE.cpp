#include<bits/stdc++.h>

using namespace std;

// typedef struct Node{
//     char c;
//     Node *n[4];
//     Node() : c('\0'){
//         for(int i=0; i<4; ++i){
//             n[i] = nullptr;
//         }
//     }
//     void attech(string &s, int &id){
//         assert(s[id] != '\0');
//         c = s[id++];
//         if(c == 'x'){
//             for(int i=0; i<4; i++){
//                 n[i] = new Node;
//                 n[i]->attech(s, id);
//             }
//         }
//         return ;
//     }
    
//     void upDown(){        
//         assert(c != '\0');
//         if(c == 'x'){            
//             for(int i=0; i<4; ++i){
//                 n[i]->upDown();
//             }
//             swap(n[0], n[2]);
//             swap(n[1], n[3]);            
//         }
//     }

//     void print(){
//         assert(c != '\0');
//         printf("%c", c);
//         if(c == 'x'){
//             for(int i=0; i<4; ++i){
//                 n[i]->print();
//             }
//         }
//     }
// } Node;

// int main(){
//     int T; cin >> T;
//     for(int t=0; t<T; ++t){
//         string s; cin >> s;
//         Node n; int id = 0;
//         n.attech(s, id);
//         n.upDown();
//         n.print(); printf("\n");
//     }
//     return 0;
// }

string reverse(string::iterator &it){
    char head = *it++;
    if(head != 'x'){
        return string(1, head);
    }
    string upperLeft = reverse(it);
    string upperRight = reverse(it);
    string lowerLeft = reverse(it);
    string lowerRight = reverse(it);
    return string(1,'x') + lowerLeft + lowerRight + upperLeft + upperRight;
}

int main(){
    cin.sync_with_stdio(false);
    int T; cin >> T;
    for(int t=0; t<T; ++t){
        string s; cin >> s; string::iterator it = s.begin();
        cout << reverse(it) << endl;
    }
    return 0;
}