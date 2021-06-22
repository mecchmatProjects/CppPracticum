#include <iostream>

template<typename ValueType>
class List;

template<typename ValueType>
class Node
{
    template<typename ValueType>
    friend class List;
public:


private:

    Node(ValueType otherValue = ValueType(), Node<ValueType>* otherpPrev = nullptr, Node<ValueType>* otherpNext = nullptr)
    {
        this->m_Value = otherValue;
        this->pPrev = otherpPrev;
        this->pNext = otherpNext;
    }

    ValueType m_Value;
    Node* pPrev;
    Node* pNext;
};

template<typename ValueType>
class List
{
public:

    List()
    {
        this->m_pHead = nullptr;
        this->m_pTail = nullptr;
        this->m_iSize = 0;
    }

    List(const List& otherStack) : List()
    {
        Node<ValueType>* currentNode = otherStack.m_pHead;
        while (currentNode)
        {
            this->push(currentNode->m_Value);
            currentNode = currentNode->pNext;
        }
    }

    ~List()
    {
        this->clear();
    }

    void push_back(const ValueType& otherValue)
    {
        Node<ValueType>* newnode = new Node<ValueType>(otherValue, this->m_pTail, nullptr);
        if (this->m_pHead == nullptr)
        {
            this->m_pHead = this->m_pTail = newnode;
        }
        else
        {
            this->m_pTail->pNext = newnode;
            this->m_pTail = this->m_pTail->pNext;
        }
        this->m_iSize++;
    }

    void pop_back()
    {
        if (this->m_pHead)
        {
            if (this->m_pHead->pNext)
            {
                this->m_pTail = this->m_pTail->pPrev;
                delete this->m_pTail->pNext;
                this->m_pTail->pNext = nullptr;
            }
            else
            {
                delete this->m_pHead;
                this->m_pHead = this->m_pTail = nullptr;
            }
            this->m_iSize--;
        }
    }

    void insert_by_index(const ValueType& otherValue, const int otherIndex)
    {
        if (otherIndex >= 0 && otherIndex < this->m_iSize) // если индекс входит в диапазон элементов
        {
            if (otherIndex == 0)
            {
                Node<ValueType>* newNode = new Node<ValueType>(otherValue, nullptr, this->m_pHead);
                this->m_pHead->pPrev = newNode;
                this->m_pHead = newNode;
            }
            else
            {
                Node<ValueType>* prevNode = this->m_pHead;
                for (size_t i = 0; i < otherIndex - 1; i++)
                {
                    prevNode = prevNode->pNext;
                }
                Node<ValueType>* newNode = new Node<ValueType>(otherValue, prevNode, prevNode->pNext);
                prevNode->pNext->pPrev = newNode;
                prevNode->pNext = newNode;
            }
            this->m_iSize++;
        }
        else
        {
            return;
        }
    }

    void delete_by_index(const int otherIndex)
    {
        if (otherIndex >= 0 && otherIndex < this->m_iSize)
        {
            if (otherIndex == 0)
            {
                if (this->m_pHead->pNext == nullptr)
                {
                    delete this->m_pHead;
                    this->m_pHead = this->m_pTail = nullptr;
                }
                else
                {
                    this->m_pHead = this->m_pHead->pNext;
                    delete this->m_pHead->pPrev;
                    this->m_pHead->pPrev = nullptr;
                }
            }
            else if (otherIndex == this->m_iSize - 1)
            {
                this->pop_back();
                return;
            }
            else
            {
                Node<ValueType>* toDeleteNode = this->m_pHead;
                for (size_t i = 0; i < otherIndex; i++)
                {
                    toDeleteNode = toDeleteNode->pNext;
                }
                toDeleteNode->pPrev->pNext = toDeleteNode->pNext;
                toDeleteNode->pNext->pPrev = toDeleteNode->pPrev;
                delete toDeleteNode;
            }
            this->m_iSize--;
        }
        else
        {
            return;
        }
    }

    ValueType getNearest(const ValueType& otherValue)
    {
        if (this->m_pHead)
        {
            Node<ValueType>* currentNode = this->m_pHead;
            ValueType elem = currentNode->m_Value;
            while (currentNode)
            {
                if (abs(currentNode->m_Value - otherValue) < abs(elem - otherValue))
                {
                    elem = currentNode->m_Value;
                }
                currentNode = currentNode->pNext;
            }
            return elem;
        }
        else
        {
            return ValueType();
        }
    }

    void clear()
    {
        while (this->m_pHead)
        {
            this->pop_back();
        }
    }

    bool empty()
    {
        return !this->m_pHead;
    }

    int size()
    {
        return this->m_iSize;
    }

    void Print()
    {
        Node<ValueType>* currentNode = this->m_pHead;
        while (currentNode)
        {
            std::cout << currentNode->m_Value << "     ";
            currentNode = currentNode->pNext;
        }
    }

private:

    Node<ValueType>* m_pHead;
    Node<ValueType>* m_pTail;
    int m_iSize;
};



int main()
{
    List<double> lst;
    lst.push_back(1.1);
    lst.push_back(9.9);
    lst.push_back(12.3);
    lst.push_back(22.6);

    std::cout << "lst:   ";
    lst.Print();
    std::cout << std::endl;


    std::cout << "Nearest for 20: " << lst.getNearest(20) << std::endl;

    lst.delete_by_index(1);
    std::cout << "lst:   ";
    lst.Print();
    std::cout << std::endl;

    std::cout << "Nearest for 10: " << lst.getNearest(10) << std::endl;

    return 0;
}
