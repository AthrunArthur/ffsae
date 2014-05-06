#include "sae/sae.h"


int main(int argc, char *argv[])
{
  ff::FMatrix m(1, 2);
  m(0, 0) = 784;
  m(0, 1) = 100;
  ff::SAE s(m);
  return 0;
}
