class TreeAncestor {
public:
    vector<vector<int> > P;
    TreeAncestor(int n, vector<int>& parent) {
        // initialize
        P.resize(20, vector<int>(parent.size(), -1));
        
        for(int i = 0; i < parent.size(); i++){
            P[0][i] = parent[i];
        }
        
        for(int i = 1; i < 20; i++){
            for(int node = 0; node < parent.size(); node ++){
                int nodep = P[i-1][node];
                if(nodep != -1) P[i][node] = P[i-1][nodep];
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        for(int i = 0; i < 20; i++){
            if(k & (1 << i)){
                node = P[i][node];
                if(node == -1) return -1;
            }
        }

        return node;
    }
};
