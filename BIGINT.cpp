#include<cstdio>
#include<cstring>
#include<string>
#include<sstream>
#include<iostream>
#include<cstdlib>
#include<algorithm>

using namespace std;
class BIGINT
{
    char* arr;
public:
    BIGINT();
    BIGINT(char* a );
    BIGINT(int a );
    BIGINT(unsigned int a );
    BIGINT(long int a );
    BIGINT(unsigned long int a );
    BIGINT(long long int a );
    BIGINT(unsigned long long  a );
    BIGINT(const BIGINT &A);
    BIGINT& operator=(BIGINT A);
    ~BIGINT();
    char* getArr(void);
    void setArr(char* cc);
    void showArr(void);
    void zero_reducer(void);
    friend istream& operator>>(istream &in, BIGINT &A );
    friend ostream& operator<<(ostream &out, BIGINT &B);
};


BIGINT Add_( BIGINT A , BIGINT B);
BIGINT Multiply_(BIGINT A , BIGINT B);
BIGINT operator*(BIGINT A ,BIGINT B);
BIGINT Power(BIGINT A, BIGINT B);
void Tenscom(BIGINT &A, int bigger);
BIGINT operator+(BIGINT A , BIGINT B);
BIGINT operator-(BIGINT A , BIGINT B);
BIGINT operator-(BIGINT A);
BIGINT factorial(BIGINT A);

int main()
{

    BIGINT A, B, C, Ans;
    cin >> A ;

    A = factorial(A);
   // cout << A;



}

BIGINT factorial(BIGINT A)
{
    char *ca = A.getArr();
    BIGINT X(1);
    while(ca[0] != 48)
    {

        X= X*A;
        cout << X << endl;
        A = A-1;
        cout << A << endl;

    }
   return X;
}










BIGINT operator-(BIGINT A)
{

    char *ca = A.getArr();
    //char *cb = B.getArr();
    if(ca[0] != '-')
    {
        char *strc = A.getArr();
        int leng = strlen(strc);
        reverse(strc,strc+leng);
        strc[leng] = '-';
        reverse(strc,strc+leng+1);
    }
    else
    {
        ca[0]=48;
        int lena = strlen(ca);
        reverse(ca,ca+lena);
        A.zero_reducer();
        reverse(ca,ca+lena-1);
    }
    return A;
}

BIGINT::BIGINT()
{
    arr = new char[1000000] {0};


}

BIGINT::BIGINT(char* a )
{
    arr= new char[1000000] {0};

    strcpy(arr,a);



}
BIGINT::BIGINT(int a )
{
    stringstream ss;
    ss<<a;
    string str;
    ss >> str;
    arr = new char[1000000] {0};
    strcpy(arr,str.c_str());



}
BIGINT::BIGINT(unsigned int a )
{
    stringstream ss;
    ss<<a;
    string str;
    ss >> str;
    arr = new char[1000000] {0};
    strcpy(arr,str.c_str());




}
BIGINT::BIGINT(long int a )
{
    stringstream ss;
    ss<<a;
    string str;
    ss >> str;
    arr = new char[1000000] {0};
    strcpy(arr,str.c_str());
}

BIGINT::BIGINT(unsigned long int a )
{
    stringstream ss;
    ss<<a;
    string str;
    ss >> str;
    arr = new char[1000000] {0};
    strcpy(arr,str.c_str());
}

BIGINT::BIGINT(long long int a )
{
    stringstream ss;
    ss<<a;
    string str;
    ss >> str;
    arr = new char[1000000] {0};
    strcpy(arr,str.c_str());
}

BIGINT::BIGINT(unsigned long long  a )
{
    stringstream ss;
    ss<<a;
    string str;
    ss >> str;
    arr = new char[1000000] {0};
    strcpy(arr,str.c_str());
}

BIGINT::BIGINT(const BIGINT &A)
{
    arr = new char[1000000];
    strcpy(arr, A.arr);
}

BIGINT&  BIGINT ::operator=(BIGINT A)
{
    arr = new char[1000000];
    strcpy(arr, A.arr);
    return *this;

}

BIGINT::~BIGINT()
{
    delete [] arr;
}

char* BIGINT::getArr(void)
{
    return arr;
}
void BIGINT:: setArr(char* cc)
{
    arr = cc;
}
ostream& operator<<(ostream &out, BIGINT &B)
{
    out << B.getArr();
    return out;
}
istream& operator>>(istream &in, BIGINT &A )
{
    char str[10000];
    in>>str;
    A = str;
    return in;
}
void  BIGINT::zero_reducer(void)
{
    for(int i = strlen(arr)-1; i>0; i--)
    {
        if(arr[i]==48)arr[i]=0;
        else break;
    }
}

void Tenscom(BIGINT &A, int bigger)
{
    char* ch = A.getArr();

    int l = strlen(ch);
    reverse(ch, ch+l);
    for(int i = l; i<bigger; i++)
    {
        ch[i]=48;
    }
    ch[bigger] = 0;
    l = bigger;
    int sum=0 , carry=0;
    reverse(ch,ch+l);
    for(int i = l-1 ; i>=0; i--)
    {

        if(i==l-1)
        {
            sum = (10-ch[i]+48);
            if(sum==10)
            {
                sum%=10;
                carry = 1;
            }

            ch[i]=sum+48;
        }
        else
        {
            sum = (9-ch[i]+48+carry);
            carry=0;
            if(sum==10)
            {
                sum%=10;
                carry = 1;
            }
            ch[i]=sum+48;
        }
    }
}

BIGINT Power(BIGINT A, BIGINT B)
{

    long long p=0;


    char *pp = B.getArr();
    long long i,l=strlen(pp);
    for( i= 0; i < l; i++)
        p =(10 * p)+ (pp[i] - 48);
    //cout << p<< endl;

    BIGINT C("1");
    for(i=0; i<p; i++)
    {
        C = C * A;


    }

    return C;



}

BIGINT operator+(BIGINT A , BIGINT B)
{

    char *ca = A.getArr();
    char *cb = B.getArr();
    if(ca[0] == '-' && cb[0]== '-')
    {


        A.setArr(++ca);
        B.setArr(++cb);
        BIGINT C = Add_(A,B);
        char *strc = C.getArr();
        int leng = strlen(strc);
        reverse(strc,strc+leng);
        strc[leng] = '-';
        reverse(strc,strc+leng+1);
        return C;

    }
    else if(ca[0] != '-' && cb[0]!= '-')
    {
        BIGINT C = Add_(A,B);
        return C;
    }
    int lenb = strlen(cb);

    int lena = strlen(ca);

    int bigger = lena > lenb ? lena : lenb;
    if(ca[0]=='-')
    {
        ca[0]=48;
        reverse(ca,ca+lena);
        A.zero_reducer();
        reverse(ca,ca+lena-1);

        Tenscom(A,bigger);
    }
    if(cb[0]=='-')
    {
        cb[0]=48;
        reverse(cb,cb+lenb);
        B.zero_reducer();
        reverse(cb,cb+lenb-1);
        ///int bigger = lena > lenb ? lena : lenb;
        Tenscom(B, bigger);
    }
    BIGINT C = Add_(A,B);
    ///cout << C.getArr()<<endl;
    char *ch = C.getArr();


    lena= strlen(A.getArr());
    lenb = strlen(B.getArr());
    int lenc = strlen(C.getArr());

    if(lena>=lenb)
    {
        if(lenc > lena)
        {
            ch[0]=48;
            reverse(ch,ch+lenc);
            C.zero_reducer();
            reverse(ch,ch+strlen(ch));
        }
        else
        {
            Tenscom(C,lenc);
            reverse(ch,ch+lenc);
            C.zero_reducer();
            ch[strlen(ch)]='-';
            ch[strlen(ch)+1]=0;
            reverse(ch,ch+strlen(ch));

        }
    }
    else
    {
        if(lenc>lenb)
        {
            ch[0]=48;
            reverse(ch,ch+lenc);
            C.zero_reducer();
            reverse(ch,ch+ strlen(ch));
        }
        else
        {
            Tenscom(C,lenc);
            reverse(ch,ch+lenc);
            C.zero_reducer();
            ch[strlen(ch)]='-';
            ch[strlen(ch)+1]=0;
            reverse(ch, ch+ strlen(ch));

        }
    }
    return C;
}

BIGINT operator-(BIGINT A , BIGINT B)
{

    char *ca = A.getArr();
    char *cb = B.getArr();
    if(cb[0] != '-')
    {
        char *strc = B.getArr();
        int leng = strlen(strc);
        reverse(strc,strc+leng);
        strc[leng] = '-';
        reverse(strc,strc+leng+1);
    }
    else
    {
        cb[0]=48;
        int lena = strlen(cb);
        reverse(cb,cb+lena);
        B.zero_reducer();
        reverse(cb,cb+lena-1);
    }
    if(ca[0] == '-' && cb[0]== '-')
    {


        A.setArr(++ca);
        B.setArr(++cb);
        BIGINT C = Add_(A,B);
        char *strc = C.getArr();
        int leng = strlen(strc);
        reverse(strc,strc+leng);
        strc[leng] = '-';
        reverse(strc,strc+leng+1);
        return C;

    }
    else if(ca[0] != '-' && cb[0]!= '-')
    {
        BIGINT C = Add_(A,B);
        return C;
    }
    int lenb = strlen(cb);

    int lena = strlen(ca);

    int bigger = lena > lenb ? lena : lenb;
    if(ca[0]=='-')
    {
        ca[0]=48;
        reverse(ca,ca+lena);
        A.zero_reducer();
        reverse(ca,ca+lena-1);

        Tenscom(A,bigger);
    }
    if(cb[0]=='-')
    {
        cb[0]=48;
        reverse(cb,cb+lenb);
        B.zero_reducer();
        reverse(cb,cb+lenb-1);
        ///int bigger = lena > lenb ? lena : lenb;
        Tenscom(B, bigger);
    }
    BIGINT C = Add_(A,B);
    ///cout << C.getArr()<<endl;
    char *ch = C.getArr();


    lena= strlen(A.getArr());
    lenb = strlen(B.getArr());
    int lenc = strlen(C.getArr());

    if(lena>=lenb)
    {
        if(lenc > lena)
        {
            ch[0]=48;
            reverse(ch,ch+lenc);
            C.zero_reducer();
            reverse(ch,ch+strlen(ch));
        }
        else
        {
            Tenscom(C,lenc);
            reverse(ch,ch+lenc);
            C.zero_reducer();
            ch[strlen(ch)]='-';
            ch[strlen(ch)+1]=0;
            reverse(ch,ch+strlen(ch));

        }
    }
    else
    {
        if(lenc>lenb)
        {
            ch[0]=48;
            reverse(ch,ch+lenc);
            C.zero_reducer();
            reverse(ch,ch+ strlen(ch));
        }
        else
        {
            Tenscom(C,lenc);
            reverse(ch,ch+lenc);
            C.zero_reducer();
            ch[strlen(ch)]='-';
            ch[strlen(ch)+1]=0;
            reverse(ch, ch+ strlen(ch));

        }
    }
    return C;
}
BIGINT Add_( BIGINT A , BIGINT B)
{
    BIGINT C;
    int carry = 0,pos=0,sum=0,j;
    char *pa = A.getArr();
    char *pb = B.getArr();
    char *pp;
    int la =strlen(pa) ;
    int lb =strlen(pb);
    if(la < lb)
    {
        pp=pa;
        pa = pb;
        pb = pp;
        swap(la,lb);
    }
    for(int j = lb; j< la; j++)
        pb[j]= 48;
    pb[la]= 0;
    char *pc = C.getArr();
    int i;
    reverse(pa,pa+la);
    reverse(pb,pb+lb);
    for(i=0; i<la; i++)
    {

        sum = pa[i]-48+pb[i]-48+carry;
        carry = 0;
        if(sum >= 10)
        {
            carry = sum/10;
            sum %= 10;
        }
        pc[i] = sum + 48;


    }

    if(carry)
        pc[i++] = carry + 48;
    reverse(pc,pc+i);
    return C;

}
BIGINT operator*(BIGINT A ,BIGINT B)
{
    int flag = 0;
    char *a = A.getArr();
    char *b = B.getArr();

    if((a[0] == '-' && b[0] == '-'))
    {
        A.setArr(++a);
        B.setArr(++b);
        BIGINT C = Multiply_(A,B);

        return C;


    }
    else if(a[0]=='-')
    {
        A.setArr(++a);
        BIGINT C = Multiply_(A ,B);
        char *strc = C.getArr();
        int leng = strlen(strc);
        reverse(strc,strc+leng);
        strc[leng] = '-';
        reverse(strc,strc+leng+1);
        return C;
    }
    else if(b[0]=='-')
    {
        B.setArr(++b);
        BIGINT C = Multiply_(A,B);
        char *strc = C.getArr();
        int leng = strlen(strc);
        reverse(strc,strc+leng);
        strc[leng] = '-';
        reverse(strc,strc+leng+1);
        return C;
    }
    else
    {
        BIGINT C = Multiply_(A,B);
        return C;
    }

}
BIGINT Multiply_(BIGINT A , BIGINT B)
{
    BIGINT C;
    char *p = A.getArr();
    int lenA =strlen(p);
    reverse(p,p+lenA);
    char *q = B.getArr();
    int lenB = strlen(q);
    reverse(q,q+lenB);
    int sum=0,pos=0,carry=0;
    char *r = C.getArr();
    for(int i = 0 ; i <lenA; i++)
    {
        sum=0;
        carry=0;
        int ad_carry=0;
        for(int j=0; j<lenB; j++)
        {
            int addition = 0;
            sum=(p[i]-48)*(q[j]-48);
            sum+=carry;
            carry=sum/10;
            sum%=10;
            if(r[pos]==0)r[pos]=48;
            addition=r[pos]-48+sum+ad_carry;
            ad_carry=0;
            if(addition>=10)
            {
                addition-=10;
                ad_carry=1;
            }
            r[pos++]=addition+48;





        }
        carry+=ad_carry;
        if(carry)
        {
            if(carry>=10)
            {
                carry-=10;
                ad_carry=1;
                if(r[pos]==0)r[pos]=48;
                r[pos++]=carry+48;
                if(r[pos]==0)r[pos]=48;
                r[pos]=ad_carry+48;
            }
            else r[pos]=carry+48;

            carry=0;
        }
        pos=i+1;

    }
    C.zero_reducer();

    reverse(r,r+strlen(r));
    return C;

}
