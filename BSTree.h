#ifndef BSTREE_H
#define BSTREE_H
#include <iostream>
#include <ostream>
#include <stdexcept>
#include "BSNode.h"
template <typename T>
class BSTree{
	private:
		int nelem;//numero de elementos del arbol
		BSNode<T>* root; //raiz del arbol
		BSNode<T>* search(BSNode<T>* n,T e) const{
			if(n==nullptr){
				throw std::runtime_error("Elemento no encontrado"); 
			}
			else if(n->elem > e){
				return search(n->left,e);
			}
                	else if (n->elem < e){
				return search(n->right,e);
			}
				return n;
		}
		BSNode<T>* insert(BSNode<T>* n, T e){
			if(n==nullptr){
				nelem++;
			return new BSNode<T>(e);
			}
			else if(n->elem==e){
				throw std::runtime_error("quieres insertar un numero que ya se encuentra en el arbol");
			}
			else if(n->elem >e){
				n->left=insert(n->left,e);
			}else{
				n->right=insert(n->right,e);
			}
			return n;
		}	
		void print_inorder(std::ostream &out, BSNode<T>* n) const{
			if(n!=nullptr){
				print_inorder(out,n->left);
				out<<n->elem<<" ";
				print_inorder(out,n->right);
			}
		}
		BSNode<T>* remove(BSNode<T>* n, T e){
			if(n==nullptr){
			throw std::runtime_error("No se ha podido encontrar el elemento a eliminar");
			}else if(n->elem<e){
				n->right=remove(n->right,e);
			}else if(n->elem>e){
				n->left=remove(n->left,e);	
			}
			else{// hemos encontrado el elemento a eliminar
				if(n->left!=nullptr && n->right!=nullptr){
					n->elem=max(n->left);
					n->left=remove_max(n->left);
				}
				else{
				n=(n->left!=nullptr)? n->left : n->right;
				nelem--;
				}
			}
			return n;
		}
		T max(BSNode<T>* n) const{
			if(n==nullptr){
				throw std::runtime_error("Ha habido un problema en la funcion Max");
			}
			else if(n->right!= nullptr){
				return max(n->right);
			}
			else{
				return n->elem;
			}
		}
		BSNode<T>* remove_max(BSNode<T>* n){
			if(n->right==nullptr){
				BSNode<T>* temp=n->left;
				delete n;
				nelem--;
				return temp;
			}else{
				n->right=remove_max(n->right);
				return n;
			}
		}
		void delete_cascade(BSNode<T>* n){
			if(n!=nullptr){
				delete_cascade(n->left);
				delete_cascade(n->right);
				delete n;
				nelem--;
			}
		}

	public:
		BSTree(){
			nelem=0;
			root=nullptr;
		}
		int size() const{
			return nelem;
		}
		T search(T e){
			return search(root,e)->elem;
		}
		T operator[](T e) const {
			return search(e);
		}
		void insert(T e){
			root=insert(root,e);	
		}
		friend std::ostream& operator<<(std::ostream &out, const BSTree<T> &bst){
			bst.print_inorder(out,bst.root);
			return out;
		
		}
		void remove(T e){
			root=remove(root,e);
		}
		
		~BSTree(){
			delete_cascade(root);
		}

};
#endif
