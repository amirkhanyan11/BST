
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
