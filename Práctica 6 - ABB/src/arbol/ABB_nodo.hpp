#pragma once

#include <cstdio>

using namespace std;

template <class T>
class ABB_nodo {
private:

    ABB_nodo<T>* left_;
    ABB_nodo<T>* right_;

	T data_;

    public:
	ABB_nodo(const T& data);

	~ABB_nodo(void);

	void set_left (ABB_nodo<T>*);
	void set_right(ABB_nodo<T>*);

	ABB_nodo<T>*& get_left(void);
	ABB_nodo<T>*& get_right(void);

	ABB_nodo<T>* get_left(void)  const;
	ABB_nodo<T>* get_right(void) const;

	void set_data(const T& data);
	T get_data(void) const;
};


	template <class T>
	ABB_nodo<T>::ABB_nodo(const T& data) :
	left_(NULL),
	right_(NULL),
	data_(data) 
	{}

	template <class T>
	ABB_nodo<T>::~ABB_nodo(void) {
		left_ = NULL;
		right_ = NULL;
	}

	template <class T>
	void ABB_nodo<T>::set_left(ABB_nodo<T>* left)
	{
		left_ = left;
	}

	template <class T>
	ABB_nodo<T>* ABB_nodo<T>::get_left(void) const
	{
		return left_;
	}

	template <class T>
	ABB_nodo<T>*& ABB_nodo<T>::get_left(void)
	{
		return left_;
	}

	template <class T>
	void ABB_nodo<T>::set_right(ABB_nodo<T>* right)
	{
		right_ = right;
	}

	template <class T>
	ABB_nodo<T>* ABB_nodo<T>::get_right(void) const
	{
		return right_;
	}

	template <class T>
	ABB_nodo<T>*& ABB_nodo<T>::get_right(void)
	{
		return right_;
	}

	template <class T>
	void ABB_nodo<T>::set_data(const T& data)
	{
		data_ = data;
	}

	template <class T>
	T ABB_nodo<T>::get_data(void) const
	{
		return data_;
	}


