#include "Source.h"

int main() {
  KufoCheck kc;

  while (true) {
    // Check first link
    kc.SetUrlDownFile(kc.UrlDownFile(kc.GetUrlOne(), kc.GetFile()));
    kc.SetSectionName("Services the computers");
    kc.StreamValue(kc.GetFile());

    kc = KufoCheck();  // Run default constructor

    // Check Second link
    kc.SetUrlDownFile(kc.UrlDownFile(kc.GetUrlTwo(), kc.GetFile()));
    kc.SetSectionName("Computers repair");
    kc.StreamValue(kc.GetFile());

    Sleep(1800000);
  }
  return 0;
}