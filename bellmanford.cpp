#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

vector<int> edges[10];
double dist[10];
int nodes,edge;
int flag=0;

void bellmanFord()
{
	dist[0]=0;
	int i,j=0;;
	for(i=0;i<nodes-1;i++)
	{
		
        for(j=0;j<edge;j++)
        {

            if(dist[edges[j][0]]!=100000&&dist[ edges[j][0]  ] + edges[j][2] < dist[ edges[j][1]]){
                dist[ edges[j][1] ] = dist[ edges[j][0]  ] + edges[j][2];
            }
            
        }
	}

	for(j=0;j<edge;j++)
	{
		if(dist[edges[j][0]]!=100000&&dist[ edges[j][0]  ] + edges[j][2] < dist[ edges[j][1]])
		{
			cout<<"There is a negative edge cycle in the graph!!";
			flag=1;
		}
	}
}

int main()
{
	int i,x,y,w;
	cout<<"Enter no of nodes and edges: ";
	cin>>nodes>>edge;
	for(i=0;i<nodes;i++)
	{
		dist[i]= 100000;
	}
	for(i=0;i<edge;i++)
	{
		cin>>x>>y>>w;
		edges[i].push_back(x);
		edges[i].push_back(y);
		edges[i].push_back(w);
	}
	bellmanFord();
	if(flag==0)
	{
		for(i=0;i<nodes;i++)
		{
			cout<<dist[i]<<" ";
		}
	}

}