
import os
import time
from cairosvg import svg2png


def load_svg(directory,file_name):
    full_path = directory + file_name 
    file_data = open(full_path, 'r')
    svg_string = file_data.read()
    file_data.close()
    return svg_string

def create_png_from_svg(directory,file_name,svg_string):
    full_path = directory + file_name 
    print(full_path)
    svg2png(bytestring=svg_string,write_to=full_path)

def svg_to_png(src_dir,dest_dir,file_name):
    svg_string = load_svg(src_dir ,file_name)
    png_file_name = file_name.replace('.svg','.png')
    create_png_from_svg(dest_dir,png_file_name,svg_string)


#eg = load_svg(dir_path ,files[0])
#svg_to_png(dir_path, output_dir_path, files[0])
#print(eg)

cwd = os.getcwd()

print(cwd)

train_src_dir_path = cwd + '/output/train/svg/'
train_dest_dir_path = cwd + '/output/train/png/'

train_files = os.listdir(cwd + '/output/train/svg/')

[svg_to_png(train_src_dir_path, train_dest_dir_path, file_name) for file_name in train_files ]

test_src_dir_path = cwd + '/output/test/svg/'
test_dest_dir_path = cwd + '/output/test/png/'
test_files = os.listdir( cwd + '/output/test/svg/')


[svg_to_png(test_src_dir_path, test_dest_dir_path, file_name) for file_name in test_files ]