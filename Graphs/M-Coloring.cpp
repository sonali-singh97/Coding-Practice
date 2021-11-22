
// Time complexity = O(m ^V)

bool safe(bool graph[101][101], int v, int node, int cl, int color[]){
    for (int i =0; i <v; i ++){
        if (i !=node && graph[i][node] && color[i] == cl) return false;
    }
    return true;
}

bool graphColouringHelper(bool graph[101][101], int m, int v, int node, int color[]){
    if (node == v) return true;
    
    for ( int i = 1; i <= m ; i++){
        if ( safe(graph,v, node, i, color)){
            color[node] = i;
           if( graphColouringHelper(graph, m , v, node+1, color)) return true;
           color[node]= 0;
        }
    }
    
    return false;
}

bool graphColoring(bool graph[101][101], int m, int V)
{   
    int color[V];
    memset(color, 0, sizeof color);
    return graphColouringHelper(graph, m , V, 0, color);
}