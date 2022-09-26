## 1 被参数化的类型

以下是一个非模板类：
```
class string_BTnode{
    public:
        //...
    private:
        string _val;
        int _cnt;
        string_BTnode *_lchild;
        string_BTnode *_rchild;
};
```
由于缺乏模板机制，为了存储不同类型的数值，我们必须为他实现各种不同的 BTnode 类，并且取不同的名称
```
template <typename valType>
class BTnode{
    public:
        //...
    
    private:
        valType     _val;
        int         _cnt;
        BTnode      *_lchild;
        BTnode      *_rchild;
};
```
为了通过类模板实例化类，必须在类模板名称之后紧接一个尖括号，其内放置一个实际类型
如：``BTnode< int > bti;`` 和 ``BTnode< string > bts;``

## 2 类模板的定义

为类模板定义一个 ``inline`` 函数，其做法与之前是一样的。但在类外定义类模板成员函数的语法却大相径庭。
```
template <typename elemType>
inline BinaryTree<elemType>::   // 在class定义范围之外
BinaryTree() : _root( 0 )       // 在class定义范围之内
{}
```
第二次出现的BinaryTree名称就不再需要限定了
因为，在class scope运算符出现之后，BinaryTree< elemType>::其后所有东西都被视为位于class定义范围内

## 3 模板类型参数的处理

举个例子，如果要为函数声明一个明确的 int 参数，会这么写：``bool find( int val );`` 它以传值(by value)的方式传参。如果声明Matrix class 为函数的参数，我们可能会改为传址(by reference)方式传递：``bool find( const Matrix &val );`` 这样可以避免对象的复制造成的不必要开销
当我们处理模板类型参数时，我们无法得知用户实际要用的类型是否为语言内置类型（如int），如果真的是内置类型，当然可以用传值的方法编写find()的参数列表。但如果是一个class类型（如上面的Matrix）就应该以传址的方式来编写参数列表
```
template <typename valType>
inline BTnode<valType>::
BTnode( const valType &val)
: _val(val){                    //建议
    _cnt = 1;
    _lchild = _rchild = 0;
}

template <typename valType>
inline BTnode<valType>::
BTnode( const valType &val){
    _val = val;                 //不建议
    _cnt = 1;
    _lchild = _rchild = 0;
}
```
对于 ``BTnode<int> btni( 42 );`` 而言，上述两种方式无效率上的区别
但对于 ``BTnode<Matrix> btnm( transform_matrix );`` 就有高下之分
    方法1. 在构造函数的成员列表初始化中将 _val 初始化，只需要一个步骤：
            以拷贝构造将 val 复制给 _val
    方法2. _val 的赋值操作可以分解为两个步骤
            a. 函数执行之前，Matrix 的默认构造函数会先作用于 _val 上
            b. 函数体内会以拷贝赋值运算将 val 复制给 _val

## 4 实现一个类模板
