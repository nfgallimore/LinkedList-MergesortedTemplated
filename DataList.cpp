#include "DataList.h"
#include <iostream>
using namespace std;

DataList::DataList()
{
	head = nullptr;
}

DataList::~DataList()
{
	// head->next = nullptr;
	// delete(head);
}

bool DataList::append(int value)
{
	try {
		DataNode* fred = new DataNode();
		fred->value = value;
		fred->next = nullptr;
		if (head == nullptr) {
			// empty list, just simply assign the new node's address to head
			head = fred;
			
			return true;
		}
		else {
			// not empty list
			// find the last node
			DataNode* tmp = head;
			while (tmp->next != nullptr) {
				tmp = tmp-> next;
			}
			tmp->next = fred;
		}
		return true;
	} catch(...) {
		return false;
	}
}


void DataList::print()
{
	DataNode* tmp = head;
	while(tmp) {

		cout << tmp->value << " ";
		tmp = tmp->next;
	}

	cout << endl;
}

bool DataList::search(int value) {
	DataNode* tmp;
	tmp = head;
	while (tmp) {
		if (tmp->value == value) {
			return true;
		}
		tmp = tmp->next;
	}
	return false;
}

bool DataList::remove(int value) {
	DataNode* tmp, *prev;
	tmp = head;
	prev = nullptr;
	while (tmp) {
		if (tmp->value == value) {
			// deletion
			if (prev == nullptr) {
				// it is the first element
				head = tmp->next;
				delete tmp;
			}
			else {
				prev->next = tmp->next;
				delete tmp;
			}
			return true;
		}
		prev = tmp;
		tmp = tmp->next;
	}
	return false;
}

void DataList::clear() {
	DataNode *tmp;
	while (head) {
		tmp = head;
		head = head->next;
		delete tmp;
	}
}

bool DataList::insert(int value) {
	try {
		DataNode* tmp, *prev;
		// create a new node
		DataNode* newNode = new DataNode();
		newNode->value = value;
		newNode->next = nullptr;

		// if list is empty
		if (head == nullptr) {
			head = newNode;
			newNode-> next = nullptr;
		}
		// searching the existing node value until the node's value greater than or equal to value
		tmp = head;
		prev = nullptr;
		while (tmp) {
			if (tmp->value >= value) {
				// insert the value before the node tmp and after the node prev
				if (prev == nullptr) {
					newNode->next = head;
					head = newNode;
				}
				else {
					newNode->next = tmp;
					prev->next = newNode;
				}
				return true; // after insertion
			}
			prev = tmp;
			tmp = tmp->next;
		}

		// at this point, there is no value in the list greater than or equal to value
		// it means we insert to end at this point ,
		// prev pointing to the last node
		prev->next = newNode;
		return true;

	}
	catch (...) 
	{
		return false;
	}
}

void DataList::sort() {
	DataNode* headCopy, *tmp;
	headCopy = head;
	head = nullptr;

	tmp = headCopy;

	while (tmp) {
		insert(tmp->value);
		tmp = tmp->next;
	}
	tmp = head;
	head = headCopy;
	clear();
	head = tmp;
}