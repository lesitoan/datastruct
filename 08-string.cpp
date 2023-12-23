#include <iostream>
using namespace std;

void toUpperCase(char* strring);
void toLowerCase(char* strring);
bool validateString(char* string);
void reverse(char* string);
bool compare(char* str1, char* str2);
bool twoStringAnagram(char* str1, char* str2);
void findDuplicatesBitwise (char* str);
void permutationString(char* str, int k);

int main() {
	char name[] = "SiToanDz";
	cout << name << endl;
	toUpperCase(name);
	cout << name << endl;
	toLowerCase(name);
	cout << name << endl;
	char password[] = "toan dz@";
	if(validateString(password)) {
		cout << "Password valid !!!" << endl;
	} else {
		cout << "Password invalid !!!" << endl;
	}
	reverse(name);
	cout << name << endl;
	
	char str1[] = "si toan";
	char str2[] = "si toandz";
	if(compare(str1, str2)) {
		cout << "same" << endl;
	} else {
		cout << "different" << endl;
	}
	
	char name1[] = "toandeptrai";
	char name2[] = "toantraidep1";
	if(twoStringAnagram(name1, name2)) {
		cout << "oke" << endl;
	} else {
		cout << "not ok" << endl;
	} 
	
	findDuplicatesBitwise(name2);
	
	char a[] = "ABC";
	permutationString(a,0);
	
	return 0;
}

void toUpperCase(char* string) {
	for (int i = 0; string[i] != '\0' ; i ++) {
		if(string[i] >= 97) string[i] -= 32;
	}
}

void toLowerCase(char* string) {
	for (int i = 0; string[i] != '\0'; i ++) {
		if(string[i] <= 90) string[i] += 32;
	}
}

bool validateString(char* string) {
	for(int i = 0; string[i] != '\0'; i++) {
		if(!(string[i] >= 65 && string[i] <= 90)
			&& !(string[i] >=97 && string[i] <= 122)
			&& !(string[i] >=48 && string[i] <= 57)) {
			return false;
		}
	}
	return true;
}

void reverse(char* string) {
	int length = 0;
	while(string[length] != '\0') length++;
	length -= 1;
	int j = 0;
	while( j < length) {
		char md = string[length];
		string[length] = string[j];
		string[j] = md;
		j++;
		length--;
	}
}

bool compare(char* str1, char* str2) {
	int i = 0;
	while (str1[i] != '\0' && str2[i] != '\0') {
		if(str1[i] != str2[i]) return false;
		i++;
 	}
 	if(str1[i] != '\0' || str2[i] != '\0') return false;
 	return true;
}

bool twoStringAnagram(char* str1, char* str2) {
	int i = 0, j = 0;
	while(str1[i] != '\0') i++;
	while(str2[j] != '\0') j++;
	if(i != j) return false;
	int arr[26] = {0};
	for(int k = 0; k < i; k++) {
		arr[str1[k] - 97]++;
		arr[str2[k] - 97]--;
	}
	for(int k = 0; k < 26; k++) {
		if(arr[k] != 0) return false;
	}
	return true;
}

void findDuplicatesBitwise (char* str) {
	long int check = 0;
	int x = 0;
	for(int i = 0; str[i] != '\0'; i++) {
		x = 1;
		x = x << (str[i] - 97);
		if((check & x) > 0) {
			cout <<"\"" << str[i] << "\"" << " duplicate" << endl;
		} else {
			check = (check | x);
		}
	}
}

void permutationString (char* str, int k) {
	static char result[10] = {0};
	static int check[10];
	int i;
	if(str[k] == '\0') {
		result[k] = '\0';
		cout << result << endl;
	} else {
		for(int i = 0; str[i] != 0; i++) {
			if(check[i] == 0) {
				result[k] = str[i];
				check[i] = 1;
				permutationString(str, k+1);
				check[i] = 0;
			}
		}
	}
}




