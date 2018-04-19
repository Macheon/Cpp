#include <iostream>

#ifndef _GRAPH.H
#define _GRAPH.H

using namespace std;

class node {
private:
	node * next;
	int value;
	int edge;
public:
	node();
	~node();
	node* getNext();
	void setNext(node*);
	int getValue();
	void setValue(int);
	int getEdge();
	void setEdge(int);
};

node::node() {
	next = NULL;
	value = 0;
	edge = 0;
}
node::~node(){}
void node::setNext(node* next) {
	this->next = next;
}
void node::setValue(int value) {
	this->value = value;
}
void node::setEdge(int edge) {
	this->edge = edge;
}
node* node::getNext() {
	return this->next;
}
int node::getValue() {
	return this->value;
}
int node::getEdge() {
	return this->edge;
}

class s_node {
private:
	s_node* s_next;
	int value;
	node* n_next;
public:
	s_node();
	~s_node();
	s_node* getS_next();
	node* getN_next();
	int getValue();
	void setS_next(s_node*);
	void setN_next(node*);
	void setValue(int);
};

s_node::s_node() {
	s_next = NULL;
	n_next = NULL;
	value = 0;
}

s_node::~s_node() {}

s_node* s_node::getS_next() {
	return s_next;
}

node* s_node::getN_next() {
	return n_next;
}
int s_node::getValue() {
	return value;
}

void s_node::setS_next(s_node* s_next) {
	this->s_next = s_next;
}
void s_node::setN_next(node* n_next) {
	this->n_next = n_next;
}
void s_node::setValue(int value) {
	this->value = value;
}

class graph {
private:
	s_node * head;
public:
	graph();
	~graph();
	bool s_search(s_node**, s_node**, int);
	bool insert(int, int, int);
	void show();
};

graph::graph() {
	head = NULL;
}

graph::~graph(){}
bool graph::s_search(s_node** p, s_node** l, int value) {
	*p = head;
	*l = NULL;
	while (*p != NULL) {
		if ((*p)->getValue() == value) {
			*l = *p;
			*p = (*p)->getS_next();
			return true;
		}
		*l = *p;
		*p = (*p)->getS_next();
	}
	return false;
}
bool graph::insert(int s_nd_v, int n_nd_v, int ed_v) {
	if (head == NULL) {
		s_node* h = new s_node();
		node* n = new node();

		head = h;
		h->setN_next(n);
		h->setValue(s_nd_v);
		n->setValue(n_nd_v);
		n->setEdge(ed_v);
		return true;
	}
	else {
		s_node* p;
		s_node* l;
		bool flag;
		flag = s_search(&p, &l, s_nd_v);
		if (flag) {
			node *cur_n = l->getN_next();
			node *post_n = NULL;
			while (cur_n != NULL) {
				post_n = cur_n;
				cur_n = cur_n->getNext();
			}
			cur_n = new node();
			post_n->setNext(cur_n);

			cur_n->setEdge(ed_v);
			cur_n->setValue(n_nd_v);

			return true;
		}
		else {
			p = new s_node();
			node *n = new node();
			l->setS_next(p);
			p->setN_next(n);
			p->setValue(s_nd_v);
			n->setEdge(ed_v);
			n->setValue(n_nd_v);

			return true;
		}
	}
	return false;
}

void graph::show() {
	s_node* s = head;
	node* n = NULL;
	while (s != NULL) {
		cout << s->getValue() << " ";
		n = s->getN_next();
		while (n != NULL) {
			cout <<"-> "<< n->getValue() <<" ("<<n->getEdge()<< ") ";
			n = n->getNext();
		}
		s = s->getS_next();
		cout << "\n";
	}
}

#endif
