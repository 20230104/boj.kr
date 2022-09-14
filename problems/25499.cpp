#include <bits/stdc++.h>
using namespace std;

class my
{
private:
int N;
vector<pair<int, int>> A;//<칸, 높이>
public:
my(){
    cin>>N;
    for(int i = 1 ; i <= N ;i++){
        int buff;
        cin>>buff;
        if(buff) A.push_back({i, buff});
    }
}
void Ution(){
    vector<pair<int, int>> memo(3, {0, 1});
    int A_size = A.size();
    for(int i = 0 ; i < A_size;i++){
        const int idx = A[i].first, height = A[i].second;//현재 선택한 블럭의 정보
        vector<pair<int, int>> tmp(3);//next_memo
        //left
        int covered_blocks = 0;
        for(auto l:memo){
            if(idx - height <= l.first)continue;
            covered_blocks = max(covered_blocks, l.second);
        }
        if(covered_blocks) tmp[0] = {idx - 1, covered_blocks + height};
        else tmp[0] = {idx, 0};//불가능

        //stay
        covered_blocks = 0;
        for(auto l:memo){
            if(l.first>=idx)continue;
            covered_blocks = max(covered_blocks, l.second);
        }
        tmp[1] = {idx, covered_blocks + 1};

        //right
        covered_blocks = 0;
        for(auto l:memo){
            if(idx + height > N)continue;
            if(i<A.size()-1&&idx + height > A[i+1].first)continue;
            covered_blocks = max(covered_blocks, l.second);
        }
        if(covered_blocks) tmp[2] = {idx + height, covered_blocks + height};
        else tmp[2] = {idx, 0};
        memo = tmp;
    }
    int max_blocks = max(memo[0].second, memo[1].second);
    max_blocks = max(max_blocks, memo[2].second);
    cout<<N + 1 - max_blocks<<'\n';
}
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    my sol;
    sol.Ution();
    
    return 0;
}