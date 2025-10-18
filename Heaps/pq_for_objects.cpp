#include <bits/stdc++.h>

using namespace std;

class Student{
    public:
    int marks;
    string name;

    Student(string name, int marks):marks(marks), name(name){}

    bool operator < (const Student &obj) const {
        return this->marks < obj.marks;
        /* 
            for max heap we need return x < y 
            while for min heap x > y is written
        */
    }
};

int main()
{
    priority_queue<Student>pq;

    pq.push(Student("kashyap", 95));
    pq.push(Student("Henil", 90));
    pq.push(Student("Jasmita", 85));
    pq.push(Student("Diya", 80));
    pq.push(Student("Shrujal", 75));

    while(pq.size() > 0){
        cout<<pq.top().name <<" , "<< pq.top().marks<<endl;
        pq.pop();
    }
    return 0;
}