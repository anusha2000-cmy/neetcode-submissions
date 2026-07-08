class CountSquares {

private:
    map<pair<int,int>,int> m;
    vector<vector<int>> p;
public:
    CountSquares() {     
    }
    
    void add(vector<int> point) {
        p.push_back(point);
        m[{point[0],point[1]}]++;
    }
    
    int count(vector<int> point) {
        int x=point[0];
        int y=point[1];
        int res=0;
        for(auto pp:p){
            if(abs(pp[1]-y)==abs(pp[0]-x) && x!=pp[0] && y!=pp[1]){
                res+=m[{x,pp[1]}]*m[{pp[0],y}];
            }
        }
        return res;
    }
};
