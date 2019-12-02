#ifndef Vectorbag_h
#define Vectorbag_h

#include "Baginterface.h"
#include <vector>

template <class ItemType>
class VectorBag{
private:
    vector<ItemType> data;
    int itemCount;
    
public:
    VectorBag();
    
    vector<ItemType> toVector() const;
    bool add(ItemType const &item);
    bool remove(const ItemType &item);
    bool contains(const ItemType &item) const;
    bool isEmpty() const;
    int getFrequencyOf(const ItemType &item) const;
    int getCurrentSize() const;
    void clear();
    
    VectorBag<ItemType> operator+(const VectorBag<ItemType>& anotherBag);
    VectorBag<ItemType> operator-(const VectorBag<ItemType>& anotherBag);
    VectorBag<ItemType> operator*(const VectorBag<ItemType>& anotherBag);
};

#endif
