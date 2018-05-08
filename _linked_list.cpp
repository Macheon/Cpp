#include<iostream>

using namespace std;

class node {
public:
	int value;
	node* next = NULL;
};

class list {
private:
	node* head;
public:
	list();
	~list();
	bool Search(int value, node **l, node **p);
	bool Insert(int x);
	bool Delete(int x, node **l);
	void show();
};

list::list() {
	head = NULL;
}
list::~list() {}

void list::show() {
	int i = 0;
	node* l;
	l = head;
	while (l != NULL) {
		cout << l->value << " ";
		l = l->next;
		i++;
	}
	if (i == 0)cout << "There is no data in this list";
	cout << "\n";
}
bool list::Search(int x, node **l, node **p) { // sorted 가정
	*p = NULL;
	*l = head;
	while (*l != NULL) {
		if (x > (*l)->value) {
			*p = *l; *l = (*l)->next;
		}
		else if (x == (*l)->value) {
			return true;
		}
		else return false;
	}
	return false;
}

bool list::Insert(int x) {
	node *l, *p, *k;
	if (!Search(x, &l, &p)){
		k = new node();
		k->value = x;
		k->next = l;
		if (p != NULL) p->next = k;
		else head = k;
	}
	else {
		return false;
	}
	return true;
}

bool list::Delete(int x) {
	node *p;
	node *l;
	if (Search(x, &l, &p)) {
		if (p != NULL)p->next = l->next;
		else head = l->next;
		delete l;
	}
	else {
		return false;
	}
	return true;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	int cmd=-1, val=0;
	node *p, *l;
	list* lst=new list();
	while (true) {
		while (cmd < 0 || cmd > 3) {
			cout << "\ninput cmd (0 : se, 1 : in, 2 : de, 3 : sh) : ";
			cin >> cmd;
		}
		if (cmd != 3) {
			cout << "input val in integer : ";
			cin >> val;
			switch (cmd) {
			case 0: 
				if (!lst->Search(val, &p, &l)) cout << "Value " << val << " is not in list\n";
				else cout << "Value " << val << " is successfully searced\n";
				break;
			case 1:
				if (!lst->Insert(val)) cout << "Value " << val << " is alreay in list\n";
				else cout << "Value " << val << " is successfully inserted\n";
				break;
			case 2:
				if(!lst->Delete(val)) cout << "Value " << val << " is not in list\n";
				else cout << "Value " << val << " is successfully deleted\n";
				break;
			}
		}
		else { lst->show(); }
		cmd = -1;
	}
}
