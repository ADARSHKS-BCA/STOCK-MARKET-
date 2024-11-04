#include <iostream>
#include <string>
#include<cmath>
using namespace std;
class TRADING {
public:
    string name, sname;
    float price;
	int face_value;
    int quantity;
//    USE OF CONSTRUCTOR
     void trade() {
        cout << "ENTER THE NAME OF THE TRADER: ";
        cin >> name;
        cout << "ENTER THE STOCK NAME WHICH YOU'RE GOING TO TRADE: ";
        cin >> sname;
}
    void tarde2(float p, int q)
	{
	price=p;
	 quantity=q;
}
    void calculate() {
        if (quantity != 0) {
            face_value = price / quantity;
            cout << "THE PRICE FOR A SINGLE STOCK (FACE VALUE) IS: " << face_value << endl;
        } else {
            cout << "Error: Quantity is zero, cannot calculate face value." << endl;
        }
    }
};
class Investment {
public:
    string name, sname;
    float price;
    int quantity, years;
    double rate, principal;
    void invest() {
        cout << "THIS IS AN INVESTMENT SYSTEM" << endl;
        cout << "ENTER THE NAME OF THE INVESTOR: ";
        cin >> name;
        cout << "ENTER THE STOCK NAME THAT YOU'RE INVESTING IN: ";
        cin >> sname;
    }
    void setDetails(double p, double r, int y) {
        principal = p;
        rate = r;
        years = y;
    }
    double calculateSimpleInterest() {
        return principal * (1 + rate * years);
    }
    double calculateCompoundInterest() {
        return principal *pow ((1 + rate), years);
    }
    void displayResults() {
        cout << "Future Value with Simple Interest: " << calculateSimpleInterest() << endl;
        cout << "Future Value with Compound Interest: " << calculateCompoundInterest() << endl;
    }
};
class BUYER {
public:
    int Bid;
    string Bname;
    void buyer_info() {
        cout << "ENTER THE BUYER ID: ";
        cin >> Bid;
        cout << "ENTER THE BUYER NAME: ";
        cin >> Bname;
    }
};
// USE OF MULTILEVEL INHERITANCE
class BUYER2 : virtual public BUYER {
public:
    float Bprice, Bquantity;
    void buyer_info2() {
        cout << "ENTER THE BUYER PRICE: ";
        cin >> Bprice;
        cout << "ENTER THE BUYER QUANTITY: ";
        cin >> Bquantity;
    }
};

class BUYER3 : public BUYER2 {
public:
    float face_value1;
    void buyer_info3() {
        face_value1 = (Bprice / Bquantity);
        cout << "THE FACE VALUE OF THE STOCK IS: " << face_value1 << endl;
    }
};
class SELLER1 {
public:
    int Sid;
    string Sname;
    int Sprice, Squantity;
    void seller_info1() {
        cout << "ENTER THE SELLER ID: ";
        cin >> Sid;
        cout << "ENTER THE SELLER NAME: ";
        cin >> Sname;
        cout << "ENTER THE PRICE OF THE STOCK: ";
        cin >> Sprice;
        cout << "ENTER THE QUANTITY OF THE STOCK: ";
        cin >> Squantity;
    }
};
class SELLER2 : public SELLER1 {
public:
    float face_value2;
    void seller_info2() {
        face_value2 = static_cast<float>(Sprice) / Squantity;
        cout << "THE FACE VALUE OF THE STOCK IS: " << face_value2 << endl;
    }
};
//USE OF HYBRID INHERITANCE
class HEDGING : public BUYER3, public SELLER2 {
public:
    float facevalue;
    void hedge() {
        int h_value1 = Bprice / 2;
        int h_value2 = Sprice / 2;
        int total_value = h_value1 + h_value2;
        cout << "THE FINAL PRICE FOR THE TRADER IS: " << total_value << endl;
    }

    void readdata(float price, int quantity) {
        if (quantity != 0) { 
            facevalue = price / quantity;
            cout << "THE CURRENT MARKET VALUE OF THE STOCK IS: " << facevalue << endl;
        } else {
            cout << "Error: Quantity is zero, cannot calculate face value." << endl;
        }
    }

    void suggestStocks() {
       int z;
       cout<<"WHAT TYPE OF STOCK DO YOU WANT TO BUY:"<<endl;
       cout<<"1.COMMON STOCK"<<endl;
       cout<<"2.PREFERRED STOCK"<<endl;
       cout<<"3.GROWTH STOCK"<<endl;
       cout<<"4.DIVIDEND STOCK"<<endl;
       cout<<"5.PENNY STOCK"<<endl;
	   cout<<"6.IPO STOCK"<<endl;
	   cout<<"7.TECHNOLOGY SECTOR"<<endl;
	   cout<<"8.FINANCIAL SECTOR"<<endl;
	   cin>>z;
	   switch(z)
	   {
	   	case 1://COMMON STOCK
	   	{
	   		cout<<"THE STOCK'S YOU CAN BUY IN COMMON SECTOR ARE"<<endl;
	   		cout<<"APPLE, TESLA, MICROSOFT"<<endl;
	   		break;
		   }
		   case 2: //PREFERRED STOCKS
		   {
		   		cout<<"THE STOCK'S YOU CAN BUY IN  PREFERRED SECTOR ARE"<<endl;
		   		cout<<"Bank of America ,Ford Motor Company ,General Electric Preferred Stock"<<endl;
		   		
		   	break;
		   }
		   case 3://GROWTH STOCKS
		   {
		   	cout<<"THE STOCK'S YOU CAN BUY IN  GROWTH SECTOR ARE"<<endl;
		   	cout<<"AMAZON,GOOGLE,NVIDIA"<<endl;
		   	break;
		   }
		   case 4://DIVIDEND STOCKS
		   {
		   	cout<<"THE STOCK'S YOU CAN BUY IN DIVIDEND SECTOR ARE"<<endl;
		   	cout<<"Procter & Gamble Co,Johnson & Johnson,Coca-Cola Co."<<endl;
		   	 break;
		   }
		   case 5://PENNY STOCK
		   {
		   	cout<<"THE STOCK'S YOU CAN BUY IN THE PENNY SECTOR ARE"<<endl;
		   	cout<<"Sundial Growers Inc.,Transocean Ltd.,Castor Maritime Inc."<<endl;
		   	break;
		   }
		   case 6:// IPO STOCK
		   {
		   	cout<<"THE STOCK'S YOU CAN BUY IN THE IPO SECTOR ARE"<<endl;
            cout<<" Rivian Automotive Inc.,Coinbase Global Inc.,Snowflake Inc."<<endl;
			break;   	
		   }
		   case 7://TECHNOLOGY SECTOR
		   {
		   cout<<"THE STOCK'S YOU CAN BUY IN THE  TECHNOLOGY SECTOR ARE"<<endl;
		   cout<<"Apple Inc.,NVIDIA Corp.,Microsoft Corp."<<endl;
        break;
		   }
		   case 8://FINANCIAL SECTOR
		   {
		   	   cout<<"THE STOCK'S YOU CAN BUY IN THE  FINANCIAL SECTOR ARE"<<endl;
               cout<<"JPMorgan Chase & Co.,Goldman Sachs Group Inc.,Bank of America Corp."<<endl;
		   }
		   default:
		   	{
		   		cout<<"INVALID ENTRY,TRY AGAIN"<<endl;
			   }
	   }
	      }

    void adjustQuantity(int &quantity) {
        int choice, adjustment;
        cout << "DO YOU WANT TO ADD OR SUBTRACT QUANTITY?" << endl;
        cout << "1. ADD" << endl;
        cout << "2. SUBTRACT" << endl;
        cout << "Choice: ";
        cin >> choice;
        cout << "ENTER THE QUANTITY TO ADJUST: ";
        cin >> adjustment;

        switch (choice) {
            case 1:
                quantity += adjustment;
                cout << "NEW QUANTITY AFTER ADDITION: " << quantity << endl;
                break;
            case 2:
                if (adjustment <= quantity) {
                    quantity -= adjustment;
                    cout << "NEW QUANTITY AFTER SUBTRACTION: " << quantity << endl;
                } else {
                    cout << "Error: Cannot subtract more than current quantity." << endl;
                }
                break;
            default:
                cout << "INVALID CHOICE" << endl;
        }
    }
    void calculationH()
    {
    	int h;
    	cout<<"ENTER THE TYPE OF CALCULATION YOU WANT:"<<endl;
    	cout<<"1.RETURN ON INVESTMENT (ROI)"<<endl;
    	cout<<"2.EARNING PER SHARE (EPS)"<<endl;
    	cout<<"3.PRICE TO EARNING RATIO (PE RATIO)"<<endl;
		cin>>h;
		switch(h)
		{
			        case 1: { // ROI
            double purchasePrice, currentPrice;
            cout << "ENTER PURCHASE PRICE OF STOCK:" << endl;
            cin >> purchasePrice;
            cout << "ENTER CURRENT PRICE OF STOCK:" << endl;
            cin >> currentPrice;
            double roi = ((currentPrice - purchasePrice) / purchasePrice) * 100;
            cout << "RETURN ON INVESTMENT (ROI): " << roi << "%" << endl;
            break;
        }
        case 2: { // EPS
            double netIncome, dividends, outstandingShares;
            cout << "ENTER NET INCOME OF THE COMPANY:" << endl;
            cin >> netIncome;
            cout << "ENTER DIVIDENDS PAID TO SHAREHOLDERS:" << endl;
            cin >> dividends;
            cout << "ENTER THE NUMBER OF OUTSTANDING SHARES:" << endl;
            cin >> outstandingShares;
            double eps = (netIncome - dividends) / outstandingShares;
            cout << "EARNINGS PER SHARE (EPS): " << eps << endl;
            break;
        }
        case 3: { // P/E Ratio
            double currentPrice, eps;
            cout << "ENTER CURRENT STOCK PRICE:" << endl;
            cin >> currentPrice;
            cout << "ENTER EARNINGS PER SHARE (EPS):" << endl;
            cin >> eps;
            double peRatio = currentPrice / eps;
            cout << "PRICE-TO-EARNINGS RATIO (P/E): " << peRatio << endl;
            break;
        }
        default:{
		    cout << "INVALID CHOICE" << endl;
		}
    }	
}
};
int main()
 {
    float price;
    int quantity, choice;
    int numUsers;
    string name;
    int age;
    long int pno;
    cout<<"WELCOME TO WEALTH MINDS"<<endl;
    cout<<"ENTER THE NAME FOR REGISTRATION:"<<endl;
    cin>>name;
    cout<<"ENTER THE PHONE NUMBER:"<<endl;
    cin>>pno;
    cout<<"ENTER THE AGE(ABOVE 18 ONLY) :"<<endl;
    cin>>age;
     if(age>=18)
{
    cout << "ENTER THE NUMBER OF USERS YOU WANT: ";
    cin >> numUsers;
    for (int i = 0; i < numUsers; i++) {
        cout << "\nTHIS IS FOR THE PERSON: " << (i + 1) << endl;
        TRADING T;
        Investment I;
        HEDGING H;

        bool userMenuActive = true;
        while (userMenuActive) {
            cout << "\nSELECT A CLASS TO ACCESS:" << endl;
            cout << "1. TRADING" << endl;
            cout << "2. Investment" << endl;
            cout << "3. BUYER/SELLER (Hedging)" << endl;
            cout<<  "4. CALCULATION STOCKS"<<endl;
            cout << "5. Exit to Next User" << endl;
            cout << "Choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    // Trading information already handled in TRADING constructor
                    cout << "Trading information has been initialized." << endl;
					T.trade();
					 cout << "ENTER THE PRICE OF THE STOCK: ";
			        cin >> price;
			        cout << "ENTER THE QUANTITY OF THE STOCK: ";
			        cin >> quantity;
					T.tarde2(price,quantity);
                    T.calculate();
                    break;
                case 2: {
                    double principal, rate;
                    int years;
                    I.invest();
                    cout << "Enter initial investment amount (principal): ";
                    cin >> principal;
                    cout << "Enter annual interest rate (as a decimal): ";
                    cin >> rate;
                    cout << "Enter the number of years: ";
                    cin >> years;
                    I.setDetails(principal, rate, years);
                    I.displayResults();
                    break;
                }
                case 3: {
                    H.buyer_info();
                    H.buyer_info2();
                    H.buyer_info3();
                    cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
                    H.seller_info1();
                    H.seller_info2();
                    cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
                    H.hedge();

                    int action;
                    cout << "\nSELECT AN ACTION FOR HEDGING:" << endl;
                    cout << "1. Calculate and Display Face Value" << endl;
                    cout << "2. Suggest Stocks to Buy" << endl;
                    cout << "3. Adjust Stock Quantity" << endl;
                    cout << "4. Return to Main Menu" << endl;
                    cout << "Choice: ";
                    cin >> action;

                    switch (action) {
                        case 1:
                            H.readdata(price, quantity);
                            break;
                        case 2:
                            H.suggestStocks();
                            break;
                        case 3:
                            H.adjustQuantity(quantity);
                            break;
                        case 4:
                            break;
                        default:
                            cout << "Invalid choice. Please select again." << endl;
                    }
                    break;
                }
                case 4:
				{
                	H.calculationH();
					break;
				}
                case 5:
                    userMenuActive = false; // Exit loop for this user
                    cout << "Moving to the next user...\n";
                    break;
                default:
                    cout << "Invalid choice. Please select again." << endl;
            }
        }
    }
    cout << "THANK YOU FOR USING THE WEALTH MINDS!" << endl;
}
  else
{
	cout<<"SORRY PEOPLE BELOW AGE LIMIT CAN'T USE  IT";
}
return 0;
}
