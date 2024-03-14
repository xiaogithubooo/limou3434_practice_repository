//blocking_queue.hpp
#pragma once
#include <iostream>
#include <queue>
#include <unistd.h>
#include <pthread.h>

const int gDefaultCap = 5;

template<typename T>
class BlockingQueue
{
    private:bool IsQueueEmpty()
    {
        return _bq.size() == 0;
    }
    private:bool IsQueueFull()
    {
        return _bq.size() == _capacity;
    }

    //初始化锁和条件变量
    public:BlockingQueue(int capacity = gDefaultCap) //默认为上限为 5
        : _capacity(capacity)
    {
        pthread_mutex_init(&_mutex, nullptr);
        pthread_cond_init(&_p_cond, nullptr);
        pthread_cond_init(&_c_cond, nullptr);
    }

    //生产者产数据
    public:void Push(const T& in)
    {
        //加锁，防止消费者非法消费
        pthread_mutex_lock(&_mutex);

        //检测临界资源是否满足访问条件（队列是否为满）
        if (IsQueueFull())
            pthread_cond_wait(&_full, &_mutex);
        //第二个参数是锁的原因是：
        //生产者是带着锁去阻塞的，那消费者就无法拿到锁，
        //最终生产者的挂起是没有效果的，本来我们挂起就是为了让消费者去消费资源...
        //因此第二个参数可以传递锁，在函数内的锁会被自动解开

        //如果线程在这行之前曾被挂起，则会从这里继续运行/唤醒，唤醒的时候 pthread_cond_wait() 会自动为线程获取锁
         
        //访问临界资源，生产数据
        _bq.push(in);

        //解锁
        pthread_mutex_unlock(&_mutex);

        //唤醒消费者
        pthread_cond_signal(&_empty);
    }

    //消费者取数据
    public:void Pop(T* out)
    {
        //加锁
        pthread_mutex_lock(&_mutex);

        //检测临界资源是否满足访问条件（队列是否为空）
        if(IsQueueEmpty()) pthread_cond_wait(&_empty, &_mutex);

        //访问临界资源，取得数据
        *out = _bq.front();
        _bq.pop();

        //解锁
        pthread_mutex_unlock(&_mutex);

        //唤醒生产者
        pthread_cond_signal(&_full);

    }

    public:~BlockingQueue()
    {
        pthread_mutex_destroy(&_mutex);
        pthread_cond_destroy(&_empty);
        pthread_cond_destroy(&_full);
    }

private:
    std::queue<T> _bq; //阻塞队列，存储数据
    int _capacity; //容量上限

    pthread_mutex_t _mutex; //通过互斥锁保护队列安全（对队列的 Push 和 Pop 操作都需要依靠这个锁来达到原子）
    pthread_cond_t _p_cond; //通过条件变量阻塞队列（该条件变量表示 _bq 为满，可以让生产者停止生产）
    pthread_cond_t _c_cond; //通过条件变量阻塞队列（该条件变量表示 _bq 为空，可以让消费者停止消费）
    /* 如果不用条件变量，那么线程每一次都会去申请锁来检查队列的情况。而谁来唤醒生产者和消费者呢？实际上双方互相提醒是最合适的! */
};