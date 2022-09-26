
template <typename valType>
class BTnode{
    friend class BinaryTree<valType>;
    public:
        BTnode( const valType&);
    
    private:
        valType     _val;
        int         _cnt;
        BTnode      *_lchild;
        BTnode      *_rchild;
};