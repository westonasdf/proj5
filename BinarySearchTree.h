/*
 * BinarySearchTree.h
 *
 *  Created on: Nov 30, 2016
 *      Author: wwh160130
 */

#ifndef BINARYSEARCHTREE_H_
#define BINARYSEARCHTREE_H_

#include <iostream>
#include <iomanip>
#include <cstddef>


// forward declaration of the template class BinarySearchTree
template<class DataType>
class BinarySearchTree;
// TreeNode class
template <class DataType>
	class TreeNode{
		friend class BinarySearchTree<DataType>;
	private:
		// contains the actual data
		DataType dataType;
		// pointer to the left side
		TreeNode<DataType>* llink;
		// pointer to the right side
		TreeNode<DataType>* rlink;
	public:
		// the rest of the TreeNode classs declaration goes here
		TreeNode(){llink = nullptr;rlink = nullptr;};

		TreeNode* left(){
			return llink;
		}

		TreeNode* right(){
			return rlink;
		}

};
// BinarySearchTree class
template <class DataType>
class BinarySearchTree{
	private:
		std::size_t numberNodes;
	protected:
		// point to the first node or nullptr for empty list
		TreeNode<DataType>* root;
	public:
		BinarySearchTree(){
			numberNodes = 0;
			root = nullptr;
		}

		bool empty() const{
			if(numberNodes==0)
				return true;
			return false;
		}

		std::size_t size() const{
			return numberNodes;
		}

		bool find(const DataType &searchItem, void (*foundNode)(const DataType&));

		void traverse(void (*itemFound)(const DataType& foundItem)) const;

		void inOrder(DataType node, void (*itemFound)(const DataType& foundItem));
		bool inOrder(DataType node, DataType searchItem, void (*itemFound)(const DataType&));
		void insert(const DataType &newItem);

		void insert(const DataType &newItem,void (*duplicateItemFound)(DataType &existingItem,const DataType &newItem));
		bool erase(const DataType &deleteItem);
		void treeDelete(TreeNode<DataType> *node);



};





template<class DataType>
bool BinarySearchTree<DataType>::inOrder(DataType node, DataType searchItem, void (*foundNode)(const DataType& foundItem)){
	if(node!=nullptr){
		inOrder(node->lLink,searchItem,*foundNode);
		if(node->dataType == searchItem){
			(*foundNode)(node->dataType);
			return true;
		}
		inorder(node ->rLink,searchItem,*foundNode);
	}
	return false;
}
template<class DataType>
void BinarySearchTree<DataType>::inOrder(DataType node, void(*itemFound)(const DataType& foundItem)){
	if(node!=nullptr){
		inOrder(node->lLink,*itemFound);
		(*itemFound)(node->dataType);
		inorder(node ->rLink, *itemFound);
	}
}

template<class DataType>
bool BinarySearchTree<DataType>::find(const DataType &searchItem, void (*foundNode)(const DataType&)){
	return inOrder(root,searchItem,*foundNode);
	
}

template<class DataType>
void BinarySearchTree<DataType>::traverse(void (*itemFound)(const DataType& foundItem)) const{
	inorder(root,*itemFound);
}

template<class DataType>
void BinarySearchTree<DataType>::insert(const DataType &newItem){
	TreeNode<DataType> *current;
	TreeNode<DataType> *trail;
	TreeNode<DataType> *newNode;

	newNode = new TreeNode<DataType>;
	newNode->dataType = newItem;
	newNode->lLink = nullptr;
	newNode->rLink = nullptr;
	if(root == nullptr)
		root = newNode;
	else{
		current = root;
		while(current != nullptr){
			trail = current;

			//found node
			if(current->dataType==newItem)
				current->dataType = newItem;

			else if(current->dataType > newItem)
				current = current->lLink;

			else
				current = current->rLink;
		}

		if(trail->dataType > newItem)
			trail->lLink = newNode;
		else
			trail->rLink = newNode;
	}
}
template<class DataType>
void BinarySearchTree<DataType>::insert(const DataType &newItem,void (*duplicateItemFound)(DataType &existingItem,const DataType &newItem)){
	TreeNode<DataType> *current;
	TreeNode<DataType> *trail;
	TreeNode<DataType> *newNode;

	newNode = new TreeNode<DataType>;
	newNode->dataType = newItem;
	newNode->lLink = nullptr;
	newNode->rLink = nullptr;
	if(root == nullptr)
		root = newNode;
	else{
		current = root;
		while(current != nullptr){
			trail = current;

			//found node
			if(current->dataType==newItem){
				current->dataType = newItem;
				(*duplicateItemFound)(current,&newItem);
			}

			else if(current->dataType > newItem)
				current = current->lLink;

			else
				current = current->rLink;
		}

		if(trail->dataType > newItem)
			trail->lLink = newNode;
		else
			trail->rLink = newNode;
	}
}
template<class DataType>
bool BinarySearchTree<DataType>::erase(const DataType &deleteItem){
     	TreeNode<DataType> *current;
     	TreeNode<DataType> *trail;
     	bool found;
     	if(root == nullptr)
     		return false;
     	else{
     		current = root;
     		trail = root;


     		while(current!=nullptr && !found){
     			if(current->dataType == deleteItem)
     				found = true;
     			else{
     				trail = current;
     				if(current->dataType > deleteItem)
     					current = current->rLink;
     				else
     					current = current->lLink;
     			}
     		}
     	}

     	if(current==nullptr)
     		return false;
     	else if(found){
     		if(current == root){
     			treeDelete(root);
     			return true;
     		}
     		else if(trail->dataType > deleteItem){
     			treeDelete(trail->lLink);
     			return true;
     		}
     		else{
     			treeDelete(trail->rLink);
     			return true;
     		}
     	}
     	else
     		return false;

}

template<class DataType>
void BinarySearchTree<DataType>::treeDelete(TreeNode<DataType> *node){
	TreeNode<DataType> *current;
	TreeNode<DataType> *trail;
	TreeNode<DataType> *temp;
	if(node->lLink ==nullptr && node->rLink == nullptr){
		temp = node;
		node = nullptr;
		delete temp;
	}
	else if(node->lLink == nullptr){
		temp = node;
		node = temp->rLink;
		delete temp;
	}

	else if(node->rLink == nullptr){
		temp = node;
		node = temp->lLink;
		delete temp;
	}
	else{
		current = node->llink;
		trail = nullptr;
		while(current->rLink!=nullptr){
			trail = current;
			current = current->rLink;
		}
		node->dataType = current->dataType;
		if(trail==nullptr)
			node->lLink = current ->lLink;
		else
			trail->rLink = current -> lLink;

		delete current;
	}

}

#endif /* BINARYSEARCHTREE_H_ */
