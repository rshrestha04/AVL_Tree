/* 
 * File:   Avl_tree.h
 * Author: Ronish
 *
 * Created on November 23, 2019, 3:09 PM
 */

#ifndef AVL_TREE_H
#define	AVL_TREE_H

#include<bits/stdc++.h> 
using namespace std; 
  

class Node {
    
public :
    int key;
    Node *left;
    Node *right; 
    int height;        
};

//Funtion to get maximum number between A and B
int max(int a, int b){
    return (a > b) ? a:b; 
}

int get_key(Node* N){
    if (N== NULL) return 0;
    return N->key;
}
//Funtion to get the height of the tree 

int tree_height(Node* N){
    if (N==NULL) return 0;
    return N->height;
}

//Funtion to allocate a new node with provided key

Node* New_node(int key){

Node* new_node = new Node();
new_node->key = key;
new_node->height= 1;
new_node->left= NULL;
new_node->right = NULL;
return new_node;
}

//Right Rotation 

Node* Right_rotation(Node* x){
    Node* A= x->left; 
    Node* B= A->right;
     
    //Rotation
    A->right = x;
    x->left = B;
    
   
    //updating height
    
    x->height= max(tree_height(x->left), tree_height(x->right))+1;
    A->height = max(tree_height(A->left),tree_height(A->right))+1;
    
    return A;
    
 }

Node* Left_rotation(Node *x){
    Node *A= x->right;
    Node *B= A->left;
    
    A->left = x;
    x->right = B;
    
    //updating height
    
    x->height= max(tree_height(x->left), tree_height(x->right) )+1;
    A->height= max(tree_height(A->left), tree_height(A->right))+1;
    
    return A;
        
}

int Balance_factor(Node* N){
    if(N == NULL) return 0;
    return tree_height(N->left)- tree_height(N->right);
}

//Recurssive funtion to insert node
Node* insert_node (Node* N, int key){
    
    if (N==NULL){
        return New_node(key);
    }
    
    if (key < N->key)
        N->left = insert_node(N->left, key);
    else if (key > N->key)
        N->right = insert_node(N->right, key);
    else  
        {cout << "CANNOT HAVE SAME KEY";
        return N;}
    
    N->height = 1+ max(tree_height(N->right), tree_height(N->left));
    
    
    int balanceFactor = Balance_factor(N);
    
    
    
       // Right Right Case  
    if (key > get_key(N->right) and balanceFactor < -1)
        return Left_rotation(N); 
   
     // Left Left Case  
    if (balanceFactor > 1 and key < get_key(N->left))
        return Right_rotation(N); 
    
   
  
 
    
      // Right Left Case  
    if (  key < get_key(N->right) and   balanceFactor < -1){  
        N->right = Right_rotation(N->right);  
        return Left_rotation(N);  
    }  
    
   
    // Left Right Case  
    if (key > get_key(N->left) and    balanceFactor > 1 ){  
        N->left = Left_rotation(N->left);  
        return Right_rotation(N);  
    }  
   
  
  
    // returning the node pointer
    return N;  
    
    
    
}

Node* minimum_key(Node* N){
    
    Node* current = N;
    while(current->left!=NULL){
        current=current->left; 
    }
    return current;
}



Node* delete_node(Node* root, int key){
    if(root==NULL) return root;
    
    if (get_key(root) < key){
        root->right =  delete_node(root->right, key);
    }
    else if (get_key(root) > key){
        root->left =  delete_node(root->left, key);
    }
    //key found
    else {
         //with one or no child
        if (root->left==NULL or root->right==NULL){
            Node* current=NULL;
            if (root->left ==NULL) current = root->right;
            if (root->right ==NULL) current = root->left;
            if(current==NULL){
                current=root;
                root=NULL;
            }
            //one child
            else
                *root = *current; 
            
            free(current);
               
        }
        //two child
        else{
            Node* current= minimum_key(root->right);
            root->key = current->key;
            //*************
            root->right = delete_node(root->right, root->key);
        }
        
        if (root==NULL)
            return root;
        
        root->height= max(tree_height(root->left), tree_height(root->right))+1;
        
        int balanceFactor = Balance_factor(root);
         // Left Left Case  
    if (balanceFactor > 1 and  Balance_factor(root->left) >= 0)  
        return Right_rotation(root);  
        
     
         // Right Right Case  
    if (balanceFactor < -1 and  Balance_factor(root->right) <= 0)  
        return Left_rotation(root);  
  
  
    // Left Right Case  
    if (balanceFactor > 1 and Balance_factor(root->left) < 0)  {  
        root->left = Left_rotation(root->left);  
        return Right_rotation(root);  
    }  
        
     // Right Left Case  
    if (balanceFactor < -1 and Balance_factor(root->right) > 0){  
        root->right = Right_rotation(root->right);  
        return Left_rotation(root);  
    }  
  
  
   
   
    return root;  
        
            
    }
       
}


void printNode(Node *root){  
    if(root != NULL)  
    {  
        cout << root->key << " ";  
        printNode(root->left);  
        printNode(root->right);  
    }  
} 

int get_max(Node* root){
    if (root==NULL) {
        cout << "ERROR";
        return -1;}
    
    while (root->right!= NULL){
        root = root->right;
    }    
        return root->key;
}

int get_min(Node* root){
    if (root==NULL){ 
        cout << "ERROR";
        return -1;}
    
    while (root->left!= NULL){
        root = root->left;
    }    
        return root->key;
}



#endif	/* AVL_TREE_H */

