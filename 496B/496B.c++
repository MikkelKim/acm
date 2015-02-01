#include <iostream>

using namespace std;

struct circular_array{
    int _b;
    int _e;
    const int _s;
    int* _n;

    circular_array(int s) : _b(0), _e(0), _s(s), _n(new int[s]) {}

    ~circular_array() {
        delete [] _n;
    }

    void push(int e) {
        _n[_e] = e;
        ++_e;
    }

    int& operator [] (int index) {
        return _n[(_b + index) % _s];
    }

    const int& operator [] (int index) const {
        return const_cast<circular_array*>(this)->operator[](index);
    }

    circular_array& operator = (const circular_array& rhs) {
        this->_b = rhs._b;
        for(int i = 0; i < _s; ++i) {
            this->operator[](i) = rhs[i];
        }
        return *this;
    }

    bool operator < (const circular_array& rhs) {
        for(int i = 0; i < _s; ++i) {
            if(this->operator[](i) > rhs[i])
                return false;
            else if(this->operator[](i) < rhs[i])
                return true;
            else
                continue;
        }
        return false;
    }

    void shift() {
        --_b;
        if(_b < 0)
            _b += _s;
    }

    void incr() {
        for(int i = 0; i < _s; ++i) {
            ++_n[i];
            if(_n[i] > 9)
                _n[i] -= 10;
        }
    }

    friend ostream& operator << (ostream& lhs, const circular_array& rhs) {
        for(int i = 0; i < rhs._s; ++i) {
            lhs << rhs[i];
        }
        return lhs;
    }
};

int main() {
    int s;
    cin >> s;

    circular_array min(s);
    circular_array cur(s);
    char d;

    for(int i = 0; i < s; ++i) {
        cin >> d;
        min.push(d - '0');
        cur.push(d - '0');
    }

    for(int i = 0; i < 10; ++i) {
        for(int j = 0; j < s; ++j) {
            if(cur < min) {
                min = cur;
            }
            cur.shift();
        }
        cur.incr();
    }

    cout << min << endl;
}