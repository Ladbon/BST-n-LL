#include "stdafx.h"
#include <iostream>
#include "BST.h"
#include "Llist.h"
#include "unit.h"
#include <string>
#include "vld.h"

#pragma comment(lib, "vld.lib")

int main(int argc, char* argv[])
{
	BST<int> *bst = new BST < int >;
	List<int> list;

	Unit<int> unit;
	int data = 3;
	int index = 3;
	std::string message = " ";
	bool running = true;
	int check = 0;

	std::cout << "\n\n\nUNIT TESTING INITIATED\n";


	std::cout << "\n\n---------------------------------------";
	std::cout << "\n\n\nTESTING LINKED LIST\n\n";
	std::cout << "---------------------------------------";

	//----------------------------------------
	//LINKED LIST

	//CREATE LINKED LIST
	list.Push_Front(1);
	list.Push_Front(1);
	list.Push_Front(1);
	list.Push_Back(4);
	list.Push_Back(5);
	list.Push_Back(6);

	//TEST PUSH_FRONT
	message = "\n\n\nTESTING PUSH_FRONT: ";
	list.Push_Front(3);
	unit.verify(3, list.Get_Head(), message);

	//TEST PUSH_BACK
	message = "\n\n\nTESTING PUSH_FRONT: ";
	list.Push_Back(2);
	unit.verify(2, list.Get_Last(), message);

	//TEST POP_FRONT
	message = "\n\n\nTESTING POP_FRONT: ";
	list.Pop_Front();
	unit.verify(1, list.Get_Head(), message);

	//TEST POP_BACK
	message = "\n\n\nTESTING POP_BACK: ";
	list.Pop_Back();
	unit.verify(6, list.Get_Last(), message);

	//ERASE A L_LIST NODE
	message = "\n\n\nTESTING ERASING INDIVIDUAL NODE AND SEARCH: ";
	list.Erase_Individual_Node(index);
	unit.verify(-1, list.Search(4), message);

	//PRINT SIZE OF L_LIST
	message = "\n\n\nTESTING GET_SIZE: ";
	data = list.Get_size();
	unit.verify(5, list.Get_size(), message);
	   
	list.Erase_all();

	//-------------------------------------
	//-------------------------------------
	//-------------------------------------
	//-------------------------------------

	//BINARY SEARCH TREE
	std::cout << "\n\n---------------------------------------";
	std::cout << "\n\n\nTESTING BINARY SEARCH TREE\n\n";
	std::cout << "---------------------------------------";


	//CREATE BST LIST
	bst->Insert_Root(5);

	//TEST INSERT
	message = "\n\n\nTESTING INSERT: ";
	unit.verify(5, bst->Get_Root_Data(), message);


	bst->Insert_Root(15);
	bst->Insert_Root(4);
	bst->Insert_Root(13);
	bst->Insert_Root(25);
	bst->Insert_Root(75);
	bst->Insert_Root(14);
	bst->Insert_Root(3);
	bst->Insert_Root(2);
	bst->Insert_Root(1);
	bst->Insert_Root(6);
	bst->Insert_Root(9);
	bst->Insert_Root(7);

	//ERASE SPECIFIC BST NODE
	message = "\n\n\nTESTING ERASE_INDIVIDUAL NODE: ";
	bst->Erase(bst->Get_Root(), 5);
	unit.verify(4, bst->Get_Root_Data(), message);


	//TEST BST SEARCH
	check = bst->Search_root(data);
	message = "\n\n\nTESTING SEARCH: ";
	unit.verify(bst->Get_Root_Data(), check, message);

	//CHECK HOW MANY NODES
	message = "\n\n\nTESTING GET_SIZE: ";
	unit.verify(12, bst->Size(), message);


	//TEST TRAVERSAL PRE ORDER
	std::cout << std::endl;
	message = "\nTESTING TRAVERSAL PRE ORDER: ";
	bst->Pre_Order(bst->Get_Root());

	for (int i = 11; i > -1; i--)
	{
		list.Push_Front(bst->Get_Pre(i));

	}

	for (int i = 0; i < 12; i++)
	{
		unit.verify(list.Get_Data(i), bst->Get_Pre(i), message);
	}
	std::cout << std::endl;
	bst->Nullify_order();
	list.Erase_all();



	//TEST TRAVERSAL POST
	message = "\nTRAVERSAL POST ORDER: ";
	bst->Post_Order(bst->Get_Root());

	for (int i = 11; i > -1; i--)
	{
		list.Push_Front(bst->Get_Post(i));

	}

	for (int i = 0; i < 12; i++)
	{
		unit.verify(list.Get_Data(i), bst->Get_Post(i), message);
	}
	std::cout << std::endl;
	bst->Nullify_order();
	list.Erase_all();
	std::cout << std::endl;



	//TEST TRAVERSAL IN
	message = "\nTRAVERSAL IN ORDER: ";
	bst->In_Order(bst->Get_Root());

	for (int i = 11; i > -1; i--)
	{
		list.Push_Front(bst->Get_In(i));

	}

	for (int i = 0; i < 12; i++)
	{
		unit.verify(list.Get_Data(i), bst->Get_In(i), message);
	}
	std::cout << std::endl;
	bst->Nullify_order();
	std::cout << std::endl;
	

	list.Erase_all();


	//ERASE BST TREE
	bst->ClearTree();
	std::cin >> data;

	message.clear();
	delete bst;
	return 0;
}

