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

每当我们插入某个新值，都必须建立BTnode对象、加以初始化、将它链接至二叉树的某处。我们必须自行以new表达式和delete表达式来管理每个节点的内存分配和释放。
以insert()为例，如果根结点之值尚未设定，它会由程序的空闲空间分配一块新的BTnode需要的内存空间。否则就调用BTnode的insert_value()，将新值插入二叉树中：

```
template <typename elemType>
inline void
BinaryTree<elemType>::
insert( const elemType &elem){
		if( !_root )
				_root = new BTnode<elemType>(elem);
		else _root->insert_value(elem);
}
```

new 表达式可以分解为两个操作：
1. 向程序的空闲空间请求内存。如果分配到足够的空间就返回一个指针，指向新对象
2. 如果第一步成功了，且外部指定了一个初值，这个对象便会以最适当的方式被初始化

移除某节点更为复杂。一般的算法是：
1. 以节点的右子树取代节点本身
2. 搬迁左子节点本身，使它成为右子节点的左子树的叶节点

特例：移除根节点

```
template <typename elemType>
void
BinaryTree<elemType>::
remove_root(){
	if( !_root) return;

	BTnode<elemType> *tmp = _root;
	if( _root->_rchild ){
		_root = _root->_rchild;

		if( tmp->_lchild ){
			BTnode<elemType> *lc = tmp->_lchild;
			BTnode<elemType> *newlc = _root->_lchild;
			if( !newlc )
				//没有任何子树
				_root->_lchild = lc;

			//lchild_leaf会便利整个左子树
			//寻找某个可接上去的null左子节点
			//lchild_leaf是个static member function
			else BTnode<elemType>::lchild_leaf( lc, newlc );
		}
	}
	else _root = _root->_lchild;

	delete tmp;		//已经移去先前那个根节点了
}
```
```
// remove_value()移除非根节点
template <typename valType>
void BTnode<valType>::
remove_value( const valType &val, BTnode *&prev){
	if( val < _val ){
		if( !_lchild )	return;	//不在此二叉树中
		else _lchild->remove_value( val, _lchild );
	}else if ( val > _val ){
		if( !_rchild )	return;	//不在此二叉树中
		else _rchild->remove_value( val, _rchild );
	}else{
		//找到了
		//重置此树，然后删除这一节点

		if ( _rchild ){
			//右孩子存在
			prev = _rchild;
			if( _lchild )
				//左孩子也存在
				if ( ! prev->_lchild )
					   //右孩子的左孩子不存在，则设置让左孩子取代这个空位置
					   prev->_lchild = _lchild;
				else BTnode<valType>::lchild_leaf(_lchild,prev->_lchild);	//否则将左孩子放到右子树中的最左下角
		}
		else prev = _lchild;	//右孩子不存在就直接等于左孩子
		delete this;
	}
}
```
上面的函数中prev需要设置为指针的引用
- 以指针来传递的话，更改的是指针所指的，而不是其本身
- 为了改变指针本身，需要再加一个引用，这样不仅能改变指针本身，也能改变指针指向的对象