#include "BiTree.h"

void BiTree::add(std::string date) {
	if (root == nullptr) {
		root = new Node(date);
	}
	else {
		add_more(date, root);
	}
}

void BiTree::add_more(std::string date, Node* newNode) {
	if (compare_string(date, newNode->date) == 0) {
		if (newNode->right != nullptr) {
			add_more(date, newNode->right);
		}
		else {
			newNode->right = new Node(date);
		}
	}
	else if (compare_string(date, newNode->date) == 1) {
		if (newNode->left != nullptr) {
			add_more(date, newNode->left);
		}
		else {
			newNode->left = new Node(date);
		}
	}
	else {
		newNode->score++;
	}
}

void BiTree::remove_more(std::string date, Node* deleteNode)
{
	if (date == deleteNode->date) {
		if (deleteNode->score == 1) {
			if (deleteNode->left == nullptr && deleteNode->right != nullptr) {
				Node* current = deleteNode;
				deleteNode = deleteNode->right;
				delete current;
			}
			else if (deleteNode->right == nullptr && deleteNode->left != nullptr) {
				Node* current = deleteNode;
				deleteNode = deleteNode->left;
				delete current;
			}
			else {
				Node* current = deleteNode->left;
				while (current->right != nullptr) {
					current = current->right;
				}
				if (current->left != nullptr) {
					deleteNode->date = current->date;
					deleteNode->score = current->score;
					current = current->left;
				}
				else {
					deleteNode->date = current->date;
					deleteNode->score = current->score;
					delete current;
					current = nullptr;
				}
			}
		}
		else {
			deleteNode->score--;
		}
	}
	else if (date > deleteNode->date) {
		if (deleteNode->right != nullptr) {
			remove_more(date, deleteNode->right);
		}
		else {
			std::cout << "node not found" << std::endl;
		}
	}
	else {
		if (deleteNode->left != nullptr) {
			remove_more(date, deleteNode->left);
		}
		else {
			std::cout << "node not found" << std::endl;
		}
	}
}




void BiTree::remove(std::string date) {
	if (root == nullptr) {
		std::cout << "tree is empty" << std::endl;
	}
	else {
		remove_more(date, root);
	}
}

void BiTree::show()
{
	paint();
	printTree(root, nullptr, false);

}
void BiTree::FoundStr(std::string str) {
	found_str = str;
	flag_found_str = 1;
}

void BiTree::FoundSymbol(char symbol) {
	found_symbol = symbol;
	flag_found_symbol = 1;
}

void BiTree::paint() {
	if (flag_found_str == 1) {
		if (root != nullptr) {
			if (root->date.find(found_str) != std::string::npos) {
				root->color = "Green";
			}

			if (root->right == nullptr && root->left == nullptr) {
				return;
			}
			else if (root->right == nullptr) {
				paint_left_string(root->left);
			}
			else if (root->left == nullptr) {
				paint_right_string(root->left);
			}
			else {
				paint_more_string(root->right, root->left);
			}
		}
	}
	if (flag_found_symbol == 1) {
		if (root != nullptr) {
			if (root->date[0] == found_symbol) {
				if (root->color == "Read") {

				}
				else if (root->color == "Green") {
					root->color = "Read";
				}
				else {
					root->color = "Blue";
				}
			}
			if (root->right == nullptr && root->left == nullptr) {
				return;
			}
			else if (root->right == nullptr) {
				paint_left_char(root->left);
			}
			else if (root->left == nullptr) {
				paint_right_char(root->left);
			}
			else {
				paint_more_char(root->right, root->left);
			}
		}
	}
}

void BiTree::paint_more_string(Node* right, Node* left)
{
	if (right == nullptr && left == nullptr) {
		return;
	}
	else if (right == nullptr) {
		if (left->date.find(found_str) != std::string::npos) {
			left->color = "Green";
		}
		return paint_left_string(left);
	}
	else if (left == nullptr) {
		if (right->date.find(found_str) != std::string::npos) {
			right->color = "Green";
		}
		return paint_more_string(right->right, right->left);
	}
	else {
		if (right->date.find(found_str) != std::string::npos) {
			right->color = "Green";
		}
		if (left->date.find(found_str) != std::string::npos) {
			left->color = "Green";
		}
		return paint_more_string(right->right, right->left), paint_more_string(left->right, left->left);
	}
}


void BiTree::paint_right_string(Node* right)
{
	if (right->date.find(found_str) != std::string::npos) {
		right->color = "Green";
	}
	if (right->right != nullptr && right->left != nullptr) {
		return paint_more_string(right->left, right->right);
	}
	else if (right->right != nullptr && right->left == nullptr) {
		return paint_right_string(right->right);
	}
	else if (right->right == nullptr && right->left != nullptr) {
		return paint_left_string(right->left);
	}
	else {

	}
}


void BiTree::paint_left_string(Node* left)
{
	if (left->date.find(found_str) != std::string::npos) {
		left->color = "Green";
	}
	if (left->right != nullptr && left->left != nullptr) {
		return paint_more_string(left->left, left->right);
	}
	else if (left->right != nullptr && left->left == nullptr) {
		return paint_right_string(left->right);
	}
	else if (left->right == nullptr && left->left != nullptr) {
		return paint_left_string(left->left);
	}
	else {

	}
}

void BiTree::paint_more_char(Node* right, Node* left) {

	if (right == nullptr && left == nullptr) {
		return;
	}
	else if (right == nullptr) {
		if (left->date[0] == found_symbol) {
			if (left->color == "Read") {

			}
			else if (left->color == "Green") {
				left->color = "Read";
			}
			else {
				left->color = "Blue";
			}
		}
		return paint_left_char(left);
	}
	else if (left == nullptr) {
		if (right->date[0] == found_symbol) {
			if (right->color == "Read") {

			}
			else if (right->color == "Green") {
				right->color = "Read";
			}
			else {
				right->color = "Blue";
			}
			
		}
		return paint_more_char(right->right, right->left);
	}
	else {
		if (right->date[0] == found_symbol) {
			if (right->color == "Read") {

			}
			else if (right->color == "Green") {
				right->color = "Read";
			}
			else {
				right->color = "Blue";
			}

		}
		if (left->date[0] == found_symbol) {
			if (left->color == "Read") {

			}
			else if (left->color == "Green") {
				left->color = "Read";
			}
			else {
				left->color = "Blue";
			}
		}
		return paint_more_char(right->right, right->left), paint_more_char(left->right, left->left);
	}
}

void BiTree::paint_right_char(Node* right) {
	if (right->date[0] == found_symbol) {
		if (right->color == "Read") {

		}
		else if (right->color == "Green") {
			right->color = "Read";
		}
		else {
			right->color = "Blue";
		}

	}
	if (right->right != nullptr && right->left != nullptr) {
		return paint_more_char(right->left, right->right);
	}
	else if (right->right != nullptr && right->left == nullptr) {
		return paint_right_char(right->right);
	}
	else if (right->right == nullptr && right->left != nullptr) {
		return paint_left_char(right->left);
	}
	else {

	}
}

void BiTree::paint_left_char(Node* left) {
	if (left->date[0] == found_symbol) {
		if (left->color == "Read") {

		}
		else if (left->color == "Green") {
			left->color = "Read";
		}
		else {
			left->color = "Blue";
		}
	}
	if (left->right != nullptr && left->left != nullptr) {
		return paint_more_char(left->left, left->right);
	}
	else if (left->right != nullptr && left->left == nullptr) {
		return paint_right_char(left->right);
	}
	else if (left->right == nullptr && left->left != nullptr) {
		return paint_left_char(left->left);
	}
	else {

	}
}
BiTree::BiTree()
{

}


BiTree ::~BiTree() {

}

