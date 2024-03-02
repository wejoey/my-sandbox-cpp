int main() {
  __asm__ (
        "leave;"
  );
  asm ("leave");

  return 42;
}