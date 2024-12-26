class DynamicArray {
   private:
	int* backingArr;
	int size;
	int capacity;

   public:
	DynamicArray(int capacity) {
		this->capacity = capacity;
		size = 0;
		backingArr = new int[capacity];
	}

	// DynamicArray(int capacity) : capacity(capacity), size(0) { backingArr = new int[capacity]; }

	int get(int i) { return backingArr[i]; }

	void set(int i, int n) { backingArr[i] = n; }

	void pushback(int n) {
		if (size == capacity) {
			resize();
		}

		set(size, n);
		size++;
	}

	int popback() {
		int val = get(size - 1);
		set(size - 1, 0);
		size--;
		return val;
	}

	// int popback() {
	// 	if (size > 0) {
	// 		size--;
	// 	}
	// 	return backingArr[size];
	// }

	void resize() {
		int newCapacity = capacity * 2;
		int* newArr = new int[newCapacity];
		for (int i = 0; i < size; i++) {
			newArr[i] = backingArr[i];
		}
		// delete (backingArr);
		delete[] backingArr;
		backingArr = newArr;

		capacity = newCapacity;
	}

	// void resize() {
	// 	capacity *= 2;
	// 	int* newArr = new int[capacity];
	// 	for (int i = 0; i < size; i++) {
	// 		newArr[i] = backingArr[i];
	// 	}
	// 	delete[] backingArr;
	// 	backingArr = newArr;
	// }

	int getSize() { return size; }

	int getCapacity() { return capacity; }
};