#include "VectorBag.h"
#include <vector>
using namespace std;

template <class ItemType>
VectorBag<ItemType>::VectorBag(){
    itemCount = 0;
}
template <class ItemType>
VectorBag<ItemType> VectorBag<ItemType>::operator+(const VectorBag<ItemType>& anotherBag) {
    VectorBag<ItemType> unionbaggie;
    
    for (int i = 0; i < itemCount; i++) {
        unionbaggie.add(data[i]);
    }
    for (int i = 0; i < anotherBag.itemCount; i++) {
        unionbaggie.add(anotherBag.data[i]);
    }
    return unionbaggie;
}
template <class ItemType>
VectorBag<ItemType> VectorBag<ItemType>::operator-(const VectorBag<ItemType>& anotherBag){
    VectorBag<ItemType> differenceBag;
    
    for(int i = 0; i < itemCount; i++)
        differenceBag.add(data[i]);
    
    for(int z = 0; z < itemCount; z++){
        for(int j = 0; j < anotherBag.itemCount; j++){
            if(anotherBag.data[j] == data[z]){
                differenceBag.remove(data[z]);
                itemCount--;
            }
        }
    }
    return differenceBag;
}
template <class ItemType>
VectorBag<ItemType> VectorBag<ItemType>::operator*(const VectorBag<ItemType>& anotherBag){
    VectorBag<ItemType> intersectionBag;
    
    for(int z = 0; z < itemCount; z++){
        for(int j = 0; j < anotherBag.itemCount; j++){
            if(data[z] == anotherBag.data[j] && intersectionBag.getFrequencyOf(anotherBag.data[j]) == 0)
                intersectionBag.add(anotherBag.data[j]);
        }
    }
    return intersectionBag;
}
template <class ItemType>
bool VectorBag<ItemType>::isEmpty() const{
    return data.size() == 0;
}
template <class ItemType>
bool VectorBag<ItemType>::add(ItemType const &item){
    data.push_back(item);
    itemCount++;
    return true;
}
template<class ItemType>
int VectorBag<ItemType>::getCurrentSize() const {
    return data.size();
}
template<class ItemType>
vector<ItemType> VectorBag<ItemType>::toVector() const{
    return data;
}
template<class ItemType>
int VectorBag<ItemType>::getFrequencyOf(const ItemType &item) const{
    int count = 0;
    for (int i = 0; i < data.size(); i ++) {
        if (data[i] == item)
            count++;
    }
    return count;
}
template<class ItemType>
bool VectorBag<ItemType>::contains(const ItemType &item) const{
    for (int i = 0; i < data.size(); i ++){
        if (data[i] == item)
            return true;
    }
    return false;
}
template<class ItemType>
void VectorBag<ItemType>::clear() {
    data.clear();
}
template<class ItemType>
bool VectorBag<ItemType>::remove(const ItemType &item){
    for (int i = 0; i < data.size(); i++) {
        if (data[i] == item){
            data[i] = data[data.size() - 1];
            data.pop_back();
            return true;
        }
    }
    return false;
}
