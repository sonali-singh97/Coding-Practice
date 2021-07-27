
struct Node* reverseList(struct Node *head)
    {
        if(head == NULL || head->next == NULL){
            return head;
        }
        
      struct Node* prev = NULL;
      struct Node* curr = head;
   
      while(curr != NULL) {
          struct Node * temp = curr->next;
          curr->next = prev;
          prev = curr;
          curr = temp;
      }
      
      return prev;
      
    }