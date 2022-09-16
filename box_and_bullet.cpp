#include <iostream>
#include <math.h>
using namespace std;

class error_exception{};

long long int factoriel(int n)
{
    long long int fact=1;
    for(int i=1 ; i<=n ; i++)
    {
        fact*=i;
    }
    return fact;
}
long long int combination(int n , int k)
{
    try
    {
        if(n<k ||(n==0 && k==0))
        {
            throw error_exception();
        }
        long long int fact_n=0;
        long long int fact_k=0;
        long long int fact_n_k=0;
        fact_n=factoriel(n);
        fact_k=factoriel(k);
        fact_n_k=factoriel(n-k);
        return (fact_n / (fact_k *fact_n_k));
    }
    catch (error_exception er)
    {
        cout<<"Error : Invalid Input! "<<endl;
    }
    return 0;
}
long long int calculate_sterling(int n , int k)
{
    double sum=0;
    for(int i=0 ; i<k ; i++)
    {
        sum+=combination(k,i)*pow(k-i,n)*pow(-1,i);
    }
    return  sum/factoriel(k);
}
long long int recrusive_form (int n , int k) {
    
    int result = 0;

    if (n > k && k != 1) {
        result += recrusive_form(n-1,k-1) + recrusive_form(n-k,k);
    }
    else if (n > k && k == 1) {
        result += 1;
        // cout << result << endl;
    }
    else if (n < k) {
        result += 0;
        // cout << result << endl;
    }
    else if (n == k) {
        result += 1;
        // cout << result << endl;
    }
    return result;
}
void show_menu()
{
    cout << "Please choose an option : " << endl << endl;
    cout<<"1 : Different bullets and different box and box can be empty ."<<endl;
    cout<<"2 : Different bullets and different box and box can not be empty ."<<endl;
    cout<<"3 : Different bullets and not different box and box can not be empty ."<<endl;
    cout<<"4 : Different bullets and not different box and box can be empty ."<<endl;
    cout<<"5 : Not different bullets and different box and  box can be empty ."<<endl;
    cout<<"6 : Not different bullets and different box and  box can not be empty ."<<endl;
    cout<<"7 : Not different bullets and not different box and box can not be empty ."<<endl;
    cout<<"8 : Not different bullets and not different box and box can be empty ."<<endl;
    cout<<"9 : Exit ."<<endl << endl;
}

int main()
{
    int choice = 0;
    int box = 0;
    int bullets = 0;
    bool flag = true;

    while (flag)
    {
        int result = 0;
        show_menu();
        cin >> choice;
        if(choice == 1) {
            cout << "Number of bullets : ";
            cin >> bullets;
            cout << "Number of boxes : ";
            cin >> box;
            result = pow(box,bullets);
            cout << "the result is : " << result << endl << endl;
        }
        else if(choice == 2) {
            cout<<"Number of bullets : ";
            cin >> bullets;
            cout << "Number of boxes : ";
            cin >> box;
            result = factoriel(box) * calculate_sterling(bullets,box);
            cout << "the result is : " << result << endl << endl;
        }
        else if(choice == 3) {
            cout << "Number of bullets : ";
            cin >> bullets;
            cout << "Number of boxes : ";
            cin >> box;
            result = calculate_sterling(bullets,box);
            cout << "the result is : " << result << endl << endl;

        }
        else if(choice == 4) {
            cout << "Number of bullets : ";
            cin >> bullets;
            cout << "Number of boxes : ";
            cin >> box;
            for(int i = box ; i > 0 ; i--)
            {
                result += calculate_sterling(bullets , i);
            }
            cout << "the result is : " << result << endl << endl;
        }

        else if(choice == 5) {
            cout << "Number of bullets : ";
            cin >> bullets;
            cout << "Number of boxes : ";
            cin >> box;
            result = combination(bullets+box-1,box-1);
            cout << "the result is : " << result << endl << endl;

        }
        else if(choice == 6) {
            cout << "Number of bullets : ";
            cin >> bullets;
            cout << "Number of boxes : ";
            cin >> box;
            result = combination(bullets-1,box-1);
            cout << "the result is : " << result << endl << endl;
        }

        else if(choice == 7) {
            cout << "Number of bullets : ";
            cin >> bullets;
            cout << "Number of boxes : ";
            cin >> box;
            result = recrusive_form(bullets,box);
            cout << "the result is : " << result << endl << endl;

        }
        else if (choice == 8) {
            cout << "Number of bullets : ";
            cin >> bullets;
            cout << "Number of boxes : ";
            cin >> box;
            for (int i = 1; i < box + 1; i++) {
                result += recrusive_form(bullets,i);
            }
            cout << "the result is : " << result << endl << endl;
        }
        else if (choice == 9) {
            flag = false;
        }
        else {
            cerr << "Error : Please choose one of the given options!" << endl << endl;
        }
    }
    
    return 0;
}
