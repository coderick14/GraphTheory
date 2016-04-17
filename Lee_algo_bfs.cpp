#include <iostream>
#include <list>
using namespace std;

char a[10][10];
const int dx[]={0,0,-1,1},dy[]={-1,1,0,0};
int n,m,dist[10][10];
bool visited[10][10];
bool valid_coord(int i,int j)
{
    return (i>=0 && j>=0 && i<n && j<m);
}
void bfs(int x,int y)
{
    list<int> q;
    q.push_back(x);
    q.push_back(y);
    visited[x][y]=true;
    dist[x][y]=0;
    while(!q.empty())
    {
        x=q.front();
        q.pop_front();
        y=q.front();
        q.pop_front();
        for(int i=0;i<4;i++)
        {
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(!valid_coord(nx,ny) || visited[nx][ny])
                continue;
            if(a[nx][ny]=='X')
                continue;
            dist[nx][ny]=dist[x][y]+1;    
            q.push_back(nx);
            q.push_back(ny);
            visited[nx][ny]=true;
        }
    }    
}
int main() 
{
    int i,j,sx,sy,dx,dy;
    cin>>n>>m;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {    
            cin>>a[i][j];
            visited[i][j]=false;
            if(a[i][j]=='s')
            {
                sx=i;
                sy=j;
            }
            if(a[i][j]=='d')
            {
                dx=i;
                dy=j;
            }
        }     
    }
    bfs(sx,sy);
    cout<<dist[dx][dy];
	return 0;
}
