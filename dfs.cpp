#include<bits/stdc++.h>
using namespace std;
int top = -1;
int a[20][20];

int isEmpty(int n)
{
    if(top == -1)
        return 1;
    else
        return 0;
}

int isFull(int n)
{
    if(top == n-1)
        return 1;
    else
        return 0;
}

int push(int stack[], int n, int ele)
{
    if(isFull(n))
        printf("\nStack is full.\n");
    else{
        stack[++top] == ele;
    }
}

int pop(int stack[], int n)
{
    int temp;
    if(isEmpty(n))
        printf("\nStack is empty.\n");
    else
        temp = stack[top--];
    return temp;
}

void dfs(int vis[], int si, int n, int a[][20])
{
    if(vis[si]==0){
        printf("%d ",si);
        vis[si] = 1;
        for(int i=1;i<=n;i++)
        {
            if(a[si][i]==1 && vis[i] != 1)
            dfs(vis, i, n, a);
        }
    }
}

int main()
{
    int n,e,i,j,u,v,si,t;
    cout << "\nEnter the number of nodes and number of edges in your graph: " << endl;
    cin >> n >> e;
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=n;j++)
            a[i][j] = 0;
    }
    for(i=0;i<e;i++)
    {
        scanf("%d%d",&u,&v);
        a[u][v] = 1;
        a[v][u] = 1;
    }
    printf("Adjacency matrix of the given edges are: \n");
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=n;j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }
    int stack[n];
    int vis[n];
    cout << "\nEnter the starting index for traversal of the graph: " << endl;
    cin >> si;
    // Initialising the visited array with 0
    for(i=0;i<=n;i++)
        vis[i] = 0; 
    dfs(vis, si, n, a);
    return 0;
}
