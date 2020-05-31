#include <iostream>

#include <string.h>
#include <sys/acl.h>
#include <acl/libacl.h>

using namespace std;

int chapter17(int argc, char* argv[]) {
    acl_t acl  = acl_get_file(argv[0], ACL_TYPE_ACCESS);

    acl_entry_t entry;
    ssize_t len;
    cout << acl_to_text(acl, &len) << " ";
    cout << len << endl;
    return 0;
}

