import sys


def check_argv(argv):
    if(len(argv) != 2):
        print("the argv num is wrong.")
        print("please only enter one param.")
        return False
    return True


check = check_argv(sys.argv)
if check is False:
    exit

file_name = sys.argv[1]+".h"
define_name = "__"+sys.argv[1].upper()+"_H__"

with open(file_name, "w") as f:
    f.write(f"#ifndef {define_name}\n")
    f.write(f"#define {define_name}\n")
    f.write("\n")
    f.write(f"#endif /*{define_name}*/\n")
