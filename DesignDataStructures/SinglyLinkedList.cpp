#include <vector>
class Node {
   public:
	int val;
	Node* next;
	Node(int val) : val(val) {}
	Node(int val, Node* next) : val(val), next(next) {}
};

class LinkedList {
   private:
	Node* head;
	Node* tail;
	int size;

	Node* getNode(int index) {
		if (index < 0 || index >= size)
			return nullptr;
		if (index == size - 1)
			return tail;

		Node* curr = head;
		for (int i = 0; i < index; i++) {
			curr = curr->next;
		}
		return curr;
	}

   public:
	LinkedList() : head(nullptr), tail(nullptr), size(0) {}

	int get(int index) {
		if (size == 0)
			return -1;
		if (index < 0 || index >= size)
			return -1;
		if (index == size - 1)
			return tail->val;

		Node* curr = head;
		for (int i = 0; i < index; i++) {
			curr = curr->next;
		}
		return curr->val;
	}

	void insertHead(int val) {
		if (size == 0) {
			head = tail = new Node(val);
			size++;
			return;
		}

		Node* n = new Node(val, head);
		head = n;
		size++;
	}

	void insertTail(int val) {
		if (size == 0) {
			head = tail = new Node(val);
			size++;
			return;
		}
		Node* n = new Node(val);
		tail->next = n;
		tail = n;
		size++;
	}

	bool remove(int index) {
		if (size == 0)
			return false;
		if (index < 0 || index >= size)
			return false;
		if (size == 1) {
			delete head;
			delete tail;
			head = tail = nullptr;
			size = 0;
			return true;
		}

		if (index == 0) {
			Node* oldHead = head;
			head = head->next;
			delete oldHead;
			size--;
			return true;
		}

		Node* prev = getNode(index - 1);
		Node* curr = getNode(index);
		prev->next = curr->next;
		delete curr;

		if (index == size - 1) {
			tail = prev;
		}

		size--;
		return true;
	}

	std::vector<int> getValues() {
		std::vector<int> v;
		Node* curr = head;
		while (curr) {
			v.push_back(curr->val);
			curr = curr->next;
		}

		return v;
	}
};