#include <iostream> 
#include <cmath> 
using namespace std;





///////////////////////////////////////////////////////

class encdecbase {
protected:
    string en = "AaBbCc1234";
    string de = "cCAaBb2143";
    string str = "gggsgsgxxxxxywww";
    string text = "A big cat 21";

public:
    void encrypt();
    void decrypt();
};

void encdecbase::encrypt() {

    for (int i = 0; i <= text.size(); i++)
    {
        for (int j = 0; j <= en.size(); j++)
        {
            if (text[i] == en[j])
            {
                text[i] = de[j];
                break;
            }

        }
    }
    cout << text << endl;
}

/// ////////////////////////////////////////////

class encMatrix : public encdecbase
{
public:
    void encmat(int n) {
        int j = 0;
        for (int i = 0; i < text.size(); i++)
        {
            if (i % n == 0) cout << endl;
            cout << text[i] << " ";

        }
        cout << endl;
        while (j < n)
        {
            for (int i = 0; i < text.size(); i++)
            {
                if ((i - j) % n == 0) cout << text[i];

            }
            j++;
        }
    }
};

    void encdecbase::decrypt()
    {
        for (int i = 0; i <= text.size(); i++)
        {
            for (int j = 0; j <= en.size(); j++)
            {
                if (text[i] == de[j])
                {
                    text[i] = en[j];
                    break;
                }

            }
        }
        cout << text << endl;

    }

    ////////////////////////////////////////

    class cd
    {
    public:
       
        int gcd(int n1,int n2);
    };

    int cd::gcd(int a, int b) {
        int c;
        a = abs(a);
        b = abs(b);
        c = (b == 0) ? a : gcd(b, a % b);
        return c;
    }

    ////////////    //////////////////////////////////////////////

    class rle: protected encdecbase
    {
    public :
        void printRLE()
        {
            int n = str.length();
            for (int i = 0; i < n; i++) {

                int count = 1;
                while (i < n - 1 && str[i] == str[i + 1]) {
                    count++;
                    i++;
                }
                cout << str[i] << count;
            }
        }
};


    ///getmissingnumber//////////////////////////////////////////////
    class gmn
    {
    public:
       
        int getMissingNumber(int arr[], int n)
        {
            int m = n + 1;
            int total = m * (m + 1) / 2;
            int sum = 0;
            for (int i = 0; i < n; i++) {
                sum += arr[i];
            }
            return total - sum;
        }
   };
    int main()
    {
        int arr[] = { 1, 2, 3, 4, 5, 7, 8, 9, 10 };
        int n = sizeof(arr) / sizeof(arr[0]);
        encdecbase txt;
        txt.encrypt();
        txt.decrypt();
        encMatrix mat;
        mat.encmat(4);
        cout << endl;
        cd nums;
        cout << nums.gcd(15,5);
        rle mytext;
        mytext.printRLE();
        cout << endl;
        gmn arra;
        cout<< arra.getMissingNumber(arr, n);
        return 0;
    }
