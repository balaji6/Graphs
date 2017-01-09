#include<iostream>
#include<vector>
#include<queue>
using namespace std;

bool visited[10];
vector<int> v[10];
int level[10];

void bfs(int s)
{
	queue<int> q;
	q.push(s);

	visited[s]=true;

	while(!q.empty())
	{
		int p = q.front();
		cout<<p<<endl;
		q.pop();
		for(int i=0;i<v[p].size();++i)
		{
			if((visited[v[p][i]])==false)
			{
				q.push(v[p][i]);
				level[v[p][i]]=level[p]+1;
				visited[v[p][i]]=true;
				
			}
		}

	}
}

int main()
{
	int i,nodes,edges,x,y;
	cout<<"Enter the number of nodes and edges in the graph: ";
	cin>>nodes>>edges;
	for(i=0;i<nodes;i++)
	{
		visited[i]=false;
		level[i]=0;
	}
	for(i=0;i<edges;i++)
	{
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	bfs(0);
	cout<<"\nThe level of each nodes are: ";
	for(i=0;i<nodes;i++)
	{
		cout<<"Node "<<i<<": "<<level[i]<<endl;
	}
}