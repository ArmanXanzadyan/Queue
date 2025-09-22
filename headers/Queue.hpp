#ifndef __QUEUE_HPP__
#define __QUEUE_HPP__

#include <deque>

template <typename T, typename Sequence = std::deque<T> >
class Queue : private Sequence
{
public:
    typedef typename std::deque<T>::value_type      value_type;
    typedef typename std::deque<T>::size_type       size_type;
    typedef typename std::deque<T>::reference       reference;
    typedef typename std::deque<T>::const_reference const_reference;

public:
    Queue();
    Queue(const Queue<T, Sequence>& rhv);
    ~Queue();

    Queue<T, Sequence>& operator=(const Queue<T, Sequence>& rhv);
    bool                operator==(const Queue<T, Sequence>& rhv) const;
    bool                operator!=(const Queue<T, Sequence>& rhv) const;
    bool                operator<(const Queue<T, Sequence>& rhv)  const;
    bool                operator>(const Queue<T, Sequence>& rhv)  const;
    bool                operator>=(const Queue<T, Sequence>& rhv) const;
    bool                operator<=(const Queue<T, Sequence>& rhv) const;

    reference       top();
    const_reference top() const; 
    void            push(const_reference value);
    void            pop();

    bool      empty() const;
    size_type size()  const;
};

#include "../templates/Queue.cpp"

#endif /// __QUEUE_HPP__

