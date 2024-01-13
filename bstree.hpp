using namespace juju;



template <typename T>
Tree<T>::Tree(std::initializer_list<T> list)
{
	for (auto i : list)
	{
		this->insert(i);
	}
}




template <typename T>
Tree<T>::Node::Node(const T& value) : m_data{value} {}

template <typename T>
void Tree<T>::_insert(const T& value, Node*& root)
{
	if (root == nullptr)
	{
		root = new Node{value};
		return;
	}

	else if (root->m_data < value)
		_insert(value, root->right);

	else if (root->m_data > value)
		_insert(value, root->left);
}



template <typename T>
void Tree<T>::insert(const T& value)
{
	_insert(value, this->m_root);
}

template <typename T>
size_t Tree<T>::_childcount(Node* root) const noexcept
{
	if (root->left == nullptr && root->right == nullptr)
	{
		return 0;
	}

	if (root->left != nullptr && root->right != nullptr)
	{
		return 2;
	}
	return 1;
}

template <typename T>
typename Tree<T>::Node* Tree<T>::_parent(Node* root, Node* child) const noexcept
{
	if (root == nullptr || root == child)
	{
		return nullptr;
	}

	if (root->left == child || root->right == child)
	{
		return root;
	}

	return (child->m_data > root->m_data) ? _parent(root->right, child) : _parent(root->left, child);
}


template <typename T>
typename Tree<T>::Node::Node& Tree<T>::Node::operator=(Node&& other)
{
	m_data = other.m_data;
	left = other.left;
	right = other.right;
	other.left = nullptr, other.right = nullptr;
}



template <typename T>
void Tree<T>::_remove(Node* root, Node* parent, const size_t children) noexcept
{

	Node* tmp = nullptr;


	switch (children)
	{
		case 1:
		{
			tmp = (root->left == nullptr) ? root->right : root->left;
			(parent->left == root) ? parent->left = tmp : parent->right = tmp;
			delete root, root = nullptr;
			break;
		}

		case 2:
		{
			tmp = successor(root->m_data);

			T data_t = tmp->m_data;

			_remove(tmp, _parent(this->m_root, tmp), _childcount(tmp));

			root->m_data = data_t;

			break;
		}

		case 0:
			delete root;
			(parent->left == root) ? parent->left = nullptr : parent->right = nullptr;
	}
}


template <typename T>
void Tree<T>::remove(const T& value) noexcept
{
	if (m_root->m_data == value)
	{
		delete m_root;
		return;
	}

	Node* root = this->search(value);
	Node* parent = _parent(this->m_root, _search(value, this->m_root));

	if (root == nullptr)
	{
		return;
	}

	_remove(root, parent, _childcount(root));

}


template <typename T>
void Tree<T>::_clear(Node* root) noexcept
{
	if (root == nullptr)
	{
		return;
	}

	_clear(root->left);
	_clear(root->right);
	remove(root->m_data);
}


// template <typename T>
// void Tree<T>::clear() noexcept
// {
// 	_clear(m_root);
// }


template <typename T>
typename Tree<T>::Node* Tree<T>::_search(const T& value, Node* root) const noexcept
{
	if (root == nullptr)
	{
		return nullptr;
	}

	if (root->m_data == value)
	{
		return root;
	}

	else if (root->m_data < value)
	{
		return _search(value, root->right);
	}

	else
		return _search(value, root->left);
}





template <typename T>
typename Tree<T>::Node* Tree<T>::search(const T& value) const noexcept
{
	return Tree<T>::_search(value, this->m_root);
}


template <typename T>
void Tree<T>::_process_node(const Node* root) const noexcept
{
	std::cout << root->m_data << "   ";
}


template <typename T>
void Tree<T>::_inorder(const Node* root) const noexcept
{
	if(root == nullptr)
	{
		return;
	}

	_inorder(root->left);

	_process_node(root);

	_inorder(root->right);
}

template <typename T>
void Tree<T>::_preorder(const Node* root) const noexcept
{
	if(root == nullptr)
	{
		return;
	}

	_process_node(root);

	_preorder(root->left);

	_preorder(root->right);
}

template <typename T>
void Tree<T>::_postorder(const Node* root) const noexcept
{
	if(root == nullptr)
	{
		return;
	}


	_postorder(root->left);

	_postorder(root->right);

	_process_node(root);
}


template <typename T>
void Tree<T>::inorder() const noexcept
{
	_inorder(this->m_root);
}

template <typename T>
void Tree<T>::preorder() const noexcept
{
	_preorder(this->m_root);
}

template <typename T>
void Tree<T>::postorder() const noexcept
{
	_postorder(this->m_root);
}




// template <typename T>
// typename Tree<T>::Node* Tree<T>::_find_min(Node* root) noexcept
// {
// 	return const_cast<Node*>(

// 		static_cast<const Tree*>(this)->_find_min()
// 	)
// }

// template <typename T>
// typename Tree<T>::Node* Tree<T>::_find_max(Node* root) noexcept
// {
// 	return const_cast<Node*>(

// 		static_cast<const Tree*>(this)->_find_max()
// 	)
// }



template <typename T>
typename Tree<T>::Node const* Tree<T>::_find_min(Node const* root) const noexcept
{
	if (root->left == nullptr)
	{
		return root;
	}

	return _find_min(root->left);
}

template <typename T>
typename Tree<T>::Node const* Tree<T>::_find_max(Node const* root) const noexcept
{
	if (root->right == nullptr)
	{
		return root;
	}

	return _find_max(root->right);
}



template <typename T>
typename Tree<T>::Node const* Tree<T>::find_min() const noexcept
{
	return _find_min(this->m_root);
}

template <typename T>
typename Tree<T>::Node const* Tree<T>::find_max() const noexcept
{
	return _find_max(this->m_root);
}

template <typename T>
typename Tree<T>::Node* Tree<T>::find_min() noexcept
{
	return const_cast<Node*>(

		static_cast<const Tree*>(this)->find_min()
	);
}

template <typename T>
typename Tree<T>::Node* Tree<T>::find_max() noexcept
{
	return const_cast<Node*>(

		static_cast<const Tree*>(this)->find_max()
	);
}



template <typename T>
typename Tree<T>::Node* Tree<T>::_predecessor(Node* root) noexcept
{
	return const_cast<Node*>(_find_max(root->left));
}

template <typename T>
typename Tree<T>::Node* Tree<T>::_successor(Node* root) noexcept
{
	return const_cast<Node*>(_find_min(root->right));
}


template <typename T>
typename Tree<T>::Node* Tree<T>::successor(const T& value) noexcept
{

	return Tree<T>::_successor(_search(value, this->m_root));
}

template <typename T>
typename Tree<T>::Node* Tree<T>::predecessor(const T& value) noexcept
{
	return Tree<T>::_predecessor(_search(value, this->m_root));
}


// template <typename T>
// void Tree<T>::_clear(Node* root) noexcept
// {
// 	if (root == nullptr)
// 		return;

// 	if
// }

template <typename T>
Tree<T>::~Tree()
{
	_clear(m_root);
}
