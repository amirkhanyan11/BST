
template <typename T>
size_t Tree<T>::_size(Node const* root) const noexcept
{
	return (root == nullptr) ? 0 : 1 + _size(root->left) + _size(root->right);
}

template <typename T>
size_t Tree<T>::size() const noexcept
{
	return _size(this->m_root);
}



template <typename T>
size_t Tree<T>::_height(Node const* root) const noexcept
{
	if (root == nullptr)
	{
		return 0;
	}

	size_t left_height = _height(root->left);
	size_t right_height = _height(root->right);

	return 1 + ((left_height > right_height) ? left_height : right_height);
}

template <typename T>
size_t Tree<T>::height() const noexcept
{
	return _height(this->m_root);
}