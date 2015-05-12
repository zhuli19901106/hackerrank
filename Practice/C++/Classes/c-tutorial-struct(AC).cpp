#include <iostream>
#include <string>
using namespace std;

typedef struct Student {
	int age;
	string first_name;
	string last_name;
	int standard;
} Student;

int main() {
    Student st;
    
    cin >> st.age >> st.first_name >> st.last_name >> st.standard;
    cout << st.age << " " << st.first_name << " " << st.last_name << " " << st.standard << endl;
    
    return 0;
}
