#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct station{
    int num; // 정류장
    int time; // 걸리는 시간
    int gap; // 배차 간격
    int chance; // 찬스 쓴 횟수

    bool operator < ( station o) const{
        return time > o.time;
    } 
};
vector<station> map[501];

int use[501]; // 바로 직전에 찬스를 써서 온 경우 visit
int no[501]; // 찬스를 쓰지 않은 경우 visit
void dijkstra(int chance_count){
    priority_queue<station> pq;
    pq.push({1,0,0,0});
    no[1] = 0;
    use[1] = 0;
    while(!pq.empty()){
        station now = pq.top();
        pq.pop();

        // 이미 이전에 더 작은 경우가 있을 경우
        if( no[now.num] < now.time && use[now.num] < now.time) continue;

        for(int i=0; i<map[now.num].size(); i++){
            station next = map[now.num][i];
            int necessary_time = now.time + next.time;

            // 다음 노선이 찬스 노선일 때, 이미 주어진 찬스 개수를 다썼는지 확인
            if( next.gap == 0 && now.chance == chance_count) continue; 
            // chance를 사용한 경우 visit check
            if( next.gap == 0 ){
                if( use[next.num] <= necessary_time ) continue;
                use[next.num] = necessary_time;
                pq.push({next.num, necessary_time, next.gap, now.chance + 1});
            }
            else{ // chance를 사용하지 않은 경우 visit check
                necessary_time += (now.time % next.gap); // 배차 간격 고려
                if( no[next.num] <= necessary_time ) continue;
                no[next.num] = necessary_time;
                pq.push({next.num, necessary_time, next.gap, now.chance});
            }
        }

    }
}
void init(){
    for(int i=0; i<501; i++){
        use[i] = 0x7fffffff;
        no[i] = 0x7fffffff;
    }
}
int main(){

    int N, M, K; // 정류장 개수 500, 노선 개수 250000, 빨리기다리기 500
    cin>> N >> M >> K;

    for(int i=1; i<=M; i++){
        int s, e, t, g; // 시작 노선, 끝 노선, 시간, 배차 간격
        cin>> s >> e >> t >> g;
        map[s].push_back({e,t,g,0});
        map[s].push_back({e,t,0,0}); // 빨리가기 쓴 경우
    }
    dijkstra(K);

    int ans = use[N] > no[N] ? use[N] : no[N];
    cout<<ans;
    return 0;
}