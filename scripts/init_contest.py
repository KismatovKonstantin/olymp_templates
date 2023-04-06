import os
import shutil

def main():
    dir1 = os.getcwd() # curent directory

    new_contest = input("Input the name of the contest: ")
    dir2 = dir1 + "/" + new_contest
    while os.path.exists(dir2):
        print("This folder already exists!")
        new_contest = input("Input another name of the contest: ")
        dir2 = dir1 + "/" + new_contest

    pr_q = int(input("Input the quantity of problems: "))
    while not 1 <= pr_q <= 20:
        print("BETWEEN 1 AND 20")
        pr_q = int(input("Input the quantity of problems: "))

    
    os.mkdir(dir2)
    print(dir2, "created!")

    letters = "abcdefghijklmnopqrstuvwxyz"
    for i in range(pr_q):
        name = letters[i]
        dir3 = dir2 + "/" + name
        os.mkdir(dir3)
        print(new_contest + "/" + name + " folder created!")

        shutil.copy(dir1 + "/template.cpp", dir3 + "/" + name + ".cpp")
        print("File " + new_contest + "/" + name + "/" + name + ".cpp created!")

        open(dir3 + "/input.txt", "x")
        print("File " + new_contest + "/" + name + "/input.txt created!")

if __name__ == "__main__":
    main()