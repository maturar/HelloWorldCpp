#include <iostream>
using namespace std;

// §12
// Special member functions
//  . §12.1     Constructor
//  . §12.8     Copy/Move
//    - §12/1   Copy/Move Constructor
//    - §13.5.3 Copy/Move Assignment Operator
struct T {
    int _v1;
    int _v2;
    int _v3;

    friend std::ostream& operator<<(std::ostream& os, const T& p)
    {
        return os << "[ " << p._v1 << " | " << p._v2 << " | " << p._v3 << " ]";
    }
};

struct S {
    S() // Constructor
    {
        cout << "Constructing instance of S" << endl;
        _t = new T{ 1, 2, 3 };
    }
    S(T& t) // Constructor
    {
        cout << "Initializing instance of S" << endl;
        _t = new T{ t };
    }

    S(const S& that) // Copy Constructor
    {
        cout << "Copying instance of S" << endl;
        _t = new T;
        *_t = *(that._t); // Deep copy
    }
    S& operator=(const S& that) // Copy Assignment Operator
    {
        cout << "Assigning instance of S" << endl;
        *_t = *(that._t); // Deep copy
        return *this;
    }

    S(S&& that) // Move Constructor
    {
        cout << "Moving instance of S" << endl;
        _t = that._t; // Move resources
        that._t = nullptr; // Reset source (protect)
    }
    S& operator=(S&& that) // Move Assignment Operator
    {
        cout << "Move-assigning instance of S" << endl;
        _t = that._t; // Move resources
        that._t = nullptr; // Reset source (protect)
        return *this;
    }

    T* _t;
};

int main()
{
    T t1{ 41, 42, 43 };
    cout << t1 << " Initializer" << endl;
    S s1{ t1 };
    cout << s1._t << " : " << *(s1._t) << " Initialized" << endl;

    S s2{ s1 };
    cout << s2._t << " : " << *(s2._t) << " Copy Constructed" << endl;

    S s3;
    cout << s3._t << " : " << *(s3._t) << " Default Constructed" << endl;
    s3 = s2;
    cout << s3._t << " : " << *(s3._t) << " Copy Assigned" << endl;

    S s4{ static_cast<S&&>(s3) };
    cout << s4._t << " : " << *(s4._t) << " Move Constructed" << endl;

    s2 = std::move(s4);
    cout << s2._t << " : " << *(s2._t) << " Move Assigned" << endl;

    return 0;
}
