//
// Created by user on 15.08.23.
//

#ifndef CUSTOM_CONTAINERS_CUSTOM_SEQUENCE_CONTAINER_HPP
#define CUSTOM_CONTAINERS_CUSTOM_SEQUENCE_CONTAINER_HPP

#include "custom_container.hpp"

namespace custom_containers {

    template<typename T>
    class CustomSequenceContainer
            : public CustomContainer<T> {
    public:
        using Iterator = CustomSequenceContainer<T>;
        explicit CustomSequenceContainer(T value);
        CustomSequenceContainer(std::initializer_list<T> init_list);
        void push_back(const T& value) override;
        void push_front(const T& value) override;
        void pop_back() override;
        void pop_front() override;
        void insert(long unsigned int pos, const T& value) override;
        void erase(unsigned long int pos) override;
        void erase() override;

    private:
        static constexpr long unsigned int CAPACITY_RATIO = 2;
        long unsigned int m_size{};
        long unsigned int m_capacity{};
        T* m_data = nullptr;

    };

    template<typename T>
    CustomSequenceContainer<T>::CustomSequenceContainer(std::initializer_list<T> init_list) {
        m_size = init_list.size();
        m_capacity = m_size * CAPACITY_RATIO;
        m_data = new T[m_capacity];
        unsigned long int index = 0;
        for (auto& item : init_list) {
            m_data[index] = item;
            ++index;
        }

    }

    template<typename T>
    CustomSequenceContainer<T>::CustomSequenceContainer(T value) {

    }

    template<typename T>
    void CustomSequenceContainer<T>::push_front(const T &value) {

    }

    template<typename T>
    void CustomSequenceContainer<T>::push_back(const T &value) {

    }

    template<typename T>
    void CustomSequenceContainer<T>::pop_front() {

    }

    template<typename T>
    void CustomSequenceContainer<T>::pop_back() {

    }

    template<typename T>
    void CustomSequenceContainer<T>::erase(unsigned long pos) {

    }


    template<typename T>
    void CustomSequenceContainer<T>::erase() {

    }

    template<typename T>
    void CustomSequenceContainer<T>::insert(unsigned long pos, const T& value) {

    }

}

#endif //CUSTOM_CONTAINERS_CUSTOM_SEQUENCE_CONTAINER_HPP
