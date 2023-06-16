#include <iostream>
#include <cmath>

class Node {
public:
    int coeff;
    int exp;
    Node *next;
};

class Polynomial {
private:
    Node *poly;

public:
    Polynomial() {
        poly = nullptr;
    }

    void create();
    void display();
    long evaluate(int x);
};

void Polynomial::create() {
    Node *t, *last = nullptr;
    int num;

    std::cout << "Enter number of terms: ";
    std::cin >> num;
    std::cout << "Enter each term with coeff and exp:\n";

    for (int i = 0; i < num; i++) {
        t = new Node;
        std::cin >> t->coeff >> t->exp;
        t->next = nullptr;

        if (poly == nullptr) {
            poly = last = t;
        } else {
            last->next = t;
            last = t;
        }
    }
}

void Polynomial::display() {
    Node *p = poly;

    while (p) {
        std::cout << p->coeff << "x^" << p->exp;
        if (p->next)
            std::cout << " + ";
        p = p->next;
    }
    std::cout << std::endl;
}

long Polynomial::evaluate(int x) {
    long val = 0;
    Node *p = poly;

    while (p) {
        val += p->coeff * pow(x, p->exp);
        p = p->next;
    }
    return val;
}

int main() {
    Polynomial poly;
    poly.create();
    poly.display();
    std::cout << poly.evaluate(1) << std::endl;
    return 0;
}
