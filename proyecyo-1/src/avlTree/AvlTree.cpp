//
// Created by brigidoalvarado on 16/12/24.
//
#include "../../includes/avlTree/AvlTree.h"

AvlTree::AvlTree()
{
    root = nullptr;
}

void AvlTree::setRoot(AvlNode* root)
{
    this->root = root;
}

AvlNode* AvlTree::furtherRight(AvlNode*& node)
{
    if (node->getRight() == nullptr)
    {
        return node;
    }
    return furtherRight(node->getRight());
}

AvlNode* AvlTree::getRoot()
{
    return root;
}

int AvlTree::maxHeight(AvlNode* node)
{
    if (node == nullptr) return 0;

    int hLeft = maxHeight( node->getLeft());
    int hRight = maxHeight( node->getRight());

    return hLeft > hRight ? hLeft + 1: hRight + 1;
}

int AvlTree::calcBalanceFactor(AvlNode* node)
{
    return maxHeight( node->getRight()) - maxHeight( node->getLeft());
}

void AvlTree::insert(string id, Asset *asset)
{
    AvlNode* node = new AvlNode(id);
    node->setAsset(asset);
    insert( node, this->root );
}

void AvlTree::deleteAsset(string id)
{
    deleteAsset(id, this->root);
}

void AvlTree::deleteAsset(string id, AvlNode*& root)
{
    if (root == nullptr)
    {
        std::cout << "  El activo con ID: " << id << " no existe" << std::endl;
        return;
    }

    if (id == root->getId())
    {
        //caso en que es una hoja
        if (isLeaf(root))
        {
            root = nullptr;
            return;
        }
        //caso en que no hay hijo izquierdo
        if (root->getLeft() == nullptr)
        {
            root = root->getRight();
            return;
        }
        //caso en que no hay hijo derecho
        if (root->getRight() == nullptr)
        {
            root = root->getLeft();
            return;
        }

        //Buscar el mas a la derecha del hijo izquierdo
        AvlNode *rightNode = furtherRight(root->getLeft());
        root->setValue(rightNode->getId(), rightNode->getAsset());

        deleteAsset(rightNode->getId(), root->getLeft());

        id = root->getId();
    }

    if (id < root->getId())
    {
        deleteAsset(id, root->getLeft());
    }

    else if (id > root->getId())
    {
        deleteAsset(id, root->getRight());
    }

    root->setBalanceFactor(calcBalanceFactor(root));

    if ( root->getBalanceFactor() < -1)
    {
        if (root->getLeft()->getBalanceFactor() > 0)
        {
            turnLeftRight(root);
            return;
        }
        turnRight(root);
        return;
    }

    if (root->getBalanceFactor() > 1)
    {
        if (root->getRight()->getBalanceFactor() < 0)
        {
            turnRightLeft(root);
            return;
        }
        turnLeft(root);
        return;
    }
}

void AvlTree::insert(AvlNode* value, AvlNode*& root)
{

    if (root == nullptr)
    {
        root = value;
        root->setBalanceFactor(calcBalanceFactor(root));
        return;
    }

    if (value->getId() < root->getId())
    {
        insert( value, root->getLeft() );
    } else
    {
        insert( value, root->getRight() );
    }

    root->setBalanceFactor(calcBalanceFactor(root));

    if ( root->getBalanceFactor() < -1)
    {
        if (root->getLeft()->getBalanceFactor() > 0)
        {
            turnLeftRight(root);
            return;
        }
        turnRight( root );
        return;
    }

    if (root->getBalanceFactor() > 1)
    {
        if (root->getRight()->getBalanceFactor() <   0)
        {
            turnRightLeft(root);
            return;
        }
        turnLeft( root );
    }
}

void AvlTree::turnRight(AvlNode*& node)
{
    AvlNode *aux = node->getLeft();

    node->setLeft(aux->getRight());
    aux->setRight(node);
    node = aux;

    node             -> setBalanceFactor (calcBalanceFactor(      node               ) );
    node->getRight() -> setBalanceFactor (calcBalanceFactor (node -> getRight() ) );
    if ( node->getLeft() == nullptr ) return;
    node->getLeft()  -> setBalanceFactor (calcBalanceFactor (node -> getLeft()  ) );
}

void AvlTree::turnRightLeft(AvlNode*& node)
{
    turnRight( node->getRight() );
    turnLeft( node );
}

void AvlTree::turnLeft(AvlNode*& node)
{
    AvlNode *aux = node->getRight();

    node->setRight(aux->getLeft());
    aux->setLeft(node);
    node = aux;

    node            ->setBalanceFactor(calcBalanceFactor(      node               ) );
    node->getLeft()->setBalanceFactor(calcBalanceFactor  (node -> getLeft()  ) );
    if (node->getRight() == nullptr) return;
    node->getRight()->setBalanceFactor(calcBalanceFactor (node -> getRight() ) );
}

void AvlTree::turnLeftRight(AvlNode*& node)
{
    turnLeft( node->getLeft() );
    turnRight( node );
}

bool AvlTree::isLeaf(AvlNode* node)
{
    return node->getLeft() == nullptr && node->getRight() == nullptr;
}


void AvlTree::printTree()
{
    printTree(this->root);
}

void AvlTree::printTree(AvlNode* root)
{
    if (root == nullptr)
    {
        return;
    }
    std::cout << "  ID: " << root->getId() << " nombre: " << root->getAsset()->getName() << std::endl;
    printTree(root->getLeft());
    printTree(root->getRight());
}

Asset* AvlTree::getAsset(string id)
{
    getAsset(id, this->root);
}

Asset* AvlTree::getAsset(string id, AvlNode*& root)
{
    if (root == nullptr)
    {
        return nullptr;
    }
        if (root->getId() == id)
        {
            return root->getAsset();
        }

        if (root->getAsset()->getName() < id)
        {
            return getAsset(id, root->getLeft());
        }

        if (root->getAsset()->getName() > id)
        {
            return getAsset(id, root->getRight());
        }
}

