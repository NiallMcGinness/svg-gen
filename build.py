import os


os.system("clang++ --std=c++11 src/main.cpp src/generate_labels/generate_labels.cpp src/generate_svg/generateSVG.cpp -o test/buildSVG ")


os.system("cd test && python3 delete_and_rebuild_data.py")