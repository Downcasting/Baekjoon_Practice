/* Include */
#include <stdio.h>
#include <stdlib.h>

/* Define */
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a>b?b:a

/* Struct */
typedef struct Node{
    int num;
    int height;
    struct Node* parent;
} Node;
typedef struct{
    Node* node1;
    Node* node2;
    int weight;
} Edge;

/* Global Var */

/* Functions */
Node* makeNode(int num);
Edge* makeEdge(Node* n1, Node* n2, int w);
int static compare (const void* first, const void* second);
Node* getParent(Node* node);
int sameParents(Edge* edge);

/* Main */
int main(void){
    int V, E;
    int n1, n2, w;
    scanf("%d %d", &V, &E);

    Node* nodes[V];
    Edge* edges[E];

    for(int i=0; i<V; i++)
        nodes[i] = makeNode(i);
    for(int i=0; i<E; i++){
        scanf("%d %d %d",&n1, &n2, &w);
        edges[i] = makeEdge(nodes[n1-1], nodes[n2-1], w);
    }
    qsort(edges, E, sizeof(Edge), compare);

    int totalWeight = 0;
    for(int i=0; i<E; i++){
        if(!sameParents(edges[i])){
            if((edges[i])->node1->height > (edges[i])->node2->height)
                (edges[i])->node2->parent = (edges[i])->node1;
            else if((edges[i])->node1->height < (edges[i])->node2->height)
                (edges[i])->node1->parent = (edges[i])->node2;
            else{
                (edges[i])->node1->parent = (edges[i])->node2;
                (edges[i])->node2->height = (edges[i])->node2->height + 1;
            }
            totalWeight += edges[i]->weight;
        }
    }
    printf("%d\n", totalWeight);
    return 0;
}

/* Functions */
Node* makeNode(int num){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->num = num;
    newNode->height = 0;
    newNode->parent = NULL;
    return newNode;
}
Edge* makeEdge(Node* n1, Node* n2, int w){
    Edge* newEdge = (Edge*)malloc(sizeof(Edge));
    newEdge->node1 = n1;
    newEdge->node2 = n2;
    newEdge->weight = w;
    return newEdge;
}
int static compare (const void* first, const void* second)
{
    return ((Edge*)first)->weight - ((Edge*)second)->weight;
}
Node* getParent(Node* node){ // ?
    if(node == NULL)
        return NULL;
    Node* nod = node;
    while(nod->parent != NULL){
        nod = nod->parent;
    }
    return nod;
}
int sameParents(Edge* edge){
    return getParent(edge->node1) == getParent(edge->node2);
}