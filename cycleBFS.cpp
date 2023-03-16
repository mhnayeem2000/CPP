#include<bits/stdc++.h>
using namespace std;

int main(){
    bool iscycle(int v , vector<int> adj[]){
        for(int i = 1; i < v ; i++){
            if(!vis[i]){
                if(checkCycle(i , v, vis)) return true;
            }
        }
    }
}