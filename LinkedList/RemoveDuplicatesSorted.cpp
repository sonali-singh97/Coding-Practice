void removeDuplicates(struct Node* head)
{
    if(head == NULL)
    return head;
    
   struct Node* temp = head;
  
    while(temp->next != NULL){
        if(temp->data == temp -> next -> data){
           struct Node* rem = temp -> next;
            temp -> next = rem -> next;
        }
        
        else 
        temp = temp ->next;
    }
    return head;
    
}