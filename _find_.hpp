

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
