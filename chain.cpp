#include "chain.h"
#include <cmath>
#include <iostream>

// PA1 functions
// Complete all of the missing implementation
// and submit this file for grading.

/**
 * Destroys the current Chain. This function should ensure that
 * memory does not leak on destruction of a chain.
 */
Chain::~Chain()
{
	Clear();
}

/**
 * Inserts a new node after the node pointed to by p in the
 * chain (so p->next is the new node) and returns a pointer to
 * the newly created node.
 * If p is NULL, inserts a new head node to the chain.
 * This function **SHOULD** create a new Node and increase length_.
 *
 * @param p = The new node should be pointed to by p->next.
 *            If p is NULL, the new node becomes the head of the chain.
 * @param ndata = The data to be inserted.
 */
Chain::Node *Chain::InsertAfter(Node *p, const Block &ndata)
{
	/* your code here */
	return nullptr;
}

/**
 * Swaps the position in the chain of the two nodes pointed to
 * by p and q.
 * If p or q is NULL or p==q, do nothing.
 * Change the chain's head pointer if necessary.
 */
void Chain::Swap(Node *p, Node *q)
{
	/* your code here */
}

/**
 * Destroys all dynamically allocated memory associated with the
 * current Chain class.
 */
void Chain::Clear()
{
	// basically loop through the chain and set every node to null
	Node *curr = head_;

	if (curr == nullptr)
	{
		length_ = 0;
		return;
	}

	while (curr != nullptr)
	{
		Node *nextNode = curr->next;
		delete curr;
		curr = nextNode;
	}
	head_ = nullptr;
	length_ = 0;
}

/**
 * Makes the current object into a copy of the parameter:
 * All member variables should have the same value as
 * those of other, but the memory should be completely
 * independent. This function is used in both the copy
 * constructor and the assignment operator for Chains.
 */
void Chain::Copy(Chain const &other)
{
	head_ = nullptr;
	length_ = 0;
	Node *otherCurr = other.head_; // sets the head ptr for chain to copy

	if (otherCurr == nullptr) // finish early if chain to copy is empty
	{
		return;
	}

	Node *curr = new Node(otherCurr->data);
	head_ = curr; // set current head to the start of curr chain
	length_++;
	
	otherCurr = otherCurr->next;

	while (otherCurr != nullptr) // while theres still elements in the other chain
	{
		Node* newNode = new Node(otherCurr->data);
		curr->next = newNode; // make current node new nodes data
		newNode->prev = curr;
		curr = curr->next;
		otherCurr = otherCurr->next; // move other list forwards
		length_++;
	}
}

/**
 * Takes the current chain and renders it into a
 * correctly sized PNG. The blocks in the chain
 * are placed in the image left to right in order
 * of their occurrence in the chain.
 */
PNG Chain::Render()
{
    if (head_ == nullptr)
    {
        return PNG();
    }

    int imgHeight = head_->data.Height();
    int blockWidth = head_->data.Width();
    int imgWidth = blockWidth * 10;

    PNG img;
    img.resize(imgWidth, imgHeight);

    Node* p = head_;
    int blockIndex = 0;
    // traverse list and add each block to PNG()
    while (p->next != nullptr)
    {
        // add the pixels
        p->data.Render(img, imgWidth * blockIndex);

        // increment
        blockIndex++;
        p = p->next;
    }
    return img;
}

/* Modifies the current chain:
 * 1) Find the node with the first (leftmost) block in the unscrambled
 *    image and move it to the head of the chain.
 *	This block is the one whose closest match (to the left) is the
 *	largest.  That is, the distance (using distanceTo) to this block
 *	is big for all other blocks.
 *	For each block B, find the distanceTo B from every other block
 *	and take the minimum of these distances as B's "value".
 *	Choose the block B with the maximum value over all blocks and
 *	swap its node to the head of the chain.
 *
 * 2) Starting with the (just found) first block B, find the node with
 *    the block that is the closest match to follow B (to the right)
 *    among the remaining blocks, move (swap) it to follow B's node,
 *    then repeat to unscramble the chain/image.
 */
void Chain::Unscramble()
{
	/* your code here */
}

/**************************************************
 * IF YOU HAVE DECLARED PRIVATE FUNCTIONS IN       *
 * chain-private.h, COMPLETE THEIR IMPLEMENTATIONS *
 * HERE                                            *
 **************************************************/
