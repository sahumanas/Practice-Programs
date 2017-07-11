#define STR1(X) #X
#define STR(X) STR1(X)
int main() {
  // prints correctly
  std::cout << STR(PROTO((int), f, (int)(a)(float)(b)));














}
