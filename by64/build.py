import os
import time


print("compling test and train svg generators")

os.system("clang++ --std=c++11 src/gen_train.cpp -o train")


os.system("clang++ --std=c++11 src/gen_test.cpp -o test")

print("started building train svgs and csv label")

os.system("./train")

print("finished building train svgs and csv label")

print("==========================================")
print("started building test svgs and csv label")

os.system("./test")

print("finished building test svgs and csv label")
print("==========================================")


print(" making png files from train svgs ")

os.system("python3 topng.py")

print(" finished making  png files from  svgs ")
print("==========================================")

