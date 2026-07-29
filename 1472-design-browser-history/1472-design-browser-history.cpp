class BrowserHistory {
private: 
    stack<string> backward;
    stack<string> front;

public:
    BrowserHistory(string homepage) {
        backward.push(homepage);
    }
    
    void visit(string url) {
        backward.push(url);

        while(!front.empty()) {
            front.pop();
        }
    }
    
    string back(int steps) {
        while(steps && backward.size() > 1) {
            front.push(backward.top());
            backward.pop();
            steps--;
        } 
        return backward.top();
    }
    
    string forward(int steps) {
        while(steps && !front.empty()) {
            backward.push(front.top());
            front.pop();
            steps--;
        }
        return backward.top();
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */