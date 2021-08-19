
    Node* divide(int N, Node *head){
        
        Node *dummyEven = new Node(1);
        Node *dummyOdd = new Node(1);
        
        Node *temp = head;
        Node *even = dummyEven;
        Node *odd = dummyOdd;
        
        while ( temp != NULL) {
            
            if( temp->data %2 == 0){
                even -> next = temp;
                even = even-> next;
            }
            
            else { 
                odd -> next = temp;
                odd = odd -> next;
                
            }
            
            temp = temp -> next;
        }
    
        even -> next = dummyOdd -> next;
        odd -> next = NULL;
        
        return dummyEven -> next;
        
    }