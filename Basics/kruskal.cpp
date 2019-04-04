#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(),x.end()
#define mp make_pair

typedef long long ll;
typedef unsigned long long ull;
typedef long double ldb;

class Graph
{
    int nv;
    vector<pair<int,int> > *adjL;
    vector<pair<int ,pair<int ,int> > > edgL;
public:
    Graph(int nv)
    {
        this->nv=nv;
        adjL= new vector<pair<int,int> >[nv];
    }

    void addedge(int a ,int b,int w);
    void display();
    void kruskal();
};


    void Graph::addedge(int a,int b,int w)
    {
        adjL[a].push_back(mp(b,w));
        adjL[b].push_back(mp(a,w));
        edgL.pb(mp(w,mp(a,b)));

    }

    void Graph::display()
    {
        for(int i=0;i<nv;i++)
        {
            cout<<"["<<i<<"] :";
            int sz=adjL[i].size();
            for(int j=0;j<sz;j++)
            {
                cout<<adjL[i][j].first<<"->";
            }
            cout<<endl;
        }
    }

    void Graph::kruskal()
    {  
         vector< pair<int,pair<int,int> > > MST;
        sort(all(edgL));
        bool vis[nv];
        memset(vis,0,nv);
        int cnt=0;

     
        for(auto it : edgL)
        {
            if(cnt==nv-1)
                break;
            if(vis[it.second.first] && vis[it.second.second])
                continue;
            
            vis[it.second.first]=1;
            vis[it.second.second]=1;
            MST.pb(it);
            cnt++;
            
        }

        for(auto it: MST)
        {
            cout<<"["<<it.second.first<<":"<<it.second.second<<":"<<it.first<<"]"<<endl;
        }
        
     }


int main()
{   int n,e;
    cout<<"\n Enter no. of Vertices in Graph :";
    cin>>n;
    Graph G(n);
    cout<<"\n Enter no. of Edges :";
    cin>>e;
    cout<<"\n Vertices are no. from 0 to "<<n-1<<" enter edges accordingly";
    cout<<"\n Enter Starting Vertex ,Ending Vertex ,Weight :";
    for(int i=0;i<e;i++)
    {
        int a,b,w;
        cin>>a>>b>>w;
        G.addedge(a,b,w);
    }
    G.kruskal();

}