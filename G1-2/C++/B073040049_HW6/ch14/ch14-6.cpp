#include <iostream>
#include <string>

using namespace std;

class Payment{
    public:
        void changepay(float num){
            this->pay = num;
        }
        float getamountpay(){
            return this->pay;
        }
        void paymentDetail(){
            cout<<"this cost "<<pay<<" dollars\n";
        }
    protected:
        float pay;
};

class CashPayment:public Payment{
    public:
        CashPayment(float dollarsa){
            changepay(dollarsa);
        }
        void paymentDetail(){
            cout<<"The cash payment amount is "<<pay<<"\n";
        }
};

class CreditCardPayment:public Payment{
    public:
        CreditCardPayment(string expireDaya,string cardNuma,string nameOnCarda,float dollarsa){
            changepay(dollarsa);
			this->expireDay = expireDaya;
			this->nameOnCard = nameOnCarda;
			this->cardNum = cardNuma;
        }
        void paymentDetail(){
            cout<<"The credit payment amount is "<<pay<<"\n";
            cout<<"The name on the credit card is "<<nameOnCard<<"\n";
            cout<<"The expiration date is "<<expireDay<<"\n";
            cout<<"The credit card is "<<cardNum<<"\n";
        }
    private:
        string expireDay;
        string cardNum;
        string nameOnCard;
};
int main(){
    cout<<"cash 1 details:\n";
    CashPayment A(50.5);
    A.paymentDetail();
    cout<<"cash 2 details:\n";
    CashPayment B(20.45);
    B.paymentDetail();
    cout<<"Credit 1 details:\n";
    CreditCardPayment C("10/5/2010","123455678908","Fred",10.5);
    C.paymentDetail();
    cout<<"Credit 2 details:\n";
    CreditCardPayment D("11/15/2009","9876554442123","Barney",100);
    D.paymentDetail();
    return 0;
}