class Solution {
public:
    bool f(int n, int c, vector<int>& color, vector<vector<int>>& graph) {
        color[n] = c;

        for(auto i: graph[n]) {
            if(color[i] == -1) {
                if(f(i, !c, color, graph) == false) {
                    return false;
                }
            } else {
                if(color[i] == color[n]) {
                    return false;
                }
            }
        }

        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size(), -1);

        for(int i=0; i<graph.size(); i++) {
            if(color[i] == -1) {
                if(!f(i, 0, color, graph)) return false;
            }
        }

        return true;

    }
};
