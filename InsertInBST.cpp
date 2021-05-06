InsertInBST.cpp

Node* insert(Node* root, int key)
{
    // Your code here
    
    if(root ==NULL)
      {
          Node* newNode = new Node(key);
         return newNode;
      }
    
    else if(root->data > key)
           root-> left = insert(root->left, key);
    
    
    else if(root->data < key)
    root-> right = insert(root->right, key);
    

    return root;
    
}
