#include <iostream>
#include <time.h> 
#include <Windows.h>
#include <conio.h>
#include <stdio.h>
#include "compare_string.h"



enum ColorConsole {
    Blue = 1,
    Green = 2,
    Read = 12,
    White = 7
};
class Node {
public:
	std::string date;
    std::string color;
	int score;
	Node* right;
	Node* left;
	Node(std::string date) {
        color = "White";
		this->date = date;
		right = nullptr;
		left = nullptr;
		score = 1;
	}
};

class BiTree {
	Node* root;
    std::string found_str;
    char found_symbol;
    bool flag_found_str = 0;
    bool flag_found_symbol = 0;
	void add_more(std::string date, Node* Newroot);
	void remove_more(std::string date, Node * deleteNode);
    void paint_more_char(Node* left, Node* right);
    void paint_left_char(Node* left);
    void paint_right_char(Node* right);
    void paint_more_string(Node* left, Node* right);
    void paint_left_string(Node* left);
    void paint_right_string(Node* right);
    struct Trunk
    {
        Trunk* prev;
        std::string str;

        Trunk(Trunk* prev, std::string str)
        {
            this->prev = prev;
            this->str = str;
        }
    };

    // Вспомогательная функция для печати ветвей бинарного дерева
    void showTrunks(Trunk* p)
    {
        if (p == nullptr) {
            return;
        }

        showTrunks(p->prev);
        std::cout << p->str;
    }

    void printTree(Node* root, Trunk* prev, bool isLeft)
    {
        if (root == nullptr) {
            return;
        }

        std::string prev_str = "    ";
        Trunk* trunk = new Trunk(prev, prev_str);

        printTree(root->right, trunk, true);

        if (!prev) {
            trunk->str = "———";
        }
        else if (isLeft)
        {
            trunk->str = ".---";
            prev_str = "   |";
        }
        else {
            trunk->str = "`---";
            prev->str = prev_str;
        }

        showTrunks(trunk);
        HANDLE hConsole;
        hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        if (root->color == "Green") {
            SetConsoleTextAttribute(hConsole, Green);
            std::cout << " " << root->date << std::endl;
            SetConsoleTextAttribute(hConsole, White);
        }
        else if (root->color == "Blue") {
            SetConsoleTextAttribute(hConsole, Blue);
            std::cout << " " << root->date << std::endl;
            SetConsoleTextAttribute(hConsole, White);
        }
        else if (root->color == "Read") {
            SetConsoleTextAttribute(hConsole, Read);
            std::cout << " " << root->date << std::endl;
            SetConsoleTextAttribute(hConsole, White);
        }
        else {
            SetConsoleTextAttribute(hConsole, White);
            std::cout << " " << root->date << std::endl;
        }
        if (prev) {
            prev->str = prev_str;
        }
        trunk->str = "   |";

        printTree(root->left, trunk, false);
    }

public:
	void add(std::string date);
	void remove(std::string date);
	void show();
    void paint();
    void FoundStr(std::string str);
    void FoundSymbol(char symbol);
	BiTree();
	~BiTree();
};



