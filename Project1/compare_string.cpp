#include "compare_string.h"
bool compare_string(std::string left, std::string right) {
	int size_right = right.size();
	int size_left = right.size();
	if (size_right > size_left) {
		for (int i = 0; i < size_left; ++i) {
			if (left[i] > right[i]) {
				return 0;
			}
			else if (left[i] < right[i]) {
				return 1;
			}
			else {

			}
		}
	}
	else {
		for (int i = 0; i < size_right; ++i) {
			if (left[i] > right[i]) {
				return 0;
			}
			else if (left[i] < right[i]) {
				return 1;
			}
			else {

			}
		}
	}
}
