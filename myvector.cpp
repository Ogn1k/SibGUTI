template <typename T> 
class myvector 
{
    T* arr = nullptr;
    int cap = 0;
    int cur = 0;
    public:
    myvector()
    {
        arr = new T[1];
        cap=1;
        cur=0;
    }
    myvector(int size)
    {
        arr = new T[size];
        cap=size;
        cur=0;
    }

    myvector(int size, T data)
    {
        arr = new T[size];
        cur=cap=size;
        for(int i=0; i<size;i++)
            arr[i]=data;

    }

    ~myvector() {delete[] arr;}

    void rmVec() { delete[] arr;}

    void push(T data)
    {
        if(cur==cap)
        {
            T* temp = new T[2*cap];    
            for(int i=0; i<cap;i++)
                temp[i] = arr[i];
            delete[] arr;
            cap *=2;
            arr = temp;
        }
        arr[cur] = data;
        cur++;
    }

    void push(T data, int ind)
    {
        if(ind >= cap)
            push(data);
        else
            arr[ind] = data;
    }

    T get(int ind)
    {
        if(ind < cur)
            return arr[ind];
        return T();
    }

    bool operator== (const myvector& arr) const
    {
        return *this == arr;
    }

    // void operator=(const myvector& arr)
    // {
    //     if(arr.cap < cap)
    //     {
    //         delete[] this->arr;
    //         this->arr = new T[arr.cap];
    //     }
    //     for (int i=0; i<arr.cap;i++)
    //     {
    //         this->arr[i]=arr[i];
    //     }
    // }

    T& operator[](int ind)
    {
        return arr[ind];
    }

    void pop() { if (cur > 0) cur--; }

    int size() { return cur; }

    int getCap() { return cap; }
};
