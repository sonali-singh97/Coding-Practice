
Node* segregate(Node *head) {
        
        Node* temp = head;

        
        Node* dummy0 = new Node(0);
        Node * dummy1 = new Node(0);
        Node* dummy2 = new Node(0);
        
        Node *zero = dummy0;
        Node * one = dummy1;
        Node* two = dummy2;
        
        while(temp != NULL){
            if(temp->data == 0){
                zero -> next = temp;
                zero = zero->next;
            }
            
            else if ( temp -> data ==1){
                one -> next = temp;
                one = one-> next;
            }
            
            else {
                two -> next = temp;
                two = two -> next;
            }
            
            temp = temp->next;
            
        }
        
        zero-> next = dummy1->next ? dummy1 ->next : dummy2->next;
        one->next = dummy2 ->next;
        two ->next = NULL;
        
        delete dummy0;
        delete dummy1;
        delete dummy2;
        
        return dummy0->next;
        
    }