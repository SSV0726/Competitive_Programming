#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define lb lower_bound
#define up upper_bound
#define all(x) x.begin(),x.end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ldb;

int main()
{
     #ifndef ONLINE_JUDGE
    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE
    
    
    ll n;
    cin>>n;
    vector<ll> v(n+3,0);
    map<ll,ll> M1,M2;
    ll S=0;
    for(int i=1;i<=n;i++)
    {   
        cin>>v[i];
        S+=v[i];
        M2[v[i]]++;
    }
    if(S&1)
    {
        cout<<"NO";
        return(0);
    }

    ll csum=0;
    for(int i=1;i<=n;i++)
    {  
         M1[v[i]]++;
         M2[v[i]]--;
         csum+=v[i];
         if(csum==S/2)
         {
             cout<<"YES";
             return(0);
         }
         if(csum<S/2)
         {
             if(M2[(S/2)-csum]!=0)
              {  
                  cout<<"YES";
                return(0);
              }
         }
         
         if(csum>S/2)
         {
             if(M1[csum-(S/2)]!=0)
             {   cout<<"YES";
                return(0);
             }
         }

         
    }

    cout<<"NO"<<endl;
    return(0);

}












