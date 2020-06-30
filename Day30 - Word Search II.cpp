class tries{
    bool terminal;
    //int terminal;
    unordered_map<char ,tries *> children;
    char ch;
    tries(char data){
        ch=data;
        terminal =false;
    }
};
class Solution {
public:
    void backtrack(int x, int y, vector<vector<char> > &board, tries *node, vector<string> &ans, string &cur){
        char tmp = board[x][y];
        board[x][y] = '#' ;
        node = node->children[tmp];
        if(node->terminal){
            ans.push_back(cur);
            node->terminal=false;
        }

        int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        for(int i=0; i<4; ++i){
            int x_ = x+dir[i][0], y_ = y+dir[i][1];
            if(x_ >= 0 && x_ < board.size() && y_ >= 0 && y_ < board[0].size() && board[x_][y_] != '#' && node->children[board[x_][y_]]){
                cur.push_back(board[x_][y_]);
                backtrack(x_, y_, board, node, ans, cur);
                cur.pop_back();
            }
        }
        board[x][y] = tmp;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        if(board.empty() || words.empty()) return vector<string>();
        tries *root = new tries('\0');
        for(auto &word: words){
            tries *temp = root;
            for(auto &c: word){
                if(temp->children.count(c))
                    temp=temp->children[c];
                else{
                    Node * n=new Node(c);
                    temp->children[c]=n;
                    temp=n;
                }
            }
            temp->terminal=true;
        }

        vector<string> ans;
        ans.reserve(words.size());
        int N = board.size(), M = board[0].size();
        for(int i=0; i<N; ++i){
            for(int j=0; j<M; ++j){
                if(root->children.count([board[i][j])){
                    string cur = "";
                    cur.push_back(board[i][j]);
                    backtrack(i, j, board, root, ans, cur);
                }
            }
        }
        return ans;
    }
};
