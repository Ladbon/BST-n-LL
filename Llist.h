//Llist.hpp

template <typename T>
class List
{

private:

	//Nodes
	struct Node
	{
		int data;
		Node *next;
	};
	//Head node, will check everything
	Node *head;
	//Keep track of size with this int.
	unsigned short int m_size;

public:

	//Construct
	List()
	{
		m_size = 0;
		head = nullptr;

	}
	~List()
	{
		Erase_all();
	}
	//PUSH FRONT - put data in the front of the list
	void Push_Front(T data)
	{

		Node* node_front = new Node;

		node_front->next = nullptr;

		node_front->data = data;
		node_front->next = head;
		head = node_front;
		++m_size;
	}
	//PUSH BACK - put data to the back of the list
	void Push_Back(T data)
	{
		if (!head)
		{
			Push_Front(data);
			return;
		}

		Node* node_back = new Node;
		node_back->data = data;

		for (Node *x = head; x != nullptr; x = x->next)
		{
			if (x->next == nullptr)
			{
				x->next = node_back;
				node_back->next = nullptr;
				break;
			}
		}
		++m_size;
	}
	//POP FRONT - delete first node in the list
	void Pop_Front()
	{
		if (Get_size() > 0 && head)
		{
			//create temporary node
			Node *x;
			x = head->next;

			//delete what head was pointing at
			delete head;
			head = nullptr;
			//put head as the second one in line
			head = x;

			--m_size;
		}
		//Print_Nodes();
	}
	//POP BACK - delete the last node in the list
	void Pop_Back()
	{
		//create to node pointers, last and second last node
		Node *last;
		last = head;

		if (Get_size() > 1)
		{

			Node *second_last;


			//find the last and second last node
			while (last->next != nullptr)
			{
				second_last = last;

				last = last->next;
			}

			//tell the second last that its looking at a nullptr and delete the last
			second_last->next = nullptr;
			delete last;
			last = nullptr;
		}

		if (Get_size() == 1)
		{
			delete last;
			last = nullptr;
			head = nullptr;
		}

		if (Get_size() > 0)
		{
			//Print_Nodes();
			--m_size;
		}
	}
	int Get_Data(int p_index)
	{
		Node* index;
		index = head;

		for (int i = 0; i < p_index; i++)
		{
			index = index->next;
		}
		return index->data;
	}
	//ERASE INDIVIDUAL NODE - delete a node between the first and the last
	void Erase_Individual_Node(const int &p_index)
	{

		if (Get_size() > 0)
		{

			//create a temp node for the one your deleting
			Node *erase_node;
			erase_node = head;

			//fix the list with this node
			Node *fix_list;
			fix_list = erase_node;

			//choose which one your deleting

			if (p_index == 0)
			{
				Pop_Front();
				return;
			}
			else if (p_index < 0 || p_index >= Get_size())
			{
				return;
			}

			//Find the one you want to delete
			for (int i = 0; i < p_index; i++)
			{
				fix_list = erase_node;
				erase_node = erase_node->next;
			}
			fix_list->next = erase_node->next;
			delete erase_node;
			erase_node = nullptr;
			--m_size;
		}
	}
	//PRINT THE NODES IN AN ORDERLY FASHION
	void Print_Nodes()
	{
		std::cout << "A list over all the nodes: " << std::endl;

		int counter = 0;
		Node *x;
		x = head;

		if (Get_size() > 0)
		{

			for (int i = 0; i != Get_size(); i++)
			{

				std::cout << counter << ": " << x->data << std::endl;

				if (x->next == nullptr)
				{
					std::cout << "\n";
					counter = 0;
					break;
				}
				counter++;
				x = x->next;
			}
		}
	}
	//GET THE SIZE OF THE LIST
	int Get_size()
	{
		return m_size;
	}
	//ERASE THE WHOLE LIST
	void Erase_all()
	{
		if (m_size < 1)
		{
			std::cout << "Error: Nothing to erase!";
			return;
		}
		else
		{
			while (m_size > 0)
			{
				Pop_Front();
			}
			//while (head->next != nullptr)
			//{
			//	//temporary head
			//	Node *x;

			//	x = head->next;


			//	//delete what the head is looking at
			//	delete head;
			//	//head = nullptr;

			//	//put head as what the first in line was looking at
			//	head = x;

			//	--m_size;

			//	x = nullptr;

			//}
			////head->next = nullptr;
			//delete head;
			//head = nullptr;
			//--m_size;
		}
		//std::cout << "ALL NODES DELETED!\n";
	}
	//Print the size of the list
	void Print_size()
	{
		std::cout << "THERE ARE: " << Get_size() << " NODES.\n";
	}
	//Search for a node with a value
	int Search(T data)
	{
		if (!head)
		{
			std::cout << "ERROR: NO NODES\n";
			return -1;
		}
		Node* temp1;
		temp1 = head;
		int count = 0;

		while (temp1 != nullptr)
		{
			if (temp1->data == data)
			{
				return count;
			}
			temp1 = temp1->next;
			++count;
		}

		return -1;
	}
	int Get_Head()
	{
		return head->data;
	}
	int Get_Last()
	{
		for (Node *x = head; x != nullptr; x = x->next)
		{
			if (x->next == nullptr)
			{
				return x->data;
			}
		}
		return 0;
	}
};
