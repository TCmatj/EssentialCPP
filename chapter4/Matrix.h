#include <iostream>
using namespace std;

class Matrix{
    public:
        Matrix(int row, int col)
                :_row(row), _col(col)
        {
            //constructor进行资源的分配
            //注意此处未检查成功与否
            _pmat = new double[ row * col];
        }

        Matrix(const Matrix &rhs)
            : _row(rhs._row), _col(rhs._col)
        {
            //对rhs._pmat所指的数组产生一份完全复本
            int elem_cnt = _row * _col;
            _pmat = new double[ elem_cnt ];

            for(int ix = 0; ix < elem_cnt; ix++)
                _pmat[ix] = rhs._pmat[ix];
        }

        ~Matrix()
        {
            //destructor进行资源的释放
            delete [] _pmat;
        }

        private:
            int  _row, _col;
            double* _pmat;
};