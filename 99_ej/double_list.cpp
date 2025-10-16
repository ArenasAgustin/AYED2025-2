#include <iostream>

template <typename T>
class DoubleNode
{
private:
    T value;
    DoubleNode *prev;
    DoubleNode *next;

public:
    DoubleNode() : value(NULL), prev(nullptr), next(nullptr) {}
    DoubleNode(T val) : value(val), prev(nullptr), next(nullptr) {}

    void set_value(T val) { value = val; }
    void set_next(DoubleNode<T> *node) { next = node; }
    void set_prev(DoubleNode<T> *node) { prev = node; }
    T get_value() { return value; }
    DoubleNode<T> *get_next() { return next; }
    DoubleNode<T> *get_prev() { return prev; }
};

template <typename T>
class DoubleList
{
private:
    DoubleNode<T> *front;
    DoubleNode<T> *back;

    void remove_node(DoubleNode<T> *node);

public:
    DoubleList() : front(nullptr), back(nullptr) {}
    DoubleList(DoubleNode<T> *node) : front(node), back(node) {}
    ~DoubleList();

    void set_front(DoubleNode<T> *node) { front = node; }
    void set_back(DoubleNode<T> *node) { back = node; }
    DoubleNode<T> *get_front() { return front; }
    DoubleNode<T> *get_back() { return back; }

    bool is_empty();
    void add(T a);
    void remove(T a);
    void remove_opt(T a);

    void print();
    void print_reverse();
};

template <typename T>
DoubleList<T>::~DoubleList()
{
    std::cout << "Destruyendo ..." << std::endl;

    while (!is_empty())
    {
        DoubleNode<T> *temp = get_front();
        set_front(front->get_next());
        delete temp;
    }
}

template <typename T>
bool DoubleList<T>::is_empty()
{
    return get_front() == nullptr;
}

template <typename T>
void DoubleList<T>::add(T a)
{
    DoubleNode<T> *new_node = new DoubleNode(a);

    if (!is_empty())
    {
        DoubleNode<T> *back = get_back();

        new_node->set_prev(back);
        back->set_next(new_node);
    }
    else
    {
        set_front(new_node);
    }

    set_back(new_node);
}

template <typename T>
void DoubleList<T>::remove_node(DoubleNode<T> *node)
{
    if (node == get_front() && node == get_back())
    {
        set_front(nullptr);
        set_back(nullptr);
    }
    else if (node == get_front())
    {
        set_front(node->get_next());
        get_front()->set_prev(nullptr);
    }
    else if (node == get_back())
    {
        set_back(node->get_prev());
        get_back()->set_next(nullptr);
    }
    else
    {
        node->get_prev()->set_next(node->get_next());
        node->get_next()->set_prev(node->get_prev());
    }

    delete node;

    std::cout
        << std::endl
        << "Elemento borrado" << std::endl;
}

template <typename T>
void DoubleList<T>::remove(T a)
{
    if (is_empty())
    {
        std::cout << std::endl
                  << "Lista vacia" << std::endl;
        return;
    }

    DoubleNode<T> *current = get_front();

    while (current != nullptr)
    {
        if (current->get_value() == a)
        {
            remove_node(current);
            return;
        }

        current = current->get_next();
    }

    std::cout << std::endl
              << "Elemento no encontrado" << std::endl;
}

template <typename T>
void DoubleList<T>::remove_opt(T a)
{
    if (is_empty())
    {
        std::cout << std::endl
                  << "Lista vacia" << std::endl;
        return;
    }

    DoubleNode<T> *front_ptr = get_front();
    DoubleNode<T> *back_ptr = get_back();

    while (front_ptr != nullptr && back_ptr != nullptr && front_ptr != back_ptr && front_ptr->get_next() != back_ptr)
    {
        if (front_ptr->get_value() == a)
        {
            remove_node(front_ptr);
            return;
        }
        if (back_ptr->get_value() == a)
        {
            remove_node(back_ptr);
            return;
        }

        front_ptr = front_ptr->get_next();
        back_ptr = back_ptr->get_prev();
    }

    std::cout << std::endl
              << "Elemento no encontrado" << std::endl;
}

template <typename T>
void DoubleList<T>::print()
{
    if (is_empty())
    {
        std::cout << std::endl
                  << "Lista vacia" << std::endl;
        return;
    }
    else
        std::cout << std::endl
                  << "Imprimiendo lista" << std::endl;

    DoubleNode<T> *tmp = get_front();

    while (tmp != nullptr)
    {
        std::cout << tmp->get_value() << std::endl;
        tmp = tmp->get_next();
    }
}

template <typename T>
void DoubleList<T>::print_reverse()
{
    if (is_empty())
    {
        std::cout << std::endl
                  << "Lista vacia" << std::endl;
        return;
    }
    else
        std::cout << std::endl
                  << "Imprimiendo lista al reves" << std::endl;

    DoubleNode<T> *tmp = get_back();

    while (tmp != nullptr)
    {
        std::cout << tmp->get_value() << std::endl;
        tmp = tmp->get_prev();
    }
}

void testingDoubleList()
{
    {
        // Imprimir: debe imprimir en orden de inserción y al revés
        DoubleList<int> *double_list = new DoubleList<int>();
        double_list->add(1);
        double_list->add(2);
        double_list->add(3);
        double_list->add(4);
        double_list->print();         // 1 2 3 4
        double_list->print_reverse(); // 4 3 2 1

        delete double_list;
    }

    {
        // remove: elimina por extremos y medio
        DoubleList<int> *list = new DoubleList<int>();
        list->add(1);
        list->add(2);
        list->add(3);
        list->add(4);
        list->print(); // 1 2 3 4
        list->remove(1);
        list->print(); // 2 3 4
        list->remove(4);
        list->print(); // 2 3
        list->remove(3);
        list->print(); // 2
        list->remove(2);
        list->print(); // lista vacia

        delete list;
    }

    {
        // remove_opt: elimina por extremos y medio
        DoubleList<int> *list_opt = new DoubleList<int>();
        list_opt->add(1);
        list_opt->add(2);
        list_opt->add(3);
        list_opt->add(4);
        list_opt->print(); // 1 2 3 4
        list_opt->remove_opt(1);
        list_opt->print(); // 2 3 4
        list_opt->remove_opt(4);
        list_opt->print(); // 2 3
        list_opt->remove_opt(3);
        list_opt->print(); // 2
        list_opt->remove_opt(2);
        list_opt->print(); // lista vacia

        delete list_opt;
    }

    {
        // Duplicados: debe borrar la primera aparición que encuentre
        DoubleList<int> *list_dup = new DoubleList<int>();
        list_dup->add(1);
        list_dup->add(2);
        list_dup->add(2);
        list_dup->add(3);
        list_dup->add(2);
        list_dup->print(); // 1 2 2 3 2
        list_dup->remove(2);
        list_dup->print(); // 1 2 3 2
        list_dup->remove(2);
        list_dup->print(); // 1 3 2
        list_dup->remove(2);
        list_dup->print();   // 1 3
        list_dup->remove(2); // no borra
        list_dup->print();   // 1 3

        delete list_dup;
    }

    {
        // No encontrado: la lista no debe cambiar
        DoubleList<int> *list_nf = new DoubleList<int>();
        list_nf->add(5);
        list_nf->add(6);
        list_nf->print();    // 5 6
        list_nf->remove(42); // no borra
        list_nf->print();    // 5 6

        delete list_nf;
    }

    {
        // Reversa: comprobar orden inverso
        DoubleList<int> *list_rev = new DoubleList<int>();
        list_rev->add(10);
        list_rev->add(20);
        list_rev->add(30);
        list_rev->print();         // 10 20 30
        list_rev->print_reverse(); // 30 20 10
        list_rev->remove(20);
        list_rev->print();         // 10 30
        list_rev->print_reverse(); // 30 10

        delete list_rev;
    }

    {
        // Vacía: imprimir sin elementos
        DoubleList<int> *list_empty = new DoubleList<int>();
        list_empty->print();         // lista vacia
        list_empty->print_reverse(); // lista vacia

        delete list_empty;
    }
}