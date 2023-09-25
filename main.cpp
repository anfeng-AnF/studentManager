#include"StudentManager.h"
#include"admin.h"

int main() {
	StudentManager* stu = nullptr;
	Admin a(1, "Bronya");
	stu = &a;
	stu->initMenu();
	return 0;
}