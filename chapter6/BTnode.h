#include <string.h>
#include <iostream>
using namespace std;

template <typename T>class BinaryTree;

template <typename valType>
class BTnode{
    friend class BinaryTree<valType>;
    public:
        BTnode( const valType&);
    	void insert_value( const valType&);
		void lchild_leaf( BTnode *, BTnode *);
		void remove_value( const valType&, BTnode *&);
		void preorder( BTnode *);

    private:
        valType     _val;
        int         _cnt;
        BTnode      *_lchild;
        BTnode      *_rchild;
};

template <typename valType>
inline BTnode<valType>::
BTnode( const valType &val)
: _val(val){
    _cnt = 1;
    _lchild = _rchild = 0;
}

template <typename valType>
void BTnode<valType>::
insert_value( const valType &val){
	if( val == _val ){	//已存在，计算插入次数
		_cnt++;
		return;
	}
	if( val < _val ){
		if( !_lchild )	//左子树为空
		    _lchild = new BTnode( val );
		else _lchild->insert_value( val );//否则递归插入左子树·
	}else{
		if( !_rchild )
			_rchild = new BTnode( val );
		else _rchild->insert_value( val );
	}
}


// 将左子节点搬迁到右子树中，位置为最左下的左叶子
template <typename valType>
inline void
BTnode<valType>::
lchild_leaf( BTnode *leaf, BTnode *subtree ){
	while( subtree->_lchild )
		subtree = subtree->_lchild;
	subtree->_lchild = leaf;
}

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

template <typename valType>
void BTnode<valType>::preorder( BTnode*pt ){//, std::ostream &os
	if( pt ){
		//display_val( pt, os);
		cout << string(pt->_val) << ' ';
		if(pt->_lchild)	preorder(pt->_lchild);
		if(pt->_rchild)	preorder(pt->_rchild);
	}
}