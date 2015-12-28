#include<iostream>
#include<string>

template <typename T>
bool alloc_mem(T **ptr) {
    try {
        *ptr = new T;
    } catch(std::bad_alloc& exc) {
        return false;
    }
    return true;
}

class llnode {
    private:
        int data;
        llnode *nxt;
    public:
        llnode() {
            data=0;
            nxt=NULL;
        }
        void setdata(int val) {
            data=val;
            return;
        }
        int getdata() {
            return data;
        }
        llnode* next() {
            return nxt;
        }
        void setnext(llnode *ptr) {
            nxt=ptr;
            return;
        }
};

class ll {
    private:
        llnode *head, *tail;
    public:
        ll() {
            head=NULL;
            tail=NULL;
        }
        bool addfront(int data) {
            if (head==NULL) {
                if (!alloc_mem(&head)) return false;
                head->setdata(data);
                head->setnext(NULL);
                tail=head;
            } else {
                llnode *newnode;
                if (!alloc_mem(&newnode)) return false;
                newnode->setdata(data);
                newnode->setnext(head);
                head=newnode;
            }
            return true;
        }
        bool addrear(int data) {
            if (tail==NULL) {
                if (!alloc_mem(&head)) return false;
                head->setdata(data);
                head->setnext(NULL);
                tail=head;
            } else {
                llnode *newnode;
                if (!alloc_mem(&newnode)) return false;
                newnode->setdata(data);
                newnode->setnext(NULL);
                tail->setnext(newnode);
                tail=newnode;
            }
            return true;
        }
        bool del(int val) {
            llnode *ptr=head;
            if (ptr->getdata()==val) {
                head=head->next();
                delete ptr;
                return true;
            }
            while (ptr->next()!=NULL && ptr->next()->getdata()!=val) {
                ptr=ptr->next();
            }
            if (ptr->next()==NULL) return false;
            else if (ptr->next()->getdata()==val) {
                llnode *temp=ptr->next();
                ptr->setnext(ptr->next()->next());
                delete temp;
                return true;
            }
            return false;
        }
        void print() {
            llnode *ptr=head;
            while(ptr!=NULL) {
                std::cout<<ptr->getdata()<<" ";
                ptr=ptr->next();
            }
            std::cout<<std::endl;
        }
};

int main() {
    ll ll1;
    ll1.addfront(10);
    ll1.addfront(5);
    ll1.addrear(15);
    ll1.addfront(1);
    ll1.addrear(16);
    ll1.print();
    ll1.del(5);
    ll1.print();
    return 1;
}
