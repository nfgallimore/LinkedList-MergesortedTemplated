#ifndef CHARLIST_HPP
#define CHARLIST_HPP

/**** if the order is required, use insert() only ***///
class CharList
{
	private:
		template <class T>
		struct Node
		{
			T value;
			Node* next;
		};

	public:

		// constructor
		CharList();	

		// print the list
		void displayList() const;	

		// sorts the list
		void sort();

		// append a value ot the end of the list
		template <class T>
		bool appendNode(T const &value);

		// insert value between. This method will be called if you want to maintain theo rder of all values
		template <class T> 
		void insertNode(T const &value);

		// delete value from the list. return true of successful, false if failed
		template <class T> 
		bool deleteNode(T const &value);

		// search a value in the list, return true if found
		template <class T> 
		bool search(T const &value);
	
		// destructor
		virtual ~CharList();
		
	private:
		Node* head<char>;
};

#endif // CHARLIST_HPP