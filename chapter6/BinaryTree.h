#include "BTnode.h"

template <typename elemType>
class BinaryTree{
    public:
        BinaryTree();
        BinaryTree( const BinaryTree& );
        ~BinaryTree();
        BinaryTree& operator=( const BinaryTree& );

        bool empty(){ return _root == 0; }
        void clear(){ if(_root){ clear(_root);_root = 0;}};
		void insert( const elemType&);
		void remove( const elemType&);
        void remove_root();
        void pre();

    private:
        // BTnode 必须以 template parameter list 加以限定
        BTnode<elemType> *_root;
        void clear( BTnode<elemType>*);
        void copy( BTnode<elemType>*tar, BTnode<elemType>*src );
};

template <typename elemType>
inline BinaryTree<elemType>::
BinaryTree() : _root( 0 )
{}

template <typename elemType>
inline BinaryTree<elemType>::BinaryTree(const BinaryTree &rhs) {
	 copy(_root, rhs._root); 
}

template <typename elemType>
inline BinaryTree<elemType>::~BinaryTree() { 
    clear(); 
}

template <typename elemType>
inline BinaryTree<elemType>& BinaryTree<elemType>::operator=(const BinaryTree &rhs) {
	if (this != &rhs) {
		clear();
		copy(_root, rhs._root);
	}
	return *this;
}

template <typename elemType>
inline void
BinaryTree<elemType>::
insert( const elemType &elem){
		if( !_root )
				_root = new BTnode<elemType>(elem);
		else _root->insert_value(elem);
}

template <typename elemType>
inline void
BinaryTree<elemType>::
remove( const elemType &elem ){
	if( _root ){
		if( _root->val == elem )
			remove_root();//特例处理
		else
			_root->remove_value( elem, _root );
	}
}

template <typename elemType>
void BinaryTree<elemType>::
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

template <typename elemType>
void BinaryTree<elemType>::
clear( BTnode<elemType> *pt){
	if(pt){
		clear(pt->_lchild);
		clear(pt->_rchild);
		delete pt;
	}
}

template <typename elemType>
void BinaryTree<elemType>::
pre(){
    this->_root->preorder(this->_root);
}