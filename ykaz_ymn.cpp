// ykaz_ymn.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <memory>


template <typename T>
class SharedPtr {
public:
    

    SharedPtr() :ptr_(nullptr), ptr_count_(int(0)) {}
    SharedPtr(T* ptr) :
        ptr_(ptr), ptr_count_(int(1)) { }
    SharedPtr(const SharedPtr& other) :
        ptr_(other.ptr_),
        ptr_count_(other.ptr_count_) {
        ++(*ptr_count_);
    }
    
    ~SharedPtr() {
        --(*ptr_count_);
        if (*ptr_count_ == 0) {
            delete ptr_;
            delete ptr_count_;
          
        }
    }

  

    void release() {
        --(*ptr_count_);
        if (*ptr_count_ == 0) {
            delete ptr_;
            delete ptr_count_;

        }
    }


    T& operator*() const { return *ptr_; }

    T* operator->() const { return ptr_; }

    T* get() const { return ptr_; }

    

    void reset(T* ptr = nullptr) {
        --(*ptr_count_);
        if (*ptr_count_ == 0) {
            delete ptr_;
            delete ptr_count_;
        }
            ptr_ = ptr;
        }
     SharedPtr& operator=(SharedPtr& other) {
         if (ptr_ != other.ptr_) {
             release();
             ptr_ = other.ptr_;
             ptr_count_ = other.ptr_count_;
             ++(*ptr_count_);
         }
         
        return *this;

    }
    
    

private:
    T* ptr_;
    int* ptr_count_;

};

int main()
{
    int* test=new int;
    std::shared_ptr<int> ptr(test);

    return 0;
}
