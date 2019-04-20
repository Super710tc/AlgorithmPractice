/*
*/
class MyCircularQueue {
public:
    /** 初始化 */
    MyCircularQueue(int k) {
        rear=-1;
        front=0;
        QueueSize=k+1;
        data=new int[k+1];
    }
    
    /** 入队*/
    bool enQueue(int value) {
        if(!isFull())
        {
            rear=(rear+1)%QueueSize;
            data[rear]=value;
            return true;
        }
        else
            return false; 
    }
    
    /** 出队 */
    bool deQueue() {
        if(!isEmpty())
        {
            front=(front+1)%QueueSize;
            return true;
        }
        else
            return false;
    }
    
    /** 取头结点 */
    int Front() {
        if(!isEmpty())
        {
            return data[front];
        }
        else
            return -1;
    }
    
    /** 尾节点 */
    int Rear() {
        if(!isEmpty())
        {
            return data[rear];
        }
        else
            return -1;
    }
    
	 /** 判断空 */
    bool isEmpty() {
        return (rear+1)%QueueSize==front;
    }
    
    /** 判断满 */
    bool isFull() {
        return (rear+2)%QueueSize==front;
    }
    private:
    int*data;
    int front,rear;
    int QueueSize;
};
    bool isEmpty() {
        return (rear+1)%QueueSize==front;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return (rear+2)%QueueSize==front;
    }
    private:
    int*data;
    int front,rear;
    int QueueSize;
};