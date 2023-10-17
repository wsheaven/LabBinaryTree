/***********************************************************************
 * Header:
 *    BINARY NODE
 * Summary:
 *    One node in a binary tree (and the functions to support them).
 *      __       ____       ____         __
 *     /  |    .'    '.   .'    '.   _  / /
 *     `| |   |  .--.  | |  .--.  | (_)/ /
 *      | |   | |    | | | |    | |   / / _
 *     _| |_  |  `--'  | |  `--'  |  / / (_)
 *    |_____|  '.____.'   '.____.'  /_/
 *
 *
 *    This will contain the class definition of:
 *        BNode         : A class representing a BNode
 *    Additionally, it will contain a few functions working on Node
 * Author
 *    Sam Heaven, Abram Hansen
 ************************************************************************/

#pragma once

#include <iostream>  // for OFSTREAM
#include <cassert>

/*****************************************************************
 * BNODE
 * A single node in a binary tree.  Note that the node does not know
 * anything about the properties of the tree so no validation can be done.
 *****************************************************************/
template <class T>
class BNode
{
public:
   // 
   // Construct
   //
   BNode()
   {
      pLeft = pRight = pParent = nullptr;
      data = 0; 
   }
   BNode(const T& t) : data(t), pLeft(nullptr), pRight(nullptr), pParent(nullptr)
   {
    
   }
   BNode(T&& t) : data(t), pLeft(nullptr), pRight(nullptr), pParent(nullptr)
   {
      
   }

   //
   // Data
   //
   BNode <T>* pLeft;
   BNode <T>* pRight;
   BNode <T>* pParent;
   T data;
};

/*******************************************************************
 * SIZE BTREE
 * Return the size of a b-tree under the current node
 *******************************************************************/
template <class T>
inline size_t size(const BNode <T> * p)
{
   if (p == nullptr)
   {
      return 0; 
   }
   else
   {
      return size(p->pLeft) + 1 + size(p->pRight); 
   }
}


/******************************************************
 * ADD LEFT
 * Add a node to the left of the current node
 ******************************************************/
template <class T>
inline void addLeft(BNode <T> * pNode, BNode <T> * pAdd)
{
   pNode->pLeft = pAdd->pLeft; 
}

/******************************************************
 * ADD RIGHT
 * Add a node to the right of the current node
 ******************************************************/
template <class T>
inline void addRight (BNode <T> * pNode, BNode <T> * pAdd)
{
   pNode->pRight = pAdd->pRight;
}

/******************************************************
 * ADD LEFT
 * Add a node to the left of the current node
 ******************************************************/
template <class T>
inline void addLeft (BNode <T> * pNode, const T & t)
{
   pNode->pLeft = new BNode<T>(t); 
}

template <class T>
inline void addLeft(BNode <T>* pNode, T && t)
{
   pNode->pLeft = new BNode<T>(t);
}

/******************************************************
 * ADD RIGHT
 * Add a node to the right of the current node
 ******************************************************/
template <class T>
void addRight (BNode <T> * pNode, const T & t)
{
   pNode->pRight = new BNode<T>(t);
}

template <class T>
void addRight(BNode <T>* pNode, T && t)
{
   pNode->pRight = new BNode<T>(t);
}

/*****************************************************
 * DELETE BINARY TREE
 * Delete all the nodes below pThis including pThis
 * using postfix traverse: LRV
 ****************************************************/
template <class T>
void clear(BNode <T> * & pThis)
{
   if (pThis == nullptr)
   {
      return; 
   }
   clear(pThis->pLeft); 
   clear(pThis->pRight); 
   pThis = nullptr;
   delete pThis; 
}

/***********************************************
 * SWAP
 * Swap the list from LHS to RHS
 *   COST   : O(1)
 **********************************************/
template <class T>
inline void swap(BNode <T>*& pLHS, BNode <T>*& pRHS)
{
   std::swap(pLHS, pRHS); 
}

/**********************************************
 * COPY BINARY TREE
 * Copy pSrc->pRight to pDest->pRight and
 * pSrc->pLeft onto pDest->pLeft
 *********************************************/
template <class T>
BNode <T> * copy(const BNode <T> * pSrc)
{
   if (pSrc == nullptr) {
      return nullptr;
   }

   // Create a new node for the destination tree and copy the value
   BNode<T>* pDest = new BNode<T>(pSrc->data);

   pDest->pLeft = copy(pSrc->pLeft);
   if (pDest->pLeft != nullptr)
   {
      pDest->pLeft->pParent = pDest; 
   }
   
   pDest->pRight = copy(pSrc->pRight);
   if (pDest->pRight != nullptr)
   {
      pDest->pRight->pParent = pDest;
   }

   return pDest;

}

/**********************************************
 * assign
 * copy the values from pSrc onto pDest preserving
 * as many of the nodes as possible.
 *********************************************/
template <class T>
void assign(BNode <T> * & pDest, const BNode <T>* pSrc)
{

}
