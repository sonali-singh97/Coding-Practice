/*** Question: 450 list 
 Src: https://leetcode.com/problems/clone-graph/
 *****/

  Node* cloneGraphHelper(Node* node, unordered_map<int,Node*>& store){
      int value = node->val;
      
        if(store.find(value)!= store.end()){
            return store[value];
        }
        
        Node* nodeClone = new Node(value);
        store[value] = nodeClone;
        for ( auto it : node->neighbors){
            nodeClone->neighbors.push_back(cloneGraphHelper(it, store));
        }
        
        return nodeClone;
    }
    
    Node* cloneGraph(Node* node) {
      if (node == NULL) return NULL;
      unordered_map<int, Node*> store;
      return cloneGraphHelper(node, store);
    }

/****Approach****
Time Complexity: O(E+V) (In case of fully connected graph= (E.V))
- Use DFS to clone the graph and store the cloned nodes in hashmap/array
******/