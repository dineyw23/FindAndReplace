#ifndef TRACKINGDEQUE_H
#define TRACKINGDEQUE_H
#include <deque>
#include <iostream>

using std::deque;

template <class T> 
class TrackingDeque : public deque<T>
{
  public:
    TrackingDeque(); 
    ~TrackingDeque();
    void push_front(const T&); 
    void push_back(const T&);
  private:
    int max_tracking_deque;
};

template <class T> 
TrackingDeque<T> :: TrackingDeque() : max_tracking_deque(0)
{
}

template <class T> 
TrackingDeque<T> :: ~TrackingDeque() 
{
  std::cout << "--> "  << max_tracking_deque <<" <--" << std::endl;
}

template <class T> 
void TrackingDeque<T> :: push_front(const T& value)
{
  deque<T> :: push_front(value);
  if(deque<T> :: size() > max_tracking_deque)
    ++max_tracking_deque;
}
template <class T> 
void TrackingDeque<T> :: push_back(const T& value)
{
  deque<T> :: push_back(value);
  if(deque<T> :: size() > max_tracking_deque)
    ++max_tracking_deque;
}
#endif 
