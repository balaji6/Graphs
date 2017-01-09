#include<iostream>
#include<vector>

using namespace std;

bool visited[10];
vector<int> v[10];

void dfs(int s)
{
	int i;
	visited[s]=true;
	cout<<s<<endl;
	for(int i=0;i<v[s].size();i++)
	{
		if((visited[v[s][i]])==false)
		{
			
			dfs(v[s][i]);
		}
	}
}

int main()
{
	int x,y,i;
	int edges, vertices;
	cout<<"Enter the number of edges and vertices :";
	cin>>edges>>vertices;

	for(i=0;i<vertices;i++)
	{
		visited[i]=false;

	}	

	for(i=0;i<edges;i++)
	{
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);

	}

	dfs(0);
}