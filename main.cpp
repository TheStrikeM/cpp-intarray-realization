#include <iostream>

class IntArray {
public:
    explicit IntArray(size_t size)
        : _size(size), _data(new int[size]) {
        for (size_t i = 0; i != _size; ++i)
            _data[i] = 0;
    }

    IntArray(IntArray const &a)
        : _size(a._size), _data(new int[_size]) {
        for (size_t i = 0; i != _size; ++i)
            _data[i] = a._data[i];
    }

    IntArray & operator=(IntArray const &a) {
        if (this != &a)
            IntArray(a).swap(*this);
        return *this;
    }

    ~IntArray() {
        delete [] _data;
    }

    void swap(IntArray &arr) {
        std::swap(_size, arr._size);
        std::swap(_data, arr._data);
    }

    size_t size() const { return _size; }

    int get(size_t i) const { return _data[i]; }
    int &get(size_t i) { return _data[i]; }


private:
    size_t _size;
    int * _data;
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
