//
// COMP2711,8801 Computer Programming 2
// Flinders University
//

#include "Rolodex.h"
using namespace std;

/**
 * Creates a new empty Rolodex.
 */
Rolodex::Rolodex()
{
    // Add code here
    //sentinel = nullptr;
    sentinel->value_ = "";
    sentinel->next_ = sentinel;
    sentinel->prev_ = sentinel;
    current = sentinel;
    len = 0;
}

/**
 * Returns true if the Rolodex is positioned before the first card.
 */
bool Rolodex::isBeforeFirst() const
{
    // Replace with real code
    if(current == sentinel)
    {
        return true;
    }

    return false;
}

/**
 * Returns true if the Rolodex is positioned after the last card.
 */
bool Rolodex::isAfterLast() const
{
    // Replace with real code
    if(current == sentinel)
    {
        return true;
    }

    return false;
}

/**
 * Rotates the Rolodex one card forwards.
 */
void Rolodex::rotateForward()
{
    // Add code here
    current = current->next_;
}

/**
 * Rotates the Rolodex one card backwards.
 */
void Rolodex::rotateBackward()
{
    // Add code here
    current = current->prev_;
}

/**
 * Returns the value of the current card.
 */
const std::string& Rolodex::currentValue() const
{
    // Temporary hack to keep the compiler happy
    // Replace both lines with real code
    static std::string dummy;

    dummy = current->value_;

    return dummy;
}

/**
 * Inserts a new card after the current card and positions the Rolodex
 * at the newly inserted card.
 *
 * @param value The value to insert into a new card.
 */
void Rolodex::insertAfterCurrent(const std::string& value)
{
    // Add code here
    RolodexItem* temp = new RolodexItem;
    if(len == 0)
    {
        temp->value_ = value;
        temp->prev_ = sentinel;
        temp->next_ = sentinel;
        sentinel->prev_ = temp;
        sentinel->next_ = temp;
        current = temp;
        len += 1;
    }
    else if(len >= 1)
    {
        temp->value_ = value;
        temp->prev_ = current;
        temp->next_ = current->next_;
        current->next_->prev_ = temp;
        current->next_ = temp;
        current = temp;
        len += 1;
    }
}

/**
 * Inserts a new card before the current card and positions the Rolodex
 * at the newly inserted card.
 *
 * @param value The value to insert into a new card.
 */
void Rolodex::insertBeforeCurrent(const std::string& value)
{
    // Add code here
    RolodexItem* temp = new RolodexItem;

    if(len == 0)
    {
        temp->value_ = value;
        temp->prev_ = sentinel;
        temp->next_ = sentinel;
        sentinel->prev_ = temp;
        sentinel->next_ = temp;
        current = temp;
        len += 1;
    }
    else if(len >= 1)
    {
        temp->value_ = value;
        temp->prev_ = current->prev_;
        temp->next_ = current;
        current->prev_->next_ = temp;
        current->prev_ = temp;
        current = temp;
        len += 1;
    }
}

//remove function
void Rolodex::removeCurrent(const std::string &value) {
    if (len == 0)
    {
        return;
    }
    else
    {
        RolodexItem *temp = current;
        current->prev_->next_ = current->next_;
        current->next_->prev_ = current->prev_;

        if(current->next_ != sentinel)
        {
            current = temp->next_;
        }
        else
        {
            current = temp->prev_;
        }

        delete(temp);
    }
}