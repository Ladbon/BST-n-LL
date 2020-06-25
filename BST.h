//BST.HPP

//Binary Search Tree <bst.h>

template <typename T>
class BST
{
private:

	//skapa en nod
	struct Node
	{
		T data;
		Node *right;
		Node *left;
	};

	//root nod
	Node *m_root;
	//Föräldrar nod
	Node *parent;
	//kolla storleken.
	int m_size;
	//byt detta värde med roten om du ska ta bort roten
	int replacement;
	//en tillfällig nod för att ändra föräldrar med två barn
	Node* m_temp;
	//unit testing arrays
	int pre[12];
	int post[12];
	int in[12];
	int order_traversal;

	//lägg till en ny nod som inte är rot.
	void Insert(Node *leaf, T data)
	{
		if (data < leaf->data)
		{
			if (leaf->left)
			{
				Insert(leaf->left, data);
			}
			else
			{
				Node* nod = new Node;
				leaf->left = nod;
				leaf->left->data = data;
				leaf->left->left = nullptr;
				leaf->left->right = nullptr;
				++m_size;
			}
		}
		else if (data > leaf->data)
		{
			if (leaf->right)
			{
				Insert(leaf->right, data);
			}
			else
			{
				Node* nod = new Node;
				leaf->right = nod;
				leaf->right->data = data;
				leaf->right->left = nullptr;
				leaf->right->right = nullptr;
				++m_size;
			}
		}
	}
	//kolla efter en nod som inte är roten
	int Search_Nodes(Node *p_node, T data)
	{

		if (data == m_root->data)
		{
			return m_root->data;
		}

		if (data < p_node->data)
		{
			if (p_node->left)
			{
				if (p_node->left->data == data)
				{
					return p_node->left->data;
				}
				else if (p_node->left)
				{
					Search_Nodes(p_node->left, data);
				}
				else
				{
					return 0;
				}
			}
		}
		else if (data > p_node->data)
		{
			if (p_node->right)
			{
				if (p_node->right->data == data)
				{
					return p_node->right->data;
				}
				else if (p_node->right)
				{
					Search_Nodes(p_node->right, data);
				}
				else
				{
					return 0;

				}
			}
		}
		return 0;
	}
	//Erase All
	void Erase_Root(Node* p_node)
	{
		//Post order deleting
		if (p_node)
		{
			Erase_Root(p_node->left);
			Erase_Root(p_node->right);
			--m_size;
			if (p_node != nullptr)
			{
				delete p_node;
				p_node = nullptr;
			}
		}
	}
	Node* Minimum(Node* p_node, Node* p_parent)
	{
		if (!p_node)
		{
			return nullptr;
		}
		while (p_node->right)
		{
			p_parent = p_node;
			p_node = p_node->right;
		}
		return p_node;

	}
	void No_Child(Node* p_node, T data, Node* p_parent)
	{
		//Ta bort lövet!
		//om förälderns data är mindre, nullptr:a den pekaren hos föräldern
		if (!p_node->left && !p_node->right && parent->data < p_node->data)
		{
			parent->right = nullptr;
			delete p_node;
			p_node = nullptr;
			--m_size;
			return;
		}
		//om förälderns data är större, nullptr:a den pekaren hos föräldern
		else if (!p_node->right && !p_node->left && parent->data > p_node->data)
		{
			parent->left = nullptr;
			delete p_node;
			p_node = nullptr;
			--m_size;
			return;
		}
	}
	void One_Child(Node* p_node, T data, Node* p_parent)
	{
		//ta bort en nod med ett barn
		//om vänstra pekaren i noden har ett barn och förälderns data är mer, lägg barnet till vänster om föräldern
		if (p_node->left && !p_node->right && parent->data > p_node->left->data)
		{
			parent->left = p_node->left;
			delete p_node;
			p_node = nullptr;
			--m_size;
			return;
		}
		//om vänstra pekaren i noden har ett barn och förälderns data är mindre, lägg barnet till höger om föräldern
		else if (p_node->left && !p_node->right && parent->data < p_node->left->data)
		{
			parent->right = p_node->left;
			delete p_node;
			p_node = nullptr;
			--m_size;
			return;
		}
		//om högra pekaren i noden har ett barn och förälderns data är mer, lägg barnet till vänster om föräldern
		if (!p_node->left && p_node->right && parent->data > p_node->right->data)
		{
			parent->left = p_node->left;
			delete p_node;
			p_node = nullptr;
			--m_size;
			return;
		}
		//om högra pekaren i noden har ett barn och förälderns data är mindre, lägg barnet till höger om föräldern
		else if (!p_node->left && p_node->right && parent->data < p_node->right->data)
		{
			parent->right = p_node->left;
			delete p_node;
			p_node = nullptr;
			--m_size;
			return;
		}
	}
public:

	BST()
	{
		replacement = 0;
		m_size = 0;
		order_traversal = 0;
		m_root = nullptr;
		parent = nullptr;
		m_temp = nullptr;

	}
	~BST()
	{
		Erase_Root(m_root);
	}
	void Insert_Root(T data)
	{
		if (!m_root)
		{
			m_root = new Node;
			m_root->data = data;
			m_root->right = nullptr;
			m_root->left = nullptr;
			++m_size;
		}
		else
		{
			Insert(m_root, data);
		}
	}
	void Erase(Node* p_node, T data)
	{

		//finns det en rot?
		if (!m_root)
		{
			std::cout << "ERROR: NO NODES\n";
			return;
		}
		//är datat mindre än noden vi kollar på?
		else if (data < p_node->data)
		{
			parent = p_node;
			Erase(p_node->left, data);
		}
		//är datat större än noden vi kollar på?
		else if (data > p_node->data)
		{
			parent = p_node;
			Erase(p_node->right, data);
		}
		//Hittade dig!
		else
		{
			if (m_size == 1)
			{
				Erase_Root(m_root);
			}
			if (replacement > 0)
			{
				if (data < m_root->data)
				{
					m_root->data = replacement;
				}
				else
				{
					m_temp->data = replacement;
					delete m_temp;
					m_temp = nullptr;
				}

				replacement = 0;
			}
			//ett löv
			if (!p_node->left && !p_node->right)
			{
				No_Child(p_node, data, parent);
				return;
			}
			//ett barn
			if (!p_node->left && p_node->right || p_node->left && !p_node->right)
			{
				One_Child(p_node, data, parent);
				return;
			}
			//--------------------------------------------------------------------------------------------------------------------
			//ta bort en nod med två barn
			if (p_node->left && p_node->right)
			{

				Node* temp1 = Minimum(p_node->left, parent);

				if (p_node->data == m_root->data)
				{
					replacement = temp1->data;
					Erase(m_root, temp1->data);
				}
				else
				{
					replacement = temp1->data;
					m_temp = p_node;
					Erase(m_root, temp1->data);

				}

			}
		}

	}
	void ClearTree()
	{
		Erase_Root(m_root);
		m_root = nullptr;
	}
	int Search_root(T data)
	{
		if (m_size == 0)
		{
			return 0;
		}
		else
			return Search_Nodes(m_root, data);


	}
	//hur många noder det finns
	int Size()
	{
		return m_size;
	}
	//kolla igenom trädet i Traversal_Pre_Order
	// Traverse the root, left sub-tree, right sub-tree
	void Pre_Order(Node *p_node)
	{
		if (m_size < 1)
			return;

		if (p_node)
		{

			Pre_Order(p_node->left);
			Pre_Order(p_node->right);
		}
	}
	//Kolla igenom trädet i Traversal_Post_Order
	// Traverse left sub-tree, right sub-tree, root
	void Post_Order(Node *p_node)
	{
		if (m_size < 1)
			return;

		if (p_node)
		{

			Post_Order(p_node->left);
			Post_Order(p_node->right);
		}
	}
	//Kolla igenom trädet i Traversal_In_order
	// Traverse the left sub-tree, root, right sub-tree
	void In_Order(Node* p_node)
	{
		if (m_size < 1)
			return;

		if (p_node)
		{
			In_Order(p_node->left);
			In_Order(p_node->right);
		}
	}
	Node *Get_Root() { return m_root; }
	int Get_Root_Data() { return m_root->data; }
	int Get_Data(Node* p_node) { return p_node->data; }
	int Get_Pre(int p_order) { return pre[p_order]; }
	int Get_Post(int p_order) { return post[p_order]; }
	int Get_In(int p_order) { return in[p_order]; }
	void Nullify_order() { order_traversal = 0; }
};