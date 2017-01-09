#include<iostream>
using namespace std;

int graph[100][100];
int dis[100][100];
int nodes;


int min(int a,int b)
{
	if(a<b)
		return a;
	else 
		return b;
}

void floydWarshall()
{
	int k,i,j;
	for(i=0;i<nodes;i++)
	{
		for(j=0;j<nodes;j++)
		{
			dis[i][j]=graph[i][j];

		}
	}

	for(k=0;k<nodes;k++)
	{
		for(i=0;i<nodes;i++)
		{
			for(j=0;j<nodes;j++)
			{	
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
}



int main()
{
	int i,j;
	cout<<"Enter the number of nodes in your graph: \n";
	cin>>nodes;
	cout<<"\n Enter the distance matrix :";


	for(i=0;i<nodes;i++)
	{
		for(j=0;j<nodes;j++)
		{
			cin>>graph[i][j];
		}
	}

	floydWarshall();

	for(i=0;i<nodes;i++)
	{
		for(j=0;j<nodes;j++)
		{
			
			if(dis[i][j]==99)
			{
				cout<<"INF"<<" ";
			}
			else
				cout<<dis[i][j]<<" ";

		}
		cout<<endl;
	}
}


