


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
