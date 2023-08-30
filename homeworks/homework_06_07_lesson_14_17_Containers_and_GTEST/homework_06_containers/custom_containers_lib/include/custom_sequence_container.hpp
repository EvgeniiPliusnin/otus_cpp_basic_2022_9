//
// Created by user on 15.08.23.
//

#ifndef CUSTOM_CONTAINERS_CUSTOM_SEQUENCE_CONTAINER_HPP
#define CUSTOM_CONTAINERS_CUSTOM_SEQUENCE_CONTAINER_HPP

#include <iostream>

namespace custom_containers {

    template<typename T>
    class CustomSequenceContainer{
    public:
        explicit CustomSequenceContainer(T value);
        explicit CustomSequenceContainer(unsigned long int quantity);
        CustomSequenceContainer(unsigned long int quantity, T value);
        CustomSequenceContainer(std::initializer_list<T> initializer_list);
        CustomSequenceContainer(const CustomSequenceContainer<T>& other);
        ~CustomSequenceContainer();
        void push_back(const T& value);
        void push_front(const T& value);
        void pop_back();
        void pop_front();
        void insert(long unsigned int pos, const T& value);
        void erase(unsigned long int pos);
        void erase();
        long unsigned int size() const;
        long unsigned int capacity() const;
        T& operator[] (unsigned long int pos);

    private:
        void shift_right(unsigned long int pos, unsigned long int shift);
        void shift_left(unsigned long int pos, unsigned long int shift);
        T* get_expanded_zero_array();

    private:
        static constexpr long unsigned int CAPACITY_RATIO = 2;
        long unsigned int m_size{};
        long unsigned int m_capacity{};
        T* m_data = nullptr;
    };

    template<typename T>
    CustomSequenceContainer<T>::CustomSequenceContainer(const CustomSequenceContainer<T> & other) {
        m_size = other.m_size;
        m_capacity = other.m_capacity;
        m_data = new T[m_capacity];
        for (int index = 0; index < m_size; ++index) {
            m_data[index] = other.m_data[index];
        }
    }

    template<typename T>
    CustomSequenceContainer<T>::~CustomSequenceContainer() {
        delete[] m_data;
    }

    template<typename T>
    CustomSequenceContainer<T>::CustomSequenceContainer(T value) : CustomSequenceContainer(1, value) {}

    template<typename T>
    CustomSequenceContainer<T>::CustomSequenceContainer(unsigned long quantity) {
        m_size = quantity;
        m_capacity = m_size * CAPACITY_RATIO;
        m_data = new T[m_capacity] {0};
    }

    template<typename T>
    CustomSequenceContainer<T>::CustomSequenceContainer(unsigned long quantity, T value) : CustomSequenceContainer(quantity){
        for (int index = 0; index < m_size; ++index) {
            m_data[index] = value;
        }
    }

    template<typename T>
    CustomSequenceContainer<T>::CustomSequenceContainer(std::initializer_list<T> initializer_list) {
        m_size = initializer_list.size();
        m_capacity = m_size * CAPACITY_RATIO;
        m_data = new T[m_capacity];
        unsigned long int index = 0;
        for (auto& item : initializer_list) {
            m_data[index] = item;
            ++index;
        }
    }

    template<typename T>
    T *CustomSequenceContainer<T>::get_expanded_zero_array() {
        auto _capacity =  (m_size + 1) * CAPACITY_RATIO;
        m_capacity = _capacity;
        return new T[_capacity];
    }

    template<typename T>
    void CustomSequenceContainer<T>::shift_left(unsigned long pos, unsigned long shift) {
        for (unsigned long int index = pos + shift; index < m_size ; ++index) {
            m_data[index - shift] = m_data[index];
        }
    }

    template<typename T>
    void CustomSequenceContainer<T>::shift_right(unsigned long int pos, unsigned long int shift) {
        auto array_shift = shift - 1;
        for (unsigned long int index = m_size + array_shift; index > pos ; --index) {
            m_data[index] = m_data[index - shift];
        }
    }

    template<typename T>
    void CustomSequenceContainer<T>::push_front(const T &value) {
        insert(0, value);
    }

    template<typename T>
    void CustomSequenceContainer<T>::push_back(const T &value) {
        if (m_size == m_capacity) {
            T* new_data = get_expanded_zero_array();
            for(auto index = 0; index < m_size; ++index) {
                new_data[index] = m_data[index];
            }
            delete[] m_data;
            m_data = new_data;
        }
        ++m_size;
        m_data[m_size - 1] = value;
    }

    template<typename T>
    void CustomSequenceContainer<T>::pop_front() {
        erase(0);
    }

    template<typename T>
    void CustomSequenceContainer<T>::pop_back() {
        if (m_size > 0) {
            --m_size;
        }
    }

    template<typename T>
    void CustomSequenceContainer<T>::erase(unsigned long pos) {
        shift_left(pos, 1);
        --m_size;
    }

    template<typename T>
    void CustomSequenceContainer<T>::erase() {
        m_size = 0;
    }

    template<typename T>
    void CustomSequenceContainer<T>::insert(unsigned long pos, const T& value) {
        if (m_size == m_capacity) {
            T* new_data = get_expanded_zero_array();
            for (unsigned long int index = 0; index <= m_size; ++index) {
                if (index < pos) {
                    new_data[index] = m_data[index];
                } else if (index > pos) {
                    new_data[index] = m_data[index - 1];
                }
            }
            delete[] m_data;
            m_data = new_data;
        } else {
            shift_right(pos, 1);
        }

        ++m_size;
        m_data[pos] = value;
    }

    template<typename T>
    long unsigned int CustomSequenceContainer<T>::size() const {
        return m_size;
    }

    template<typename T>
    long unsigned int CustomSequenceContainer<T>::capacity() const {
        return m_capacity;
    }

    template<typename T>
    T& CustomSequenceContainer<T>::operator[](unsigned long pos) {
        return m_data[pos];
    }

}

#endif //CUSTOM_CONTAINERS_CUSTOM_SEQUENCE_CONTAINER_HPP
