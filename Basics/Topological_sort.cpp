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

}