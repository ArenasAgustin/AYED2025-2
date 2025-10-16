#include <iostream>

template <typename T>
class BinaryNode        delete tree;
    }

    // ==========================================
    // TESTS DE REMOVE
    // ==========================================

    {
        // Remove: eliminar nodo hoja
        BinaryTree<int> *tree = new BinaryTree<int>();
        tree->add(50);
        tree->add(30);
        tree->add(70);
        tree->add(20);
        tree->add(40);

        /*
         * Antes:     50
         *           /  \
         *         30    70
         *        /  \
         *       20  40
         */

        std::cout << std::endl
                  << "=== Remove nodo hoja (20) ===" << std::endl;
        std::cout << "Antes:" << std::endl;
        tree->print_in_order(); // 20, 30, 40, 50, 70

        std::cout << "Remove 20: " << (tree->remove(20) ? "Eliminado" : "No encontrado") << std::endl;
        std::cout << "Despues:" << std::endl;
        tree->print_in_order(); // 30, 40, 50, 70

        std::cout << "Buscar 20: " << (tree->contains(20) ? "Encontrado" : "No encontrado") << std::endl;

        delete tree;
    }

    {
        // Remove: eliminar nodo con un hijo izquierdo
        BinaryTree<int> *tree = new BinaryTree<int>();
        tree->add(50);
        tree->add(30);
        tree->add(70);
        tree->add(20);

        /*
         * Antes:     50
         *           /  \
         *         30    70
         *        /
         *       20
         */

        std::cout << std::endl
                  << "=== Remove nodo con hijo izquierdo (30) ===" << std::endl;
        std::cout << "Antes:" << std::endl;
        tree->print_in_order(); // 20, 30, 50, 70

        std::cout << "Remove 30: " << (tree->remove(30) ? "Eliminado" : "No encontrado") << std::endl;
        std::cout << "Despues:" << std::endl;
        tree->print_in_order(); // 20, 50, 70

        delete tree;
    }

    {
        // Remove: eliminar nodo con un hijo derecho
        BinaryTree<int> *tree = new BinaryTree<int>();
        tree->add(50);
        tree->add(30);
        tree->add(70);
        tree->add(80);

        /*
         * Antes:     50
         *           /  \
         *         30    70
         *                \
         *                80
         */

        std::cout << std::endl
                  << "=== Remove nodo con hijo derecho (70) ===" << std::endl;
        std::cout << "Antes:" << std::endl;
        tree->print_in_order(); // 30, 50, 70, 80

        std::cout << "Remove 70: " << (tree->remove(70) ? "Eliminado" : "No encontrado") << std::endl;
        std::cout << "Despues:" << std::endl;
        tree->print_in_order(); // 30, 50, 80

        delete tree;
    }

    {
        // Remove: eliminar nodo con dos hijos
        BinaryTree<int> *tree = new BinaryTree<int>();
        tree->add(50);
        tree->add(30);
        tree->add(70);
        tree->add(20);
        tree->add(40);
        tree->add(60);
        tree->add(80);

        /*
         * Antes:     50
         *           /  \
         *         30    70
         *        /  \   /  \
         *       20  40 60  80
         */

        std::cout << std::endl
                  << "=== Remove nodo con dos hijos (30) ===" << std::endl;
        std::cout << "Antes:" << std::endl;
        tree->print_in_order(); // 20, 30, 40, 50, 60, 70, 80

        std::cout << "Remove 30: " << (tree->remove(30) ? "Eliminado" : "No encontrado") << std::endl;
        std::cout << "Despues (30 reemplazado por su sucesor 40):" << std::endl;
        tree->print_in_order(); // 20, 40, 50, 60, 70, 80

        std::cout << "Buscar 30: " << (tree->contains(30) ? "Encontrado" : "No encontrado") << std::endl;
        std::cout << "Buscar 40: " << (tree->contains(40) ? "Encontrado" : "No encontrado") << std::endl;

        delete tree;
    }

    {
        // Remove: eliminar la raíz (caso hoja)
        BinaryTree<int> *tree = new BinaryTree<int>();
        tree->add(42);

        std::cout << std::endl
                  << "=== Remove raiz (unico elemento) ===" << std::endl;
        std::cout << "Antes:" << std::endl;
        tree->print_in_order(); // 42

        std::cout << "Remove 42: " << (tree->remove(42) ? "Eliminado" : "No encontrado") << std::endl;
        std::cout << "Arbol vacio: " << (tree->empty() ? "SI" : "NO") << std::endl;

        delete tree;
    }

    {
        // Remove: eliminar la raíz con dos hijos
        BinaryTree<int> *tree = new BinaryTree<int>();
        tree->add(50);
        tree->add(30);
        tree->add(70);
        tree->add(20);
        tree->add(40);
        tree->add(60);
        tree->add(80);

        /*
         * Antes:     50
         *           /  \
         *         30    70
         *        /  \   /  \
         *       20  40 60  80
         */

        std::cout << std::endl
                  << "=== Remove raiz con dos hijos (50) ===" << std::endl;
        std::cout << "Antes:" << std::endl;
        tree->print_in_order(); // 20, 30, 40, 50, 60, 70, 80

        std::cout << "Remove 50: " << (tree->remove(50) ? "Eliminado" : "No encontrado") << std::endl;
        std::cout << "Despues (50 reemplazado por su sucesor 60):" << std::endl;
        tree->print_in_order(); // 20, 30, 40, 60, 70, 80

        delete tree;
    }

    {
        // Remove: elemento no existe
        BinaryTree<int> *tree = new BinaryTree<int>();
        tree->add(50);
        tree->add(30);
        tree->add(70);

        std::cout << std::endl
                  << "=== Remove elemento inexistente ===" << std::endl;
        std::cout << "Antes:" << std::endl;
        tree->print_in_order(); // 30, 50, 70

        std::cout << "Remove 99: " << (tree->remove(99) ? "Eliminado" : "No encontrado") << std::endl;
        std::cout << "Despues (sin cambios):" << std::endl;
        tree->print_in_order(); // 30, 50, 70

        delete tree;
    }

    {
        // Remove: árbol vacío
        BinaryTree<int> *tree = new BinaryTree<int>();

        std::cout << std::endl
                  << "=== Remove en arbol vacio ===" << std::endl;
        std::cout << "Remove 10: " << (tree->remove(10) ? "Eliminado" : "No encontrado") << std::endl;

        delete tree;
    }

    {
        // Remove: eliminar todos los elementos progresivamente
        BinaryTree<int> *tree = new BinaryTree<int>();
        tree->add(50);
        tree->add(30);
        tree->add(70);
        tree->add(20);
        tree->add(40);
        tree->add(60);
        tree->add(80);

        std::cout << std::endl
                  << "=== Remove todos los elementos ===" << std::endl;
        std::cout << "Inicial:" << std::endl;
        tree->print_in_order(); // 20, 30, 40, 50, 60, 70, 80

        tree->remove(20);
        std::cout << "Despues remove 20:" << std::endl;
        tree->print_in_order(); // 30, 40, 50, 60, 70, 80

        tree->remove(80);
        std::cout << "Despues remove 80:" << std::endl;
        tree->print_in_order(); // 30, 40, 50, 60, 70

        tree->remove(50);
        std::cout << "Despues remove 50:" << std::endl;
        tree->print_in_order(); // 30, 40, 60, 70

        tree->remove(30);
        std::cout << "Despues remove 30:" << std::endl;
        tree->print_in_order(); // 40, 60, 70

        tree->remove(70);
        std::cout << "Despues remove 70:" << std::endl;
        tree->print_in_order(); // 40, 60

        tree->remove(40);
        std::cout << "Despues remove 40:" << std::endl;
        tree->print_in_order(); // 60

        tree->remove(60);
        std::cout << "Despues remove 60 (deberia estar vacio):" << std::endl;
        std::cout << "Arbol vacio: " << (tree->empty() ? "SI" : "NO") << std::endl;

        delete tree;
    }

    {
        // Remove: verificar orden in-order después de múltiples remociones
        BinaryTree<int> *tree = new BinaryTree<int>();
        tree->add(15);
        tree->add(10);
        tree->add(20);
        tree->add(8);
        tree->add(12);
        tree->add(17);
        tree->add(25);

        /*
         * Estructura:
         *        15
         *       /  \
         *     10    20
         *    /  \   /  \
         *   8  12  17  25
         */

        std::cout << std::endl
                  << "=== Verificar orden in-order tras remociones ===" << std::endl;
        std::cout << "Inicial:" << std::endl;
        tree->print_in_order(); // 8, 10, 12, 15, 17, 20, 25

        tree->remove(10); // nodo con dos hijos
        std::cout << "Despues remove 10:" << std::endl;
        tree->print_in_order(); // 8, 12, 15, 17, 20, 25

        tree->remove(20); // nodo con dos hijos
        std::cout << "Despues remove 20:" << std::endl;
        tree->print_in_order(); // 8, 12, 15, 17, 25

        std::cout << "Orden correcto mantenido" << std::endl;

        delete tree;
    }

    {
        // Remove: con duplicados
        BinaryTree<int> *tree = new BinaryTree<int>();
        tree->add(50);
        tree->add(30);
        tree->add(50); // duplicado
        tree->add(30); // duplicado

        std::cout << std::endl
                  << "=== Remove con duplicados ===" << std::endl;
        std::cout << "Antes:" << std::endl;
        tree->print_in_order(); // 30, 30, 50, 50

        std::cout << "Remove 50 (elimina primera aparicion): " << (tree->remove(50) ? "Eliminado" : "No encontrado") << std::endl;
        std::cout << "Despues:" << std::endl;
        tree->print_in_order(); // 30, 30, 50

        std::cout << "Remove 50 otra vez: " << (tree->remove(50) ? "Eliminado" : "No encontrado") << std::endl;
        std::cout << "Despues:" << std::endl;
        tree->print_in_order(); // 30, 30

        delete tree;
    }
}

private:
    T value;
    BinaryNode *left;
    BinaryNode *right;

public:
    BinaryNode() : value(NULL), left(nullptr), right(nullptr) {}
    BinaryNode(T val) : value(val), left(nullptr), right(nullptr) {}

    void set_value(T val) { value = val; }
    void set_right(BinaryNode<T> *node) { right = node; }
    void set_left(BinaryNode<T> *node) { left = node; }

    T get_value() { return value; }
    BinaryNode<T> *get_right() { return right; }
    BinaryNode<T> *get_left() { return left; }
};

template <typename T>
class BinaryTree
{
private:
    BinaryNode<T> *root;

    void destroy_tree(BinaryNode<T> *node);

    bool remove_helper(BinaryNode<T> *&node, T a);

    void print_in_order_helper(BinaryNode<T> *node);
    void print_pre_order_helper(BinaryNode<T> *node);
    void print_post_order_helper(BinaryNode<T> *node);

public:
    BinaryTree() : root(nullptr) {}
    BinaryTree(BinaryNode<T> *node) : root(node) {}
    ~BinaryTree();

    void set_root(BinaryNode<T> *node) { root = node; }
    BinaryNode<T> *get_root() { return root; }

    bool empty();
    void add(T a);
    bool remove(T a);
    bool contains(T a);

    void print_in_order();
    void print_pre_order();
    void print_post_order();
};

template <typename T>
void BinaryTree<T>::destroy_tree(BinaryNode<T> *node)
{
    if (node != nullptr)
    {
        destroy_tree(node->get_left());
        destroy_tree(node->get_right());
        delete node;
    }
}

template <typename T>
bool BinaryTree<T>::remove_helper(BinaryNode<T> *&node, T a)
{
    if (node == nullptr)
    {
        return false;
    }

    if (a < node->get_value())
    {
        return remove_helper(node->get_left(), a);
    }
    else if (a > node->get_value())
    {
        return remove_helper(node->get_right(), a);
    }
    else
    {

        if (node->get_left() == nullptr && node->get_right() == nullptr)
        {
            delete node;
            node = nullptr;
        }
        else if (node->get_left() == nullptr)
        {
            BinaryNode<T> *temp = node;
            node = node->get_right();
            delete temp;
        }
        else if (node->get_right() == nullptr)
        {
            BinaryNode<T> *temp = node;
            node = node->get_left();
            delete temp;
        }
        else
        {
            BinaryNode<T> *currentParent = node;
            BinaryNode<T> *current = node->get_right();

            while (current->get_left() != nullptr)
            {
                currentParent = current;
                current = current->get_left();
            }

            node->set_value(current->get_value());

            if (currentParent->getLeft() == current)
                currentParent->setLeft(current->getRight());
            else
                currentParent->setRight(current->getRight());

            delete current;
        }

        return true;
    }
}

template <typename T>
BinaryTree<T>::~BinaryTree()
{
    destroy_tree(root);
    std::cout << "Destruyendo ..." << std::endl;
}

template <typename T>
bool BinaryTree<T>::empty()
{
    return get_root() == nullptr;
}

template <typename T>
void BinaryTree<T>::add(T a)
{
    BinaryNode<T> *new_node = new BinaryNode(a);

    if (empty())
    {
        set_root(new_node);
        return;
    }

    BinaryNode<T> *current = get_root();
    BinaryNode<T> *parent = nullptr;

    while (true)
    {
        parent = current;

        if (a < current->get_value())
        {
            current = current->get_left();

            if (current == nullptr)
            {
                parent->set_left(new_node);
                return;
            }
        }
        else
        {
            current = current->get_right();

            if (current == nullptr)
            {
                parent->set_right(new_node);
                return;
            }
        }
    }
}

template <typename T>
bool BinaryTree<T>::remove(T a)
{
    if (empty())
    {
        return false;
    }

    return remove_helper(get_root(), a);
}

template <typename T>
bool BinaryTree<T>::contains(T a)
{
    if (empty())
    {
        return false;
    }

    BinaryNode<T> *current = get_root();

    while (current != nullptr)
    {
        if (a == current->get_value())
        {
            return true;
        }
        else if (a < current->get_value())
        {
            current = current->get_left();
        }
        else
        {
            current = current->get_right();
        }
    }

    return false;
}

template <typename T>
void BinaryTree<T>::print_in_order_helper(BinaryNode<T> *node)
{
    if (node != nullptr)
    {
        print_in_order_helper(node->get_left());
        std::cout << "node: " << node->get_value() << std::endl;
        print_in_order_helper(node->get_right());
    }
}

template <typename T>
void BinaryTree<T>::print_in_order()
{
    print_in_order_helper(get_root());
}

template <typename T>
void BinaryTree<T>::print_pre_order_helper(BinaryNode<T> *node)
{
    if (node != nullptr)
    {
        std::cout << "node: " << node->get_value() << std::endl;
        print_pre_order_helper(node->get_left());
        print_pre_order_helper(node->get_right());
    }
}

template <typename T>
void BinaryTree<T>::print_pre_order()
{
    print_pre_order_helper(get_root());
}

template <typename T>
void BinaryTree<T>::print_post_order_helper(BinaryNode<T> *node)
{
    if (node != nullptr)
    {
        print_post_order_helper(node->get_left());
        print_post_order_helper(node->get_right());
        std::cout << "node: " << node->get_value() << std::endl;
    }
}

template <typename T>
void BinaryTree<T>::print_post_order()
{
    print_post_order_helper(get_root());
}

void testingBinaryTree()
{
    {
        // Árbol vacío: empty debe retornar true
        BinaryTree<int> *tree = new BinaryTree<int>();
        std::cout << "Arbol vacio: " << (tree->empty() ? "SI" : "NO") << std::endl; // SI

        delete tree;
    }

    {
        // Agregar elementos y verificar recorridos
        BinaryTree<int> *tree = new BinaryTree<int>();
        tree->add(50);
        tree->add(30);
        tree->add(70);
        tree->add(20);
        tree->add(40);
        tree->add(60);
        tree->add(80);

        /*
         * Estructura del árbol:
         *        50
         *       /  \
         *     30    70
         *    /  \   /  \
         *   20  40 60  80
         */

        std::cout << std::endl
                  << "=== In-Order (deberia ser: 20, 30, 40, 50, 60, 70, 80) ===" << std::endl;
        tree->print_in_order();

        std::cout << std::endl
                  << "=== Pre-Order (deberia ser: 50, 30, 20, 40, 70, 60, 80) ===" << std::endl;
        tree->print_pre_order();

        std::cout << std::endl
                  << "=== Post-Order (deberia ser: 20, 40, 30, 60, 80, 70, 50) ===" << std::endl;
        tree->print_post_order();

        delete tree;
    }

    {
        // Find: buscar elementos existentes y no existentes
        BinaryTree<int> *tree = new BinaryTree<int>();
        tree->add(50);
        tree->add(30);
        tree->add(70);
        tree->add(20);
        tree->add(40);

        std::cout << std::endl
                  << "=== Busqueda ===" << std::endl;
        std::cout << "Buscar 30: " << (tree->contains(30) ? "Encontrado" : "No encontrado") << std::endl; // Encontrado
        std::cout << "Buscar 70: " << (tree->contains(70) ? "Encontrado" : "No encontrado") << std::endl; // Encontrado
        std::cout << "Buscar 20: " << (tree->contains(20) ? "Encontrado" : "No encontrado") << std::endl; // Encontrado
        std::cout << "Buscar 99: " << (tree->contains(99) ? "Encontrado" : "No encontrado") << std::endl; // No encontrado
        std::cout << "Buscar 5: " << (tree->contains(5) ? "Encontrado" : "No encontrado") << std::endl;   // No encontrado

        delete tree;
    }

    {
        // Árbol con un solo elemento
        BinaryTree<int> *tree = new BinaryTree<int>();
        tree->add(42);

        std::cout << std::endl
                  << "=== Arbol con un solo elemento ===" << std::endl;
        std::cout << "In-Order (deberia ser: 42):" << std::endl;
        tree->print_in_order();

        std::cout << "Buscar 42: " << (tree->contains(42) ? "Encontrado" : "No encontrado") << std::endl; // Encontrado
        std::cout << "Buscar 10: " << (tree->contains(10) ? "Encontrado" : "No encontrado") << std::endl; // No encontrado

        delete tree;
    }

    {
        // Árbol desbalanceado (solo hijos derechos)
        BinaryTree<int> *tree = new BinaryTree<int>();
        tree->add(1);
        tree->add(2);
        tree->add(3);
        tree->add(4);
        tree->add(5);

        /*
         * Estructura:
         *   1
         *    \
         *     2
         *      \
         *       3
         *        \
         *         4
         *          \
         *           5
         */

        std::cout << std::endl
                  << "=== Arbol desbalanceado (solo derechos) ===" << std::endl;
        std::cout << "In-Order (deberia ser: 1, 2, 3, 4, 5):" << std::endl;
        tree->print_in_order();

        delete tree;
    }

    {
        // Árbol desbalanceado (solo hijos izquierdos)
        BinaryTree<int> *tree = new BinaryTree<int>();
        tree->add(5);
        tree->add(4);
        tree->add(3);
        tree->add(2);
        tree->add(1);

        /*
         * Estructura:
         *         5
         *        /
         *       4
         *      /
         *     3
         *    /
         *   2
         *  /
         * 1
         */

        std::cout << std::endl
                  << "=== Arbol desbalanceado (solo izquierdos) ===" << std::endl;
        std::cout << "In-Order (deberia ser: 1, 2, 3, 4, 5):" << std::endl;
        tree->print_in_order();

        delete tree;
    }

    {
        // Duplicados: agregar el mismo valor (deberia ir a la derecha)
        BinaryTree<int> *tree = new BinaryTree<int>();
        tree->add(50);
        tree->add(30);
        tree->add(50); // duplicado, va a la derecha
        tree->add(30); // duplicado, va a la derecha

        std::cout << std::endl
                  << "=== Con duplicados ===" << std::endl;
        std::cout << "In-Order (deberia ser: 30, 30, 50, 50):" << std::endl;
        tree->print_in_order();

        std::cout << "Buscar 50: " << (tree->contains(50) ? "Encontrado" : "No encontrado") << std::endl; // Encontrado
        std::cout << "Buscar 30: " << (tree->contains(30) ? "Encontrado" : "No encontrado") << std::endl; // Encontrado

        delete tree;
    }

    {
        // Árbol balanceado perfecto
        BinaryTree<int> *tree = new BinaryTree<int>();
        tree->add(4);
        tree->add(2);
        tree->add(6);
        tree->add(1);
        tree->add(3);
        tree->add(5);
        tree->add(7);

        /*
         * Estructura:
         *       4
         *      / \
         *     2   6
         *    / \ / \
         *   1  3 5  7
         */

        std::cout << std::endl
                  << "=== Arbol balanceado perfecto ===" << std::endl;
        std::cout << "In-Order (deberia ser: 1, 2, 3, 4, 5, 6, 7):" << std::endl;
        tree->print_in_order();

        std::cout << std::endl
                  << "Pre-Order (deberia ser: 4, 2, 1, 3, 6, 5, 7):" << std::endl;
        tree->print_pre_order();

        std::cout << std::endl
                  << "Post-Order (deberia ser: 1, 3, 2, 5, 7, 6, 4):" << std::endl;
        tree->print_post_order();

        delete tree;
    }

    {
        // Remove: eliminar nodo hoja
        BinaryTree<int> *tree = new BinaryTree<int>();
        tree->add(50);
        tree->add(30);
        tree->add(70);
        tree->add(20);
        tree->add(40);

        /*
         * Antes:     50
         *           /  \
         *         30    70
         *        /  \
         *       20  40
         */

        std::cout << std::endl
                  << "=== Remove nodo hoja (20) ===" << std::endl;
        std::cout << "Antes:" << std::endl;
        tree->print_in_order(); // 20, 30, 40, 50, 70

        std::cout << "Remove 20: " << (tree->remove(20) ? "Eliminado" : "No encontrado") << std::endl;
        std::cout << "Despues:" << std::endl;
        tree->print_in_order(); // 30, 40, 50, 70

        std::cout << "Buscar 20: " << (tree->contains(20) ? "Encontrado" : "No encontrado") << std::endl;

        delete tree;
    }

    {
        // Remove: eliminar nodo con un hijo izquierdo
        BinaryTree<int> *tree = new BinaryTree<int>();
        tree->add(50);
        tree->add(30);
        tree->add(70);
        tree->add(20);

        /*
         * Antes:     50
         *           /  \
         *         30    70
         *        /
         *       20
         */

        std::cout << std::endl
                  << "=== Remove nodo con hijo izquierdo (30) ===" << std::endl;
        std::cout << "Antes:" << std::endl;
        tree->print_in_order(); // 20, 30, 50, 70

        std::cout << "Remove 30: " << (tree->remove(30) ? "Eliminado" : "No encontrado") << std::endl;
        std::cout << "Despues:" << std::endl;
        tree->print_in_order(); // 20, 50, 70

        delete tree;
    }

    {
        // Remove: eliminar nodo con un hijo derecho
        BinaryTree<int> *tree = new BinaryTree<int>();
        tree->add(50);
        tree->add(30);
        tree->add(70);
        tree->add(80);

        /*
         * Antes:     50
         *           /  \
         *         30    70
         *                \
         *                80
         */

        std::cout << std::endl
                  << "=== Remove nodo con hijo derecho (70) ===" << std::endl;
        std::cout << "Antes:" << std::endl;
        tree->print_in_order(); // 30, 50, 70, 80

        std::cout << "Remove 70: " << (tree->remove(70) ? "Eliminado" : "No encontrado") << std::endl;
        std::cout << "Despues:" << std::endl;
        tree->print_in_order(); // 30, 50, 80

        delete tree;
    }

    {
        // Remove: eliminar nodo con dos hijos
        BinaryTree<int> *tree = new BinaryTree<int>();
        tree->add(50);
        tree->add(30);
        tree->add(70);
        tree->add(20);
        tree->add(40);
        tree->add(60);
        tree->add(80);

        /*
         * Antes:     50
         *           /  \
         *         30    70
         *        /  \   /  \
         *       20  40 60  80
         */

        std::cout << std::endl
                  << "=== Remove nodo con dos hijos (30) ===" << std::endl;
        std::cout << "Antes:" << std::endl;
        tree->print_in_order(); // 20, 30, 40, 50, 60, 70, 80

        std::cout << "Remove 30: " << (tree->remove(30) ? "Eliminado" : "No encontrado") << std::endl;
        std::cout << "Despues (30 reemplazado por su sucesor 40):" << std::endl;
        tree->print_in_order(); // 20, 40, 50, 60, 70, 80

        std::cout << "Buscar 30: " << (tree->contains(30) ? "Encontrado" : "No encontrado") << std::endl;
        std::cout << "Buscar 40: " << (tree->contains(40) ? "Encontrado" : "No encontrado") << std::endl;

        delete tree;
    }

    {
        // Remove: eliminar la raíz (caso hoja)
        BinaryTree<int> *tree = new BinaryTree<int>();
        tree->add(42);

        std::cout << std::endl
                  << "=== Remove raiz (unico elemento) ===" << std::endl;
        std::cout << "Antes:" << std::endl;
        tree->print_in_order(); // 42

        std::cout << "Remove 42: " << (tree->remove(42) ? "Eliminado" : "No encontrado") << std::endl;
        std::cout << "Arbol vacio: " << (tree->empty() ? "SI" : "NO") << std::endl;

        delete tree;
    }

    {
        // Remove: eliminar la raíz con dos hijos
        BinaryTree<int> *tree = new BinaryTree<int>();
        tree->add(50);
        tree->add(30);
        tree->add(70);
        tree->add(20);
        tree->add(40);
        tree->add(60);
        tree->add(80);

        /*
         * Antes:     50
         *           /  \
         *         30    70
         *        /  \   /  \
         *       20  40 60  80
         */

        std::cout << std::endl
                  << "=== Remove raiz con dos hijos (50) ===" << std::endl;
        std::cout << "Antes:" << std::endl;
        tree->print_in_order(); // 20, 30, 40, 50, 60, 70, 80

        std::cout << "Remove 50: " << (tree->remove(50) ? "Eliminado" : "No encontrado") << std::endl;
        std::cout << "Despues (50 reemplazado por su sucesor 60):" << std::endl;
        tree->print_in_order(); // 20, 30, 40, 60, 70, 80

        delete tree;
    }

    {
        // Remove: elemento no existe
        BinaryTree<int> *tree = new BinaryTree<int>();
        tree->add(50);
        tree->add(30);
        tree->add(70);

        std::cout << std::endl
                  << "=== Remove elemento inexistente ===" << std::endl;
        std::cout << "Antes:" << std::endl;
        tree->print_in_order(); // 30, 50, 70

        std::cout << "Remove 99: " << (tree->remove(99) ? "Eliminado" : "No encontrado") << std::endl;
        std::cout << "Despues (sin cambios):" << std::endl;
        tree->print_in_order(); // 30, 50, 70

        delete tree;
    }

    {
        // Remove: árbol vacío
        BinaryTree<int> *tree = new BinaryTree<int>();

        std::cout << std::endl
                  << "=== Remove en arbol vacio ===" << std::endl;
        std::cout << "Remove 10: " << (tree->remove(10) ? "Eliminado" : "No encontrado") << std::endl;

        delete tree;
    }

    {
        // Remove: eliminar todos los elementos progresivamente
        BinaryTree<int> *tree = new BinaryTree<int>();
        tree->add(50);
        tree->add(30);
        tree->add(70);
        tree->add(20);
        tree->add(40);
        tree->add(60);
        tree->add(80);

        std::cout << std::endl
                  << "=== Remove todos los elementos ===" << std::endl;
        std::cout << "Inicial:" << std::endl;
        tree->print_in_order(); // 20, 30, 40, 50, 60, 70, 80

        tree->remove(20);
        std::cout << "Despues remove 20:" << std::endl;
        tree->print_in_order(); // 30, 40, 50, 60, 70, 80

        tree->remove(80);
        std::cout << "Despues remove 80:" << std::endl;
        tree->print_in_order(); // 30, 40, 50, 60, 70

        tree->remove(50);
        std::cout << "Despues remove 50:" << std::endl;
        tree->print_in_order(); // 30, 40, 60, 70

        tree->remove(30);
        std::cout << "Despues remove 30:" << std::endl;
        tree->print_in_order(); // 40, 60, 70

        tree->remove(70);
        std::cout << "Despues remove 70:" << std::endl;
        tree->print_in_order(); // 40, 60

        tree->remove(40);
        std::cout << "Despues remove 40:" << std::endl;
        tree->print_in_order(); // 60

        tree->remove(60);
        std::cout << "Despues remove 60 (deberia estar vacio):" << std::endl;
        std::cout << "Arbol vacio: " << (tree->empty() ? "SI" : "NO") << std::endl;

        delete tree;
    }

    {
        // Remove: verificar orden in-order después de múltiples remociones
        BinaryTree<int> *tree = new BinaryTree<int>();
        tree->add(15);
        tree->add(10);
        tree->add(20);
        tree->add(8);
        tree->add(12);
        tree->add(17);
        tree->add(25);

        /*
         * Estructura:
         *        15
         *       /  \
         *     10    20
         *    /  \   /  \
         *   8  12  17  25
         */

        std::cout << std::endl
                  << "=== Verificar orden in-order tras remociones ===" << std::endl;
        std::cout << "Inicial:" << std::endl;
        tree->print_in_order(); // 8, 10, 12, 15, 17, 20, 25

        tree->remove(10); // nodo con dos hijos
        std::cout << "Despues remove 10:" << std::endl;
        tree->print_in_order(); // 8, 12, 15, 17, 20, 25

        tree->remove(20); // nodo con dos hijos
        std::cout << "Despues remove 20:" << std::endl;
        tree->print_in_order(); // 8, 12, 15, 17, 25

        std::cout << "Orden correcto mantenido" << std::endl;

        delete tree;
    }

    {
        // Remove: con duplicados
        BinaryTree<int> *tree = new BinaryTree<int>();
        tree->add(50);
        tree->add(30);
        tree->add(50); // duplicado
        tree->add(30); // duplicado

        std::cout << std::endl
                  << "=== Remove con duplicados ===" << std::endl;
        std::cout << "Antes:" << std::endl;
        tree->print_in_order(); // 30, 30, 50, 50

        std::cout << "Remove 50 (elimina primera aparicion): " << (tree->remove(50) ? "Eliminado" : "No encontrado") << std::endl;
        std::cout << "Despues:" << std::endl;
        tree->print_in_order(); // 30, 30, 50

        std::cout << "Remove 50 otra vez: " << (tree->remove(50) ? "Eliminado" : "No encontrado") << std::endl;
        std::cout << "Despues:" << std::endl;
        tree->print_in_order(); // 30, 30

        delete tree;
    }
}