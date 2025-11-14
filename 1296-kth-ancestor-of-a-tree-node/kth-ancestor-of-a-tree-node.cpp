class TreeAncestor {
public:
    vector<vector<int>> up;
    TreeAncestor(int n, vector<int>& parent) {
        up.resize(5e4+1, vector<int>(16));
        for(int i = 0; i < n; i++)
            up[i][0] = parent[i];
        for(int j = 1; j < 16; j++) 
            for(int i = 0; i < n; i++) {
                if(up[i][j - 1] == -1)
                    up[i][j] = -1;
                else
                    up[i][j] = up[ up[i][j - 1] ][j - 1];
            }
    }
    
    int getKthAncestor(int node, int k) {
        while(k) {
            int msb = (31 - __builtin_clz(k));
            node = up[node][msb];
            if(node == -1)
                return node;
            k ^= (1 << msb);
        }
        return node;
    }
};

