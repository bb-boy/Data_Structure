#include <stdio.h>
#include <malloc.h>
#define num(a) sizeof(a) / sizeof(a[0])
#define MAX 100

typedef struct Edge {                 //边节点
	int pos;
	struct Edge* next_edge;
}EdgeNode,*edge_point;

typedef struct VNode {
	char data;
	edge_point first_edge;
}VNode;

typedef struct _Graph {

	int vexnum;
	int edgenum;
	VNode vexs[15];
}Graph;

int pos(Graph g, char c) {
	for (int i = 0; i < g.vexnum; i++) {
		if (c == g.vexs[i].data)
			return i;
	
	}
}

void link_edge_node(VNode &v, edge_point e) {
	edge_point  p = v.first_edge;
	while (p->next_edge!=NULL) {
		p = p->next_edge;

	}
	p->next_edge = e;
	
}


/*创建有向邻接表*/
Graph Create_Graph1(Graph& gp, char edge[][2]) {
	for (int i = 0; i < gp.edgenum; i++) {
		char c1 = edge[i][0];
		char c2 = edge[i][1];
		int a1 = pos(gp, c1);
		int a2 = pos(gp, c2);
		EdgeNode* node1 = (edge_point)calloc(1, sizeof(EdgeNode));
		node1->pos = a2;
		node1->next_edge = NULL;
		if (gp.vexs[a1].first_edge == NULL)
			gp.vexs[a1].first_edge = node1;

		else
			link_edge_node(gp.vexs[a1], node1);

		EdgeNode* node2 = (edge_point)calloc(1, sizeof(EdgeNode));
		node2->pos = a1;
		node2->next_edge = NULL;
		
	}
	return gp;
}


/*创建邻接表*/
Graph Create_Graph(Graph &gp,char edge[][2]) {
	for (int i = 0; i < gp.edgenum; i++) {
		char c1 = edge[i][0];
		char c2 = edge[i][1];
		int a1 = pos(gp, c1);
		int a2 = pos(gp, c2);
		EdgeNode* node1 = (edge_point)calloc(1, sizeof(EdgeNode));
		node1->pos = a2;
		node1->next_edge = NULL;
		if (gp.vexs[a1].first_edge == NULL)
			gp.vexs[a1].first_edge = node1;

		else
			link_edge_node(gp.vexs[a1], node1);

		EdgeNode* node2 = (edge_point)calloc(1, sizeof(EdgeNode));
		node2->pos = a1;
		node2->next_edge = NULL;
		if (gp.vexs[a2].first_edge == NULL)
			gp.vexs[a2].first_edge = node2;

		else
			link_edge_node(gp.vexs[a2], node2);
	}
	return gp;
}

/*打印无向邻接表*/
void print_Graph(Graph gp) {
	for (int i = 0; i < gp.vexnum; i++) {

		edge_point p = gp.vexs[i].first_edge;
		if (NULL == p)
			continue;
		while (p != NULL) {
			int j = p->pos;
			printf("%c%-3c", gp.vexs[i].data, gp.vexs[j].data);
			p = p->next_edge;
		}
	}
}

/*深度优先遍历*/


void DFS(Graph gp,int i,int *visited) {
	visited[i] = 1;
	printf("%c", gp.vexs[i].data);
	edge_point p = gp.vexs[i].first_edge;
	while (p != NULL) {
		int pos = p->pos;
		if (!visited[pos]) {
			visited[pos] = 1;
			printf("%c", gp.vexs[pos].data);
			p = gp.vexs[pos].first_edge;

		}
		else
			p = p->next_edge;

	}
}
	
void DFSTraverse(Graph gp) {
	int visited[MAX];
	for (int i = 0; i < gp.vexnum; i++)
		visited[i] = 0;
	for (int i = 0; i < gp.vexnum; i++) {
		if (!visited[i])
			DFS(gp, i, visited);
	}
}
	

/*广度优先遍历*/
void BFS(Graph gp) {
	int queue[MAX];
	int rear = 0,head = 0;
	int visited[MAX];
	for (int i = 0; i < gp.vexnum; i++)
		visited[i] = 0;

	for (int i = 0; i < gp.vexnum; i++) {
		if (!visited[i]) {
			visited[i] = 1;
			printf("%c", gp.vexs[i].data);
			queue[rear++] = i;
			while (rear != head) {
				int j = queue[head++];
				edge_point node = gp.vexs[j].first_edge;
				while (NULL != node) {
					int pos = node->pos;
					if (!visited[pos]) {
						visited[pos] = 1;
						printf("%c", gp.vexs[pos].data);
						queue[rear++] = pos;


					}
					node = node->next_edge;
				}
			}

			
		}
	}
	
	

}

int main() {
	char vex[] = { 'A','B','C','D','E','F','G' };
	char edge[][2] = {
		{'A','B'},
		{'B','E'},
		{'B','C'},
		{'B','F'},
		{'C','E'},
		{'D','C'},
		{'E','B'},
		{'E','D'},
		{'F','G'}
	};

	/*打印边*/
	//for (int i = 0; i < 7; i++) {
	//	printf("第%d条边是", i + 1);
	//	for (int j = 0; j < 2; j++) {
	//		printf("%c", edge[i][j]);
	//	}
	//	printf("\n");
	//}

	_Graph gp;
	gp.vexnum = num(vex);
	gp.edgenum = num(edge);
	for (int i = 0; i < gp.vexnum; i++) {
		gp.vexs[i].data = vex[i];
		gp.vexs[i].first_edge = NULL;
	}

	/*创建有向邻接表*/
	//Create_Graph(gp, edge);
	//print_Graph(gp);

	/*创建有向邻接表*/
	Create_Graph1(gp, edge);
	print_Graph(gp);

	//DFSTraverse(gp);
	BFS(gp);

	
}