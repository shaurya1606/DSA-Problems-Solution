class MyStack {

    private Queue<Integer> mainQueue;
    private Queue<Integer> helperQueue;

    public MyStack() {
        mainQueue = new LinkedList<>();
        helperQueue = new LinkedList<>();
    }

    public void push(int x) {

        helperQueue.offer(x);

        while (!mainQueue.isEmpty()) {
            helperQueue.offer(mainQueue.poll());
        }

        Queue<Integer> temp = mainQueue;
        mainQueue = helperQueue;
        helperQueue = temp;
    }

    public int pop() {
        return mainQueue.poll();
    }

    public int top() {
        return mainQueue.peek();
    }

    public boolean empty() {
        return mainQueue.isEmpty();
    }
}