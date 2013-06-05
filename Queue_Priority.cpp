#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include "Queuewithpriority.h"
using namespace std;

int main(void)
{
    cout << "Test class" << endl;
    QueueWithPriority queue;
    QueueElement qe("l_nya1", LOW);
    queue.putElement(qe);
    queue.putElement(QueueElement("n_nya1", NORMAL));
    queue.putElement("n_nya2", NORMAL);
    queue.putElement("h_nya1", HIGH);
    queue.putElement("h_nya2", HIGH);
    queue.putElement("n_nya3", NORMAL);
    queue.putElement("h_nya3", HIGH);
    queue.putElement("l_nya2", LOW);

    queue.print_queue();
	cout <<"\nFirst element"<< endl;
    cout << queue.getElement() << endl;

	return 0;
}