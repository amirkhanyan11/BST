

template <typename T>
typename Tree<T>::Node* Tree<T>::_predecessor(Node* root) noexcept
{
	if(root->left == nullptr)
	{
		std::cout << "\nnema" << std::endl;
		return nullptr;
	}
	return const_cast<Node*>(_find_max(root->left));
}

template <typename T>
typename Tree<T>::Node* Tree<T>::_successor(Node* root) noexcept
{
	if(root-> right == nullptr)
	{
		std::cout << "\nnema" << std::endl;
		return nullptr;
	}
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
