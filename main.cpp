/* 
 * File:   main.cpp
 * Author: Ronish
 *
 * Created on November 23, 2019, 3:09 PM
 */

#include <cstdlib>
#include "Avl_tree.h"

int main()  
{  
    Node *root = NULL;
    //root = New_node(5);
    
      
    for (int i = 1 ; i < 50; i++) 
    root = insert_node(root, i);
    
    
   

      
   
  
    cout << "the AVL tree in preorder traversal looks like"<<endl ;  
    printNode(root);  
    
        cout << "max in the AVL tree is" << get_max(root)<< endl;
    
     
      
    
    root = delete_node(root, 49);  

    cout << "The AVL tree after deleting 49"<<endl;
    
    printNode(root); 
    
    cout << "max in the AVL tree is" << get_max(root)<<endl;
     
    
    cout << "minimum in the AVL tree is" << get_min(root)<<endl;
    
    return 0;
}  
