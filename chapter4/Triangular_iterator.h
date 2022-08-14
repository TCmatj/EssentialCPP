
class Triangular_iterator{
    public:
    //为了不要每次访问元素时都执行-1操作，将_index的值设为index-1
        Triangular_iterator(int index) : _index(index-1){}
        bool operator==(const Triangular_iterator&) const;
        bool operator!=(const Triangular_iterator&) const;
        int operator*() const;
        Triangular_iterator& operator++();      //前置版本
        Triangular_iterator operator++(int);    //后置版本

    private:
        void check_integrity() const;
        int _index;
};