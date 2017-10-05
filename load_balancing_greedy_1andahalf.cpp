//Solution to the Load balancing problem with approximation ratio of 2
#include<bits/stdc++.h>
using namespace std;
const int nmax=10009;
long long M;//Number of processors
long long N;//Number of jobs to be assigned
long long t[nmax];//The time needed for each task to be completed
set<long long> A[nmax];//The set of jobs for each processor
struct processor{
   long long idx;
   long long T;//The workload of each processor
   processor(){}
   processor(long long _idx,long long _T){
      idx=_idx;
      T=_T;
   }
   bool operator < (const processor &x)const{
      return T>x.T;
   }
};
priority_queue<processor> pq;
processor P[nmax];
void read(){
   cin>>M>>N;
   for(int i=1;i<=N;i++){
      cin>>t[i];
   }
}
void solve(){
   for(int i=1;i<=M;i++){
      P[i].idx=i;
      P[i].T=0;
      pq.push(P[i]);
   }
   sort(t+1,t+N+1);
   reverse(t+1,t+N+1);
   for(int i=1;i<=N;i++){
      processor curr=pq.top();
      pq.pop();
      curr.T+=t[i];
      P[curr.idx].T=curr.T;
      A[curr.idx].insert(i);
      pq.push(curr);
   }
   long long mx=0;
   for(int i=1;i<=M;i++){
      //cout<<"Processor "<<i<<" does jobs:";
      //for(set<int>::iterator it=A[i].begin();it!=A[i].end();it++){
      //   cout<<" "<<*it;
      //}
      //cout<<"\n";
      mx=max(mx,P[i].T);
   }
   cout<<mx<<"\n"; 
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   read();
   solve();
}
