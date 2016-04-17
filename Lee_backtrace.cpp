#include <iostream>
#include <list>
#include <climits>
using namespace std;

const int dx[]={0,0,-1,1},dy[]={-1,1,0,0};
int n,m,dist[10][10];
char a[10][10];
bool visited[10][10];
bool valid_coord(int i,int j)
{
    return (i>=0 && j>=0 && i<n && j<m);
}
void path(int x,int y)
{
    list<char> p;
    while(a[x][y]!='s')
    {
        for(int i=0;i<4;i++)
        {
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(!valid_coord(nx,ny) || a[nx][ny]=='X')
                continue;
            if(dist[nx][ny]<dist[x][y])
            {
                if(i==0)
                    p.push_front('R');
                else if(i==1)
                    p.push_front('L');
                else if(i==2)
                    p.push_front('D');
                else
                    p.push_front('U');
                x=nx;
                y=ny;
                break;
            }
        }
    }
    list<char>::iterator it;
    for(it=p.begin();it!=p.end();it++)
        cout<<*it<<"--->";
}
void lee(int x,int y)
{
    list<int> q;
    q.push_back(x);
    q.push_back(y);
    dist[x][y]=0;
    visited[x][y]=true;
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
            dist[i][j]=INT_MAX;
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
    lee(sx,sy);
    /*for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
            cout<<dist[i][j]<<" ";
        cout<<endl;
    }*/
    path(dx,dy);
    cout<<"\nDistance = "<<dist[dx][dy]<<" units";
	return 0;
}
