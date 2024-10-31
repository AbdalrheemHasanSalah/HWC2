#include <iostream>
#include<math.h>
#include<fstream>
using namespace std;


class circle {
private:
    int radiues;
public:
    circle() {
      
    }
    circle(int r) { radiues = r; }
    ~circle() {
    }
    void set_radiues(int r) {
        radiues = r;
    }
    int get_radiues()const {
        return radiues;
    }
    double get_area() {
        return 3.14 * pow(radiues, 2);
    }
    double get_circumference()const {
        return 2 * 3.14 * radiues;
    }
   
    circle(circle& c) {
        set_radiues(c.get_radiues());
    }

};




class cylinder:public circle{
private:
    int height;


public:
    cylinder():circle() {
       
    }
    cylinder(int h) :circle(NULL) {
        set_height(h);
    }
    void set_height(int h) {
        height = h;
    }
    int get_height()  {
        return height;
    }
    ~cylinder() {

    }
    cylinder& operator =(cylinder& cyd) {
        
       if(this!=&cyd)
       set_radiues(cyd.get_radiues());
       set_height(cyd.get_height());
        return *this;
    }
    int get_size(int count)const  {
        return count;
    }
    
    
    friend ostream& operator <<(ostream& out, cylinder& cyd) {
        out << "radiues : " << cyd.get_radiues() << " area of circle : " << cyd.get_area() << "  circumference : " << cyd.get_circumference() << endl;
        out << "height: " << cyd.get_height() << "  cylinder area: " << cyd.compute_area() << " cylinder volume: " << cyd.compute_volume()<<endl<<endl;
        return out;
    }
    friend istream& operator >>(istream& in, cylinder& cyd) {
        int h=0, r=0;
       
        while (h <= 0) {
            cout << "height is :";

            in >> h;
           
          
        }
        while (r <= 0) {
            cout << "radueis is:";
            in >> r;
        }
        cout << endl;
        cyd.set_radiues(r);
        cyd.set_height(h);
        return in;
    }
    double compute_volume() {
        double x = (get_height() * get_area());
        return x;
    } 
    double compute_area() {
        return get_area() * (get_height() + get_radiues());
    }
    cylinder(cylinder& cyd) {
        set_radiues(cyd.get_radiues());
        set_height(cyd.get_height());
    } 
protected:



};

class arraycyd {
private:
    cylinder* a;
    int count;
public:
    void set_arraycyd(cylinder * p) {
        set_size(count);
        a = new cylinder[get_size()];
        for (int i = 0; i < get_size(); i++) {
            *(get_arraycyd() + i) = *(p + i);
        }
    }
    cylinder* get_arraycyd()const {
        return a;
    }
    void set_size(int count) {
        this->count = count;
    }
    int get_size()const {
        return count;
    }
    arraycyd() {
        count = 10;
        a = new cylinder[count];
    }
    arraycyd(arraycyd& cyd) {
        set_size(cyd.get_size());
        a = new cylinder[cyd.get_size()];
        for (int i = 0; i < get_size(); i++) {
            get_arraycyd()[i] = cyd.get_arraycyd()[i];
        }
    }
    arraycyd(cylinder *A, int count) {
        set_size(count);
        a = new cylinder[get_size()];
        for (int i = 0; i < get_size(); i++) {
            *(get_arraycyd() + i) = *(A+i);
        }
    }

    void read() {
        for (int i = 0; i < get_size(); i++) {
            cin >> (get_arraycyd() [i]);
           
        }
    }
    void readfromfile() {
        ifstream file;
        file.open("read.txt");
        int i = 0;
        if (file.is_open()) {
            cout << "file is open to read "<<endl;
            int h, r;
            while (!file.eof()) {
                file >>h ;
                if (h <= 0)cout << "wrong input value height :"<<h<<endl;
                else (get_arraycyd()[i]).set_height(h);
                file >> r;
                if (r <= 0)cout << "wrong input value radiues :"<<r << endl;
                else (get_arraycyd()[i]).set_radiues(r);
                i++;
          }

        }
        else cout << "file isnot open to read"<<endl;
    }
    void writetofile() {
        ofstream file;
        file.open("text.txt");
        if (file.is_open()) {
            cout << "file is open to write "<<endl;
            file << "befor sort"<<endl;
           for(int i=0;i< get_size();i++)
                file<< (get_arraycyd()[i]);
           sort();
           file << "after sort"<<endl;
           for (int i = 0; i < get_size(); i++)
               file << (get_arraycyd()[i]);
           file << "cylinder with largest volume is : " << (get_arraycyd()[get_size() - 1])<<endl;
           file << "cylinder with smallest volume is : " << (get_arraycyd()[0])<<endl;

        }
        else cout << "file isnot open to write";
    }
    void write() {
        for (int i = 0; i < get_size(); i++)
        {
            cout << (get_arraycyd()[i]);
        }
    }
    void sort() {
        
        for(int i=0;i<get_size();i++)
            for (int j = i+1; j < get_size(); j++) {
                if ((get_arraycyd()[i]).compute_volume() >(get_arraycyd()[j]).compute_volume())
                {
                    cylinder c = get_arraycyd()[i];
                    (get_arraycyd()[i] )= (get_arraycyd()[j]);
                    (get_arraycyd()[j]) = c;
                }
            }

    }

    void getmax()const {
        cylinder max = get_arraycyd()[0];
        for (int i = 0; i < get_size(); i++) {
            if (get_arraycyd()[i].compute_volume() > max.compute_volume())
                max = get_arraycyd()[i];
        }
        cout << "largest volume is cylinder is : " <<endl<< max;
    }
    void getmin()const {
        cylinder min = get_arraycyd()[0];
        for (int i = 0; i < get_size(); i++) {
            if (get_arraycyd()[i].compute_volume() < min.compute_volume())
                min = get_arraycyd()[i];

        }
        cout << "smallest volume is cylinder : " <<endl<< min;
    }
    arraycyd& operator =(arraycyd& arrcyd) {
        if (this != &arrcyd) {
            a = new cylinder[arrcyd.get_size()];
            set_size(arrcyd.get_size());
                for (int i = 0; i < get_size(); i++) {
                    a[i] = arrcyd.get_arraycyd()[i];
                }
        }
        return *this;
    }
    ~arraycyd() {
        delete[] a;
    }


};

int main()
{
    arraycyd a;
    
   // a.read();
    a.readfromfile();
    a.write();
    a.writetofile();
    cout << endl << endl;
    a.sort();
    cout << "after sort"<<endl;
    a.write();
    a.writetofile();
    a.getmax();
    a.getmin();
    
}
