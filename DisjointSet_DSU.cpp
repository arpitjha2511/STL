#include<iostream>
#include <bits/stdc++.h>
using namespace std;
#define int long long 

class DisjSet{
    public:
    vector<int> size, parent;

    //Constructor (1 indexed)
    DisjSet(int n){
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0; i<=n; i++)  parent[i]=i;
    }
    // //Constructor (0 indexed)
    // DisjSet(int n){
    //     size.resize(n,1);
    //     parent.resize(n);
    //     for(int i=0; i<n; i++)  parent[i]=i;
    // }

    //Find Ult Parent
    int findParent(int x){
        if(parent[x]==x)    return x;
        return parent[x]=findParent(parent[x]);
    }

    //Union
    void unionBySize(int x, int y){
        int x_ = findParent(x);
        int y_ = findParent(y);
        if(x_ == y_)    return;
        if(size[x_] > size[y_]){
            parent[y_]=x_;
            size[x_]+=size[y_];
        }else{
            parent[x_]=y_;
            size[y_]+=size[x_];
        }
    }
    // Number of separate groups
    int countGroups(){
        int x=0, n=parent.size()-1;
        for(int i=1; i<=n; i++){
            if(findParent(i)==i)    x++;
        }
        return x;
    }
    // Check if 2 nodes are in same grp
    bool isSameSet(int x, int y){
        return (findParent(x)==findParent(y));
    }
};


void solve()
{
    int n, a, b, x,y;
    cin>>n>>a>>b;
    vector<pair<int,int>>graph1(a); 
    DisjSet g1(n), g2(n);
    for(int i=0; i<a; i++){
        cin>>x>>y;
        graph1[i]={x,y};
    }
    
    for(int i=0; i<b; i++){
        cin>>x>>y;
        g2.unionBySize(x,y);
    }
    int ans=0;
    for(int i=0; i<a; i++){
        if(!g2.isSameSet(graph1[i].first , graph1[i].second)){
            ans++;
        }else{
            g1.unionBySize(graph1[i].first, graph1[i].second);
        }
    }
    
    ans = ans + (g1.countGroups()-g2.countGroups());
    cout<<ans<<endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
