#include<iostream>
#define infinity 9999
#define max 100
using namespace std;
class graph
{
  public:
    int G[max][max];
    int n;
  void get()
  {
    cout<<"Enter the number of vertices\n";
    cin>>n;
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=n;j++)
      {
        cin>>G[i][j];
      }
    }
  }

  void show()
  {
    cout<<"Entered graph adj matrix is\n";
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=n;j++)
      {
        cout<<G[i][j]<<"\t";
      }
      cout<<endl;
    }
  }

  void dj()
  {
    int s,count,min,nextv;
    int i,j;
    int cost[max][max],known[max],dist[max],path[max];

    for(i=1;i<=n;i++)
    {
      for(j=1;j<=n;j++)
      {
        if(G[i][j]==0)
        {
          cost[i][j]=infinity;
        }
        else
        {
          cost[i][j]=G[i][j];
        }
      }
    }

    cout<<"Enter the source node\n";
    cin>>s;
    for(i=1;i<=n;i++)
    {
      dist[i]=cost[s][i];
      path[i]=s;
      known[i]=0;
    }

    dist[s]=0;
    known[s]=1;
    count=1;
    while(count<=n)
    {
      min=infinity;
      for(i=1;i<=n;i++)
      {
        if(min>dist[i]&&known[i]!=1)
        {
          min=dist[i];
          nextv=i;
        }
      }

      known[nextv]=1;
      for(int i=1;i<=n;i++)
      {
        if(known[i]!=1)
        {
          if(min+cost[nextv][i]<dist[i])
          {
            dist[i]=min+cost[nextv][i];
            path[i]=nextv;
          }
        }
      }
      count++;
    }
    for(int i=1;i<=n;i++)
    {
      cout<<"VERTEX"<<i<<"KNOWN::"<<known[i]<<"DIST::"<<dist[i]<<"PATH::"<<path[i]<<"\n";
    }
  }


};






int main()
{
  graph obj;
  obj.get();
  obj.show();
  obj.dj();
  return 0;
}
