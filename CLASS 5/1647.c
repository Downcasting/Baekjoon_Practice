
// 1647번 - 도시 분할 계획

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

/* Main */
int main(void){
    int V, E;
    int n1, n2, w;
    int count=0;
    scanf("%d %d", &V, &E);

    Node* nodes[V];
    Edge* edges[E];

    for(int i=0; i<V; i++)
        nodes[i] = makeNode(i);
    for(int i=0; i<E; i++){
        scanf("%d %d %d",&n1, &n2, &w);
        edges[i] = makeEdge(nodes[n1-1], nodes[n2-1], w);
    }
    qsort(edges, E, sizeof(Edge*), compare);
    //for(int i=0; i<E; i++)
        //printf("%d: %d %d, weight %d\n", i+1, edges[i]->node1->num+1, edges[i]->node2->num+1, edges[i]->weight);

    int totalWeight = 0;
    for(int i=0; i<E && count < V-2; i++){
        Node* n1 = getParent(edges[i]->node1);
        Node* n2 = getParent(edges[i]->node2);
        if(n1 != n2){
            //printf("%dth part: %d %d connected Parent-[%d %d], weight was %d\n",i+1, edges[i]->node1->num+1, edges[i]->node2->num+1, n1->num+1, n2->num+1, edges[i]->weight);
            count++;
            if(n1->height > n2->height)
                n2->parent = n1;
            else if(n1->height < n2->height)
                n1->parent = n2;
            else{
                n1->parent = n2;
                n2->height = n2->height + 1;
            }
            totalWeight += edges[i]->weight;
        }
        //n1 = getParent(edges[i]->node1);
        //n2 = getParent(edges[i]->node2);
    }
    printf("%d", totalWeight);
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
int static compare(const void* first, const void* second) {
    if((*(Edge**)first)->weight - (*(Edge**)second)->weight > 0)
        return 1;
    else if((*(Edge**)first)->weight - (*(Edge**)second)->weight < 0)
        return -1;
    else
        return 0;
}
Node* getParent(Node* node){ // ?
    Node* nod = node;
    while(nod->parent != NULL){
        nod = nod->parent;
    }
    return nod;
}