//Reading from a text file code.
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

class Admin
{
public:
	int Aid;
	string Aname;
	string pass;
	Admin* pnext;
};
class clistAdmin
{
public:
	Admin* phead;
	Admin* ptail;
	clistAdmin() {
		phead = NULL;
		ptail = NULL;
	}

	void Attach(Admin* pnn) {
		if (phead == NULL) {
			phead = pnn;
			ptail = pnn;
		}
		else {
			ptail->pnext = pnn;
			ptail = pnn;
		}
	}

	void Display()
	{
		Admin* ptrap;
		ptrap = phead;
		while (phead != NULL) {
			cout << ptrap->Aid << ",";
			cout << ptrap->Aname << ",";
			cout << ptrap->pass << endl;

			ptrap = ptrap->pnext;
		}
	}

	~clistAdmin() {
		Admin* ptrap;
		ptrap = phead;
		while (phead != NULL) {
			phead = ptrap->pnext;
			ptrap->pnext = NULL;
			delete[] ptrap;
			ptrap = phead;
		}
	}

	void writeToFile()
	{
		ofstream AdminsFile;
		AdminsFile.open("C:/Users/omar ahmed/Desktop/projectLap/projectLap/Admin.txt");

		if (AdminsFile.is_open())
		{
			Admin* pTrav = phead;

			AdminsFile << "ID" << ",";
			AdminsFile << "Name" << ",";
			AdminsFile << "Password" << endl;

			while (pTrav != NULL)
			{
				AdminsFile << pTrav->Aid << ",";
				AdminsFile << pTrav->Aname << ",";
				AdminsFile << pTrav->pass << endl;

				pTrav = pTrav->pnext;
			}

			AdminsFile.close();
		}
	}
};

class Order
{
public:
	int Pid;
	int Cid;
	Order* pnext;
};
class clistOrders
{
public:
	Order* phead;
	Order* ptail;
	clistOrders() {
		phead = NULL;
		ptail = NULL;
	}

	void Attach(Order* pnn) {
		if (phead == NULL) {
			phead = pnn;
			ptail = pnn;
		}
		else {
			ptail->pnext = pnn;
			ptail = pnn;
		}
	}

	void Display()
	{
		Order* ptrap;
		ptrap = phead;
		while (phead != NULL) {
			cout << ptrap->Cid << ",";
			cout << ptrap->Pid << endl;
			ptrap = ptrap->pnext;
		}
	}

	~clistOrders() {
		Order* ptrap;
		ptrap = phead;
		while (phead != NULL) {
			phead = ptrap->pnext;
			ptrap->pnext = NULL;
			delete[] ptrap;
			ptrap = phead;
		}
	}

	void Remove(int id, int cid , int &q)
	{
		Order* pTrav = phead;
		Order* pB = NULL;

		while (pTrav != NULL)
		{
			if (pTrav->Pid == id && cid == pTrav->Cid)
			{
				q++;
				if (pTrav != phead) // Not the first node
				{
					if (pTrav != ptail) // Not the last node
					{
						pB->pnext = pTrav->pnext;
						pTrav->pnext = NULL;
						delete pTrav;
					}
					else // Last node
					{
						ptail = pB;
						pB->pnext = NULL;
						delete pTrav;
					}
				}
				else // First node
				{
					phead = pTrav->pnext;
					pTrav->pnext = NULL;
					delete pTrav;
				}

				break; // Exit the loop after removing the node
			}
			else
			{
				pB = pTrav;
				pTrav = pTrav->pnext;
			}
		}
	}

	void writeToFile()
	{
		ofstream OrdersFile;
		OrdersFile.open("C:/Users/omar ahmed/Desktop/projectLap/projectLap/Orders.txt");

		if (OrdersFile.is_open())
		{
			Order* pTrav = phead;

			OrdersFile << "Customer ID" << ",";
			OrdersFile << "Product ID" << endl;

			while (pTrav != NULL)
			{
				OrdersFile << pTrav->Cid << ",";
				OrdersFile << pTrav->Pid << endl;

				pTrav = pTrav->pnext;
			}

			OrdersFile.close();
		}
	}
};

class Customer
{
public:
	int Cid;
	string Cname;
	string pass;
	Customer* pnext;
};
class clistCustomer
{
public:
	Customer* phead;
	Customer* ptail;
	clistCustomer() {
		phead = NULL;
		ptail = NULL;
	}

	void Attach(Customer* pnn) {
		if (phead == NULL) {
			phead = pnn;
			ptail = pnn;
		}
		else {
			ptail->pnext = pnn;
			ptail = pnn;
		}
	}

	void Display()
	{
		Customer* ptrap;
		ptrap = phead;
		while (phead != NULL) {
			cout << ptrap->Cid << ",";
			cout << ptrap->Cname << ",";
			cout << ptrap->pass << endl;

			ptrap = ptrap->pnext;
		}
	}

	~clistCustomer() {
		Customer* ptrap;
		ptrap = phead;
		while (phead != NULL) {
			phead = ptrap->pnext;
			ptrap->pnext = NULL;
			delete[] ptrap;
			ptrap = phead;
		}
	}

	void writeCustomerToFile()
	{
		ofstream CustomersFile;
		CustomersFile.open("C:/Users/omar ahmed/Desktop/projectLap/projectLap/Customer.txt");

		if (CustomersFile.is_open())
		{
			Customer* pTrav = phead;

			CustomersFile << "ID" << ",";
			CustomersFile << "Name" << ",";
			CustomersFile << "Password" << endl;

			while (pTrav != NULL)
			{
				CustomersFile << pTrav->Cid << ",";
				CustomersFile << pTrav->Cname << ",";
				CustomersFile << pTrav->pass << endl;

				pTrav = pTrav->pnext;
			}

			CustomersFile.close();
		}
	}
};

class Product
{
public:
	int Pid;
	string Pname;
	int stock;
	int price;
	int exp_month;
	int exp_year;
	Product* pnext;
};
class clistproduct
{
public:
	Product* phead;
	Product* ptail;
	clistproduct() {
		phead = NULL;
		ptail = NULL;
	}

	void Attach(Product* pnn) {
		if (phead == NULL) {
			phead = pnn;
			ptail = pnn;
			ptail->pnext = NULL;
		}
		else {
			ptail->pnext = pnn;
			ptail = pnn;
			ptail->pnext = NULL;
		}
	}

	void Display()
	{
		Product* ptrap;
		ptrap = phead;
		while (ptrap != NULL) {
			cout << "ID: " << ptrap->Pid << " , ";
			cout << "NAME: " << ptrap->Pname << " , ";
			cout << "STOCK: " << ptrap->stock << " , ";
			cout << "PRICE: " << ptrap->price << " , ";
			cout << "EXPIRE MONTH: " << ptrap->exp_month << " , ";
			cout << "EXP YEAR: " << ptrap->exp_year << endl << "======================================================================" << endl;
			ptrap = ptrap->pnext;
		}
	}
	void DisplayInStock()
	{
		Product* ptrap;
		ptrap = phead;
		while (ptrap != NULL) {
			if (ptrap->stock > 0)
			{
				cout << "ID: " << ptrap->Pid << " , ";
				cout << "NAME: " << ptrap->Pname << " , ";
				cout << "STOCK: " << ptrap->stock << " , ";
				cout << "PRICE: " << ptrap->price << " , ";
				cout << "EXPIRE MONTH: " << ptrap->exp_month << " , ";
				cout << "EXP YEAR: " << ptrap->exp_year << endl << "======================================================================" << endl;
			}

			ptrap = ptrap->pnext;
		}
	}

	~clistproduct() {
		Product* ptrap;
		ptrap = phead;
		while (phead != NULL) {
			phead = ptrap->pnext;
			ptrap->pnext = NULL;
			delete[] ptrap;
			ptrap = phead;
		}
	}

	void writeToFile()
	{
		ofstream ProductsFile;
		ProductsFile.open("C:/Users/omar ahmed/Desktop/projectLap/projectLap/Product.txt");

		if (ProductsFile.is_open())
		{
			Product* pTrav = phead;

			ProductsFile << "ID" << ",";
			ProductsFile << "Name" << ",";
			ProductsFile << "Stock" << ",";
			ProductsFile << "Price" << ",";
			ProductsFile << "Exp Month" << ",";
			ProductsFile << "Exp Year" << endl;

			while (pTrav != NULL)
			{
				ProductsFile << pTrav->Pid << ",";
				ProductsFile << pTrav->Pname << ",";
				ProductsFile << pTrav->stock << ",";
				ProductsFile << pTrav->price << ",";
				ProductsFile << pTrav->exp_month << ",";
				ProductsFile << pTrav->exp_year << endl;

				pTrav = pTrav->pnext;
			}

			ProductsFile.close();
		}
	}
};

void readProductsFromList(clistproduct& Products)
{
	string ProductsText;
	ifstream ProductsFile;
	ProductsFile.open("C:/Users/omar ahmed/Desktop/projectLap/projectLap/Product.txt");
	if (ProductsFile.is_open())
	{
		string temp = "";
		string temp1[6];
		int k = 0;
		int ct = 0;
		//cout << "File is Open" << endl;

		while (getline(ProductsFile, ProductsText))
		{
			if (ct > 0)
			{
				for (int i = 0; i < ProductsText.length(); i++)
				{
					if (ProductsText[i] == ',')
					{
						temp.clear();
						k++;
					}
					else
					{
						temp += ProductsText[i];
						temp1[k] += ProductsText[i];
					}
				}
				k = 0;
				Product* pnn = new Product;
				pnn->Pid = stoi(temp1[0]);
				pnn->Pname = temp1[1];
				pnn->stock = stoi(temp1[2]);
				pnn->price = stoi(temp1[3]);
				pnn->exp_month = stoi(temp1[4]);
				pnn->exp_year = stoi(temp1[5]);
				pnn->pnext = NULL;
				Products.Attach(pnn);

				for (int h = 0; h < 6; h++)
				{
					temp1[h].clear();
				}
			}
			ct++;
		}
	}
	ProductsFile.close();
	//cout << "-----LIST----" << endl;
	//Products.DisplayAllProducts();
}

void readCustomerFromList(clistCustomer& Customers)
{
	string CustomersText;
	ifstream CustomersFile;

	CustomersFile.open("C:/Users/omar ahmed/Desktop/projectLap/projectLap/Customer.txt");
	if (CustomersFile.is_open())
	{
		string temp = "";
		string temp1[3];
		int k = 0;
		int ct = 0;
		//cout << "File is Open" << endl;

		while (getline(CustomersFile, CustomersText))
		{
			if (ct > 0)
			{
				for (int i = 0; i < CustomersText.length(); i++)
				{
					if (CustomersText[i] == ',')
					{
						temp.clear();
						k++;
					}
					else
					{
						temp += CustomersText[i];
						temp1[k] += CustomersText[i];
					}
				}
				k = 0;
				Customer* pnn = new Customer;
				pnn->Cid = stoi(temp1[0]);
				pnn->Cname = temp1[1];
				pnn->pass = temp1[2];
				pnn->pnext = NULL;
				Customers.Attach(pnn);

				for (int h = 0; h < 3; h++)
				{
					temp1[h].clear();
				}
			}
			ct++;
		}
	}
	CustomersFile.close();
	//cout << "-----LIST----" << endl;
	//Customers.DisplayAllCustomers();
}

void readOrderFromList(clistOrders& Orders)
{
	string OrdersText;
	ifstream OrdersFile;

	OrdersFile.open("C:/Users/omar ahmed/Desktop/projectLap/projectLap/Orders.txt");
	if (OrdersFile.is_open())
	{
		string temp = "";
		string temp1[2];
		int k = 0;
		int ct = 0;
		//cout << "File is Open" << endl;

		while (getline(OrdersFile, OrdersText))
		{
			if (ct > 0)
			{
				for (int i = 0; i < OrdersText.length(); i++)
				{
					if (OrdersText[i] == ',')
					{
						temp.clear();
						k++;
					}
					else
					{
						temp += OrdersText[i];
						temp1[k] += OrdersText[i];
					}
				}
				k = 0;
				Order* pnn = new Order;
				pnn->Cid = stoi(temp1[0]);
				pnn->Pid = stoi(temp1[1]);
				pnn->pnext = NULL;
				Orders.Attach(pnn);

				for (int h = 0; h < 2; h++)
				{
					temp1[h].clear();
				}
			}
			ct++;
		}
	}
	OrdersFile.close();
	//cout << "----- Orders LIST----" << endl;
	//Orders.DisplayAllOrders();
}

void readAdminFromList(clistAdmin& Admins)
{
	string AdminsText;
	ifstream AdminsFile;

	AdminsFile.open("C:/Users/omar ahmed/Desktop/projectLap/projectLap/Admin.txt");
	if (AdminsFile.is_open())
	{
		string temp = "";
		string temp1[3];
		int k = 0;
		int ct = 0;
		//cout << "File is Open" << endl;

		while (getline(AdminsFile, AdminsText))
		{
			if (ct > 0)
			{
				for (int i = 0; i < AdminsText.length(); i++)
				{
					if (AdminsText[i] == ',')
					{
						temp.clear();
						k++;
					}
					else
					{
						temp += AdminsText[i];
						temp1[k] += AdminsText[i];
					}
				}
				k = 0;
				Admin* pnn = new Admin;
				pnn->Aid = stoi(temp1[0]);
				pnn->Aname = temp1[1];
				pnn->pass = temp1[2];
				pnn->pnext = NULL;
				Admins.Attach(pnn);

				for (int h = 0; h < 3; h++)
				{
					temp1[h].clear();
				}
			}
			ct++;
		}
	}
	AdminsFile.close();
}

void DisplayRecipt(int id, clistproduct& lP, clistOrders& lO) {
	Order* ptrap;
	Product* ptrave;
	ptrap = lO.phead;
	int tot = 0;
	while (ptrap != NULL) {
		if (id == ptrap->Cid)
		{
			ptrave = lP.phead;
			while (ptrave != NULL)
			{
				if (ptrave->Pid == ptrap->Pid)
				{
					tot = tot + ptrave->price;
				}
				ptrave = ptrave->pnext;
			}
		}

		ptrap = ptrap->pnext;
	}

	cout << endl << "Your Total Price is : " << tot << endl;
}

void ReturnProducts(int id, int n, clistproduct& p) {

	Product* ptrave;
	ptrave = p.phead;
	while (ptrave != NULL)
	{
		if (ptrave->Pid == id) {
			ptrave->stock += n;
		}
		ptrave = ptrave->pnext;
	}
}

void adjustProduct(clistproduct& productList)
{
	int productUpatedId, choice;
	cout << "Enter the product ID you want to adjust: ";
	cin >> productUpatedId;

	Product* newProduct = productList.phead;

	while (newProduct != NULL && newProduct->Pid != productUpatedId)
	{
		newProduct = newProduct->pnext;
	}

	if (newProduct != NULL)
	{
		cout << "Product ID: " << newProduct->Pid << endl;
		cout << "Product Name: " << newProduct->Pname << endl;
		cout << "Stock: " << newProduct->stock << endl;
		cout << "Price: " << newProduct->price << endl;
		cout << "Expire Month: " << newProduct->exp_month << endl;
		cout << "Expire Year: " << newProduct->exp_year << endl;

		cout << "1-Adjust name\n"
			"2-Adjust stock\n"
			"3-Adjust price\n"
			"4-Adjust exp month\n"
			"5-Adjust exp year" << endl;
		cin >> choice;

		if (choice == 1)
		{
			cout << "Enter new product name: ";
			cin >> newProduct->Pname;
		}
		else if (choice == 2)
		{
			cout << "Enter new stock: ";
			cin >> newProduct->stock;
		}
		else if (choice == 3)
		{
			cout << "Enter new price: ";
			cin >> newProduct->price;
		}
		else if (choice == 4)
		{
			cout << "Enter new expire month: ";
			cin >> newProduct->exp_month;
		}
		else if (choice == 5)
		{
			cout << "Enter new expire year: ";
			cin >> newProduct->exp_year;
		}
		else
		{
			cout << "wrong choice" << endl;
		}
		cout << "Product information updated successfully!" << endl;
		productList.writeToFile();
	}
	else
	{
		cout << "Product with ID " << productUpatedId << " not found." << endl;
	}
}

void deleteProduct(clistproduct& productList)
{
	int productUWantDeleteId;
	cout << "Enter the product ID you want to delete: ";
	cin >> productUWantDeleteId;

	Product* ptrav = productList.phead;
	Product* pb = NULL;

	while (ptrav != NULL && ptrav->Pid != productUWantDeleteId)
	{
		pb = ptrav;
		ptrav = ptrav->pnext;
	}

	if (ptrav == NULL)
	{
		cout << "Product with ID " << productUWantDeleteId << " not found." << endl;
	}
	else
	{
		if (pb == NULL)
		{
			productList.phead = ptrav->pnext;
		}
		else
		{
			pb->pnext = ptrav->pnext;
		}

		delete ptrav;
		cout << "Product with ID " << productUWantDeleteId << " has been deleted successfully." << endl;

		productList.writeToFile();
	}
}

void addProduct(clistproduct& productList)
{
	int id, stock, price, exp_month, exp_year;
	string name;

	cout << "Enter the new product's ID: \n";
	cin >> id;
	cin.ignore();
	cout << "Enter the new product's name: \n";
	getline(cin, name);
	cout << "Enter the new product's stock: \n";
	cin >> stock;
	cout << "Enter the new product's price: \n";
	cin >> price;
	cout << "Enter the new product's expiration month: \n";
	cin >> exp_month;
	cout << "Enter the new product's expiration year: \n";
	cin >> exp_year;

	Product* newProduct = new Product;
	newProduct->Pid = id;
	newProduct->Pname = name;
	newProduct->stock = stock;
	newProduct->price = price;
	newProduct->exp_month = exp_month;
	newProduct->exp_year = exp_year;
	newProduct->pnext = NULL;

	productList.ptail->pnext = newProduct;
	productList.ptail = newProduct;
	productList.writeToFile();
	cout << "Product is added successfully\n";
}

void dispProducts(clistproduct& productList)
{
	int stockLess, flag = 0;
	cout << "Enter the quantity that you want to display less than it\n";
	cin >> stockLess;
	Product* ptrav = productList.phead;
	while (ptrav != NULL)
	{
		if (ptrav->stock < stockLess)
		{
			cout << "ID: " << ptrav->Pid << " , ";
			cout << "NAME: " << ptrav->Pname << " , ";
			cout << "STOCK: " << ptrav->stock << " , ";
			cout << "PRICE: " << ptrav->price << " , ";
			cout << "EXPIRE MONTH: " << ptrav->exp_month << " , ";
			cout << "EXP YEAR: " << ptrav->exp_year << endl << "======================================================================" << endl;
			flag = 1;
		}
		ptrav = ptrav->pnext;
	}
	if (flag == 0)
	{
		cout << "No products found with stock less than " << stockLess << endl;
	}
}

void dispOrders(clistOrders& orders)
{
	int customerId;
	cout << "Enter the customer ID: ";
	cin >> customerId;
	Order* ptrav = orders.phead;
	int orderCt = 0;
	while (ptrav != NULL)
	{
		if (ptrav->Cid == customerId)
		{
			orderCt++;
		}
		ptrav = ptrav->pnext;
	}
	cout << "Customer with ID " << customerId << " has placed " << orderCt << " orders." << endl;
}

int main()
{
	clistAdmin admin;
	clistOrders order;
	clistCustomer customer;
	clistproduct product;

	readProductsFromList(product);
	readCustomerFromList(customer);
	readOrderFromList(order);
	readAdminFromList(admin);

	int N, f = 0, id, quantity, ctshId, d = 1, q, logOut = 1 ,idd;
	string name, pass;
	for (;;) {
		if (logOut == 1)
		{


			cout << "Choose one" << endl;
			cout << "===========" << endl;
			cout << "1- Customer" << endl;
			cout << "2- Admin" << endl;
			cout << "===========" << endl;
			cin >> N;

			if (N == 0 || N >= 3)
			{
				for (;;) {
					cout << "please choose from 1 to 2" << endl;
					cout << "Choose one" << endl;
					cout << "===========" << endl;
					cout << "1- Customer" << endl;
					cout << "2- Admin" << endl;
					cout << "===========" << endl;
					cin >> N;
					if (N > 0 && N < 3)
					{

						break;
					}
				}
			}

		}
		//customer
		if (N == 1)
		{
			if (logOut == 1)
			{
				int log;
				cout << "1- SignIn" << endl;
				cout << "2- Register" << endl;
				cin >> log;
				if (log == 1)
				{
					//signIN
					cout << "Enter Your Id"<<endl;
					cin >> idd;
					cout << "Enter your Name " << endl;
					cin >> name;
					cout << endl << "Enter Your Password" << endl;
					cin >> pass;
					Customer* ptrave;
					ptrave = customer.phead;
					while (ptrave != NULL)
					{
						if (name == ptrave->Cname && pass == ptrave->pass && idd == ptrave->Cid)
						{
							cout << "Sign-in successful! Your Customer ID is: " << ptrave->Cid << endl << endl;
							ctshId = ptrave->Cid;
							f = 1;
							logOut = 0;
							break;
						}
						ptrave = ptrave->pnext;
					}
				}
				//Register
				if (f == 0 || log == 2)
				{
					cout << "====================================" << endl;
					cout << "You Do not Register Before, please Register" << endl;
					cout << "====================================" << endl;
					cout << "Enter your Name ";
					cin >> name;
					cout << endl << "Enter Your Password";
					cin >> pass;
					Customer* pnn = new Customer;
					pnn->Cid = customer.ptail->Cid + 1;
					ctshId = pnn->Cid;
					pnn->Cname = name;
					pnn->pass = pass;
					pnn->pnext = NULL;
					customer.Attach(pnn);
					f = 1;
					logOut = 0;
					customer.writeCustomerToFile();
				}
			}
			if (f == 1 || logOut == 0)
			{
				product.DisplayInStock();

				cout << endl << "YOU CAN BUY ANY PRODUCT HERE :) , please choose id and quantity of product" << endl;
				for (; d > 0;) {
					cout << "id: ";
					cin >> id;
					if (id<product.phead->Pid || id>product.ptail->Pid)
					{
						for (;;) {
							cout << "ID of product you choose not exist, please choose another one" << endl;
							cin >> id;
							if (id >= product.phead->Pid && id <= product.ptail->Pid)
							{
								break;
							}
						}
					}
					cout << "Quantity: ";
					cin >> quantity;
					Product* ptrave;
					ptrave = product.phead;
					while (ptrave != NULL)
					{
						if (id == ptrave->Pid)
						{
							if (quantity > ptrave->stock)
							{
								cout << "the quantity you choose is more than that in the stock!!!!, Do you want to buy " << ptrave->stock << " of that product" << endl;
								cin >> f;
								if (f == 1)
								{
									cout << endl << "shopping succesful!!!!";
									for (int i = 0; i < ptrave->stock; i++)
									{
										Order* pnn = new Order;
										pnn->Cid = ctshId;
										pnn->Pid = ptrave->Pid;
										pnn->pnext = NULL;
										order.Attach(pnn);
									}
									ptrave->stock = 0;
									order.writeToFile();
									break;
								}
								else
								{
									break;
								}
							}
							else
							{
								cout << endl << "shopping succesful!!!!";
								for (int i = 0; i < quantity; i++)
								{
									Order* pnn = new Order;
									pnn->Cid = ctshId;
									pnn->Pid = ptrave->Pid;
									pnn->pnext = NULL;
									order.Attach(pnn);
								}
								ptrave->stock = ptrave->stock - quantity;
								order.writeToFile();
								break;
							}
						}
						ptrave = ptrave->pnext;
					}

					cout << endl << "Do you want to buy another product , 1 for yes , 0 for no" << endl;
					cin >> d;
				}
				//return products

				cout << endl << "Do You Want to return your Products, 1 for Yes , 0 for No" << endl;

				cin >> f;
				if (f == 1)
				{
					for (;;) {
						cout << "Choose product Id that you want to return" << endl;
						cin >> N;
						cout << "Choose the quantity that you want to return" << endl;
						cin >> q;
						int qq = 0;
						for (int i = 0; i < q; i++)
						{
							order.Remove(N, ctshId,qq);
						}
						ReturnProducts(N, qq, product);
						cout << endl << "Do you want to return another product , 1 for yes , 0 for no" << endl;
						cin >> d;
						if (d == 0)
						{
							break;
						}
					}
				}
				cout << "asd";
				order.writeToFile();
				product.writeToFile();
				DisplayRecipt(ctshId, product, order);
				cout << "Do you want to Log Out ? 1 for yes , 0 for no" << endl;
				cin >> logOut;
				d = 1;
			}

		}
		//Admin
		if (N == 2)
		{
			int choice, choice1, choice2;
			cout << "Enter your Admin Name " << endl;
			cin >> name;
			cout << endl << "Enter Your Admin Password" << endl;
			cin >> pass;
			Admin* ptrav1;
			ptrav1 = admin.phead;
			while (ptrav1 != NULL)
			{
				if (name == ptrav1->Aname && pass == ptrav1->pass)
				{
					cout << "Sign-in successful! Welcome Admin " << endl;
					ctshId = ptrav1->Aid;
					f = 1;
					logOut = 0;
					while (logOut == 0)
					{
						product.Display();
						cout << "1-Product operation" << endl;
						cout << "2-Display specific thing" << endl;
						cin >> choice;
						if (choice == 1)
						{
							cout << "1-Adjust a product" << endl;
							cout << "2-Delete a product" << endl;
							cout << "3-Add new product" << endl;
							cin >> choice1;
							if (choice1 == 1)
							{
								adjustProduct(product);
							}
							else if (choice1 == 2)
							{
								deleteProduct(product);
							}
							else if (choice1 == 3)
							{
								addProduct(product);
							}
							else
							{
								cout << "Wrong choice:(" << endl;
							}
						}
						else if (choice == 2)
						{
							cout << "1-Display all products that the stock is less than a specific quantity" << endl;
							cout << "2-Display how many orders are done by a specific customer" << endl;
							cin >> choice2;
							if (choice2 == 1)
							{
								dispProducts(product);
							}
							else if (choice2 == 2)
							{
								dispOrders(order);
							}
							else
							{
								cout << "wrong choice" << endl;
							}
						}
						else
						{
							cout << "wrong choice" << endl;
						}
						cout << "Do you want to Log Out ? 1 for yes , 0 for no" << endl;
						cin >> logOut;
					}
				}
				else
				{
					cout << "Name or Password is wrong!" << endl;
				}
				ptrav1 = ptrav1->pnext;
			}
		}
	}
}