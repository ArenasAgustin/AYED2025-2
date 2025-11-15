#include <iostream>
#include <algorithm>

template <typename T>
class AVLNode
{
private:
    T value;
    int height;
    AVLNode *left;
    AVLNode *right;

public:
    AVLNode() : value(T()), height(1), left(nullptr), right(nullptr) {}
    AVLNode(T val) : value(val), height(1), left(nullptr), right(nullptr) {}

    void set_value(T val) { value = val; }
    void set_height(int h) { height = h; }
    void set_left(AVLNode<T> *node) { left = node; }
    void set_right(AVLNode<T> *node) { right = node; }

    T get_value() { return value; }
    int get_height() { return height; }
    AVLNode<T> *get_left() { return left; }
    AVLNode<T> *get_right() { return right; }
};

template <typename T>
class AVLTree
{
private:
    AVLNode<T> *root;

    void destroy_tree(AVLNode<T> *node);

    int get_height(AVLNode<T> *node);
    int get_balance_factor(AVLNode<T> *node);
    void update_height(AVLNode<T> *node);

    AVLNode<T> *rotate_right(AVLNode<T> *y);
    AVLNode<T> *rotate_left(AVLNode<T> *x);
    AVLNode<T> *balance(AVLNode<T> *node);

    AVLNode<T> *add_helper(AVLNode<T> *node, T a);
    AVLNode<T> *remove_helper(AVLNode<T> *node, T a);
    AVLNode<T> *find_min(AVLNode<T> *node);

    void print_in_order_helper(AVLNode<T> *node);
    void print_pre_order_helper(AVLNode<T> *node);
    void print_post_order_helper(AVLNode<T> *node);

public:
    AVLTree() : root(nullptr) {}
    AVLTree(AVLNode<T> *node) : root(node) {}
    ~AVLTree();

    void set_root(AVLNode<T> *node) { root = node; }
    AVLNode<T> *get_root() { return root; }

    bool empty();
    void add(T a);
    bool remove(T a);
    bool contains(T a);

    void print_in_order();
    void print_pre_order();
    void print_post_order();
};

// Destructor y funciones auxiliares
template <typename T>
void AVLTree<T>::destroy_tree(AVLNode<T> *node)
{
    if (node != nullptr)
    {
        destroy_tree(node->get_left());
        destroy_tree(node->get_right());
        delete node;
    }
}

template <typename T>
AVLTree<T>::~AVLTree()
{
    destroy_tree(root);
    std::cout << "Destruyendo AVL..." << std::endl;
}

template <typename T>
bool AVLTree<T>::empty()
{
    return root == nullptr;
}

// Funciones de altura y balance
template <typename T>
int AVLTree<T>::get_height(AVLNode<T> *node)
{
    return node == nullptr ? 0 : node->get_height();
}

template <typename T>
int AVLTree<T>::get_balance_factor(AVLNode<T> *node)
{
    return node == nullptr ? 0 : get_height(node->get_left()) - get_height(node->get_right());
}

template <typename T>
void AVLTree<T>::update_height(AVLNode<T> *node)
{
    if (node != nullptr)
    {
        node->set_height(1 + std::max(get_height(node->get_left()), get_height(node->get_right())));
    }
}

// Rotaciones
template <typename T>
AVLNode<T> *AVLTree<T>::rotate_right(AVLNode<T> *y)
{
    /*
     * Rotación a la derecha:
     *       y                x
     *      / \              / \
     *     x   C    -->     A   y
     *    / \                  / \
     *   A   B                B   C
     */
    AVLNode<T> *x = y->get_left();
    AVLNode<T> *B = x->get_right();

    // Realizar rotación
    x->set_right(y);
    y->set_left(B);

    // Actualizar alturas
    update_height(y);
    update_height(x);

    return x; // Nueva raíz
}

template <typename T>
AVLNode<T> *AVLTree<T>::rotate_left(AVLNode<T> *x)
{
    /*
     * Rotación a la izquierda:
     *     x                  y
     *    / \                / \
     *   A   y      -->     x   C
     *      / \            / \
     *     B   C          A   B
     */
    AVLNode<T> *y = x->get_right();
    AVLNode<T> *B = y->get_left();

    // Realizar rotación
    y->set_left(x);
    x->set_right(B);

    // Actualizar alturas
    update_height(x);
    update_height(y);

    return y; // Nueva raíz
}

// Balancear el nodo
template <typename T>
AVLNode<T> *AVLTree<T>::balance(AVLNode<T> *node)
{
    if (node == nullptr)
        return node;

    update_height(node);
    int balance = get_balance_factor(node);

    // Caso Left-Left
    if (balance > 1 && get_balance_factor(node->get_left()) >= 0)
        return rotate_right(node);

    // Caso Left-Right
    if (balance > 1 && get_balance_factor(node->get_left()) < 0)
    {
        node->set_left(rotate_left(node->get_left()));
        return rotate_right(node);
    }

    // Caso Right-Right
    if (balance < -1 && get_balance_factor(node->get_right()) <= 0)
        return rotate_left(node);

    // Caso Right-Left
    if (balance < -1 && get_balance_factor(node->get_right()) > 0)
    {
        node->set_right(rotate_right(node->get_right()));
        return rotate_left(node);
    }

    return node;
}

// Inserción
template <typename T>
AVLNode<T> *AVLTree<T>::add_helper(AVLNode<T> *node, T a)
{
    // 1. Inserción BST normal
    if (node == nullptr)
        return new AVLNode<T>(a);

    if (a < node->get_value())
        node->set_left(add_helper(node->get_left(), a));
    else
        node->set_right(add_helper(node->get_right(), a));

    // 2. Actualizar altura y balancear
    return balance(node);
}

template <typename T>
void AVLTree<T>::add(T a)
{
    root = add_helper(root, a);
}

// Encontrar el mínimo (para eliminación)
template <typename T>
AVLNode<T> *AVLTree<T>::find_min(AVLNode<T> *node)
{
    while (node->get_left() != nullptr)
        node = node->get_left();
    return node;
}

// Eliminación
template <typename T>
AVLNode<T> *AVLTree<T>::remove_helper(AVLNode<T> *node, T a)
{
    // 1. Eliminación BST normal
    if (node == nullptr)
        return node;

    if (a < node->get_value())
    {
        node->set_left(remove_helper(node->get_left(), a));
    }
    else if (a > node->get_value())
    {
        node->set_right(remove_helper(node->get_right(), a));
    }
    else
    {
        // Nodo encontrado
        if (node->get_left() == nullptr && node->get_right() == nullptr)
        {
            // Caso 1: Nodo hoja
            delete node;
            return nullptr;
        }
        else if (node->get_left() == nullptr)
        {
            // Caso 2: Solo hijo derecho
            AVLNode<T> *temp = node->get_right();
            delete node;
            return temp;
        }
        else if (node->get_right() == nullptr)
        {
            // Caso 3: Solo hijo izquierdo
            AVLNode<T> *temp = node->get_left();
            delete node;
            return temp;
        }
        else
        {
            // Caso 4: Dos hijos - usar sucesor in-order
            AVLNode<T> *successor = find_min(node->get_right());
            node->set_value(successor->get_value());
            node->set_right(remove_helper(node->get_right(), successor->get_value()));
        }
    }

    // 2. Actualizar altura y balancear
    return balance(node);
}

template <typename T>
bool AVLTree<T>::remove(T a)
{
    if (empty())
        return false;

    int initial_height = get_height(root);
    root = remove_helper(root, a);

    // Si la altura cambió o el árbol quedó vacío, se eliminó algo
    return (root == nullptr || get_height(root) != initial_height || !contains(a));
}

// Búsqueda
template <typename T>
bool AVLTree<T>::contains(T a)
{
    if (empty())
        return false;

    AVLNode<T> *current = root;
    while (current != nullptr)
    {
        if (a == current->get_value())
            return true;
        else if (a < current->get_value())
            current = current->get_left();
        else
            current = current->get_right();
    }
    return false;
}

// Recorridos
template <typename T>
void AVLTree<T>::print_in_order_helper(AVLNode<T> *node)
{
    if (node != nullptr)
    {
        print_in_order_helper(node->get_left());
        std::cout << "node: " << node->get_value() << " (h=" << node->get_height() << ")" << std::endl;
        print_in_order_helper(node->get_right());
    }
}

template <typename T>
void AVLTree<T>::print_in_order()
{
    print_in_order_helper(root);
}

template <typename T>
void AVLTree<T>::print_pre_order_helper(AVLNode<T> *node)
{
    if (node != nullptr)
    {
        std::cout << "node: " << node->get_value() << " (h=" << node->get_height() << ")" << std::endl;
        print_pre_order_helper(node->get_left());
        print_pre_order_helper(node->get_right());
    }
}

template <typename T>
void AVLTree<T>::print_pre_order()
{
    print_pre_order_helper(root);
}

template <typename T>
void AVLTree<T>::print_post_order_helper(AVLNode<T> *node)
{
    if (node != nullptr)
    {
        print_post_order_helper(node->get_left());
        print_post_order_helper(node->get_right());
        std::cout << "node: " << node->get_value() << " (h=" << node->get_height() << ")" << std::endl;
    }
}

template <typename T>
void AVLTree<T>::print_post_order()
{
    print_post_order_helper(root);
}

// Función de pruebas
void testingAVLTree()
{
    {
        // Árbol vacío
        AVLTree<int> *tree = new AVLTree<int>();
        std::cout << "=== Arbol AVL vacio ===" << std::endl;
        std::cout << "Vacio: " << (tree->empty() ? "SI" : "NO") << std::endl;
        delete tree;
    }

    {
        // Inserción que causa rotación derecha (Left-Left)
        AVLTree<int> *tree = new AVLTree<int>();
        std::cout << "\n=== Rotacion Right (Left-Left case) ===" << std::endl;
        tree->add(30);
        tree->add(20);
        tree->add(10); // Causa rotación

        /*
         * Antes rotación:  30        Después rotación:  20
         *                 /                            /  \
         *               20                           10   30
         *              /
         *            10
         */

        std::cout << "In-Order (deberia ser: 10, 20, 30):" << std::endl;
        tree->print_in_order();
        delete tree;
    }

    {
        // Inserción que causa rotación izquierda (Right-Right)
        AVLTree<int> *tree = new AVLTree<int>();
        std::cout << "\n=== Rotacion Left (Right-Right case) ===" << std::endl;
        tree->add(10);
        tree->add(20);
        tree->add(30); // Causa rotación

        /*
         * Antes rotación:  10        Después rotación:  20
         *                   \                          /  \
         *                   20                       10   30
         *                     \
         *                     30
         */

        std::cout << "In-Order (deberia ser: 10, 20, 30):" << std::endl;
        tree->print_in_order();
        delete tree;
    }

    {
        // Inserción que causa rotación Left-Right
        AVLTree<int> *tree = new AVLTree<int>();
        std::cout << "\n=== Rotacion Left-Right ===" << std::endl;
        tree->add(30);
        tree->add(10);
        tree->add(20); // Causa rotación doble

        /*
         * Antes:    30          Después Left en 10:  30        Después Right en 30:  20
         *          /                                /                               /  \
         *        10                               20                              10   30
         *          \                             /
         *          20                          10
         */

        std::cout << "In-Order (deberia ser: 10, 20, 30):" << std::endl;
        tree->print_in_order();
        delete tree;
    }

    {
        // Inserción que causa rotación Right-Left
        AVLTree<int> *tree = new AVLTree<int>();
        std::cout << "\n=== Rotacion Right-Left ===" << std::endl;
        tree->add(10);
        tree->add(30);
        tree->add(20); // Causa rotación doble

        /*
         * Antes:  10          Después Right en 30:  10        Después Left en 10:  20
         *           \                                  \                          /  \
         *           30                                 20                       10   30
         *          /                                     \
         *        20                                      30
         */

        std::cout << "In-Order (deberia ser: 10, 20, 30):" << std::endl;
        tree->print_in_order();
        delete tree;
    }

    {
        // Inserción secuencial manteniendo balance
        AVLTree<int> *tree = new AVLTree<int>();
        std::cout << "\n=== Insercion secuencial (1-7) con auto-balance ===" << std::endl;
        for (int i = 1; i <= 7; i++)
        {
            tree->add(i);
        }

        /*
         * En BST normal sería una cadena, pero AVL lo balancea:
         *         4
         *       /   \
         *      2     6
         *     / \   / \
         *    1   3 5   7
         */

        std::cout << "In-Order (deberia ser: 1, 2, 3, 4, 5, 6, 7):" << std::endl;
        tree->print_in_order();

        std::cout << "\nPre-Order (muestra estructura balanceada):" << std::endl;
        tree->print_pre_order();
        delete tree;
    }

    {
        // Árbol balanceado con múltiples inserciones
        AVLTree<int> *tree = new AVLTree<int>();
        std::cout << "\n=== Arbol balanceado complejo ===" << std::endl;
        int values[] = {50, 25, 75, 10, 30, 60, 80, 5, 15, 27, 55};
        for (int val : values)
        {
            tree->add(val);
        }

        std::cout << "In-Order:" << std::endl;
        tree->print_in_order();
        delete tree;
    }

    {
        // Búsqueda en AVL
        AVLTree<int> *tree = new AVLTree<int>();
        std::cout << "\n=== Busqueda en AVL ===" << std::endl;
        tree->add(50);
        tree->add(30);
        tree->add(70);
        tree->add(20);
        tree->add(40);

        std::cout << "Buscar 30: " << (tree->contains(30) ? "Encontrado" : "No encontrado") << std::endl;
        std::cout << "Buscar 70: " << (tree->contains(70) ? "Encontrado" : "No encontrado") << std::endl;
        std::cout << "Buscar 99: " << (tree->contains(99) ? "Encontrado" : "No encontrado") << std::endl;
        delete tree;
    }

    {
        // Eliminación con rebalanceo
        AVLTree<int> *tree = new AVLTree<int>();
        std::cout << "\n=== Remove con rebalanceo ===" << std::endl;

        // Crear árbol balanceado
        for (int i = 1; i <= 7; i++)
            tree->add(i * 10);

        std::cout << "Antes de eliminar:" << std::endl;
        tree->print_in_order();

        tree->remove(10);
        std::cout << "\nDespues de eliminar 10:" << std::endl;
        tree->print_in_order();

        tree->remove(20);
        std::cout << "\nDespues de eliminar 20:" << std::endl;
        tree->print_in_order();
        delete tree;
    }

    {
        // Eliminar nodo hoja
        AVLTree<int> *tree = new AVLTree<int>();
        std::cout << "\n=== Remove nodo hoja ===" << std::endl;
        tree->add(50);
        tree->add(30);
        tree->add(70);
        tree->add(20);

        std::cout << "Antes:" << std::endl;
        tree->print_in_order();

        tree->remove(20);
        std::cout << "\nDespues de eliminar 20:" << std::endl;
        tree->print_in_order();
        delete tree;
    }

    {
        // Eliminar nodo con dos hijos
        AVLTree<int> *tree = new AVLTree<int>();
        std::cout << "\n=== Remove nodo con dos hijos ===" << std::endl;
        tree->add(50);
        tree->add(30);
        tree->add(70);
        tree->add(20);
        tree->add(40);
        tree->add(60);
        tree->add(80);

        std::cout << "Antes:" << std::endl;
        tree->print_in_order();

        tree->remove(30);
        std::cout << "\nDespues de eliminar 30 (reemplazado por sucesor):" << std::endl;
        tree->print_in_order();
        delete tree;
    }

    {
        // Eliminar la raíz
        AVLTree<int> *tree = new AVLTree<int>();
        std::cout << "\n=== Remove raiz ===" << std::endl;
        tree->add(50);
        tree->add(30);
        tree->add(70);

        std::cout << "Antes:" << std::endl;
        tree->print_in_order();

        tree->remove(50);
        std::cout << "\nDespues de eliminar raiz (50):" << std::endl;
        tree->print_in_order();
        delete tree;
    }

    {
        // Eliminar todos los elementos progresivamente
        AVLTree<int> *tree = new AVLTree<int>();
        std::cout << "\n=== Remove todos los elementos ===" << std::endl;
        tree->add(50);
        tree->add(30);
        tree->add(70);
        tree->add(20);
        tree->add(40);

        std::cout << "Inicial:" << std::endl;
        tree->print_in_order();

        tree->remove(20);
        std::cout << "\nDespues remove 20:" << std::endl;
        tree->print_in_order();

        tree->remove(30);
        std::cout << "\nDespues remove 30:" << std::endl;
        tree->print_in_order();

        tree->remove(40);
        std::cout << "\nDespues remove 40:" << std::endl;
        tree->print_in_order();

        tree->remove(50);
        std::cout << "\nDespues remove 50:" << std::endl;
        tree->print_in_order();

        tree->remove(70);
        std::cout << "\nDespues remove 70:" << std::endl;
        std::cout << "Vacio: " << (tree->empty() ? "SI" : "NO") << std::endl;
        delete tree;
    }

    {
        // Elemento no existe
        AVLTree<int> *tree = new AVLTree<int>();
        std::cout << "\n=== Remove elemento inexistente ===" << std::endl;
        tree->add(50);
        tree->add(30);
        tree->add(70);

        std::cout << "Antes:" << std::endl;
        tree->print_in_order();

        std::cout << "\nRemove 99: " << (tree->remove(99) ? "Eliminado" : "No encontrado") << std::endl;
        std::cout << "Despues (sin cambios):" << std::endl;
        tree->print_in_order();
        delete tree;
    }

    {
        // Verificar que se mantiene balanceado después de muchas operaciones
        AVLTree<int> *tree = new AVLTree<int>();
        std::cout << "\n=== Verificar balance tras multiples operaciones ===" << std::endl;

        // Insertar valores aleatorios
        int values[] = {15, 10, 20, 8, 12, 25, 6, 11, 13, 22, 27};
        for (int val : values)
            tree->add(val);

        std::cout << "Despues de inserciones:" << std::endl;
        tree->print_in_order();

        // Eliminar algunos
        tree->remove(8);
        tree->remove(25);
        tree->remove(15);

        std::cout << "\nDespues de eliminaciones (15, 8, 25):" << std::endl;
        tree->print_in_order();
        std::cout << "El arbol se mantiene balanceado" << std::endl;
        delete tree;
    }
}
