import os
import sys
import copy

# Filename without extension
def format_name(filename):
    return " ".join(
        x[0].upper() + x[1:]
        for x in filename.split("-")
        if len(x) > 0)

def remove_number(name):
    return name[name.index(".")+1:]

def main():
    include_cmds = {
        ".cpp": "\\includecpp",
        ".sh": "\\includescript",
        ".tex": "\\input",
        ".texs": "\\includetex",
        ".py": "\\includepy"
        # Can be expanded to more langs if needed
    }
    source_path = os.path.join(os.path.normpath(os.getcwd()), "src")

    dirnameOrder = []

    for dirname in os.listdir(source_path):
        dirpath = os.path.join(source_path, dirname)
        if not os.path.isdir(dirpath):
            # Might be a file
            continue
        section_name = format_name(dirname)
        dirnameOrder.append([copy.deepcopy(section_name), copy.deepcopy(dirpath)])

    dirnameOrder = sorted(dirnameOrder)

    for section_name, dirname in dirnameOrder:
        dirpath = os.path.join(source_path, dirname)
        section_name = remove_number(section_name)
        if not os.path.isdir(dirpath):
            # Might be a file
            continue
        print("\section{{{}}}".format(section_name))

        section_nameOrder = []

        for file in os.listdir(dirpath):
            filepath = os.path.join(dirpath, file)
            if not os.path.isfile(filepath):
                # Might be a dir
                continue
            filename, fileext = os.path.splitext(file)
            if fileext not in include_cmds.keys():
                sys.stderr.write("Found unsupported source file {}. Skipping.\n".format(filepath))
                continue
            subsection_name = format_name(filename)
            section_nameOrder.append([copy.deepcopy(subsection_name), copy.deepcopy(file)])

        section_nameOrder = sorted(section_nameOrder)

        for [subsection_name, file] in section_nameOrder:
            subsection_name = remove_number(subsection_name)
            filepath = os.path.join(dirpath, file)
            if not os.path.isfile(filepath):
                # Might be a dir
                continue
            filename, fileext = os.path.splitext(file)
            if fileext not in include_cmds.keys():
                sys.stderr.write("Found unsupported source file {}. Skipping.\n".format(filepath))
                continue
            file_relpath = os.path.join(".", os.path.relpath(filepath)).replace("\\", "/")
            if fileext == ".tex":
                print("{}{{{}}}".format(include_cmds[fileext], file_relpath))
            else:
                print("{}{{{}}}{{{}}}".format(include_cmds[fileext], subsection_name, file_relpath))

if __name__ == "__main__":
    main()
