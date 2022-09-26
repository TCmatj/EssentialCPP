#include "BTnode.h"

template <typename elemType>
class BinaryTree{
    public:
        BinaryTree();
        BinaryTree( const BinaryTree& );
        ~BinaryTree();
        BinaryTree& operator=( const BinaryTree& );

        bool empty(){ return _root == 0; }
        void clear();
    
    private:
        // BTnode 必须以 template parameter list 加以限定
        BTnode<elemType> *_root;
        void copy( BTnode<elemType>*tar, BTnode<elemType>*src );
};