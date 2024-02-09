
/**
 * Lock Free Queue is only safe with single producer and single consumer
 * and unsafe with multiple producers/consumers
 */

template <typename T>
class LockFreeQueue
{
private:
    std::atomic<uint32_t> front {0};
    std::atomic<uint32_t> back {0};
    /**
     * the queue size must always be a power of 2 for the atomics to work 
     */
    size_t QUEUE_SIZE;
    int QUEUE_BUFFER *;

public:
    void(size_t size)
    {
        this->QUEUE_SIZE = size;
        // allocate the pointer on the heap
        QUEUE_BUFFER = new int[this->QUEUE_SIZE];
       
    }
    bool push(const T& value)
    {
        if(isFull())
        {
            return false;
        }
        this->QUEUE_BUFFER[this->maskedModulo(this->back)] = value;
        this->back++;
        return true;
    }
    bool pop(T& value)
    {
        if(isEmpty())
        {
            return false;
        }
        this->front++;
        value = this->QUEUE_BUFFER[this->maskedModulo(this->front)];
        return false;
    }
    T peek()
    {
        if(isEmpty())
        {
            return false;
        }
        value = this->QUEUE_BUFFER[this->maskedModulo(this->front)];
        return false;
    }
    bool isEmpty()
    {
        return this->front == this->back;
    }
    bool isFull()
    {
        return (this->back - this->front ) == this->QUEUE_SIZE;
    }
    /**
     * perform modulo using bitwise operation 
     */
    uint32_t maskedModulo(uint32_t index)
    {
        return index & (this->QUEUE_SIZE - 1)
    }
};