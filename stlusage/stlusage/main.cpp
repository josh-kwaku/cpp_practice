// bitset_any.cpp
// compile with: /EHsc
#include <bitset>
#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>

using namespace std;


template<typename K, typename V>
struct Node; // forward declare

template<typename K, typename V>
ostream& operator<<(ostream&, const Node<K, V>&);


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
	friend ostream& operator<<(ostream& os, const Node& node);
};

template<typename K, typename V>
ostream& operator<<(ostream& os, const Node<K, V>& node) {
	cout << "Fired" << '\n';
	if (node == nullptr)
		return os << "null" << '\n';
	return os << "{" << '\n' << "key: " << node.key << '\n' << "value: " << node.value << '\n' << "next: " << node.next << '\n' << "}";
}

template <typename K, typename V>
class MyHashMap {
private:
	int size = 256;
	Node<K, V>** elem;
	int filled_buckets = 0;
	const double threshold = 0.9;

	int hashKey(K key) {
		size_t index = hash<K>() (key);
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

    /** value will always be non-negative. */
    void put(K key, V value) {
		int h_index = hashKey(key);
		Node<K, V>* head = elem[h_index];
		//cout << "hindex: " << h_index << " , " << head << '\n';
		if (head != nullptr) {
			while (head != nullptr)
			{
				if (head->key == key) {
					head->value = value;
					return;
				}
				head = head->next;
			}
			elem[h_index] = new Node<K, V>(key, value);
		}
		else {
			elem[h_index] = new Node<K, V>(key, value);
			++filled_buckets;
		}
	
		// check if arr is almost full, resize if necessary
		float load_factor = filled_buckets / (float)size;
		if (load_factor > threshold)
		{
			cout << "----- Doubling array" << '\n';
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


			cout << "----- Double ended" << '\n';
		}
    }

    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    V get(K key) {
		int h_index = hashKey(key);
		cout << "GET: " << h_index << '\n';
		Node<K, V>* head = elem[h_index];
		while (head != nullptr)
		{
			if (head->key == key)
				return head->value;
			head = head->next;
		}
		return false;
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

		if (head == nullptr) // got to the end, element was not found
			return;

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

int main() {

	/*std::bitset<32> b1;
	std::string s1 = "made";
	std::string s2 = "dams";
	for (auto& s: s1)
		b1[s % 32] = 1;
	
	for (auto& s : s2)
		b1[s % 32] = 0;
	
	b1.any() ? std::cout <<  "Not anagrams" : std::cout << "Anagrams" << '\n';

	std::size_t test = std::hash<int>() (2);
	std::cout << "\n" << test % 1000000 << "\n";*/

	MyHashMap<char, int> m;

	// anagrams
	string s1 = "Stressed";
	string s2 = "Desserts";
	transform(s1.begin(), s1.end(), s1.begin(), [](unsigned char c) {return tolower(c); });
	transform(s2.begin(), s2.end(), s2.begin(), [](unsigned char c) {return tolower(c); });
	bool are_anagrams = true;
	
	for (auto& c : s1) {
		if (!m.has(c))
			m.put(c, 1);
		else
			m.put(c, m.get(c) + 1);
	}

	m.remove(s1[0]);
	m.put('s', 3);
	for (size_t i = 0; i < s2.length(); i++) {
		if (!m.has(s2[i])) {
			are_anagrams = false;
		}
	}

	if (are_anagrams)
	{
		cout << "Anagrams";
	}
	else
	{
		cout << "Not Anagrams";
	}

}