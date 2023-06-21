#include <iostream>
#include <vector>
using namespace std;

struct vertex {
	int vertexld;
	int matrixld;
	vertex* prev;
	vertex* next;

	vertex() {
		vertexld = matrixld = -1;
		prev = next = NULL;
	}
	vertex(int v) {
		vertexld = v;
		matrixld = -1;
		prev = next = NULL;
	}
};

struct edge {
	vertex* src;
	vertex* dst;
	edge* prev;
	edge* next;

	edge() {
		src = dst = NULL;
		prev = next = NULL;
	}
	edge(vertex* s, vertex* dst) {
		src = s;
		this->dst = dst;
		prev = next = NULL;
	}
};

class vertexList {
private:
	vertex* header;
	vertex* trailer;
public:
	vertexList() {
		header = new vertex();
		trailer = new vertex();
		header->next = trailer;
		header->matrixld = -1;
		trailer->prev = header;
	}
	void insert(vertex* n) {
		n->prev = trailer->prev;
		n->next = trailer;
		n->matrixld = trailer->prev->matrixld + 1;
		trailer->prev->next = n;
		trailer->prev = n;
	}
	void erase(vertex* del) {
		for (vertex* cur = del; cur != trailer; cur = cur->next) {
			cur->matrixld--;
		}
		del->prev->next = del->next;
		del->next->prev = del->prev;
		delete del;
	}
	vertex* find(int v) {
		for (vertex* cur = header->next; cur != trailer; cur = cur->next) {
			if (cur->vertexld == v) {
				return cur;
			}
		}
		return NULL;
	}
};

class edgeList {
private:
	edge* header;
	edge* trailer;
public:
	edgeList() {
		header = new edge();
		trailer = new edge();
		header->next = trailer;
		trailer->prev = header;
	}
	void insert(edge* n) {
		n->prev = trailer->prev;
		n->next = trailer;
		trailer->prev->next = n;
		trailer->prev = n;
	}
	void eraseEdge(edge* del) {
		del->prev->next = del->next;
		del->next->prev = del->prev;
		delete del;
	}
};

class graph {
private:
	vector<vector<edge*>>edgeMatrix;
	vertexList vList;
	edgeList eList;
public:
	void insertV(int v) {
		if (vList.find(v) != NULL) {
			return;
		}
		vertex* n = new vertex(v);
		for (int i = 0; i < edgeMatrix.size(); i++) {
			edgeMatrix[i].push_back(NULL);
		}
		edgeMatrix.push_back(vector<edge*>(edgeMatrix.size() + 1, NULL));
		vList.insert(n);
	}
	void eraseV(int v) {
		vertex* del = vList.find(v);
		if (del == NULL) {
			return;
		}
		int matrixld = del->matrixld;
		for (int i = 0; i < edgeMatrix.size(); i++) {
			if (i != matrixld) {
				if (edgeMatrix[i][matrixld] != NULL) {
					eList.eraseEdge(edgeMatrix[i][matrixld]);
				}
				edgeMatrix[i].erase(edgeMatrix[i].begin() + matrixld);
			}
		}
		edgeMatrix.erase(edgeMatrix.begin() + matrixld);
		vList.erase(del);
	}
	void insertE(int s, int d) {
		vertex* src = vList.find(s);
		vertex* dst = vList.find(d);
		if (src == NULL || dst == NULL) {
			return;
		}
		int srcMatrixld = src->matrixld;
		int dstMatrixld = dst->matrixld;
		if (edgeMatrix[srcMatrixld][dstMatrixld] != NULL || edgeMatrix[dstMatrixld][srcMatrixld]) {
			return;
		}
		edge* n = new edge(src,dst);
		eList.insert(n);
		edgeMatrix[srcMatrixld][dstMatrixld] = edgeMatrix[dstMatrixld][srcMatrixld] = n;
	}
	void eraseE(int s, int d) {
		vertex* src = vList.find(s);
		vertex* dst = vList.find(d);
		if (src == NULL || dst == NULL) {
			return;
		}
		int srcMatrixld = src->matrixld;
		int dstMatrixld = dst->matrixld;
		if (edgeMatrix[srcMatrixld][dstMatrixld] != NULL || edgeMatrix[dstMatrixld][srcMatrixld]) {
			return;
		}
		eList.eraseEdge(edgeMatrix[srcMatrixld][dstMatrixld]);
		edgeMatrix[srcMatrixld][dstMatrixld] = edgeMatrix[dstMatrixld][srcMatrixld] = NULL;
	}
};
