
Node* MovetoFront (Node* head){

if(head == NULL || head->next ==NULL){
    return;
}

NOde* temp = head;
Node* prev = NULL;

while(temp->next != NULL){
    prev = temp;
    temp = temp->next;
}

prev->next = NULL;
temp->next = head;
return temp;

}