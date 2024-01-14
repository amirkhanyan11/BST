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
void Tree<T>::_remove(Node* root, Node* parent, const size_t children) noexcept
{

	Node* tmp = nullptr;


	switch (children)
	{
		case 1:
		{
			tmp = (root->left == nullptr) ? root->right : root->left;
			(parent->left == root) ? parent->left = tmp : parent->right = tmp;
			delete root;
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


