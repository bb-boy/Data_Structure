#include <stdio.h>
#include <malloc.h>
#define num(a) sizeof(a) / sizeof(a[0])

typedef struct Edge {                 //�߽ڵ�
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


/*���������ڽӱ�*/
Graph Create_Graph1(Graph& gp, char edge[][2]) {
	for (int i = 0; i < gp.vexnum; i++) {
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


/*�����ڽӱ�*/
Graph Create_Graph(Graph &gp,char edge[][2]) {
	for (int i = 0; i < gp.vexnum; i++) {
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

/*��ӡ�ڽӱ�*/
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


int main() {
	char vex[] = { 'A','B','C','D','E','F','G' };
	char edge[][2] = {
		{'A','B'},
		{'A','C'},
		{'A','D'},
		{'B','C'},
		{'C','D'},
		{'E','G'},
		{'F','G'}
	};

	/*��ӡ��*/
	//for (int i = 0; i < 7; i++) {
	//	printf("��%d������", i + 1);
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

	/*���������ڽӱ�*/
	Create_Graph(gp, edge);
	print_Graph(gp);

	/*���������ڽӱ�*/
	Create_Graph1(gp, edge);
	print_Graph(gp);


}