#include "../headers/Queue.hpp"

template <typename T, typename Sequence>
Queue<T, Sequence>::Queue()
    : Sequence()
{}

template <typename T, typename Sequence>
Queue<T, Sequence>::Queue(const Queue<T, Sequence>& rhv)
    : Sequence(rhv)
{}

template <typename T, typename Sequence>
Queue<T, Sequence>::~Queue()
{
    Sequence::clear();
}

template <typename T, typename Sequence>
Queue<T, Sequence>&
Queue<T, Sequence>::operator=(const Queue<T, Sequence>& rhv)
{
    if (this != &rhv) {
        Sequence::operator=(rhv);
    }
    return *this;
}

template <typename T, typename Sequence>
bool
Queue<T, Sequence>::operator==(const Queue<T, Sequence>& rhv) const
{
    return (static_cast<const Sequence&>(*this)) == (static_cast<const Sequence&>(rhv));
}

template <typename T, typename Sequence>
bool
Queue<T, Sequence>::operator!=(const Queue<T, Sequence>& rhv) const
{
    return !(*this == rhv);
}

template <typename T, typename Sequence>
bool
Queue<T, Sequence>::operator<(const Queue<T, Sequence>& rhv) const
{
    return (static_cast<const Sequence&>(*this)) < (static_cast<const Sequence&>(rhv));
}

template <typename T, typename Sequence>
bool
Queue<T, Sequence>::operator>(const Queue<T, Sequence>& rhv) const
{
    return (static_cast<const Sequence&>(*this)) > (static_cast<const Sequence&>(rhv));
}

template <typename T, typename Sequence>
bool
Queue<T, Sequence>::operator<=(const Queue<T, Sequence>& rhv) const
{
    return !(*this > rhv);
}

template <typename T, typename Sequence>
bool
Queue<T, Sequence>::operator>=(const Queue<T, Sequence>& rhv) const
{
    return !(*this < rhv);
}

template <typename T, typename Sequence>
typename Queue<T, Sequence>::reference
Queue<T, Sequence>::top()
{
    assert(!empty());
    return Sequence::front();     
}

template <typename T, typename Sequence>
typename Queue<T, Sequence>::const_reference
Queue<T, Sequence>::top() const
{
    assert(!empty());
    return Sequence::front();     
}

template <typename T, typename Sequence>
void
Queue<T, Sequence>::push(const_reference value)
{
    return Sequence::push_back(value);
}

template <typename T, typename Sequence>
void
Queue<T, Sequence>::pop()
{
    assert(!empty());
    return Sequence::pop_front();
}

template <typename T, typename Sequence>
bool
Queue<T, Sequence>::empty() const
{
    return Sequence::empty();
}

template <typename T, typename Sequence>
typename Queue<T, Sequence>::size_type
Queue<T, Sequence>::size() const
{
    return Sequence::size();
}

