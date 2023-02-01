#include "Source.h"


int main() {
  KufoCheck kc;

  while (true) {
    // Check first link
    kc.SetUrlDownFile(kc.UrlDownFile(kc.GetUrlOne(), kc.GetFile()));
    kc.StreamValue(kc.GetFile());

    kc = KufoCheck();  // Run default constructor

    // Check Second link
    kc.SetUrlDownFile(kc.UrlDownFile(kc.GetUrlTwo(), kc.GetFile()));
    kc.StreamValue(kc.GetFile());

    Sleep(3600000);
  }
  return 0;
}