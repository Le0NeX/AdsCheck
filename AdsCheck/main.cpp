#include "Source.h"

int main() {
	KufoCheck kc;

	//Check first link
	kc.setUrlDownFile(kc.urlDownFile(kc.getURL_ONE(), kc.getFile()));
	kc.streamValue(kc.getFile());
	
	//Check Second link
	kc.setUrlDownFile(kc.urlDownFile(kc.getURL_TWO(), kc.getFile()));
	kc.streamValue(kc.getFile());

	return 0;
}