#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int ar[n];
    for(int i=0;i<n;i++)
    {
        cin>>ar[i];
    }
    map<int,int>mp;
    for(int i=0;i<n;i++)
    {
        mp[ar[i]]++;
    }
    for(auto x:mp)
    {
        if(x.second>1){
        cout<<x.first<<endl;
        break;
        }
    }
}
