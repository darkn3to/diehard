#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/*class Edge {
    public:
        int src, det;
        int wt;
        Edge(int src, int wt, int det) : src(src), wt(wt), det(det) {}
        Edge(int src, int det) : src(src), det(det) {}
};

//bfs alt
void bfs(vector<Edge> g) {
    queue<int> q;
    bool visited[g.size()];
    q.push(0);
    while (!q.empty()) {
        int curr=q.front();
        q.pop();
        if (!visited[curr]) {
            cout << curr << " ";
            visited[curr]=true;
            for (int i=0; i<g.size(); i++) {
                if (g[i].src==curr) {
                    q.push(g[i].det);
                }
            }
        }
    }
}
int main() {
    vector<Edge> g;
    g.push_back(Edge(0, 1));
    g.push_back(Edge(0, 2));
    g.push_back(Edge(1, 3));
    g.push_back(Edge(2, 3));
    g.push_back(Edge(3, 4));
    g.push_back(Edge(4, 5));
    g.push_back(Edge(5, 6));
    bfs(g);
}


//bfs trav
void util(vector<vector<int>> g, vector<bool> &v) {
    queue<int> q;
    q.push(0);
    v[0]=true;
    while (!q.empty()) {
        int curr=q.front();
        //cout << curr << " ";
        q.pop();
        for (auto it: g[curr]) {
            if (!v[it]) {
                q.push(it);
                v[it]=true;
            }
        }
    }
}
void bfs(vector<vector<int>> g) {
    vector<bool> v(g.size(), false);
    for (int i=0; i<g.size(); i++) {
        if (!v[i]) util(g, v);
    }
}

//dfs trav
void dfsutil(vector<vector<int>> g, vector<bool> &dv, int i) {
    cout << i << " ";
    dv[i]=true;
    for (int j=0; j<g[i].size(); j++) {
        if (!dv[g[i][j]]) dfsutil(g, dv, g[i][j]);
    }
}
void dfs(vector<vector<int>> g) {
    vector<bool> dv(g.size(), false);
    for (int i=0; i<g.size(); i++) {
        if (!dv[i]) dfsutil(g, dv, i);
    }
}*/


//dfs cycle detection
/*void util(vector<vector<int>> g, vector<bool> &v, int curr, int par) {
    v[curr]=true;
    for (int i=0; i<g[curr].size(); i++) {
        if (!v[g[curr][i]]) util(g, v, g[curr][i], curr);
        else if (g[curr][i]!=par) {
            cout << "cycle";
            exit(0);
        }
    }

}
void detect_cycle(vector<vector<int>> g) {
    vector<bool> v(g.size(), false);
    for (int i=0; i<g.size(); i++) {
        if (!v[i]) util(g, v, i, -1);
    }
}



//directed graph cycle detection
void util(vector<vector<int>> g, vector<bool> &v, vector<bool> &stack, int curr) {
    v[curr] = true;
    stack[curr] = true;

    for (int i = 0; i < g[curr].size(); i++) {
        if (!v[g[curr][i]]) util(g, v, stack, g[curr][i]);
        else if (stack[g[curr][i]]) {
            cout << "cycle";
            exit(0);
        }
    }

    stack[curr] = false;  // remove the node from the recursion stack as we leave the function
}

void detect_cycle(vector<vector<int>> g) {
    vector<bool> v(g.size(), false);
    vector<bool> stack(g.size(), false);
    for (int i = 0; i < g.size(); i++) {
        if (!v[i]) util(g, v, stack, i);
    }
}
*/

/*

//bfs cycle detection
void util(vector<vector<int>> g, vector<bool> &v, int curr, int par) {
    queue<int> q;
    q.push(curr);
    v[curr]=true;
    for (int i=0; i<g[curr].size(); i++) {
        if (!v[g[curr][i]]) {
            q.push(g[curr][i]);
            v[g[curr][i]]=true;
        }
        else if (g[curr][i]!=par) {
            cout << "cycle";
            exit(0);
        }
    }
}
void detect_cycle(vector<vector<int>> g) {
    vector<bool> v(g.size(), false);
    for (int i=0; i<g.size(); i++) {
        if (!v[i]) util(g, v, i, -1);
    }
}*/

/*

//bfs bipartite

*/


/*

//bipartite alternate approach
//needs to be reviewed.
static int flag=0;
pair<int, int> cycle(vector<vector<int>> g, vector<bool> &v, int curr, int par, int count) {
    v[curr]=true;
    cout << count << " ";
    for (int i=0; i<g[curr].size(); i++) {
        if (!v[g[curr][i]]) {
            cycle(g, v, g[curr][i], curr, count+1);
        }
        else if (g[curr][i]!=par) flag=1;
    }
    return {flag, count};
}
void bi(vector<vector<int>> g) {
    vector<bool> v(g.size(), false);
    for (int i=0; i<g.size(); i++) {
        if (!v[i]) {
            auto it=cycle(g, v, i, -1, 1);
            if (!it.first) {
                cout << "bipartite";
                exit(0);
            }
            else {
                if (it.second%2==0) {
                    cout << "bipartite";
                    exit(0);
                }
                else if (it.second%2!=0){
                    cout << "not bipartite";
                    exit(0);
                }
            }
        }
    }
}
*/
/*

//bipartite correct
void util(vector<vector<int>> g, vector<bool> &v, int curr, vector<char> &c, char c_color) {
    queue<int> q;
    q.push(curr);
    v[curr]=true;
    c[curr]=c_color;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        char adj_color = (c[node] == 'y') ? 'b' : 'y';
        for (int i = 0; i < g[node].size(); i++) {
            if (!v[g[node][i]]) {
                q.push(g[node][i]);
                v[g[node][i]] = true;
                c[g[node][i]] = adj_color;
            }
            else if (c[g[node][i]] == c[node]) {
                cout << "not bipartite";
                exit(0);
            }
        }
    }
}
void bi(vector<vector<int>> g) {
    vector<bool> v(g.size(), false);
    vector<char> c(g.size(), 'n');
    for (int i=0; i<g.size(); i++) {
        if (!v[i]) util(g, v, i, c, 'y');
    }
}*/

/*

//topological sort using dfs
void util(vector<vector<int>> g, vector<bool> &v, int curr, stack<int> &s) {
    v[curr]=true;
    for (int i=0; i<g[curr].size(); i++ ) {
        if (!v[i]) util(g, v, g[curr][i], s);
    }
    s.push(curr);
}

void tsort(vector<vector<int>> g) {
    vector<bool> v(g.size(), false);
    
    stack<int> s;
    for (int i=0; i<g.size(); i++) {
        if (!v[i]) util(g, v, i, s);
    }
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
}
*/

int main() {
    vector<vector<int>> g={
        {2}, // Node 0 is connected to nodes 1 and 3
    {0}, // Node 1 is connected to nodes 0 and 2
    {1}, // Node 2 is connected to nodes 1 and 3
    {3} 
    };
    
    //bfs(g);
    //detect_cycle(g);
    //bi(g);
    //tsort(g);
    cout << endl;
    //dfs(g);
    return 0;
}

