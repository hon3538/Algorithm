#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct station{
    int num; // 정류장 번호
    int time; // 걸리는 시간
    int term; // 배차 간격
    int current_time; // 현재 시간
    int key; // 빨리가기 
    int total; // num까지 총 걸린 시간
};
vector<station> map[501];

int main(){

    int N, M, K; // 정류장 개수 500, 노선 개수 250000, 빨리기다리기 500
    cin>> N >> M >> K;

    for(int i=1; i<=M; i++){
        int s, e, t, g; // 시작 노선, 끝 노선, 시간, 배차 간격
        map[s].push_back({e,t,g});
    }
   
    return 0;
}