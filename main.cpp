#include "Tl.h"

int main() {
    Tl a(5,2);
    Tl b(2,3);
    Tl c(0,0);
    Tl g(0,0);
    a.print();
    c *= a;
    c.print();
    g >> a-b;
    g.print();
    return 0;
}
