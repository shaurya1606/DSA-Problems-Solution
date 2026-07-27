class MyQueue {

    
     Deque<Integer> stack = new ArrayDeque<>();
        Deque<Integer> helper = new ArrayDeque<>();
    public MyQueue() {
       
    }
    
    public void push(int x) {
        stack.push(x);
    }
    
    public int pop() {
        while(!stack.isEmpty()) {
            helper.push(stack.peek());
            stack.pop();
        }
        int remove = helper.pop();
        while(!helper.isEmpty()) {
            stack.push(helper.peek());
            helper.pop();
        }
        return remove;
    }
    
    public int peek() {
        while(!stack.isEmpty()) {
            helper.push(stack.peek());
            stack.pop();
        }
        int show = helper.peek();
        while(!helper.isEmpty()) {
            stack.push(helper.peek());
            helper.pop();
        }
        return show;
    }
    
    public boolean empty() {
        return stack.isEmpty();
    }
}

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * boolean param_4 = obj.empty();
 */