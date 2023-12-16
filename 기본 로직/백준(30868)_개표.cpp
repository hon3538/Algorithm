#include<iostream>

using namespace std;

int main(){
    int T;
    cin >> T;
    for( int i = 0; i < T; i++ ){
        int n;
        cin >> n;

        int portion = n/5;
        int remainder = n%5;

        for(int j = 0; j < portion; j++){
            cout<<"++++ ";
        }
        
        for(int j = 0; j < remainder; j++){
            cout<<"|";
        }
        cout<<'\n';
    }
    return 0;
}