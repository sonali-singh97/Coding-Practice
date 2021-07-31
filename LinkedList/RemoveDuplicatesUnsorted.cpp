 Node * removeDuplicates( Node *head) 
    {
     Node* temp = head;
     Node* prev = NULL;
     unordered_map<int, int> count;
     
     while(temp != NULL){
         if(count[temp->data]){
             prev->next = temp->next;
         }
         
         else {
             count[temp->data]++;
             prev = temp;
         }
         
         temp = temp->next;
     }
     
     return head;
    }