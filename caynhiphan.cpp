#include <bits/stdc++.h>
#define Main signed main

using namespace std;

template<class T>
struct node {
    T elem;
    node *left, *right;
    node(T x) { elem = x; left = right = 0; }
};

template<class T>
void add(node<T> *&H, T x) {
    if (H == 0) {
        H = new node<T>(x);
        return;
    }
    return add(x < H->elem ? H->left : H->right, x);
}

template<class T>
void draw(node<T> *H, string p = "\n") {
    if (H) {
        draw(H->left, p + '\t');
        cout << p << H->elem;
        draw(H->right, p + '\t');
    }
}

template<class T>
T max_node(node<T> *H) {
    return H->right ? max_node(H->right) : H->elem;
}

template<class T>
void remove(node<T>* &H, T x) {
    if (H == 0) return;
    if (H->elem == x) {
        if (!H->left) { node<T> *p = H; H = H->right; delete p; }
        else if (!H->right) { node<T> *p = H; H = H->left; delete p; }
        else {
            H->elem = max_node(H->left);
            remove(H->left, H->elem);
        }
    }
    else remove(x < H->elem ? H->left : H->right, x);
}

template<class T>
bool find(node<T> *H, T x) {
	if (!H) return false;
    if (H->elem == x) return true;
    if (x < H->elem) return find(H->left, x);
    if (x > H->elem) return find(H->right, x);
    return false;
}
template<class T>
void Menu(node<T>* &H){
	cout << "\n\n\t\t==========MENU==========";
	cout << "\n1. Nhap du lieu.";
	cout << "\n2. Ve cay.";
	cout << "\n3. Xoa mot node.";
	cout << "\n4. Tim kiem node.";
	cout << "\n0. Ket thuc.";
	while (true){	
		int luachon;
		cout << "\nNhap lua chon cua ban: ";
		cin >> luachon;
		if (0 > luachon || 4 < luachon ){
			cout << "Lua chon khong hop le.";
			system("pause");
		}
		else if( luachon == 1){
			T x;
			cout << "Nhap node: ";
			cin >> x;
			add(H, x);
		}
		else if( luachon == 2){
			cout << "Cay nhi phan cua ban: ";
			draw(H);
		}
		else if (luachon == 3){
			T x;
			cout << "Nhap node can xoa: ";
			cin >> x;
			if(find(H, x)){
				remove(H, x);
			}
			else cout << "Khong co node trong cay.";
		}
		else if (luachon == 4){
			T x;
			cout << "Nhap node can tim: ";
			cin >> x;
			if (find(H, x)){
				cout << x << "Co trong cay.";
			}
			else cout << x << "Khong co trong cay";
		}
		else break;
	}
}
void Bai_1(node<int> *H, string ketQua)
{
	if (H != NULL)
	{
		ketQua += " " + std::to_string(H->elem);
		if (H->left == NULL & H->right == NULL)
		{
			cout << ketQua << "\n";
			return;
		}
		Bai_1(H->left, ketQua + "->");
		Bai_1(H->right, ketQua + "->");
	}
}

long Bai_2(node<int> *H, string ketQua)
{
	if (H != NULL)
	{
		ketQua += std::to_string(H->elem);
		if (H->left == NULL & H->right == NULL)
		{
			long lKetQua = std::stol(ketQua);
			return lKetQua;
		}
		long n1 = Bai_2(H->left, ketQua);
		long n2 = Bai_2(H->right, ketQua);

		long sum = n1 + n2;
		return sum;
	}
}
void Bai_3(node<int> *H, string ketQua, int sum, int a, int &d)
{
	if (H != NULL)
	{
		sum += H->elem;
		ketQua += " " + std::to_string(H->elem);
		if (H->left == NULL & H->right == NULL)
		{
			if (sum == a)
			{
				d++;
				cout << "True";
				cout << ketQua << "\n";
				return;
			}
		}
		Bai_3(H->left, ketQua + "->", sum, a, d);
		Bai_3(H->right, ketQua + "->", sum, a, d);
	}
}
	
	
Main() {
	node<int> *root = 0;
	Menu(root);
	system("pause");
	string ketQua;
	cout << "Cac duong di tu goc den la: \n";
	Bai_1(root, ketQua);
	long tong = Bai_2(root, ketQua);
	cout << "\nTong cac so tu goc den la: " << tong;
	int a;
	int dem = 0;
	int sum = 0;
	cout << "\nNhap gia tri a: ";
	cin >> a;
	cout << "Tong "<< a << " co trong cay: ";
	Bai_3(root, ketQua, sum, a, dem);
	if (dem == 0){
		cout << "False";
	}
    return 0;
}
