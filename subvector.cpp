#include <iostream>
using namespace std;

class sub_vector{
    public:
        bool init(){
            top=0;
            capacity=0;
            data = nullptr;
            return true;
        }

        bool push_back(int a){
            if(top>=capacity){
                capacity++;
                int* p = new int[capacity];
                for(unsigned int i=0; i<top; i++){
                    p[i]=data[i];
                }
                p[top]=a;
                top++;
                delete[] data;
                data=p;

            }
            else{
                data[top] = a;
                top++;

            }
            return true;
        }


    int pop_back(){
        if(top>0){
            top--;
            int* p= new int [capacity];
            for(int i=0; i<top; i++){
                p[i]=data[i];
            }
            delete[] data;
            data = p;
            return 1;
        }
        else{
            return 0;
        }
    }

    bool resize(unsigned int new_capacity){
        if(new_capacity >= capacity){
            capacity = new_capacity;
            int* p= new int [capacity];
            for(int i=0; i<top; i++){
                p[i]=data[i];
            }
            delete[] data;
            data = p;
            return true;
        }
        else    return false;
    }

    void shrink_to_fit(){
        capacity = top;
        int* p= new int [capacity];
        for(int i=0; i<top; i++){
            p[i]=data[i];
        }
        delete[] data;
        data = p;
    }

    void clear(){
        top=0;
        int* p= new int [capacity];
        delete[] data;
        data = p;
    }

    ~sub_vector(){
        delete[] data;
        top=0;
        capacity=0;
        data = nullptr;

    }

    private:
        unsigned int top;
        unsigned int capacity;
        int* data;

};


