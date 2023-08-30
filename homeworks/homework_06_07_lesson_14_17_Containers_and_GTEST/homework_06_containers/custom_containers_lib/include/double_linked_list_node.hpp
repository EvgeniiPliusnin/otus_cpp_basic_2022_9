//
// Created by user on 26.08.23.
//

#ifndef CUSTOM_CONTAINERS_DOUBLE_LINKED_LIST_NODE_HPP
#define CUSTOM_CONTAINERS_DOUBLE_LINKED_LIST_NODE_HPP


namespace custom_containers {

    template<typename T>
    class ListNode {
    public:
        explicit ListNode(T value) : m_data(value){}

        ListNode(const ListNode<T> &other) {
            this->m_data = other.m_data;
            this->m_next_node = other.m_next_node;
            this->m_prev_node = other.m_prev_node;
        }

        ListNode(ListNode<T> &&other) noexcept {}

        ~ListNode() = default;

        ListNode& operator= (const ListNode<T> &other) {
            this->m_next_node = other.m_next_node;
            this->m_prev_node = other.m_prev_node;
            this->m_data = other.m_data;
        }

        ListNode& operator= (ListNode<T> &&other)  noexcept {
//            TODO: learn how to use move assigment operator
        }

    public:
        T m_data;
        ListNode *m_prev_node = nullptr;
        ListNode *m_next_node = nullptr;

    };

}

#endif //CUSTOM_CONTAINERS_DOUBLE_LINKED_LIST_NODE_HPP
