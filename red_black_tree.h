#ifndef __REDBLACKTREE__
#define __REDBLACKTREE__

#include "bstree.h"

enum class __color {RED, BLACK};

namespace cocobolo
{

template <typename T>
class RedBlackTree : public Tree<T>
{

public:

    RedBlackTree() = default;
    RedBlackTree(std::initializer_list<value_type>);

private:

    struct RBnode : public Tree<value_type>::Node
    {
        friend class RedBlackTree;

        __color m_color = __color::BLACK;

        RBnode(const_reference, __color color = __color::RED, RBnode* p = nullptr);

    };


public: // x
    void _lrotate(typename Tree<value_type>::Node*& root);
    void _rrotate(RBnode*& root);

    void foo()
    {
        this->_lrotate(this->m_root);
    }

public:


    // void insert(const_reference) override;
    // void remove(const_reference) override noexcept;


};



#include "red_black_tree.hpp"


}







#endif // __REDBLACKTREE__
