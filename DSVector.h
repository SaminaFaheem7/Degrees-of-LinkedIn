// Created by MARK FONTENOT on 6/7/22.
// Updated by Samina Faheem

#ifndef PA01_SENTIMENT_DSVECTOR_H
#define PA01_SENTIMENT_DSVECTOR_H

template<typename T>
class DSVector {

private:
    int cap;
    int size;
    T* data;

public:
    DSVector(int init_capacity = 10);
    DSVector(const DSVector& arg);
    ~DSVector();
    void pushBack(const T& arg);
    T& operator[](int location);
    DSVector& operator=(const DSVector& arg);
    int getSize();
    void resize();
    void remove_value(T);
    void remove_index(int index);
    int searchindex(T);
    void swap(T &a, T &b);
    void selectionsort();
};

template <typename T>
DSVector<T>::DSVector(int init_capacity) {
    size = 0;
    cap = init_capacity;
    data = new T[cap];
}

template <typename T>
DSVector<T>::DSVector(const DSVector& arg) {
    cap = arg.cap;
    size = arg.size;
    data = new T[cap];
    for(int i = 0; i < size; i++)
        data[i] = arg.data[i];
}

template <typename T>
DSVector<T>::~DSVector() {
    delete [] data;
}

//Assigning the value on the right  DSVector to the left DSVector
template <typename T>
DSVector<T>& DSVector<T>::operator=(const DSVector& arg) {

    if(this != &arg){
        delete[] data;
        size = arg.size;
        cap = arg.cap;
        data = new T[cap];
        for (int i = 0; i < size; i++) {
            data[i] = arg.data[i];
        }
    }
    return *this;
}
//Adding contents to the end of the DSSVector
template<typename T>
void DSVector<T>::pushBack(const T& arg) {
    data[size] = arg;
    size++;
    if(size == cap)
    {
        resize();
    }
}

//Accessing values of DSSVector
template<typename T>
T& DSVector<T>::operator[](int location) {
    return data[location];
}

//Getting the size of the vector
template<typename T>
int DSVector<T>::getSize() {
    return size;
}
//The size of the vector after adding more elements to the original.
template<typename T>
void DSVector<T> ::resize() {
    cap *= 2;

    T* newdata = new T[cap];
    for(int i =0; i< size; i++)
    {
        newdata[i]= data[i];
    }
    delete []data;
    data= newdata;
}

//Removing a certain value from the DSVector
template<typename T>
void DSVector<T> ::remove_value(T value){
    for(int i=0; i< size; i++ )
    {
        if(data[i]== value)
        {
            remove_index(i);
            i--;
        }
    }
}

//Removing the index where the value existed before removing that value.
template<typename T>
void DSVector<T> ::remove_index(int index) {
    T* newdata = new T[cap];
    //Everything before
    for(int i =0; i< index; i++)
    {
        newdata[i]= data[i];
    }
    //Everything after removing the index, picking where we left off
    for(int i= index+1; i<size ;i++){
        newdata[i-1]= data[i];// one earlier than new data,
    }
    delete []data;
    data= newdata;
    size--;  // need to update the size of the new array
}

//Searching for the index where the value exist.
template<typename T>
int DSVector<T> ::searchindex(T index_val) {
    for(int i=0; i< size; i++){
        if(data[i]== index_val)
        {
            return i;
        }
    }
    return -1;
}

//Swapping the elements in the DSSVector
template<typename T>
void DSVector<T> ::swap(T &a, T &b)
{
    T temp =a;
    a=b;
    b=temp;
}

//Sorting the elemets using the method Selection sort, looked up online for the implementation.
template<typename T>
void DSVector<T>::selectionsort()
{
    for(int i=0; i< size-1; i++)
    {
        int min = i;
        for(int j = i+1; j < size; j++) {
            if (data[j] < data[min]){
                min = j;
            }
        swap(data[i], data[min]);
        }
    }
}
#endif //PA01_SENTIMENT_DSVECTOR_H
