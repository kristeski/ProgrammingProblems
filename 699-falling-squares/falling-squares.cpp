class Solution {
public:
    struct Node{
        int l, r, lz, val;
        Node *lc, *rc;
        Node(int l, int r) : l(l), r(r), lz(0), val(0), lc(NULL), rc(NULL){}
    };
    void calc(Node* curr) {
        int l, r;
        l = curr->lc->val;
        r = curr->rc->val;
        curr->val = max(l, r);
    }
    void prop(Node* curr) {
        int md = (curr->l + curr->r) >> 1;
        if(curr->l == curr->r)
            return;
        if(!curr->lc)
            curr->lc = new Node(curr->l, md);
        if(!curr->rc)
            curr->rc = new Node(md + 1, curr->r);
        if(!curr->lz) 
            return;
        curr->lc->val = curr->lz;
        curr->rc->val = curr->lz;
        curr->lc->lz = curr->lz;
        curr->rc->lz = curr->lz;
        curr->lz = 0;
    }
    int qry(int L, int R, Node* curr) {
        if(curr->l >= L && curr->r <= R)
            return curr->val;
        if(curr->l > R || curr->r < L)
            return 0;
        prop(curr);
        int lo = 0, ro = 0;
        if(curr->lc)
            lo = qry(L, R, curr->lc);
        if(curr->rc)
            ro = qry(L, R, curr->rc);
        return max(lo, ro);
    }
    void rup(int L, int R, int vl, Node* curr) {
        prop(curr);
        if(curr->r < L || curr->l > R)
            return;
        if(curr->l >= L && curr->r <= R) {
            curr->val=vl;
            curr->lz=vl;
            return;
        }
        rup(L, R, vl, curr->lc);
        rup(L, R, vl, curr->rc);
        calc(curr);
    }
    void rupp(int L, int R, int vl, Node* curr) {
        int maxi = qry(L, R, curr);
        rup(L, R, maxi + vl, curr);
    }
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        vector<int> sol;
        sol.reserve(positions.size());
        Node* root = new Node(0, (int)1e8 + 1e6);
        for(vector<int>&v : positions) {
            rupp(v[0], v[0] + v[1] - 1, v[1], root);
            sol.push_back(root->val);
        }
        return sol;
    }
};