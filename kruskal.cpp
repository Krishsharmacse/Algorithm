#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool cmp(vector<int>&a,vector<int>&b){
    return a[2]<b[2];
}
void makeset(vector<int>&parent,vector<int>&rank,int n){
    for(int i =0;i<n;i++){
        parent[i]=i;
        rank[i]=0;
    }
}
int findset(vector<int>&parent,int node){
    if(parent[node]==node){
        return node;
    }
    return parent[node]=findset(parent,parent[node]);

}
void unionset(int u,int v,vector<int>&parent,vector<int>&rank){
    u=findset(parent,u);
    v=findset(parent,v);
    if(rank[u]>rank[v]){
        parent[v]=u;
    }
    else if(rank[v]>rank[u]){
        parent[u]=v;
    }
    else{
        parent[u]=v;
        rank[u]++;
    }
}
int kruskal_algorithm(vector<vector<int>>&edges,int n){
sort(edges.begin(),edges.end(),cmp);
vector<int>parent(n);
vector<int>rank(n);
makeset(parent,rank,n);
int minweight=edges[0][2];
for(int i=0;i<edges.size();i++){
int wt = edges[i][2];
int u = findset(parent,edges[0][i]);
int v = findset(parent,edges[1][i]);
if(u!=v){
    unionset(u,v,parent,rank);
    minweight+=wt;
}

}
return minweight;
}
int main(){
    vector<vector<int>>edges={
        {0,1,12},{0,2,18},{0,3,14},{1,2,31},{1,3,16},{2,4,12},{31,53,12},{31,4,19}
    };
    int n = sizeof(edges)/sizeof(edges[0]);
    cout<<"weight of minimum spanning tree is : "<<kruskal_algorithm(edges,n);
    return 0;
}
