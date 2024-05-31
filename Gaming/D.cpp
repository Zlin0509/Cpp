
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTEX_NUM 20

#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define NOT_FOUND -1

typedef int Status;
typedef int VRType;
typedef int InfoType;
typedef char VertexType;

typedef struct
{
    VRType adj;
    InfoType *info;
} ArcCell, AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];

typedef struct
{
    VertexType vexs[MAX_VERTEX_NUM];
    AdjMatrix arcs;
    int vexnum;
    int arcnum;
} MGraph;
bool visited[MAX_VERTEX_NUM];

int LocateVex(MGraph G, VertexType v)
{
    for (int i = 0; i < G.vexnum; ++i)
    {
        if (G.vexs[i] == v)
            return i;
    }
    return NOT_FOUND;
}

void CreateGraph(MGraph &G)
{
    scanf("%d %d", &(G.vexnum), &(G.arcnum));
    getchar();

    for (int i = 0; i < G.vexnum; ++i)
        scanf("%c", &(G.vexs[i]));
    getchar();

    for (int i = 0; i < G.arcnum; ++i)
        for (int j = 0; j < G.arcnum; ++j)
            G.arcs[i][j].adj = 0;

    for (int i = 0; i < G.arcnum; ++i)
    {
        VertexType v1, v2;
        scanf("%c%c", &v1, &v2);
        getchar();
        int r1 = LocateVex(G, v1);
        int r2 = LocateVex(G, v2);
        G.arcs[r1][r2].adj = 1;
        G.arcs[r2][r1].adj = 1;
    }
}

void DFSTraverse(MGraph G)
{
    for (int i = 0; i < G.vexnum; i++)
    {
        visited[i] = false;
    }
}
void BFSTraverse(MGraph G)
{
    for (int i = 0; i < G.vexnum; i++)
    {
        visited[i] = false;
    }
    
}

int main()
{
    MGraph x;

    CreateGraph(x);

    printf("DFS:");
    DFSTraverse(x);
    printf("\n");

    printf("BFS:");
    BFSTraverse(x);
    printf("\n");

    return 0;
}
/* 你的代码将被嵌在这里 */