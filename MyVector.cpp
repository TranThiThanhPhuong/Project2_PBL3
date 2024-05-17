#include"MyVector.h"
#include<cstddef> 
// #include"Subject.h"
// #include"Students.h"
#include <iostream>
using namespace std;
template <class T>
MyVector<T>::MyVector()  {
    this->data = NULL;
    this->size = 0;
}

template <class T>
MyVector<T>::~MyVector() {
    delete[] data;
}
// Trả về kích thước hiện tại của vector.
template <class T>
int MyVector<T>::getSize() const {
    return size;
}
// Kiểm tra xem vector có rỗng không (kích thước bằng 0).
template <class T>
bool MyVector<T>::isEmpty() const {
    return size == 0;
}
// Đặt kích thước vector về 0, làm rỗng vector.
template <class T>
void MyVector<T>::clear() {
    delete[] data;
    data = NULL;
    size = 0;
}
// Thêm một phần tử vào cuối vector. Nếu vector đầy, thực hiện một phương thức resize() để tăng dung lượng của vector.
template <class T>
void MyVector<T>::pushBack(const T& value) {
    T* new_p = new T[size + 1];
    for (int i = 0; i < size; i++){
        new_p[i] = data[i];
    }
    new_p[size] = value;
    delete[] data;
    data = new_p;
    size++;
    // if (size == capacity) {
    //     resize(2 * capacity);
    // }
    // data[size++] = value;
}
//  Loại bỏ phần tử cuối cùng khỏi vector.
template <class T>
void MyVector<T>::popBack() {
    if (size > 0) {
        T* new_p = new T[size - 1];
        for (int i = 0; i < size - 1; i++) {
            new_p[i] = data[i];
        }
        delete[] data;
        data = new_p;
        size--;
    }
    // if (!isEmpty()) {
    //     size--;
    // }
}
template <class T>
T& MyVector<T>::at(int index) {
    if (index < size) {
        return data[index];
    } else {
        throw std::out_of_range("Index out of range");
    }
}
// Trả về tham chiếu đến phần tử tại chỉ số index. Kiểm tra giới hạn chỉ số và xử lý nếu nó vượt quá kích thước hiện tại.
template <class T>
const T& MyVector<T>::at(int index) const {
    if (index < size) {
        return data[index];
    } else {
        // Thay vì không trả về giá trị, bạn có thể throw một exception
        // hoặc trả về giá trị mặc định, tùy thuộc vào yêu cầu của bạn.
        throw std::out_of_range("Index out of range");
    }
}
// Chèn một phần tử vào vector tại chỉ số index. Nếu vector đầy, thực hiện một phương thức resize() để tăng dung lượng của vector.
// template <class T>
// void MyVector<T>::insert(int index, const T& value) {
//     if (index > size) {
//         // Handle invalid index, e.g., throw an exception
//         return;
//     }
//     if (size == capacity) {
//         resize(2 * capacity);
//     }
//     for (int i = size; i > index; i--) {
//         data[i] = data[i - 1];
//     }
//     data[index] = value;
//     size++;
// }
// Loại bỏ phần tử tại chỉ số index từ vector.
template <class T>
void MyVector<T>::remove(const int index) {
     if (index >= 0 && index < size) {
        for (int i = index; i < size - 1; i++) {
            data[i] = data[i + 1];
        }
        size--;
    }
    // if (index < size) {
    //     for (int i = index; i < size - 1; i++) {
    //         data[i] = data[i + 1];
    //     }
    //     size--;
    // }
}
template <class T>
T& MyVector<T>::operator[](const int& index) {
    // return at(index);
    if (index >= size || index < 0) {
        return data[0];        /// Trả về mặc định rồi so sánh
    }
    return data[index];
}
// In ra màn hình các phần tử của vector.
template <class T>
void MyVector<T>::print() const {
    cout << "[ ";
    for (int i = 0; i < size; i++) {
        cout << data[i];
        if (i < size - 1) {
            cout << ", ";
        }
    }
    cout << " ]" << std::endl;
}
template <typename T>
bool MyVector<T>::contains(const T& element) const {
        for (int i = 0; i < size; i++) {
            if (data[i] == element) {
                return false;
            }
        }
        return true;
    }
template<typename T>
MyVector<T>& MyVector<T>::operator=(const MyVector<T>& v) {
    if (this != &v) {
        delete[] data;
        size = v.size;
        data = new T[size];
        for (int i = 0; i < size; i++) {
            data[i] = v.data[i];
        }
    }
    return *this;
}

// template class MyVector<Subject>;
// template class MyVector<Students>;
