#ifndef QUEUEWITHPRIORITY_H
#define QUEUEWITHPRIORITY_H
//#define _HAS_ITERATOR_DEBUGGING 0
#include <list>
#include <string>
#include <iostream>
using namespace std;

typedef enum
{
    LOW,
    NORMAL,
    HIGH } ElementPriority;

/** QueueElement structure */
struct QueueElement
{
    /// Priority enum #ElementPriority
    ElementPriority priority;
    /// Element name
    string name;
    /** Default constructor */
    QueueElement(string _name, ElementPriority _priority);
    /** Alternate constructor */
    QueueElement(char _name[], ElementPriority _priority);
    /** Overload < for sort. Desperated. */
    friend bool operator<(const QueueElement &leftel, const QueueElement &rightel);
    /// Overload << for iostream
    friend ostream& operator<<( ostream &ostr, const QueueElement &L );
};

/// Container type for #QueueWithPriority
typedef list<QueueElement> __queue_type;
/// Container iterator type for #QueueWithPriority
typedef __queue_type::iterator __queue_iterator_type;
/// Container reverse iterator type for #QueueWithPriority
typedef __queue_type::reverse_iterator __queue_reverse_iterator_type;

/** QueueWithPriority container for QueueElement */
class QueueWithPriority
{
private:
    __queue_type __queue;
public:
    /// Constructor
    QueueWithPriority(void);
    /// Desctructor
    ~QueueWithPriority(void);
    /// put #QueueElement
    void putElement(const QueueElement &element);
    /// put char name[] and #ElementPriority priority
    void putElement(const char name[], ElementPriority priority);
    /// return first #QueueElement
    QueueElement getElement(void);
    int size(void){
        return __queue.size();
    }
    /// for human print #QueueWithPriority
    void print_queue(void);

};
/** @} */


/**

*/
#include "queuewithpriority.h"
#include <iostream>
using namespace std;


QueueElement::QueueElement(string _name, ElementPriority _priority)
{
    name=_name;
    priority=_priority;
}

QueueElement::QueueElement(char _name[], ElementPriority _priority)
{
    name = string(_name),
    priority = _priority;
}

bool operator<(const QueueElement &leftel, const QueueElement &rightel)
{
    return (leftel.priority < rightel.priority);
}

ostream& operator<<( ostream &ostr, const QueueElement &L )
{
    char *priority_name;
    switch (L.priority)
    {
    case LOW: priority_name = "LOW";
        break;
    case NORMAL: priority_name = "NORMAL";
        break;
    case HIGH: priority_name = "HIGH";
        break;
    default: priority_name = "None";
    }

    ostr << "Q("<< L.name << "," << priority_name << ")";
    return ostr;
}

/// Constructor
QueueWithPriority::QueueWithPriority()
{

}
/// Destructor
QueueWithPriority::~QueueWithPriority()
{

}

void QueueWithPriority::putElement(const QueueElement &element)
{
    __queue_iterator_type iter;
    int check;
    bool insert = false;
    if ((!__queue.empty()) & (element.priority != LOW))
    {
        for(iter=__queue.begin(); iter != __queue.end(); iter++)
        {
            check = iter->priority - element.priority;
            if (check == -1)
            {
                __queue.insert(iter, element);
                insert = true;
                break;
            }
        }
        if (!insert)
        {
            __queue.push_front(element);
        }
    } else {
        __queue.push_back(element);
    }
}

void QueueWithPriority::putElement(const char name[], ElementPriority priority)
{
    putElement(QueueElement(name, priority));
}

QueueElement QueueWithPriority::getElement()
{
    if (!__queue.empty())
    {
        QueueElement qe = __queue.front();
        __queue.pop_front();
        return qe;
    } else {
        cerr << "No more QueueElement in QueueWithPriority!"<< endl;
        throw "fail";
    }

}

void QueueWithPriority::print_queue()
{
    __queue_iterator_type iter;
    for(iter=__queue.begin(); iter != __queue.end();iter++)
    {
        cout<< *iter<< "\n";
    }
}
/** */

#endif // QUEUEWITHPRIORITY_H