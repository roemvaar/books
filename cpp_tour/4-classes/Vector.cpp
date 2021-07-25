class Vector {
private:
    double∗ elem; // elem points to an array of sz doubles
    int sz;
public:
    Vector(int s) :elem{new double[s]}, sz{s} // constr uctor: acquire resources
    {
        for (int i=0; i!=s; ++i) // initialize elements
        elem[i]=0;
    }

    ~Vector() { delete[] elem; } // destr uctor: release resources
    
    double& operator[](int i);
    int size() const;
};
