#ifndef HASHMAP_H
#define HASHMAP_H

#include <iostream>
#include <algorithm>
#include <functional>

template <typename, typename>
struct Node;

template<typename K, typename V>
std::ostream& operator<<(std::ostream&, const Node<K, V>&);

template <typename K, typename V>
struct Node {
	K key;
	V value;
	Node<K, V>* next = nullptr;

	Node() {}

	Node(K k, V v) {
		key = k;
		value = v;
	}

	int& operator+(V v) {
		this->value = this->value + v;
		return this->value;
	}

	int& operator-(V v) {
		this->value = this->value - v;
		return this->value;
	}

	Node<K, V>& operator=(V v) {
		this->value = v;
		return *this;
	}

	friend std::ostream& operator<< <>(std::ostream& os, const Node<K, V>& node);
};

template <typename K, typename V>
std::ostream& operator <<(std::ostream& os, const Node<K, V>& node) {
	return os << "Key: " << node.key << " Value: " << node.value;
}

template <typename K, typename V>
class MyHashMap {
private:
	int size = 2;
	Node<K, V>** elem;
	int filled_buckets = 0;
	const double threshold = 0.9;

	int hashKey(K key) {
		size_t index = std::hash<K>() (key);
		return index % size;
	}

public:
	/** Initialize your data structure here. */
	MyHashMap() {
		elem = new Node<K, V>*[size];
		for (int i = 0; i < size; i++)
		{
			elem[i] = nullptr;
		}
	}

	~MyHashMap() {
		delete[] elem;
	}

	Node<K, V>& operator[](K key) {
		int h_index = hashKey(key);
		Node<K, V>* head = elem[h_index];
		Node<K, V>* prev = nullptr;
		if (head == nullptr) {
			elem[h_index] = new Node<K, V>(key, V());
			return *elem[h_index];
		}
		else {
			while (head != nullptr)
			{
				prev = head;
				if (head->key == key)
					return *head;
				head = head->next;
			}
			prev->next = new Node<K, V>(key, V());
			return *prev->next;
		}
	}


	void set(K key, V value) {
		int h_index = hashKey(key);
		Node<K, V>* head = elem[h_index];
		Node<K, V>* prev = nullptr;
		if (head != nullptr) {
			while (head != nullptr)
			{
				prev = head;
				if (head->key == key) {
					head->value = value;
					return;
				}
				head = head->next;
			}
			prev->next = new Node<K, V>(key, value);
		}
		else {
			elem[h_index] = new Node<K, V>(key, value);
			++filled_buckets;
		}

		// check if arr is almost full, resize if necessary
		float load_factor = filled_buckets / (float)size;
		if (load_factor > threshold)
		{
			int old_size = size;
			size *= 2;
			Node<K, V>** temp = new Node<K, V>*[size];
			for (int i = 0; i < size; i++)
			{
				temp[i] = nullptr;
			}
			for (int i = 0; i < old_size; i++)
			{
				if (elem[i] != nullptr) {
					int new_h_index = hashKey(elem[i]->key);
					temp[new_h_index] = elem[i];
				}
			}
			delete[] elem;
			elem = temp;
		}
	}

	/** Returns the value to which the specified key is mapped*/
	V& get(K key) {
		int h_index = hashKey(key);
		Node<K, V>* head = elem[h_index];
		while (head != nullptr)
		{
			if (head->key == key)
				return head->value;
			head = head->next;
		}
		return head->value;
	}

	/** Removes the mapping of the specified value key if this map contains a mapping for the key */
	void remove(K key) {
		int h_index = hashKey(key);
		Node<K, V>* head = elem[h_index];
		Node<K, V>* prev = nullptr;
		if (head == nullptr)
			return;
		while (head != nullptr)
		{
			if (head->key == key)
				break;
			prev = head;
			head = head->next;
		}


		if (head->next == nullptr) { // only element in the bucket
			delete elem[h_index]; // since elem[h_index] was created using 'new';
			elem[h_index] = nullptr;
			return;
		}
		else {
			if (prev != nullptr) {
				prev->next = head->next;
			}
			// set prev as head
			elem[h_index] = prev;
		}
	}

	bool has(int key) {
		int h_index = hashKey(key);
		Node<K, V>* head = elem[h_index];
		if (head == nullptr)
			return false;
		while (head != nullptr)
		{
			if (head->key == key)
				return true;
			head = head->next;
		}
		return false;
	}
};

#endif // !HASHMAP_H