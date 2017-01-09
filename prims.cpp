#include<iostream>
#include<vector>
#include<utility>
#include<functional>
#include<queue>
#include<vector>
using namespace std;

const int maxi = 1e4 + 5;
typedef pair<long long, int> PII;
bool marked[maxi];

vector<PII> adj[maxi];

long long prim(int x)
{
	priority_queue<PII, vector<PII>, greater<PII> > Q;
	int y;
	PII p;
	long long minCost=0;
	Q.push(make_pair(0,x));
	while(!Q.empty())
	{
		// Select the edge with minimum weight
		p = Q.top();
		Q.pop();
		x = p.second;

		// check for cycle

		if(marked[x]==true)
			continue;
		minCost+=p.first;
		marked[x]=true;

		for(int i=0;i<adj[x].size();i++)
		{
			y=adj[x][i].second;
			if(marked[y]==false)
				Q.push(adj[x][i]);
		}
	}

	return minCost;
}

int main()
{
	int nodes,edges,x,y;
	long long weight,minCost;
	cin>>nodes>>edges;
	for(int i=0;i<edges;i++)
	{
		cin>>x>>y>>weight;
		adj[x].push_back(make_pair(weight,y));
		adj[y].push_back(make_pair(weight,x));
	}

	minCost=prim(1);
	cout<<minCost<<endl;
	return 0;
}