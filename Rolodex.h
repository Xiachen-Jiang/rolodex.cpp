//
// COMP2711,8801 Computer Programming 2
// Flinders University
//

#ifndef ROLODEX_H
#define ROLODEX_H

#include <string>
using namespace std;

struct RolodexItem {
    string value_;
    RolodexItem* next_ ;
    RolodexItem* prev_ ;
};

class Rolodex {
public:
    /**
     * Creates a new empty Rolodex.
     */
    explicit Rolodex();

    RolodexItem* add_item(string val)
    {
        RolodexItem* temp = new RolodexItem();
        temp->value_ = val;
        temp->prev_ = nullptr;
        temp->next_ = nullptr;

        return temp;
    }

    /**
     * Returns true if the Rolodex is positioned before the first card.
     */
    bool isBeforeFirst() const;

    /**
     * Returns true if the Rolodex is positioned after the last card.
     */
    bool isAfterLast() const;

    /**
     * Rotates the Rolodex one card forwards.
     */
    void rotateForward();

    /**
     * Rotates the Rolodex one card backwards.
     */
    void rotateBackward();

    /**
     * Returns the value of the current card.
     */
    const std::string& currentValue() const;
    /**
     * Inserts a new card after the current card and positions the Rolodex
     * at the newly inserted card.
     *
     * @param value The value to insert into a new card.
     */
    void insertAfterCurrent(const std::string& value);

    /**
     * Inserts a new card before the current card and positions the Rolodex
     * at the newly inserted card.
     *
     * @param value The value to insert into a new card.
     */
    void insertBeforeCurrent(const std::string& value);

    void removeCurrent(const std::string& value);

private:
    // Add instance variables here
    RolodexItem* current = new RolodexItem;
    RolodexItem* sentinel = new RolodexItem;
    int len;
};

#endif //ROLODEX_H
