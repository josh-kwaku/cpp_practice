#include <iterator>
#include <cstddef>

class Integers
{
public:
    class Iterator
    {
        using iterator_category = std::forward_iterator_tag;
        using difference_type = std::ptrdiff_t;
        using value_type = int;
        using pointer = int*;
        using reference = int&;

        Iterator(pointer ptr) : m_ptr(ptr) {}

        reference operator*() const { return *m_ptr; }
        pointer operator->() { return m_ptr; }
        Iterator& operator++() { m_ptr++; return *this; }
        Iterator operator++(int) { Iterator tmp = *this; ++(*this); return tmp; }
        bool operator== (const Iterator& b) { return m_ptr == b.m_ptr; };
        bool operator!= (const Iterator& b) { return m_ptr != b.m_ptr; };

    private:
        pointer m_ptr;
    };

    Iterator begin() { return Iterator(&m_data[0]); }
    Iterator end() { return Iterator(&m_data[200]); }

private:
    int m_data[200];
};