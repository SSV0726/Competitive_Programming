#include<bits/stdc++.h>
using namespace std;

class Graph
{
         int N;
         vector<int> *v;
public :
        Graph(int N)
        {
            this->N=N;
            v = new vector<int>[N];         // its similar to java like when we create an array
        }

        void addedge(int a,int b);
        void display();
        void topological_sort(); 
        void topSortUtil(int pos,bool vis[],stack<int> &S);

};

void Graph::addedge(int a,int b)
{
    v[a].push_back(b);
}

void Graph::display()
{
    for(int i=0;i<N;i++)
    {
        cout<<"["<<i<<"]"<<":";
        int sz=v[i].size();
        for(int j=0;j<sz;j++)
        {
            cout<<v[i][j]<<"->";
        }
        cout<<endl;
    }    
}

void Graph::topological_sort()
{
    stack<int> S;
    
    bool *vis=new bool[N];
    memset(vis,0,N);

    // push in stack
    for(int i=0;i<N;i++)
    {
        if(!vis[i])
        {
            topSortUtil(i,vis,S);
        }
    }

    //print stack
    while(S.empty()==false)
    {
        cout<<S.top()<<" ";
        S.pop();
    }
}

void Graph::topSortUtil(int pos,bool vis[],stack<int> &S)
{
    vis[pos]=1;
    for(auto it: v[pos])
    {
        if(!vis[it])
            topSortUtil(it,vis,S);
    }

    S.push(pos);
}

int main()
{
    int n,e;
    cout<<"\n Enter no. of nodes in a graph";
    cin>>n;
    Graph G(n);
    cout<<"\n Enter no. of edges";
    cin>>e;
    for(int i=0;i<e;i++)
    {
        int a,b;
        cin>>a>>b;
        G.addedge(a,b);
    }
    G.display();
    G.topological_sort();

}